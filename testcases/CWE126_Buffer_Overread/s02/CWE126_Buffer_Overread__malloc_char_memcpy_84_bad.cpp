/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__malloc_char_memcpy_84_bad.cpp
Label Definition File: CWE126_Buffer_Overread__malloc.label.xml
Template File: sources-sink-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Use a small buffer
 * GoodSource: Use a large buffer
 * Sinks: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__malloc_char_memcpy_84.h"

namespace CWE126_Buffer_Overread__malloc_char_memcpy_84
{
CWE126_Buffer_Overread__malloc_char_memcpy_84_bad::CWE126_Buffer_Overread__malloc_char_memcpy_84_bad(char * dataCopy)
{
    data = dataCopy;
    /* FLAW: Use a small buffer */
    data = (char *)malloc(50*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 50-1); /* fill with 'A's */
    data[50-1] = '\0'; /* null terminate */
}

CWE126_Buffer_Overread__malloc_char_memcpy_84_bad::~CWE126_Buffer_Overread__malloc_char_memcpy_84_bad()
{
    {
        char dest[100];
        memset(dest, 'C', 100-1);
        dest[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: using memcpy with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memcpy(dest, data, strlen(dest)*sizeof(char));
        dest[100-1] = '\0';
        printLine(dest);
        free(data);
    }
}
}
