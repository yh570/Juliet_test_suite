/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_loop_81_bad.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE806.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: loop
 *    BadSink : Copy data to string using a loop
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_loop_81.h"

namespace CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_loop_81
{

void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_loop_81_bad::action(char * data) const
{
    {
        char dest[50] = "";
        size_t i, dataLen;
        dataLen = strlen(data);
        /* POTENTIAL FLAW: Possible buffer overflow if data is larger than dest */
        for (i = 0; i < dataLen; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = '\0'; /* Ensure the destination buffer is null terminated */
        printLine(data);
    }
}

}
