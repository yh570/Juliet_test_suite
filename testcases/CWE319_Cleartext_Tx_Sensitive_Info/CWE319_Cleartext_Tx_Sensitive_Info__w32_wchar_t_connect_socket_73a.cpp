/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73a.cpp
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * BadSource: connect_socket Read the password using a connect socket (client side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    GoodSink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    BadSink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */

#define TCP_PORT 27015
#define IP_ADDRESS "127.0.0.1"

using namespace std;

namespace CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73
{


/* bad function declaration */
void badSink(list<wchar_t *> passwordList);

void bad()
{
    wchar_t * password;
    list<wchar_t *> passwordList;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    {
        WSADATA wsaData;
        int wsaDataInit = 0;
        int recvResult;
        struct sockaddr_in service;
        wchar_t *replace;
        SOCKET connectSocket = INVALID_SOCKET;
        size_t passwordLen = wcslen(password);
        do
        {
            if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
            {
                break;
            }
            wsaDataInit = 1;
            connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (connectSocket == INVALID_SOCKET)
            {
                break;
            }
            memset(&service, 0, sizeof(service));
            service.sin_family = AF_INET;
            service.sin_addr.s_addr = inet_addr(IP_ADDRESS);
            service.sin_port = htons(TCP_PORT);
            if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
            {
                break;
            }
            /* Abort on error or the connection was closed, make sure to recv one
             * less char than is in the recv_buf in order to append a terminator */
            /* POTENTIAL FLAW: Reading sensitive data from the network */
            recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0);
            if (recvResult == SOCKET_ERROR || recvResult == 0)
            {
                break;
            }
            /* Append null terminator */
            password[passwordLen + recvResult / sizeof(wchar_t)] = L'\0';
            /* Eliminate CRLF */
            replace = wcschr(password, L'\r');
            if (replace)
            {
                *replace = L'\0';
            }
            replace = wcschr(password, L'\n');
            if (replace)
            {
                *replace = L'\0';
            }
        }
        while (0);
        if (connectSocket != INVALID_SOCKET)
        {
            closesocket(connectSocket);
        }
        if (wsaDataInit)
        {
            WSACleanup();
        }
    }
    /* Put password in a list */
    passwordList.push_back(password);
    passwordList.push_back(password);
    passwordList.push_back(password);
    badSink(passwordList);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<wchar_t *> passwordList);

static void goodG2B()
{
    wchar_t * password;
    list<wchar_t *> passwordList;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    /* FIX: Use a hardcoded password (it was not sent over the network)
    * INCIDENTAL FLAW: CWE-259 Hard Coded Password */
    wcscpy(password, L"Password1234!");
    /* Put password in a list */
    passwordList.push_back(password);
    passwordList.push_back(password);
    passwordList.push_back(password);
    goodG2BSink(passwordList);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<wchar_t *> passwordList);

static void goodB2G()
{
    wchar_t * password;
    list<wchar_t *> passwordList;
    wchar_t passwordBuffer[100] = L"";
    password = passwordBuffer;
    {
        WSADATA wsaData;
        int wsaDataInit = 0;
        int recvResult;
        struct sockaddr_in service;
        wchar_t *replace;
        SOCKET connectSocket = INVALID_SOCKET;
        size_t passwordLen = wcslen(password);
        do
        {
            if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
            {
                break;
            }
            wsaDataInit = 1;
            connectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (connectSocket == INVALID_SOCKET)
            {
                break;
            }
            memset(&service, 0, sizeof(service));
            service.sin_family = AF_INET;
            service.sin_addr.s_addr = inet_addr(IP_ADDRESS);
            service.sin_port = htons(TCP_PORT);
            if (connect(connectSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
            {
                break;
            }
            /* Abort on error or the connection was closed, make sure to recv one
             * less char than is in the recv_buf in order to append a terminator */
            /* POTENTIAL FLAW: Reading sensitive data from the network */
            recvResult = recv(connectSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(wchar_t), 0);
            if (recvResult == SOCKET_ERROR || recvResult == 0)
            {
                break;
            }
            /* Append null terminator */
            password[passwordLen + recvResult / sizeof(wchar_t)] = L'\0';
            /* Eliminate CRLF */
            replace = wcschr(password, L'\r');
            if (replace)
            {
                *replace = L'\0';
            }
            replace = wcschr(password, L'\n');
            if (replace)
            {
                *replace = L'\0';
            }
        }
        while (0);
        if (connectSocket != INVALID_SOCKET)
        {
            closesocket(connectSocket);
        }
        if (wsaDataInit)
        {
            WSACleanup();
        }
    }
    passwordList.push_back(password);
    passwordList.push_back(password);
    passwordList.push_back(password);
    goodB2GSink(passwordList);
}

void good()
{
    goodG2B();
    goodB2G();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE319_Cleartext_Tx_Sensitive_Info__w32_wchar_t_connect_socket_73; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
    return 0;
}

#endif
