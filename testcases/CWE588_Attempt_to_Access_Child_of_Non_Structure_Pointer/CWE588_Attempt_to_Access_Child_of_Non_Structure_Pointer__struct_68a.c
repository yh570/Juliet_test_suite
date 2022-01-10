/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68a.c
Label Definition File: CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 588 Attempt to Access Child of Non Structure Pointer
 * BadSource:  Void pointer to an int
 * GoodSource: Void pointer to a twoints struct
 * Sink:
 *    BadSink : Print data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

void * CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68_badData;
void * CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68_goodG2BData;


/* bad function declaration */
void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68b_badSink();

void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68_bad()
{
    void * data;
    twoIntsStruct dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    /* FLAW: Set data to point to an int */
    data = &dataBadBuffer;
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68_badData = data;
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68b_badSink();
}



/* good function declarations */
void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    void * data;
    twoIntsStruct dataGoodBuffer;
    int dataBadBuffer = 100;
    dataGoodBuffer.intOne = 0;
    dataGoodBuffer.intTwo = 0;
    /* FIX: Set data to point to a twoIntsStruct struct */
    data = &dataGoodBuffer;
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68_goodG2BData = data;
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68b_goodG2BSink();
}

void CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68_good()
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
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer__struct_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
