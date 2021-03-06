/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE193.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate memory for a string, but do not allocate space for NULL terminator
 * GoodSource: Allocate enough memory for a string and the NULL terminator
 * Sink: loop
 *    BadSink : Copy array to data using a loop
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_68_badData;
extern wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_68b_badSink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_68_badData;
    {
        wchar_t source[10+1] = SRC_STRING;
        size_t i, sourceLen;
        sourceLen = wcslen(source);
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        for (i = 0; i < sourceLen + 1; i++)
        {
            data[i] = source[i];
        }
        printWLine(data);
        free(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_68b_goodG2BSink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_loop_68_goodG2BData;
    {
        wchar_t source[10+1] = SRC_STRING;
        size_t i, sourceLen;
        sourceLen = wcslen(source);
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        for (i = 0; i < sourceLen + 1; i++)
        {
            data[i] = source[i];
        }
        printWLine(data);
        free(data);
    }
}

