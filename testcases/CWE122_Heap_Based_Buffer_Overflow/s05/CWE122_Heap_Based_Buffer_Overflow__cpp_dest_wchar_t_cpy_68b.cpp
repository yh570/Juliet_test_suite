/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_68b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_dest.label.xml
Template File: sources-sink-68b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: cpy
 *    BadSink : Copy string to data using wcscpy
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_68_badData;
extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_68_goodG2BData;

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_68
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void badSink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_68_badData;
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
        wcscpy(data, source);
        printWLine(data);
        delete [] data;
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__cpp_dest_wchar_t_cpy_68_goodG2BData;
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
        wcscpy(data, source);
        printWLine(data);
        delete [] data;
    }
}


} /* close namespace */
