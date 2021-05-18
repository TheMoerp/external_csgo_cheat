#pragma once
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <TlHelp32.h>

#include "config.h"
#include "offsets.h"


class Memory {
private:
	struct StringChar_t {
		char buffer[256];
	};

public:
	HWND hWnd;
	DWORD pID;
	HANDLE hSS;
	MODULEENTRY32 mEntry;

	DWORD GetProcessID(const wchar_t* windowName);
	MODULEENTRY32 GetModule(DWORD pID, const wchar_t* moduleName);
	void Setup();
	void GetModules();

	// Read value from memory
	template <typename T>
	T ReadMemory(DWORD address) {
		T buffer;
		ReadProcessMemory(offsets.hProcess, (LPVOID)_address, &buffer, sizeof(buffer), NULL);
		return buffer;
	}

	
	// Write value from memory
	template <typename T>
	void WriteMemory(DWORD address, T val) {
		WriteProcessMemory(offsets.hProcess, (LPVOID)address, &val, sizeof(val), NULL);
	}

	
	// Read string from memory
	std::string ReadStringMemory(DWORD address);
};


extern Memory mem;