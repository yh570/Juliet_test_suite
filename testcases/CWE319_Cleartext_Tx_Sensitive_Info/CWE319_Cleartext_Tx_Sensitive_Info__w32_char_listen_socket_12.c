/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_12.c
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-12.tmpl.c
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * BadSource: listen_socket Read the password using a listen socket (server side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    GoodSink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    BadSink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 12 Control flow: if(globalReturnsTrueOrFalse())
 *
 * */

#include "std_testcase.h"

#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#pragma comment(lib, "advapi32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */


void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_12_bad()
{
    char * password;
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    if(globalReturnsTrueOrFalse())
    {
        {
            WSADATA wsaData;
            int wsaDataInit = 0;
            int recvResult;
            struct sockaddr_in service;
            char *replace;
            SOCKET listenSocket = INVALID_SOCKET;
            SOCKET acceptSocket = INVALID_SOCKET;
            size_t passwordLen = strlen(password);
            do
            {
                if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
                {
                    break;
                }
                wsaDataInit = 1;
                listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (listenSocket == INVALID_SOCKET)
                {
                    break;
                }
                memset(&service, 0, sizeof(service));
                service.sin_family = AF_INET;
                service.sin_addr.s_addr = INADDR_ANY;
                service.sin_port = htons(TCP_PORT);
                if (bind(listenSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
                {
                    break;
                }
                if (listen(listenSocket, LISTEN_BACKLOG) == SOCKET_ERROR)
                {
                    break;
                }
                acceptSocket = accept(listenSocket, NULL, NULL);
                if (acceptSocket == SOCKET_ERROR)
                {
                    break;
                }
                /* Abort on error or the connection was closed */
                /* POTENTIAL FLAW: Reading sensitive data from the network */
                recvResult = recv(acceptSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0);
                if (recvResult == SOCKET_ERROR || recvResult == 0)
                {
                    break;
                }
                /* Append null terminator */
                password[passwordLen + recvResult / sizeof(char)] = '\0';
                /* Eliminate CRLF */
                replace = strchr(password, '\r');
                if (replace)
                {
                    *replace = '\0';
                }
                replace = strchr(password, '\n');
                if (replace)
                {
                    *replace = '\0';
                }
            }
            while (0);
            if (listenSocket != INVALID_SOCKET)
            {
                closesocket(listenSocket);
            }
            if (acceptSocket != INVALID_SOCKET)
            {
                closesocket(acceptSocket);
            }
            if (wsaDataInit)
            {
                WSACleanup();
            }
        }
    }
    else
    {
        /* FIX: Use a hardcoded password (it was not sent over the network)
        * INCIDENTAL FLAW: CWE-259 Hard Coded Password */
        strcpy(password, "Password1234!");
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            /* POTENTIAL FLAW: Using sensitive information that was possibly sent in plaintext over the network */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
    else
    {
        {
            HCRYPTPROV hCryptProv = 0;
            HCRYPTHASH hHash = 0;
            HCRYPTKEY hKey = 0;
            char hashData[100] = HASH_INPUT;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            do
            {
                BYTE payload[(100 - 1) * sizeof(char)]; /* same size as password except for NUL terminator */
                DWORD payloadBytes;
                /* Hex-decode the input string into raw bytes */
                payloadBytes = decodeHexChars(payload, sizeof(payload), password);
                /* Wipe the hex string, to prevent it from being given to LogonUserA if
                 * any of the crypto calls fail. */
                SecureZeroMemory(password, 100 * sizeof(char));
                /* Aquire a Context */
                if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0))
                {
                    break;
                }
                /* Create hash handle */
                if(!CryptCreateHash(hCryptProv, CALG_SHA_256, 0, 0, &hHash))
                {
                    break;
                }
                /* Hash the input string */
                if(!CryptHashData(hHash, (BYTE*)hashData, strlen(hashData), 0))
                {
                    break;
                }
                /* Derive an AES key from the hash */
                if(!CryptDeriveKey(hCryptProv, CALG_AES_256, hHash, 0, &hKey))
                {
                    break;
                }
                /* FIX: Decrypt the password */
                if(!CryptDecrypt(hKey, 0, 1, 0, payload, &payloadBytes))
                {
                    break;
                }
                /* Copy back into password and NUL-terminate */
                memcpy(password, payload, payloadBytes);
                password[payloadBytes / sizeof(char)] = '\0';
            }
            while (0);
            if (hKey)
            {
                CryptDestroyKey(hKey);
            }
            if (hHash)
            {
                CryptDestroyHash(hHash);
            }
            if (hCryptProv)
            {
                CryptReleaseContext(hCryptProv, 0);
            }
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
}



/* goodB2G() - use badsource and goodsink by changing the first "if" so that
   both branches use the BadSource and the second "if" so that both branches
   use the GoodSink */
static void goodB2G()
{
    char * password;
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    if(globalReturnsTrueOrFalse())
    {
        {
            WSADATA wsaData;
            int wsaDataInit = 0;
            int recvResult;
            struct sockaddr_in service;
            char *replace;
            SOCKET listenSocket = INVALID_SOCKET;
            SOCKET acceptSocket = INVALID_SOCKET;
            size_t passwordLen = strlen(password);
            do
            {
                if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
                {
                    break;
                }
                wsaDataInit = 1;
                listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (listenSocket == INVALID_SOCKET)
                {
                    break;
                }
                memset(&service, 0, sizeof(service));
                service.sin_family = AF_INET;
                service.sin_addr.s_addr = INADDR_ANY;
                service.sin_port = htons(TCP_PORT);
                if (bind(listenSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
                {
                    break;
                }
                if (listen(listenSocket, LISTEN_BACKLOG) == SOCKET_ERROR)
                {
                    break;
                }
                acceptSocket = accept(listenSocket, NULL, NULL);
                if (acceptSocket == SOCKET_ERROR)
                {
                    break;
                }
                /* Abort on error or the connection was closed */
                /* POTENTIAL FLAW: Reading sensitive data from the network */
                recvResult = recv(acceptSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0);
                if (recvResult == SOCKET_ERROR || recvResult == 0)
                {
                    break;
                }
                /* Append null terminator */
                password[passwordLen + recvResult / sizeof(char)] = '\0';
                /* Eliminate CRLF */
                replace = strchr(password, '\r');
                if (replace)
                {
                    *replace = '\0';
                }
                replace = strchr(password, '\n');
                if (replace)
                {
                    *replace = '\0';
                }
            }
            while (0);
            if (listenSocket != INVALID_SOCKET)
            {
                closesocket(listenSocket);
            }
            if (acceptSocket != INVALID_SOCKET)
            {
                closesocket(acceptSocket);
            }
            if (wsaDataInit)
            {
                WSACleanup();
            }
        }
    }
    else
    {
        {
            WSADATA wsaData;
            int wsaDataInit = 0;
            int recvResult;
            struct sockaddr_in service;
            char *replace;
            SOCKET listenSocket = INVALID_SOCKET;
            SOCKET acceptSocket = INVALID_SOCKET;
            size_t passwordLen = strlen(password);
            do
            {
                if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
                {
                    break;
                }
                wsaDataInit = 1;
                listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (listenSocket == INVALID_SOCKET)
                {
                    break;
                }
                memset(&service, 0, sizeof(service));
                service.sin_family = AF_INET;
                service.sin_addr.s_addr = INADDR_ANY;
                service.sin_port = htons(TCP_PORT);
                if (bind(listenSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
                {
                    break;
                }
                if (listen(listenSocket, LISTEN_BACKLOG) == SOCKET_ERROR)
                {
                    break;
                }
                acceptSocket = accept(listenSocket, NULL, NULL);
                if (acceptSocket == SOCKET_ERROR)
                {
                    break;
                }
                /* Abort on error or the connection was closed */
                /* POTENTIAL FLAW: Reading sensitive data from the network */
                recvResult = recv(acceptSocket, (char*)(password + passwordLen), (100 - passwordLen - 1) * sizeof(char), 0);
                if (recvResult == SOCKET_ERROR || recvResult == 0)
                {
                    break;
                }
                /* Append null terminator */
                password[passwordLen + recvResult / sizeof(char)] = '\0';
                /* Eliminate CRLF */
                replace = strchr(password, '\r');
                if (replace)
                {
                    *replace = '\0';
                }
                replace = strchr(password, '\n');
                if (replace)
                {
                    *replace = '\0';
                }
            }
            while (0);
            if (listenSocket != INVALID_SOCKET)
            {
                closesocket(listenSocket);
            }
            if (acceptSocket != INVALID_SOCKET)
            {
                closesocket(acceptSocket);
            }
            if (wsaDataInit)
            {
                WSACleanup();
            }
        }
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            HCRYPTPROV hCryptProv = 0;
            HCRYPTHASH hHash = 0;
            HCRYPTKEY hKey = 0;
            char hashData[100] = HASH_INPUT;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            do
            {
                BYTE payload[(100 - 1) * sizeof(char)]; /* same size as password except for NUL terminator */
                DWORD payloadBytes;
                /* Hex-decode the input string into raw bytes */
                payloadBytes = decodeHexChars(payload, sizeof(payload), password);
                /* Wipe the hex string, to prevent it from being given to LogonUserA if
                 * any of the crypto calls fail. */
                SecureZeroMemory(password, 100 * sizeof(char));
                /* Aquire a Context */
                if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0))
                {
                    break;
                }
                /* Create hash handle */
                if(!CryptCreateHash(hCryptProv, CALG_SHA_256, 0, 0, &hHash))
                {
                    break;
                }
                /* Hash the input string */
                if(!CryptHashData(hHash, (BYTE*)hashData, strlen(hashData), 0))
                {
                    break;
                }
                /* Derive an AES key from the hash */
                if(!CryptDeriveKey(hCryptProv, CALG_AES_256, hHash, 0, &hKey))
                {
                    break;
                }
                /* FIX: Decrypt the password */
                if(!CryptDecrypt(hKey, 0, 1, 0, payload, &payloadBytes))
                {
                    break;
                }
                /* Copy back into password and NUL-terminate */
                memcpy(password, payload, payloadBytes);
                password[payloadBytes / sizeof(char)] = '\0';
            }
            while (0);
            if (hKey)
            {
                CryptDestroyKey(hKey);
            }
            if (hHash)
            {
                CryptDestroyHash(hHash);
            }
            if (hCryptProv)
            {
                CryptReleaseContext(hCryptProv, 0);
            }
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
    else
    {
        {
            HCRYPTPROV hCryptProv = 0;
            HCRYPTHASH hHash = 0;
            HCRYPTKEY hKey = 0;
            char hashData[100] = HASH_INPUT;
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            do
            {
                BYTE payload[(100 - 1) * sizeof(char)]; /* same size as password except for NUL terminator */
                DWORD payloadBytes;
                /* Hex-decode the input string into raw bytes */
                payloadBytes = decodeHexChars(payload, sizeof(payload), password);
                /* Wipe the hex string, to prevent it from being given to LogonUserA if
                 * any of the crypto calls fail. */
                SecureZeroMemory(password, 100 * sizeof(char));
                /* Aquire a Context */
                if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0))
                {
                    break;
                }
                /* Create hash handle */
                if(!CryptCreateHash(hCryptProv, CALG_SHA_256, 0, 0, &hHash))
                {
                    break;
                }
                /* Hash the input string */
                if(!CryptHashData(hHash, (BYTE*)hashData, strlen(hashData), 0))
                {
                    break;
                }
                /* Derive an AES key from the hash */
                if(!CryptDeriveKey(hCryptProv, CALG_AES_256, hHash, 0, &hKey))
                {
                    break;
                }
                /* FIX: Decrypt the password */
                if(!CryptDecrypt(hKey, 0, 1, 0, payload, &payloadBytes))
                {
                    break;
                }
                /* Copy back into password and NUL-terminate */
                memcpy(password, payload, payloadBytes);
                password[payloadBytes / sizeof(char)] = '\0';
            }
            while (0);
            if (hKey)
            {
                CryptDestroyKey(hKey);
            }
            if (hHash)
            {
                CryptDestroyHash(hHash);
            }
            if (hCryptProv)
            {
                CryptReleaseContext(hCryptProv, 0);
            }
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
}

/* goodG2B() - use goodsource and badsink by changing the first "if" so that
   both branches use the GoodSource and the second "if" so that both branches
   use the BadSink */
static void goodG2B()
{
    char * password;
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    if(globalReturnsTrueOrFalse())
    {
        /* FIX: Use a hardcoded password (it was not sent over the network)
        * INCIDENTAL FLAW: CWE-259 Hard Coded Password */
        strcpy(password, "Password1234!");
    }
    else
    {
        /* FIX: Use a hardcoded password (it was not sent over the network)
        * INCIDENTAL FLAW: CWE-259 Hard Coded Password */
        strcpy(password, "Password1234!");
    }
    if(globalReturnsTrueOrFalse())
    {
        {
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            /* POTENTIAL FLAW: Using sensitive information that was possibly sent in plaintext over the network */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
    else
    {
        {
            HANDLE pHandle;
            char * username = "User";
            char * domain = "Domain";
            /* Use the password in LogonUser() to establish that it is "sensitive" */
            /* POTENTIAL FLAW: Using sensitive information that was possibly sent in plaintext over the network */
            if (LogonUserA(
                        username,
                        domain,
                        password,
                        LOGON32_LOGON_NETWORK,
                        LOGON32_PROVIDER_DEFAULT,
                        &pHandle) != 0)
            {
                printLine("User logged in successfully.");
                CloseHandle(pHandle);
            }
            else
            {
                printLine("Unable to login.");
            }
        }
    }
}

void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_12_good()
{
    goodB2G();
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_12_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE319_Cleartext_Tx_Sensitive_Info__w32_char_listen_socket_12_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
