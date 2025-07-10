#pragma once
#include <windows.h>

typedef BOOL (WINAPI *CUS_CREATEPROCESSA)(
    LPCSTR                lpApplicationName,
    LPSTR                 lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    BOOL                  bInheritHandles,
    DWORD                 dwCreationFlags,
    LPVOID                lpEnvironment,
    LPCSTR                lpCurrentDirectory,
    LPSTARTUPINFOA        lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation
);

typedef SHFOLDERAPI (WINAPI *CUS_SHGetFolderPathA)(
    HWND   hwnd,
    int    csidl,
    HANDLE hToken,
    DWORD  dwFlags,
    LPSTR  pszPath
);