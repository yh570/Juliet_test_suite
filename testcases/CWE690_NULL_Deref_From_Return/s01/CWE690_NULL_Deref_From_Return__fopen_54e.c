/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_54e.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-54e.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"


void CWE690_NULL_Deref_From_Return__fopen_54e_badSink(FILE * data)
{
    /* FLAW: if the fopen failed, data will be NULL here */
    fclose(data);
}



void CWE690_NULL_Deref_From_Return__fopen_54e_goodB2GSink(FILE * data)
{
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

