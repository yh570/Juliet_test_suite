/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: ncpy
 *    BadSink : Copy string to data using wcsncpy()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67_structType
{
    wchar_t * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67_structType;


void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        wchar_t source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        wcsncpy(data, source, wcslen(source) + 1);
        printWLine(data);
        free(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67b_goodG2BSink(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_ncpy_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        wchar_t source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        wcsncpy(data, source, wcslen(source) + 1);
        printWLine(data);
        free(data);
    }
}

