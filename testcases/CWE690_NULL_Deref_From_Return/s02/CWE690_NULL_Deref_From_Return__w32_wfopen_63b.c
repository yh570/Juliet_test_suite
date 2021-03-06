/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_63b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE690_NULL_Deref_From_Return__w32_wfopen_63b_badSink(FILE * * dataPtr)
{
    FILE * data = *dataPtr;
    /* FLAW: if the fopen failed, data will be NULL here */
    fclose(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_From_Return__w32_wfopen_63b_goodB2GSink(FILE * * dataPtr)
{
    FILE * data = *dataPtr;
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

