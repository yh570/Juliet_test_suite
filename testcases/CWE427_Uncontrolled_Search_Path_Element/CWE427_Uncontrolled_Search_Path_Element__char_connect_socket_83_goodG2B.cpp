/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_goodG2B.cpp
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83.h"

namespace CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83
{
CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_goodG2B::CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_goodG2B(char * dataCopy)
{
    data = dataCopy;
    /* FIX: Set the path as the "system" path */
    strcat(data, NEW_PATH);
}

CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_goodG2B::~CWE427_Uncontrolled_Search_Path_Element__char_connect_socket_83_goodG2B()
{
    /* POTENTIAL FLAW: Set a new environment variable with a path that is possibly insecure */
    PUTENV(data);
}
}
