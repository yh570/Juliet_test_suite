/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22b.c
Label Definition File: CWE319_Cleartext_Tx_Sensitive_Info__w32.label.xml
Template File: sources-sinks-22b.tmpl.c
*/
/*
 * @description
 * CWE: 319 Cleartext Transmission of Sensitive Information
 * BadSource: connect_socket Read the password using a connect socket (client side)
 * GoodSource: Use a hardcoded password (one that was not sent over the network)
 * Sinks:
 *    GoodSink: Decrypt the password before using it in an authentication API call to show that it was transferred as ciphertext
 *    BadSink : Use the password directly from the source in an authentication API call to show that it was transferred as plaintext
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */


/* The global variable below is used to drive control flow in the sink function */
extern int CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_badGlobal;

void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_badSink(char * password)
{
    if(CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_badGlobal)
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



/* The global variables below are used to drive control flow in the sink functions. */
extern int CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_goodB2G1Global;
extern int CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_goodB2G2Global;
extern int CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_goodG2BGlobal;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_goodB2G1Sink(char * password)
{
    if(CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_goodB2G1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
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

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_goodB2G2Sink(char * password)
{
    if(CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_goodB2G2Global)
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

/* goodG2B() - use goodsource and badsink */
void CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_goodG2BSink(char * password)
{
    if(CWE319_Cleartext_Tx_Sensitive_Info__w32_char_connect_socket_22_goodG2BGlobal)
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

