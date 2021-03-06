/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_52b.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: fopen Open and close a file using fopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE675_Duplicate_Operations_on_Resource__fopen_52c_badSink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_52b_badSink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_52c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE675_Duplicate_Operations_on_Resource__fopen_52c_goodG2BSink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_52b_goodG2BSink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE675_Duplicate_Operations_on_Resource__fopen_52c_goodB2GSink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_52b_goodB2GSink(FILE * data)
{
    CWE675_Duplicate_Operations_on_Resource__fopen_52c_goodB2GSink(data);
}

