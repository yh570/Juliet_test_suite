/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE321_Hard_Coded_Cryptographic_Key__w32_char_54b.c
Label Definition File: CWE321_Hard_Coded_Cryptographic_Key__w32.label.xml
Template File: sources-sink-54b.tmpl.c
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

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_54c_badSink(char * cryptoKey);

void CWE321_Hard_Coded_Cryptographic_Key__w32_char_54b_badSink(char * cryptoKey)
{
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_54c_badSink(cryptoKey);
}



/* good function declaration */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_54c_goodG2BSink(char * cryptoKey);

/* goodG2B uses the GoodSource with the BadSink */
void CWE321_Hard_Coded_Cryptographic_Key__w32_char_54b_goodG2BSink(char * cryptoKey)
{
    CWE321_Hard_Coded_Cryptographic_Key__w32_char_54c_goodG2BSink(cryptoKey);
}

