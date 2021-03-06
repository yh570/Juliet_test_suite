/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__listen_socket_sleep_81_bad.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE400_Resource_Exhaustion__listen_socket_sleep_81.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP Sleep
#else
#include <unistd.h>
#define SLEEP usleep
#endif

namespace CWE400_Resource_Exhaustion__listen_socket_sleep_81
{

void CWE400_Resource_Exhaustion__listen_socket_sleep_81_bad::action(int count) const
{
    /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
    SLEEP(count);
    printLine("Sleep time possibly too long");
}

}
