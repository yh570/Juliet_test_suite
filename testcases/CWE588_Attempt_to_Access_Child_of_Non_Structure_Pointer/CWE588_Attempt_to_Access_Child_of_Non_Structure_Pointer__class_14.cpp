/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_14.cpp
Label Definition File: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class.label.xml
Template File: sources-sink-14.tmpl.cpp
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of Non Structure Pointer
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints class
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 14 Control flow: if(globalFive==5) and if(globalFive!=5)
 *
 * */

#include "std_testcase.h"

namespace CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_14
{


void bad()
{
    void * data;
    TwoIntsClass dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    if(globalFive==5)
    {
        /* FLAW: Set data to point to an int */
        data = &dataBadBuffer;
    }
    /* POTENTIAL FLAW: Attempt to print a class member when data may be a non-object data type */
    printIntLine((reinterpret_cast<TwoIntsClass *>(data))->intTwo);
}



/* goodG2B1() - use goodsource and badsink by changing the globalFive==5 to globalFive!=5 */
static void goodG2B1()
{
    void * data;
    TwoIntsClass dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    if(globalFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Set data to point to a TwoIntsClass class */
        data = &dataGoodBuffer;
    }
    /* POTENTIAL FLAW: Attempt to print a class member when data may be a non-object data type */
    printIntLine((reinterpret_cast<TwoIntsClass *>(data))->intTwo);
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    void * data;
    TwoIntsClass dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    if(globalFive==5)
    {
        /* FIX: Set data to point to a TwoIntsClass class */
        data = &dataGoodBuffer;
    }
    /* POTENTIAL FLAW: Attempt to print a class member when data may be a non-object data type */
    printIntLine((reinterpret_cast<TwoIntsClass *>(data))->intTwo);
}

void good()
{
    goodG2B1();
    goodG2B2();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__class_14; /* so that we can use good and bad easily */

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
