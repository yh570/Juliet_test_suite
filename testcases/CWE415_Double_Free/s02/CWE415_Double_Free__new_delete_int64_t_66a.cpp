/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_int64_t_66a.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-66a.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE415_Double_Free__new_delete_int64_t_66
{


/* bad function declaration */
void badSink(int64_t * dataArray[]);

void bad()
{
    int64_t * data;
    int64_t * dataArray[5];
    /* Initialize data */
    data = NULL;
    data = new int64_t;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    /* put data in array */
    dataArray[2] = data;
    badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(int64_t * dataArray[]);

static void goodG2B()
{
    int64_t * data;
    int64_t * dataArray[5];
    /* Initialize data */
    data = NULL;
    data = new int64_t;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    dataArray[2] = data;
    goodG2BSink(dataArray);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(int64_t * dataArray[]);

static void goodB2G()
{
    int64_t * data;
    int64_t * dataArray[5];
    /* Initialize data */
    data = NULL;
    data = new int64_t;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
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

using namespace CWE415_Double_Free__new_delete_int64_t_66; /* so that we can use good and bad easily */

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
