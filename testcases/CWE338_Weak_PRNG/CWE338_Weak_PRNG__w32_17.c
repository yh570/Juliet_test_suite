/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE338_Weak_PRNG__w32_17.c
Label Definition File: CWE338_Weak_PRNG__w32.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 338 Use of Cryptographically Weak PRNG
 * Sinks:
 *    GoodSink: Use CryptGenRandom() to generate a random number
 *    BadSink : Use rand() to generate a random number
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <wincrypt.h>
#pragma comment(lib, "advapi32.lib")


void CWE338_Weak_PRNG__w32_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            /* FLAW: Use of rand() as a PRNG */
            int data = rand();
            printIntLine(data);
        }
    }
}



/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            HCRYPTPROV hCryptProv;
            int data;
            if (!CryptAcquireContextW(&hCryptProv, 0, 0, PROV_RSA_FULL, 0))
            {
                exit(1);
            }
            /* FIX: Use of CryptGenRandom() as a more secure PRNG */
            if (!CryptGenRandom(hCryptProv, sizeof(data), (BYTE *) &data))
            {
                CryptReleaseContext(hCryptProv, 0);
                exit(1);
            }
            if (hCryptProv)
            {
                CryptReleaseContext(hCryptProv, 0);
            }
            printIntLine(data);
        }
    }
}

void CWE338_Weak_PRNG__w32_17_good()
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
    CWE338_Weak_PRNG__w32_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE338_Weak_PRNG__w32_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
