/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_31.c
Label Definition File: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct.label.xml
Template File: sources-sink-31.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of Non Structure Pointer
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sinks:
 *    BadSink : Print data
 * Flow Variant: 31 Data flow using a copy of data within the same function
 *
 * */

#include "std_testcase.h"


void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_31_bad()
{
    void * data;
    twoIntsStruct dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    /* FLAW: Set data to point to an int */
    data = &dataBadBuffer;
    {
        void * dataCopy = data;
        void * data = dataCopy;
        /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
        printStructLine((twoIntsStruct *)data);
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    void * data;
    twoIntsStruct dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    /* FIX: Set data to point to a twoIntsStruct struct */
    data = &dataGoodBuffer;
    {
        void * dataCopy = data;
        void * data = dataCopy;
        /* POTENTIAL FLAW: Attempt to print a struct when data may be a non-struct data type */
        printStructLine((twoIntsStruct *)data);
    }
}

void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_31_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */
#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_31_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_31_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
