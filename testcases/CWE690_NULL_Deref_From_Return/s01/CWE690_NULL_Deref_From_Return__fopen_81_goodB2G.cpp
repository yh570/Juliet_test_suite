/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_81_goodB2G.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-81_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__fopen_81.h"

namespace CWE690_NULL_Deref_From_Return__fopen_81
{

void CWE690_NULL_Deref_From_Return__fopen_81_goodB2G::action(FILE * data) const
{
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

}
