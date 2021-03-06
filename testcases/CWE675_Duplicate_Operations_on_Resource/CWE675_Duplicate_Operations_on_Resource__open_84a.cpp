/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_84a.cpp
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using open() and close()
 * GoodSource: Open a file using open()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE675_Duplicate_Operations_on_Resource__open_84.h"

namespace CWE675_Duplicate_Operations_on_Resource__open_84
{


void bad()
{
    int data;
    data = -1; /* Initialize data */
    CWE675_Duplicate_Operations_on_Resource__open_84_bad * badObject = new CWE675_Duplicate_Operations_on_Resource__open_84_bad(data);
    delete badObject;
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    data = -1; /* Initialize data */
    CWE675_Duplicate_Operations_on_Resource__open_84_goodG2B * goodG2BObject = new CWE675_Duplicate_Operations_on_Resource__open_84_goodG2B(data);
    delete goodG2BObject;
}

/* goodG2B uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    data = -1; /* Initialize data */
    CWE675_Duplicate_Operations_on_Resource__open_84_goodB2G * goodB2GObject = new CWE675_Duplicate_Operations_on_Resource__open_84_goodB2G(data);
    delete goodB2GObject;
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

using namespace CWE675_Duplicate_Operations_on_Resource__open_84; /* so that we can use good and bad easily */

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
