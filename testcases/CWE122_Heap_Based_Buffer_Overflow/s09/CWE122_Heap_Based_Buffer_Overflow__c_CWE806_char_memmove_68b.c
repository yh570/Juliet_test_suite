/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_68b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE806.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern char * CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_68_badData;
extern char * CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_68b_badSink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_68_badData;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        memmove(dest, data, strlen(data)*sizeof(char));
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
        free(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_68b_goodG2BSink()
{
    char * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_memmove_68_goodG2BData;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        memmove(dest, data, strlen(data)*sizeof(char));
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
        free(data);
    }
}

