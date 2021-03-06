/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_67b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sinks: cpy
 *    BadSink : Copy string to data using wcscpy()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

typedef struct _CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_67_structType
{
    wchar_t * structFirst;
} CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_67_structType;


void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        wchar_t source[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        wcscpy(data, source);
        printWLine(data);
        free(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_67b_goodG2BSink(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_cpy_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        wchar_t source[10+1] = SRC_STRING;
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        wcscpy(data, source);
        printWLine(data);
        free(data);
    }
}

