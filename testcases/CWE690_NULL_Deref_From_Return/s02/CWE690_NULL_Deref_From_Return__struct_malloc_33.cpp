/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__struct_malloc_33.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-33.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: malloc Allocate data using malloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 33 Data flow: use of a C++ reference to data within the same function
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE690_NULL_Deref_From_Return__struct_malloc_33
{


void bad()
{
    twoIntsStruct * data;
    twoIntsStruct * &dataRef = data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (twoIntsStruct *)malloc(1*sizeof(twoIntsStruct));
    {
        twoIntsStruct * data = dataRef;
        /* FLAW: Initialize memory buffer without checking to see if the memory allocation function failed */
        data[0].intOne = 1;
        data[0].intTwo = 1;
        printStructLine(&data[0]);
        free(data);
    }
}



/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoIntsStruct * data;
    twoIntsStruct * &dataRef = data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (twoIntsStruct *)malloc(1*sizeof(twoIntsStruct));
    {
        twoIntsStruct * data = dataRef;
        /* FIX: Check to see if the memory allocation function was successful before initializing the memory buffer */
        if (data != NULL)
        {
            data[0].intOne = 1;
            data[0].intTwo = 1;
            printStructLine(&data[0]);
            free(data);
        }
    }
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

using namespace CWE690_NULL_Deref_From_Return__struct_malloc_33; /* so that we can use good and bad easily */

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
