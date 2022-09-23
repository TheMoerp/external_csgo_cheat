#pragma once
#include <Windows.h>
#include <TlHelp32.h>

#include "memory.h"

DWORD FindAddress(HANDLE hProcess, const wchar_t* moduleName, const char* pattern, const char* mask);

DWORD FindPattern(char* base, size_t size, const char* pattern, const char* mask);