/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__CWE129_fgets_81_goodG2B.cpp
Label Definition File: CWE126_Buffer_Overread__CWE129.label.xml
Template File: sources-sinks-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 126 Buffer Overread
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE126_Buffer_Overread__CWE129_fgets_81.h"

namespace CWE126_Buffer_Overread__CWE129_fgets_81
{

void CWE126_Buffer_Overread__CWE129_fgets_81_goodG2B::action(int data) const
{
    {
        int buffer[10] = { 0 };
        /* POTENTIAL FLAW: Attempt to access an index of the array that is above the upper bound
         * This check does not check the upper bounds of the array index */
        if (data >= 0)
        {
            printIntLine(buffer[data]);
        }
        else
        {
            printLine("ERROR: Array index is negative");
        }
    }
}

}
