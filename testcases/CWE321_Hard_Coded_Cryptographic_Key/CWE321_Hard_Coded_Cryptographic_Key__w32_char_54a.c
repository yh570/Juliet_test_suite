/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_54a.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-54a.tmpl.c
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sink:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CRYPTO_KEY "Hardcoded"

#include <windows.h>
#include <wincrypt.h>

/* Link with the Advapi32.lib file for Crypt* functions */
#pragma comment (lib, "Advapi32")


/* bad function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_54b_badSink(char * cryptoKey);

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_54_bad()
{
    char * cryptoKey;
    char cryptoKeyBuffer[100] = "";
    cryptoKey = cryptoKeyBuffer;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    strcpy(cryptoKey, CRYPTO_KEY);
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_54b_badSink(cryptoKey);
}



/* good function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_54b_goodG2BSink(char * cryptoKey);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * cryptoKey;
    char cryptoKeyBuffer[100] = "";
    cryptoKey = cryptoKeyBuffer;
    {
        size_t cryptoKeyLen = strlen(cryptoKey);
        /* if there is room in cryptoKey, read into it from the console */
        if(100-cryptoKeyLen > 1)
        {
            /* FIX: Obtain the hash input from the console */
            if (fgets(cryptoKey+cryptoKeyLen, (int)(100-cryptoKeyLen), stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                cryptoKey[cryptoKeyLen] = '\0';
            }
            /* The next 3 lines remove the carriage return from the string that is
             * inserted by fgets() */
            cryptoKeyLen = strlen(cryptoKey);
            if (cryptoKeyLen > 0)
            {
                cryptoKey[cryptoKeyLen-1] = '\0';
            }
        }
    }
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_54b_goodG2BSink(cryptoKey);
}

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_54_good()
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
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
