/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_int_51a.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-51a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_int_51
{


/* bad function declaration */
void badSink(int * data);

void bad()
{
    int * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new int[100];
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
    badSink(data);
}



/* good function declarations */
void goodG2BSink(int * data);
void goodB2GSink(int * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    int dataGoodBuffer[100];
    data = dataGoodBuffer;
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
    goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new int[100];
    /* Initialize and make use of data */
    data[0] = 5;
    printIntLine(data[0]);
    goodB2GSink(data);
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

using namespace CWE401_Memory_Leak__new_array_int_51; /* so that we can use good and bad easily */

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
