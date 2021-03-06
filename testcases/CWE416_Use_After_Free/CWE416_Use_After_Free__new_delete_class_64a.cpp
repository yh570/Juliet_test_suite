/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE416_Use_After_Free__new_delete_class_64a.cpp
Label Definition File: CWE416_Use_After_Free__new_delete.label.xml
Template File: sources-sinks-64a.tmpl.cpp
*/
/*
 * @description
 * CWE: 416 Use After Free
 * BadSource:  Allocate data using new, initialize memory block, and Deallocate data using delete
 * GoodSource: Allocate data using new and initialize memory block
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Use data after delete
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE416_Use_After_Free__new_delete_class_64
{


/* bad function declaration */
void badSink(void * dataVoidPtr);

void bad()
{
    TwoIntsClass * data;
    /* Initialize data */
    data = NULL;
    data = new TwoIntsClass;
    data->intOne = 1;
    data->intTwo = 2;
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete data;
    badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    TwoIntsClass * data;
    /* Initialize data */
    data = NULL;
    data = new TwoIntsClass;
    data->intOne = 1;
    data->intTwo = 2;
    /* FIX: Do not delete data in the source */
    goodG2BSink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(void * dataVoidPtr);

static void goodB2G()
{
    TwoIntsClass * data;
    /* Initialize data */
    data = NULL;
    data = new TwoIntsClass;
    data->intOne = 1;
    data->intTwo = 2;
    /* POTENTIAL FLAW: Delete data in the source - the bad sink attempts to use data */
    delete data;
    goodB2GSink(&data);
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

using namespace CWE416_Use_After_Free__new_delete_class_64; /* so that we can use good and bad easily */

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
