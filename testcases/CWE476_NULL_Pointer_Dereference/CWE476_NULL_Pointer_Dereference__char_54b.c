/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__char_54b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE476_NULL_Pointer_Dereference__char_54c_badSink(char * data);

void CWE476_NULL_Pointer_Dereference__char_54b_badSink(char * data)
{
    CWE476_NULL_Pointer_Dereference__char_54c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE476_NULL_Pointer_Dereference__char_54c_goodG2BSink(char * data);

void CWE476_NULL_Pointer_Dereference__char_54b_goodG2BSink(char * data)
{
    CWE476_NULL_Pointer_Dereference__char_54c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE476_NULL_Pointer_Dereference__char_54c_goodB2GSink(char * data);

void CWE476_NULL_Pointer_Dereference__char_54b_goodB2GSink(char * data)
{
    CWE476_NULL_Pointer_Dereference__char_54c_goodB2GSink(data);
}

