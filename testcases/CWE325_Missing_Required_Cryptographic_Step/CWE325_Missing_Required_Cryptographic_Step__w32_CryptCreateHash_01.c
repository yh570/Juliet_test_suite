/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE325_Missing_Required_Cryptographic_Step__w32_CryptCreateHash_01.c
Label Definition File: CWE325_Missing_Required_Cryptographic_Step__w32.label.xml
Template File: point-flaw-01.tmpl.c
*/
/*
 * @description
 * CWE: 325 Missing Required Cryptographic Step
 * Sinks: CryptCreateHash
 *    GoodSink: All required cryptographic steps are present
 *    BadSink : Missing call to CryptCreateHash()
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#include <wincrypt.h>

#pragma comment(lib, "advapi32")

#define HASH_INPUT "ABCDEFG123456" /* INCIDENTAL: Hardcoded crypto */
#define PAYLOAD "plaintext"


void CWE325_Missing_Required_Cryptographic_Step__w32_CryptCreateHash_01_bad()
{
    {
        BYTE payload[100];
        DWORD payloadLen = strlen(PAYLOAD);
        HCRYPTPROV hCryptProv = (HCRYPTPROV)NULL;
        HCRYPTHASH hHash = (HCRYPTHASH)NULL;
        HCRYPTKEY hKey = (HCRYPTKEY)NULL;
        char hashData[100] = HASH_INPUT;
        do
        {
            /* Copy plaintext into payload buffer */
            memcpy(payload, PAYLOAD, payloadLen);
            /* Aquire a Context */
            if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0))
            {
                break;
            }
            /* FLAW: Missing required step (CryptCreateHash) causes the payload to remain in plaintext form */
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
            /* Encrypt the payload */
            if(!CryptEncrypt(hKey, 0, 1, 0, payload, &payloadLen, sizeof(payload)))
            {
                break;
            }
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
        /* Do something with the encrypted data */
        printBytesLine(payload, payloadLen);
    }
}



static void good1()
{
    {
        BYTE payload[100];
        DWORD payloadLen = strlen(PAYLOAD);
        HCRYPTPROV hCryptProv = (HCRYPTPROV)NULL;
        HCRYPTHASH hHash = (HCRYPTHASH)NULL;
        HCRYPTKEY hKey = (HCRYPTKEY)NULL;
        char hashData[100] = HASH_INPUT;
        do
        {
            /* Copy plaintext into payload buffer */
            memcpy(payload, PAYLOAD, payloadLen);
            /* Aquire a Context */
            if(!CryptAcquireContext(&hCryptProv, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0))
            {
                break;
            }
            /* FIX: All required steps are present */
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
            /* Encrypt the payload */
            if(!CryptEncrypt(hKey, 0, 1, 0, payload, &payloadLen, sizeof(payload)))
            {
                break;
            }
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
        /* Do something with the encrypted data */
        printBytesLine(payload, payloadLen);
    }
}

void CWE325_Missing_Required_Cryptographic_Step__w32_CryptCreateHash_01_good()
{
    good1();
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
    CWE325_Missing_Required_Cryptographic_Step__w32_CryptCreateHash_01_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE325_Missing_Required_Cryptographic_Step__w32_CryptCreateHash_01_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
