/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_sleep_53d.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-53d.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#include <windows.h>
#define SLEEP Sleep
#else
#include <unistd.h>
#define SLEEP usleep
#endif


void CWE400_Resource_Exhaustion__fscanf_sleep_53d_badSink(int count)
{
    /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
    SLEEP(count);
    printLine("Sleep time possibly too long");
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fscanf_sleep_53d_goodG2BSink(int count)
{
    /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
    SLEEP(count);
    printLine("Sleep time possibly too long");
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fscanf_sleep_53d_goodB2GSink(int count)
{
    /* FIX: Validate count before using it as a parameter in the sleep function */
    if (count > 0 && count <= 2000)
    {
        SLEEP(count);
        printLine("Sleep time OK");
    }
    else
    {
        printLine("Sleep time too long");
    }
}

