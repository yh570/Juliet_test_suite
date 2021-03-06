/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_68b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.label.xml
Template File: sources-sink-68b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: cat
 *    BadSink : Copy data to string using strcat
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

extern char * CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_68_badData;
extern char * CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_68_goodG2BData;

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_68b_badSink()
{
    char * data = CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_68_badData;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than sizeof(dest)-strlen(dest)*/
        strcat(dest, data);
        printLine(data);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_68b_goodG2BSink()
{
    char * data = CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_68_goodG2BData;
    {
        char dest[50] = "";
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than sizeof(dest)-strlen(dest)*/
        strcat(dest, data);
        printLine(data);
    }
}

