/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__fopen_64b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: fopen Open data with fopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE690_NULL_Deref_From_Return__fopen_64b_badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    FILE * * dataPtr = (FILE * *)dataVoidPtr;
    /* dereference dataPtr into data */
    FILE * data = (*dataPtr);
    /* FLAW: if the fopen failed, data will be NULL here */
    fclose(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_From_Return__fopen_64b_goodB2GSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    FILE * * dataPtr = (FILE * *)dataVoidPtr;
    /* dereference dataPtr into data */
    FILE * data = (*dataPtr);
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
    }
}

