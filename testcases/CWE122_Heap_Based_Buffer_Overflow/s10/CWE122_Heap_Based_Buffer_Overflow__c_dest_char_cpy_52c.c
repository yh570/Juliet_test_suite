/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_dest_char_cpy_52c.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_dest.label.xml
Template File: sources-sink-52c.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using malloc() and set data pointer to a small buffer
 * GoodSource: Allocate using malloc() and set data pointer to a large buffer
 * Sink: cpy
 *    BadSink : Copy string to data using strcpy
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE122_Heap_Based_Buffer_Overflow__c_dest_char_cpy_52c_badSink(char * data)
{
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
        strcpy(data, source);
        printLine(data);
        free(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_dest_char_cpy_52c_goodG2BSink(char * data)
{
    {
        char source[100];
        memset(source, 'C', 100-1); /* fill with 'C's */
        source[100-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possible buffer overflow if source is larger than data */
        strcpy(data, source);
        printLine(data);
        free(data);
    }
}

