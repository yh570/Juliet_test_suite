/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_struct_twoIntsStruct_54a.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-54a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_struct_twoIntsStruct_54
{


/* bad function declaration */
void badSink_b(struct _twoIntsStruct * data);

void bad()
{
    struct _twoIntsStruct * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new struct _twoIntsStruct;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printStructLine((twoIntsStruct *)data);
    badSink_b(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_b(struct _twoIntsStruct * data);

static void goodG2B()
{
    struct _twoIntsStruct * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    struct _twoIntsStruct dataGoodBuffer;
    data = &dataGoodBuffer;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printStructLine((twoIntsStruct *)data);
    goodG2BSink_b(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_b(struct _twoIntsStruct * data);

static void goodB2G()
{
    struct _twoIntsStruct * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new struct _twoIntsStruct;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printStructLine((twoIntsStruct *)data);
    goodB2GSink_b(data);
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

using namespace CWE401_Memory_Leak__new_struct_twoIntsStruct_54; /* so that we can use good and bad easily */

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
