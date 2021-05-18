#include "memory.h"

Memory mem;
using namespace std;


// Get a process by windowname
DWORD Memory::GetProcessID(const wchar_t* windowName) {
	do {
		hWnd = FindWindow(0, windowName);
		Sleep(50);
	} while (!hWnd); 

	GetWindowThreadProcessId(hWnd, &pID);
	
	cout << "CS:GO ProcessID found: " << pID << endl;
	cout << "" << endl;
	return pID;
}


// Get a module by name
MODULEENTRY32 Memory::GetModule(DWORD pID, const wchar_t* moduleName) {
	hSS= CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pID);
	mEntry.dwSize = sizeof(MODULEENTRY32);

	if (hSS!= INVALID_HANDLE_VALUE) {
		if (Module32First(hSS, &mEntry)) {
			do {
				if (!wcscmp((const wchar_t*)mEntry.szModule, moduleName)) {
					break;
				}
			} while (Module32Next(hSS, &mEntry));
		}
		CloseHandle(hSS);
	}

	return mEntry;
}


void Memory::Setup() {
	offsets.processID = GetProcessID(L"Counter-Strike: Global Offensive");
	offsets.hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, offsets.processID);
}


// Get client.dll and engine.dll
void Memory::GetModules() {
	do {
		offsets.clientBase = (DWORD)GetModule(offsets.processID, L"client.dll").modBaseAddr;
		Sleep(50);
	} while (!offsets.clientBase);

	do {
		offsets.engineBase = (DWORD)GetModule(offsets.processID, L"engine.dll").modBaseAddr;
		Sleep(50);
	} while (!offsets.engineBase);
}

// Read string from memory
std::string Memory::ReadStringMemory(DWORD address) {
	string str;
	StringChar_t tmp = ReadMemory<StringChar_t>(address);

	for (int i = 0; i < sizeof(StringChar_t); i++) {
		if (tmp.buffer[i] == '\0') {
			break;
		}
		str += tmp.buffer[i];
	}
	return str;
}