/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_snprintf_83_goodG2B.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.string.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: snprintf
 *    BadSink : Copy string to data using snprintf
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_snprintf_83.h"

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_snprintf_83
{
CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_snprintf_83_goodG2B::CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_snprintf_83_goodG2B(char * dataCopy)
{
    data = dataCopy;
    /* FIX: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
    data = new char[100];
    data[0] = '\0'; /* null terminate */
}

CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_snprintf_83_goodG2B::~CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_snprintf_83_goodG2B()
{
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
        SNPRINTF(data, 100, "%s", source);
        printLine(data);
        delete [] data;
    }
}
}
