/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_65b.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-65b.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sinks: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"


void CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_65b_badSink(int data)
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
            strncpy(dest, source, data);
            dest[data] = '\0'; /* strncpy() does not always NULL terminate */
        }
        printLine(dest);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_65b_goodG2BSink(int data)
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
            strncpy(dest, source, data);
            dest[data] = '\0'; /* strncpy() does not always NULL terminate */
        }
        printLine(dest);
    }
}

