/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE665_Improper_Initialization__wchar_t_cat_81_bad.cpp
Label Definition File: CWE665_Improper_Initialization.label.xml
Template File: sources-sink-81_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 665 Improper Initialization
 * BadSource:  Do not initialize data properly
 * GoodSource: Initialize data
 * Sinks: cat
 *    BadSink : Copy string to data using wcscat
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE665_Improper_Initialization__wchar_t_cat_81.h"

namespace CWE665_Improper_Initialization__wchar_t_cat_81
{

void CWE665_Improper_Initialization__wchar_t_cat_81_bad::action(wchar_t * data) const
{
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1); /* fill with L'C's */
        source[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: If data is not initialized properly, wcscat() may not function correctly */
        wcscat(data, source);
        printWLine(data);
    }
}

}
