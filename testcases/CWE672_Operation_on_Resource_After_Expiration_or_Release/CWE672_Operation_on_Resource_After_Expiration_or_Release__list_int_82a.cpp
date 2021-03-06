/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82a.cpp
Label Definition File: CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int.label.xml
Template File: sources-sinks-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 672 Operation on Resource After Expiration or Release
 * BadSource:  Add values to the list, including the number zero
 * GoodSource: Add value to the list that are not zero
 * Sinks:
 *    GoodSink: Iterate through the list without attempting to clear its contents
 *    BadSink : Iterate through the list, but clear the list if it contains a zero
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82.h"

namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82
{


void bad()
{
    list<int>  data;
    /* POTENTIAL FLAW: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
    CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_base* baseObject = new CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_bad;
    baseObject->action(data);
    delete baseObject;
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    list<int>  data;
    /* FIX: Insert non-zero values into the list */
    data.push_back(100);
    data.push_back(200);
    CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_base* baseObject = new CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_goodG2B;
    baseObject->action(data);
    delete baseObject;
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    list<int>  data;
    /* POTENTIAL FLAW: Insert a zero into the list */
    data.push_back(100);
    data.push_back(0);
    CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_base* baseObject = new CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82_goodB2G;
    baseObject->action(data);
    delete baseObject;
}

void good()
{
    goodG2B();
    goodB2G();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE672_Operation_on_Resource_After_Expiration_or_Release__list_int_82; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
    return 0;
}

#endif
