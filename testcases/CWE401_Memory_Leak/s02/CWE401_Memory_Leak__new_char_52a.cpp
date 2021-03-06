/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_char_52a.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-52a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_char_52
{


/* bad function declaration */
void badSink_b(char * data);

void bad()
{
    char * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new char;
    /* Initialize and make use of data */
    *data = 'A';
    printHexCharLine(*data);
    badSink_b(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_b(char * data);

static void goodG2B()
{
    char * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    char dataGoodBuffer;
    data = &dataGoodBuffer;
    /* Initialize and make use of data */
    *data = 'A';
    printHexCharLine(*data);
    goodG2BSink_b(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_b(char * data);

static void goodB2G()
{
    char * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new char;
    /* Initialize and make use of data */
    *data = 'A';
    printHexCharLine(*data);
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

using namespace CWE401_Memory_Leak__new_char_52; /* so that we can use good and bad easily */

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
