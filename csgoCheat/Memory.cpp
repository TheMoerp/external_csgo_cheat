#include "Memory.h"
#include <iostream>

Memory mem;
using namespace std;

// This function gets the window handle of cs:go and returns the process ID
DWORD Memory::GetProcessID(const wchar_t* _windowName) {
	do {
		hWnd = FindWindow(0, _windowName); // gets the window handle
		Sleep(50);
	} while (!hWnd); 

	GetWindowThreadProcessId(hWnd, &pID); // gets the process ID 
	
	cout << "CS:GO ProcessID found: " << pID << endl;
	cout << "" << endl;
	return pID;
}

// This function returns the moduleentry for a module that is searched
MODULEENTRY32 Memory::GetModule(DWORD _pID, const wchar_t* _moduleName) {
	hSS= CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, _pID);
	mEntry.dwSize = sizeof(MODULEENTRY32);

	if (hSS!= INVALID_HANDLE_VALUE) {
		if (Module32First(hSS, &mEntry)) {
			do {
				if (!wcscmp((const wchar_t*)mEntry.szModule, _moduleName)) {
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