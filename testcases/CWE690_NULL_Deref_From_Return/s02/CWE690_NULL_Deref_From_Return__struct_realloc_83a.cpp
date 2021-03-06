/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__struct_realloc_83a.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-83a.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__struct_realloc_83.h"

namespace CWE690_NULL_Deref_From_Return__struct_realloc_83
{


void bad()
{
    twoIntsStruct * data;
    data = NULL; /* Initialize data */
    CWE690_NULL_Deref_From_Return__struct_realloc_83_bad badObject(data);
}



/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoIntsStruct * data;
    data = NULL; /* Initialize data */
    CWE690_NULL_Deref_From_Return__struct_realloc_83_goodB2G goodB2GObject(data);
}

void good()
{
    goodB2G();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE690_NULL_Deref_From_Return__struct_realloc_83; /* so that we can use good and bad easily */

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
