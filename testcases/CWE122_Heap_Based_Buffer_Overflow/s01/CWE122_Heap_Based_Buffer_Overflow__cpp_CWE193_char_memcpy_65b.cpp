/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_memcpy_65b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193.label.xml
Template File: sources-sink-65b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: memcpy
 *    BadSink : Copy string to data using memcpy()
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING "AAAAAAAAAA"

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE193_char_memcpy_65
{


void badSink(char * data)
{
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        memcpy(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        delete [] data;
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(char * data)
{
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        memcpy(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
        delete [] data;
    }
}


} /* close namespace */
