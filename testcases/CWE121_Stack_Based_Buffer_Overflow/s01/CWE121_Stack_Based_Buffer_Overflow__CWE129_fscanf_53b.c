/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_53b.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE129.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_53c_badSink(int data);

void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_53b_badSink(int data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_53c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_53c_goodG2BSink(int data);

void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_53b_goodG2BSink(int data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_53c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_53c_goodB2GSink(int data);

void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_53b_goodB2GSink(int data)
{
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_53c_goodB2GSink(data);
}

