/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE617_Reachable_Assertion__fscanf_53c.c
Label Definition File: CWE617_Reachable_Assertion.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 617 Reachable Assertion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Number greater than ASSERT_VALUE
 * Sink:
 *    BadSink : Assert if n is less than or equal to ASSERT_VALUE
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <assert.h>

#define ASSERT_VALUE 5

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE617_Reachable_Assertion__fscanf_53d_badSink(int data);

void CWE617_Reachable_Assertion__fscanf_53c_badSink(int data)
{
    CWE617_Reachable_Assertion__fscanf_53d_badSink(data);
}



/* good function declaration */
void CWE617_Reachable_Assertion__fscanf_53d_goodG2BSink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE617_Reachable_Assertion__fscanf_53c_goodG2BSink(int data)
{
    CWE617_Reachable_Assertion__fscanf_53d_goodG2BSink(data);
}

