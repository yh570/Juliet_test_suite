/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_snprintf_67b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.string.label.xml
Template File: sources-sink-67b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sinks: snprintf
 *    BadSink : Copy string to data using snprintf
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define SNPRINTF _snprintf
#else
#define SNPRINTF snprintf
#endif

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_char_snprintf_67
{

typedef struct _structType
{
    char * structFirst;
} structType;


void badSink(structType myStruct)
{
    char * data = myStruct.structFirst;
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



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(structType myStruct)
{
    char * data = myStruct.structFirst;
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


} /* close namespace */
