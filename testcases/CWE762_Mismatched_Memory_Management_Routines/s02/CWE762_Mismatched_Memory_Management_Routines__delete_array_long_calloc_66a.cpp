/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_66a.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__delete_array.label.xml
Template File: sources-sinks-66a.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_66
{


/* bad function declaration */
void badSink(long * dataArray[]);

void bad()
{
    long * data;
    long * dataArray[5];
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (long *)calloc(100, sizeof(long));
    if (data == NULL) {exit(-1);}
    /* put data in array */
    dataArray[2] = data;
    badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(long * dataArray[]);

static void goodG2B()
{
    long * data;
    long * dataArray[5];
    /* Initialize data*/
    data = NULL;
    /* FIX: Allocate memory using new [] */
    data = new long[100];
    dataArray[2] = data;
    goodG2BSink(dataArray);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(long * dataArray[]);

static void goodB2G()
{
    long * data;
    long * dataArray[5];
    /* Initialize data*/
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
    data = (long *)calloc(100, sizeof(long));
    if (data == NULL) {exit(-1);}
    dataArray[2] = data;
    goodB2GSink(dataArray);
}

void good()
{
    goodG2B();
    goodB2G();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__delete_array_long_calloc_66; /* so that we can use good and bad easily */

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
