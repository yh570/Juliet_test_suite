/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_68a.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-68a.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: memmove
 *    BadSink : Copy string to data using memmove()
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

wchar_t * CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_68_badData;
wchar_t * CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_68_goodG2BData;

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_68
{


/* bad function declaration */
void badSink();

void bad()
{
    wchar_t * data;
    data = NULL;
    /* FLAW: Did not leave space for a null terminator */
    data = new wchar_t[10];
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_68_badData = data;
    badSink();
}



/* good function declarations */
void goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    /* FIX: Allocate space for a null terminator */
    data = new wchar_t[10+1];
    CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_68_goodG2BData = data;
    goodG2BSink();
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

using namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_wchar_t_memmove_68; /* so that we can use good and bad easily */

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
