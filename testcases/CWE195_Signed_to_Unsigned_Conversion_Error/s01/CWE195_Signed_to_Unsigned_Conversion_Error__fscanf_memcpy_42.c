/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_42.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-42.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 42 Data flow: data returned from one function to another in the same source file
 *
 * */

#include "std_testcase.h"


static int badSource(int data)
{
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    return data;
}

void CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_42_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    data = badSource(data);
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign conversion could result in a very large number */
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
    }
}



static int goodG2BSource(int data)
{
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    return data;
}

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    data = goodG2BSource(data);
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign conversion could result in a very large number */
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
    }
}

void CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_42_good()
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
    CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_42_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_42_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
