/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_53c.cpp
Label Definition File: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class.label.xml
Template File: sources-sink-53c.tmpl.cpp
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of Non Structure Pointer
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints class
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_53
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void badSink_d(void * data);

void badSink_c(void * data)
{
    badSink_d(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_d(void * data);

void goodG2BSink_c(void * data)
{
    goodG2BSink_d(data);
}


} /* close namespace */
