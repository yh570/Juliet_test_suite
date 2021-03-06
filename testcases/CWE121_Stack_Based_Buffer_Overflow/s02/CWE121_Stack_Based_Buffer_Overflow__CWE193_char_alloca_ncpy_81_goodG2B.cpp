/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_ncpy_81_goodG2B.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE193.label.xml
Template File: sources-sink-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Point data to a buffer that does not have space for a NULL terminator
 * GoodSource: Point data to a buffer that includes space for a NULL terminator
 * Sinks: ncpy
 *    BadSink : Copy string to data using strncpy()
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_ncpy_81.h"

namespace CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_ncpy_81
{

void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_ncpy_81_goodG2B::action(char * data) const
{
    {
        char source[10+1] = SRC_STRING;
        /* Copy length + 1 to include NUL terminator from source */
        /* POTENTIAL FLAW: data may not have enough space to hold source */
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
    }
}

}
