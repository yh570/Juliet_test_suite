/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_81_goodG2B.cpp
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Positive integer
 * Sinks: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_81.h"

namespace CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_81
{

void CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_81_goodG2B::action(short data) const
{
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign extension could result in a very large number */
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
    }
}

}
