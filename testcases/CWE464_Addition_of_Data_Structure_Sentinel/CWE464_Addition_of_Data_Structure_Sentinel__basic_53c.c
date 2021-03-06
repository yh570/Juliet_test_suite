/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Addition_of_Data_Structure_Sentinel__basic_53c.c
Label Definition File: CWE464_Addition_of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-53c.tmpl.c
*/
/*
 * @description
 * CWE: 464 Addition of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sink:
 *    BadSink : Place data into and print an array
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE464_Addition_of_Data_Structure_Sentinel__basic_53d_badSink(char data);

void CWE464_Addition_of_Data_Structure_Sentinel__basic_53c_badSink(char data)
{
    CWE464_Addition_of_Data_Structure_Sentinel__basic_53d_badSink(data);
}



/* good function declaration */
void CWE464_Addition_of_Data_Structure_Sentinel__basic_53d_goodG2BSink(char data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE464_Addition_of_Data_Structure_Sentinel__basic_53c_goodG2BSink(char data)
{
    CWE464_Addition_of_Data_Structure_Sentinel__basic_53d_goodG2BSink(data);
}

