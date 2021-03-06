/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_65a.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sinks:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#define CRYPTO_KEY L"Hardcoded"

#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")


/* bad function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_65b_badSink(wchar_t * cryptoKey);

void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_65_bad()
{
    wchar_t * cryptoKey;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_65b_badSink;
    wchar_t cryptoKeyBuffer[100] = L"";
    cryptoKey = cryptoKeyBuffer;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    wcscpy(cryptoKey, CRYPTO_KEY);
    /* use the function pointer */
    funcPtr(cryptoKey);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_65b_goodG2BSink(wchar_t * cryptoKey);

static void goodG2B()
{
    wchar_t * cryptoKey;
    void (*funcPtr) (wchar_t *) = CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_65b_goodG2BSink;
    wchar_t cryptoKeyBuffer[100] = L"";
    cryptoKey = cryptoKeyBuffer;
    {
        size_t cryptoKeyLen = wcslen(cryptoKey);
        /* if there is room in cryptoKey, read into it from the console */
        if(100-cryptoKeyLen > 1)
        {
            /* FIX: Obtain the hash input from the console */
            if (fgetws(cryptoKey+cryptoKeyLen, (int)(100-cryptoKeyLen), stdin) == NULL)
            {
                printLine("fgetws() failed");
                /* Restore NUL terminator if fgetws fails */
                cryptoKey[cryptoKeyLen] = L'\0';
            }
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgetws() */
            cryptoKeyLen = wcslen(cryptoKey);
            if (cryptoKeyLen > 0)
            {
                cryptoKey[cryptoKeyLen-1] = L'\0';
            }
        }
    }
    funcPtr(cryptoKey);
}

void CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_65_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE321_Hard_Coded_Cryptographic_Key__w32_wchar_t_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
