/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__rand_memmove_52b.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: rand Set data to result of RAND32(), which could be negative
 * GoodSource: Positive integer
 * Sink: memmove
 *    BadSink : Copy strings using memmove() with the length of data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE194_Unexpected_Sign_Extension__rand_memmove_52c_badSink(short data);

void CWE194_Unexpected_Sign_Extension__rand_memmove_52b_badSink(short data)
{
    CWE194_Unexpected_Sign_Extension__rand_memmove_52c_badSink(data);
}



/* good function declaration */
void CWE194_Unexpected_Sign_Extension__rand_memmove_52c_goodG2BSink(short data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE194_Unexpected_Sign_Extension__rand_memmove_52b_goodG2BSink(short data)
{
    CWE194_Unexpected_Sign_Extension__rand_memmove_52c_goodG2BSink(data);
}

