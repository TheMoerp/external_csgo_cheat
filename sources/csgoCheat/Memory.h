#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#include "config.h"
#include "offsets.h"


class Memory {
public:
	HWND hWnd;
	DWORD pID;
	HANDLE hSS;
	MODULEENTRY32 mEntry;

	DWORD GetProcessID(const wchar_t* _windowName);
	MODULEENTRY32 GetModule(DWORD _pID, const wchar_t* _moduleName);
	void Setup();
	void GetModules();


	template <typename T>
	T ReadMemory(DWORD _address) {
		T buffer;
		ReadProcessMemory(offsets.hProcess, (LPVOID)_address, &buffer, sizeof(buffer), NULL);
		return buffer;
	}


	template <typename T>
	void WriteMemory(DWORD _address, T _val) {
		WriteProcessMemory(offsets.hProcess, (LPVOID)_address, &_val, sizeof(_val), NULL);
	}
};


extern Memory mem;