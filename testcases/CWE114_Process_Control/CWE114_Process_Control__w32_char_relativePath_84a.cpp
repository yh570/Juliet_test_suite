/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_relativePath_84a.cpp
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: relativePath Hard code the relative pathname to the library
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE114_Process_Control__w32_char_relativePath_84.h"

namespace CWE114_Process_Control__w32_char_relativePath_84
{


void bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE114_Process_Control__w32_char_relativePath_84_bad * badObject = new CWE114_Process_Control__w32_char_relativePath_84_bad(data);
    delete badObject;
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE114_Process_Control__w32_char_relativePath_84_goodG2B * goodG2BObject =  new CWE114_Process_Control__w32_char_relativePath_84_goodG2B(data);
    delete goodG2BObject;
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE114_Process_Control__w32_char_relativePath_84; /* so that we can use good and bad easily */

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
