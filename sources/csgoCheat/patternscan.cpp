#include "patternscan.h"


DWORD FindAddress(HANDLE hProcess, wchar_t* moduleName, char* pattern, char* mask) {
	MODULEENTRY32 moduleEntry = mem.GetModule(offsets.processID, moduleName);

	if (!moduleEntry.th32ModuleID) {
		return NULL;
	}

	uintptr_t base = (uintptr_t)moduleEntry.modBaseAddr;
	uintptr_t size = base + moduleEntry.modBaseSize;

	uintptr_t curChunk = base;
	SIZE_T bytesRead;

	while (curChunk < size) {
		char buffer[4096];

		DWORD oProtect;
		VirtualProtectEx(hProcess, (LPVOID)curChunk, sizeof(buffer), PAGE_EXECUTE_READWRITE, &oProtect);
		ReadProcessMemory(hProcess, (LPVOID)curChunk, &buffer, sizeof(buffer), &bytesRead);
		VirtualProtectEx(hProcess, (LPVOID)curChunk, sizeof(buffer), oProtect, &oProtect);

		if (bytesRead == 0) {
			return NULL;
		}
		
		DWORD internalAddr = FindPattern((char*)&buffer, bytesRead, pattern, mask);

		if (internalAddr != NULL) {
			uintptr_t offsetFromBuffer = (uintptr_t)internalAddr - (uintptr_t)&buffer;

			return (DWORD)(curChunk + offsetFromBuffer);
		}
		else {
			curChunk += bytesRead;
		}

		return NULL;
	}
}


