/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__fgets_strncpy_18.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-18.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Positive integer
 * Sink: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 18 Control flow: goto statements
 *
 * */

#include "std_testcase.h"

/* Must be at least 8 for atoi() to work properly */
#define CHAR_ARRAY_SIZE 8


void CWE194_Unexpected_Sign_Extension__fgets_strncpy_18_bad()
{
    short data;
    /* Initialize data */
    data = 0;
    goto source;
source:
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* FLAW: Use a value input from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to short */
            data = (short)atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign extension could result in a very large number */
            strncpy(dest, source, data);
            dest[data] = '\0'; /* strncpy() does not always NULL terminate */
        }
        printLine(dest);
    }
}



/* goodG2B() - use goodsource and badsink by reversing the blocks on the goto statement */
static void goodG2B()
{
    short data;
    /* Initialize data */
    data = 0;
    goto source;
source:
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign extension could result in a very large number */
            strncpy(dest, source, data);
            dest[data] = '\0'; /* strncpy() does not always NULL terminate */
        }
        printLine(dest);
    }
}

void CWE194_Unexpected_Sign_Extension__fgets_strncpy_18_good()
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
    CWE194_Unexpected_Sign_Extension__fgets_strncpy_18_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE194_Unexpected_Sign_Extension__fgets_strncpy_18_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
