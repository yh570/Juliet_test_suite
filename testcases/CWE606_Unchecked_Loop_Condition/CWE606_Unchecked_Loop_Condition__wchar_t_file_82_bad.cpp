/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE606_Unchecked_Loop_Condition__wchar_t_file_82_bad.cpp
Label Definition File: CWE606_Unchecked_Loop_Condition.label.xml
Template File: sources-sinks-82_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 606 Unchecked Input For Loop Condition
 * BadSource: file Read input from a file
 * GoodSource: Input a number less than MAX_LOOP
 * Sinks:
 *    GoodSink: Use data as the for loop variant after checking to see if it is less than MAX_LOOP
 *    BadSink : Use data as the for loop variant without checking its size
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE606_Unchecked_Loop_Condition__wchar_t_file_82.h"

namespace CWE606_Unchecked_Loop_Condition__wchar_t_file_82
{

void CWE606_Unchecked_Loop_Condition__wchar_t_file_82_bad::action(wchar_t * data)
{
    {
        int i, n, intVariable;
        if (swscanf(data, L"%d", &n) == 1)
        {
            /* POTENTIAL FLAW: user-supplied value 'n' could lead to very large loop iteration */
            intVariable = 0;
            for (i = 0; i < n; i++)
            {
                /* INCIDENTAL: CWE 561: Dead Code - non-avoidable if n <= 0 */
                intVariable++; /* avoid a dead/empty code block issue */
            }
            printIntLine(intVariable);
        }
    }
}

}
