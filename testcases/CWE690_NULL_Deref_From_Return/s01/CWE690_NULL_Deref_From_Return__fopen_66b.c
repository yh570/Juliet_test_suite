/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_66b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-66b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE690_NULL_Deref_From_Return__fopen_66b_badSink(FILE * dataArray[])
{
    /* copy data out of dataArray */
    FILE * data = dataArray[2];
    /* FLAW: if the fopen failed, data will be NULL here */
    fclose(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_From_Return__fopen_66b_goodB2GSink(FILE * dataArray[])
{
    FILE * data = dataArray[2];
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

