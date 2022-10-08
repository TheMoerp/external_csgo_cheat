#include "patternscan.h"


DWORD FindAddress(HANDLE hProcess, const wchar_t* moduleName, const char* pattern, const char* mask) {
    MODULEENTRY32 moduleEntry = mem.GetModule(offsets.processID, moduleName);

    // No Module Entry found
    if (!moduleEntry.th32ModuleID) {
        return NULL;
    }

    // Module base address = scan starting point
    uintptr_t base = (uintptr_t)moduleEntry.modBaseAddr;
    // Size of Module = scan end point
    uintptr_t size = base + moduleEntry.modBaseSize;

    uintptr_t curChunk = base;
    SIZE_T bytesRead;

    while (curChunk < size) {
        // Area to scan
        char buffer[4096];

        // Change read protection, raed memory and change read protection back to the original
        DWORD oProtect;
        VirtualProtectEx(hProcess, (LPVOID)curChunk, sizeof(buffer), PAGE_EXECUTE_READWRITE, &oProtect);
        ReadProcessMemory(hProcess, (LPVOID)curChunk, &buffer, sizeof(buffer), &bytesRead);
        VirtualProtectEx(hProcess, (LPVOID)curChunk, sizeof(buffer), oProtect, &oProtect);

        // No bytes read
        if (bytesRead == 0) {
            return NULL;
        }

        DWORD internalAddr = FindPattern((char*)&buffer, bytesRead, pattern, mask);

        if (internalAddr != NULL) {
            // Calculate real address
            uintptr_t offsetFromBuffer = (uintptr_t)internalAddr - (uintptr_t)&buffer;

            return (DWORD)(curChunk + offsetFromBuffer);
        }
        else {
            // Next chunk
            curChunk += bytesRead;
        }
    }
    return NULL;
}


// Find matching pattern
DWORD FindPattern(char* base, size_t size, const char* pattern, const char* mask) {
    size_t patternLen = strlen(mask);

    for (DWORD i = 0; i < size - patternLen; i++) {
        bool found = true;

        for (DWORD j = 0; j < patternLen; j++) {

            if (mask[j] != '?' && pattern[j] != *(base + i + j)) {
                found = false;
                break;
            }
        }

        if (found) {
            return (DWORD)(base + i);
        }
    }

    return NULL;
}
