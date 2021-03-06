/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_cpy_81a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: cpy
 *    BadSink : Copy string to data using wcscpy()
 * Flow Variant: 81 Data flow: data passed in a parameter to a virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_cpy_81.h"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_cpy_81
{


void bad()
{
    wchar_t * data;
    data = NULL;
    /* FLAW: Did not leave space for a null terminator */
    data = new wchar_t[10];
    const CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_cpy_81_base& baseObject = CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_cpy_81_bad();
    baseObject.action(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    /* FIX: Allocate space for a null terminator */
    data = new wchar_t[10+1];
    const CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_cpy_81_base& baseObject = CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_cpy_81_goodG2B();
    baseObject.action(data);
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

using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_cpy_81; /* so that we can use good and bad easily */

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
