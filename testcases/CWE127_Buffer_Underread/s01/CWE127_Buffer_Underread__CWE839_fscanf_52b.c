/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__CWE839_fscanf_52b.c
Label Definition File: CWE127_Buffer_Underread__CWE839.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Underread
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-negative but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking to see if the value is negative
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE127_Buffer_Underread__CWE839_fscanf_52c_badSink(int data);

void CWE127_Buffer_Underread__CWE839_fscanf_52b_badSink(int data)
{
    CWE127_Buffer_Underread__CWE839_fscanf_52c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE127_Buffer_Underread__CWE839_fscanf_52c_goodG2BSink(int data);

void CWE127_Buffer_Underread__CWE839_fscanf_52b_goodG2BSink(int data)
{
    CWE127_Buffer_Underread__CWE839_fscanf_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE127_Buffer_Underread__CWE839_fscanf_52c_goodB2GSink(int data);

void CWE127_Buffer_Underread__CWE839_fscanf_52b_goodB2GSink(int data)
{
    CWE127_Buffer_Underread__CWE839_fscanf_52c_goodB2GSink(data);
}

