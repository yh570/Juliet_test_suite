/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__struct_realloc_22a.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-22a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* The global variable below is used to drive control flow in the sink function */
int CWE690_NULL_Deref_From_Return__struct_realloc_22_badGlobal = 0;

void CWE690_NULL_Deref_From_Return__struct_realloc_22_badSink(twoIntsStruct * data);

void CWE690_NULL_Deref_From_Return__struct_realloc_22_bad()
{
    twoIntsStruct * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (twoIntsStruct *)realloc(data, 1*sizeof(twoIntsStruct));
    CWE690_NULL_Deref_From_Return__struct_realloc_22_badGlobal = 1; /* true */
    CWE690_NULL_Deref_From_Return__struct_realloc_22_badSink(data);
}



/* The global variables below are used to drive control flow in the sink functions. */
int CWE690_NULL_Deref_From_Return__struct_realloc_22_goodB2G1Global = 0;
int CWE690_NULL_Deref_From_Return__struct_realloc_22_goodB2G2Global = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void CWE690_NULL_Deref_From_Return__struct_realloc_22_goodB2G1Sink(twoIntsStruct * data);

static void goodB2G1()
{
    twoIntsStruct * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (twoIntsStruct *)realloc(data, 1*sizeof(twoIntsStruct));
    CWE690_NULL_Deref_From_Return__struct_realloc_22_goodB2G1Global = 0; /* false */
    CWE690_NULL_Deref_From_Return__struct_realloc_22_goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void CWE690_NULL_Deref_From_Return__struct_realloc_22_goodB2G2Sink(twoIntsStruct * data);

static void goodB2G2()
{
    twoIntsStruct * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (twoIntsStruct *)realloc(data, 1*sizeof(twoIntsStruct));
    CWE690_NULL_Deref_From_Return__struct_realloc_22_goodB2G2Global = 1; /* true */
    CWE690_NULL_Deref_From_Return__struct_realloc_22_goodB2G2Sink(data);
}

void CWE690_NULL_Deref_From_Return__struct_realloc_22_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE690_NULL_Deref_From_Return__struct_realloc_22_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__struct_realloc_22_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
