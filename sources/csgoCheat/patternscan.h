#pragma once
#include <Windows.h>
#include <TlHelp32.h>

#include "memory.h"

DWORD FindAddress(HANDLE hProcess, wchar_t* moduleName, char* pattern, char* mask);

DWORD FindPattern(char* base, size_t size, char* pattern, char* mask);