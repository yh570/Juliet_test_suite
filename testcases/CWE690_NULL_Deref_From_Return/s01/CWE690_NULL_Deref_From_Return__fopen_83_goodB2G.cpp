/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_83_goodB2G.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-83_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE690_NULL_Deref_From_Return__fopen_83.h"

namespace CWE690_NULL_Deref_From_Return__fopen_83
{
CWE690_NULL_Deref_From_Return__fopen_83_goodB2G::CWE690_NULL_Deref_From_Return__fopen_83_goodB2G(FILE * dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = fopen("file.txt", "w+");
}

CWE690_NULL_Deref_From_Return__fopen_83_goodB2G::~CWE690_NULL_Deref_From_Return__fopen_83_goodB2G()
{
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}
}
