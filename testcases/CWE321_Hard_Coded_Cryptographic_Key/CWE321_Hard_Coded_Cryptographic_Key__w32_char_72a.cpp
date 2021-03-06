/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_72a.cpp
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-72a.tmpl.cpp
*/
/*
 * @description
 * CWE: 321 Use of Hard-coded Cryptographic Key
 * BadSource:  Copy a hardcoded value into cryptoKey
 * GoodSource: Read cryptoKey from the console
 * Sinks:
 *    BadSink : Hash cryptoKey and use the value to encrypt a string
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#define CRYPTO_KEY "Hardcoded"

using namespace std;

namespace CWE321_Hard_Coded_Cryptographic_Key__w32_char_72
{


/* bad function declaration */
void badSink(vector<char *> cryptoKeyVector);

void bad()
{
    char * cryptoKey;
    vector<char *> cryptoKeyVector;
    char cryptoKeyBuffer[100] = "";
    cryptoKey = cryptoKeyBuffer;
    /* FLAW: Use a hardcoded value for the hash input causing a hardcoded crypto key in the sink */
    strcpy(cryptoKey, CRYPTO_KEY);
    /* Put cryptoKey in a vector */
    cryptoKeyVector.insert(cryptoKeyVector.end(), 1, cryptoKey);
    cryptoKeyVector.insert(cryptoKeyVector.end(), 1, cryptoKey);
    cryptoKeyVector.insert(cryptoKeyVector.end(), 1, cryptoKey);
    badSink(cryptoKeyVector);
}



/* good function declarations */

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<char *> cryptoKeyVector);

static void goodG2B()
{
    char * cryptoKey;
    vector<char *> cryptoKeyVector;
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
    /* Put cryptoKey in a vector */
    cryptoKeyVector.insert(cryptoKeyVector.end(), 1, cryptoKey);
    cryptoKeyVector.insert(cryptoKeyVector.end(), 1, cryptoKey);
    cryptoKeyVector.insert(cryptoKeyVector.end(), 1, cryptoKey);
    goodG2BSink(cryptoKeyVector);
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE321_Hard_Coded_Cryptographic_Key__w32_char_72; /* so that we can use good and bad easily */

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
