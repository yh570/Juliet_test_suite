/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_TwoIntsClass_81a.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE401_Memory_Leak__new_TwoIntsClass_81.h"

namespace CWE401_Memory_Leak__new_TwoIntsClass_81
{


void bad()
{
    TwoIntsClass * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new TwoIntsClass;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printIntLine(data->intOne);
    printIntLine(data->intTwo);
    const CWE401_Memory_Leak__new_TwoIntsClass_81_base& o = CWE401_Memory_Leak__new_TwoIntsClass_81_bad();
    o.action(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    TwoIntsClass * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack */
    TwoIntsClass dataGoodBuffer;
    data = &dataGoodBuffer;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printIntLine(data->intOne);
    printIntLine(data->intTwo);
    const CWE401_Memory_Leak__new_TwoIntsClass_81_base& baseObject = CWE401_Memory_Leak__new_TwoIntsClass_81_goodG2B();
    baseObject.action(data);
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    TwoIntsClass * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = new TwoIntsClass;
    /* Initialize and make use of data */
    data->intOne = 0;
    data->intTwo = 0;
    printIntLine(data->intOne);
    printIntLine(data->intTwo);
    const CWE401_Memory_Leak__new_TwoIntsClass_81_base& baseObject = CWE401_Memory_Leak__new_TwoIntsClass_81_goodB2G();
    baseObject.action(data);
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

using namespace CWE401_Memory_Leak__new_TwoIntsClass_81; /* so that we can use good and bad easily */

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
