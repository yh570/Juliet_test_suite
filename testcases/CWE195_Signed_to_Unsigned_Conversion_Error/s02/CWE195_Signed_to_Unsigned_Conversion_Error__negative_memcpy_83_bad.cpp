/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_83_bad.cpp
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-83_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sinks: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_83.h"

namespace CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_83
{
CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_83_bad::CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_83_bad(int dataCopy)
{
    data = dataCopy;
    /* FLAW: Use a negative number */
    data = -1;
}

CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_83_bad::~CWE195_Signed_to_Unsigned_Conversion_Error__negative_memcpy_83_bad()
{
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign conversion could result in a very large number */
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
    }
}
}
