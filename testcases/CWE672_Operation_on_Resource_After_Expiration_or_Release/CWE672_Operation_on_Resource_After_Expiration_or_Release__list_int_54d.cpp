/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54d.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-54d.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * BadSource:  Add values to the list, including the number zero
 * GoodSource: Add value to the list that are not zero
 * Sinks:
 *    GoodSink: Iterate through the list without attempting to clear its contents
 *    BadSink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <list>
#include <iostream>

using namespace std;

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_54
{


/* bad function declaration */
void badSink_e(list<int>  data);

void badSink_d(list<int>  data)
{
    badSink_e(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_e(list<int>  data);

void goodG2BSink_d(list<int>  data)
{
    goodG2BSink_e(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_e(list<int>  data);

void goodB2GSink_d(list<int>  data)
{
    goodB2GSink_e(data);
}


} /* close namespace */
