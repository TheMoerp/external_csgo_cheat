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

	int ReadInt(int address);

	// Read value from memory
	template <typename T>
	T ReadMemory(DWORD address) {
		T buffer;
		ReadProcessMemory(offsets.hProcess, (LPVOID)address, &buffer, sizeof(buffer), NULL);
		return buffer;
	}

	
	// Write value from memory
	template <typename T>
	void WriteMemory(DWORD address, T val) {
		WriteProcessMemory(offsets.hProcess, (LPVOID)address, &val, sizeof(val), NULL);
	}

	int BytesToInt32(unsigned char input[], int startOffset)
	{
		return (input[startOffset]) | (input[startOffset + 1] << 8) |
			(input[startOffset + 2] << 16) | (input[startOffset + 3] << 24);
	}

	template <typename IntegerType>
	IntegerType BytesToInt32(IntegerType& result, unsigned char bytes[], bool isLittleEndian = true)
	{
		result = 0;

		if (isLittleEndian)
			for (int n = sizeof(result); n >= 0; n--)
				result = (result << 8) + bytes[n];
		else
			for (unsigned n = 0; n < sizeof(result); n++)
				result = (result << 8) + bytes[n];

		return result;
	}
};


extern Memory mem;