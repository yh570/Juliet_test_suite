/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_73a.cpp
Label Definition File: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct.label.xml
Template File: sources-sink-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of Non Structure Pointer
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_73
{


/* bad function declaration */
void badSink(list<void *> dataList);

void bad()
{
    void * data;
    list<void *> dataList;
    twoIntsStruct dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    /* FLAW: Set data to point to an int */
    data = &dataBadBuffer;
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    badSink(dataList);
}



/* good function declarations */

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<void *> dataList);

static void goodG2B()
{
    void * data;
    list<void *> dataList;
    twoIntsStruct dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    /* FIX: Set data to point to a twoIntsStruct struct */
    data = &dataGoodBuffer;
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    goodG2BSink(dataList);
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_73; /* so that we can use good and bad easily */

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
