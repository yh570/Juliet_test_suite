/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_22b.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-22b.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"


/* The global variable below is used to drive control flow in the source function */
extern int CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_22_badGlobal;

int CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_22_badSource(int data)
{
    if(CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_22_badGlobal)
    {
        /* POTENTIAL FLAW: Read data from the console using fscanf() */
        fscanf(stdin, "%d", &data);
    }
    return data;
}



/* The global variables below are used to drive control flow in the source functions. */
extern int CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_22_goodG2B1Global;
extern int CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_22_goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
int CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_22_goodG2B1Source(int data)
{
    if(CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_22_goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
int CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_22_goodG2B2Source(int data)
{
    if(CWE195_Signed_to_Unsigned_Conversion_Error__fscanf_memcpy_22_goodG2B2Global)
    {
        /* FIX: Use a positive integer less than &InitialDataSize&*/
        data = 100-1;
    }
    return data;
}

