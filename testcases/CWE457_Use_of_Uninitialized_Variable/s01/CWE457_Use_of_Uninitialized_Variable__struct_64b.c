/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__struct_64b.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c.label.xml
Template File: sources-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: no_init Don't initialize data
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


void CWE457_Use_of_Uninitialized_Variable__struct_64b_badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    twoIntsStruct * dataPtr = (twoIntsStruct *)dataVoidPtr;
    /* dereference dataPtr into data */
    twoIntsStruct data = (*dataPtr);
    /* POTENTIAL FLAW: Use data without initializing it */
    printIntLine(data.intOne);
    printIntLine(data.intTwo);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE457_Use_of_Uninitialized_Variable__struct_64b_goodG2BSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    twoIntsStruct * dataPtr = (twoIntsStruct *)dataVoidPtr;
    /* dereference dataPtr into data */
    twoIntsStruct data = (*dataPtr);
    /* POTENTIAL FLAW: Use data without initializing it */
    printIntLine(data.intOne);
    printIntLine(data.intTwo);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE457_Use_of_Uninitialized_Variable__struct_64b_goodB2GSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    twoIntsStruct * dataPtr = (twoIntsStruct *)dataVoidPtr;
    /* dereference dataPtr into data */
    twoIntsStruct data = (*dataPtr);
    /* FIX: Ensure data is initialized before use */
    data.intOne = 1;
    data.intTwo = 2;
    printIntLine(data.intOne);
    printIntLine(data.intTwo);
}

