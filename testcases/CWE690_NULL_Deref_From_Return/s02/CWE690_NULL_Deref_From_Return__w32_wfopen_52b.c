/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_52b.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE690_NULL_Deref_From_Return__w32_wfopen_52c_badSink(FILE * data);

void CWE690_NULL_Deref_From_Return__w32_wfopen_52b_badSink(FILE * data)
{
    CWE690_NULL_Deref_From_Return__w32_wfopen_52c_badSink(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_From_Return__w32_wfopen_52c_goodB2GSink(FILE * data);

void CWE690_NULL_Deref_From_Return__w32_wfopen_52b_goodB2GSink(FILE * data)
{
    CWE690_NULL_Deref_From_Return__w32_wfopen_52c_goodB2GSink(data);
}

