/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_65b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-65b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"


void CWE690_NULL_Deref_From_Return__fopen_65b_badSink(FILE * data)
{
    /* FLAW: if the fopen failed, data will be NULL here */
    fclose(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_From_Return__fopen_65b_goodB2GSink(FILE * data)
{
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

