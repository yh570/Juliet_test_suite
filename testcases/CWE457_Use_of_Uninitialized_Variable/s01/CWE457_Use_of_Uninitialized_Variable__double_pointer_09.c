/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__double_pointer_09.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-09.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE457_Use_of_Uninitialized_Variable__double_pointer_09_bad()
{
    double * data;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printDoubleLine(*data);
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void goodB2G1()
{
    double * data;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Ensure data is initialized before use */
        /* initialize both the pointer and the data pointed to */
        data = (double *)malloc(sizeof(double));
        if (data == NULL) {exit(-1);}
        *data = 5.0;
        printDoubleLine(*data);
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    double * data;
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Don't initialize data */
        ; /* empty statement needed for some flow variants */
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: Ensure data is initialized before use */
        /* initialize both the pointer and the data pointed to */
        data = (double *)malloc(sizeof(double));
        if (data == NULL) {exit(-1);}
        *data = 5.0;
        printDoubleLine(*data);
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first GLOBAL_CONST_TRUE to GLOBAL_CONST_FALSE */
static void goodG2B1()
{
    double * data;
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Initialize data */
        /* initialize both the pointer and the data pointed to */
        data = (double *)malloc(sizeof(double));
        if (data == NULL) {exit(-1);}
        *data = 5.0;
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printDoubleLine(*data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    double * data;
    if(GLOBAL_CONST_TRUE)
    {
        /* FIX: Initialize data */
        /* initialize both the pointer and the data pointed to */
        data = (double *)malloc(sizeof(double));
        if (data == NULL) {exit(-1);}
        *data = 5.0;
    }
    if(GLOBAL_CONST_TRUE)
    {
        /* POTENTIAL FLAW: Use data without initializing it */
        printDoubleLine(*data);
    }
}

void CWE457_Use_of_Uninitialized_Variable__double_pointer_09_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE457_Use_of_Uninitialized_Variable__double_pointer_09_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__double_pointer_09_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
