/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__new_struct_array_partial_init_01.cpp
Label Definition File: CWE457_Use_of_Uninitialized_Variable__new.label.xml
Template File: sources-sinks-01.tmpl.cpp
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: partial_init Initialize part, but not all of the array
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 01 Baseline
 *
 * */

#include "std_testcase.h"

namespace CWE457_Use_of_Uninitialized_Variable__new_struct_array_partial_init_01
{


void bad()
{
    twoIntsStruct * data;
    data = new twoIntsStruct[10];
    /* POTENTIAL FLAW: Partially initialize data */
    {
        int i;
        for(i=0; i<(10/2); i++)
        {
            data[i].intOne = i;
            data[i].intTwo = i;
        }
    }
    /* POTENTIAL FLAW: Use data without initializing it */
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].intOne);
            printIntLine(data[i].intTwo);
        }
    }
    /* deallocate the memory */
    delete [] data;
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    twoIntsStruct * data;
    data = new twoIntsStruct[10];
    /* FIX: Completely initialize data */
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].intOne = i;
            data[i].intTwo = i;
        }
    }
    /* POTENTIAL FLAW: Use data without initializing it */
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].intOne);
            printIntLine(data[i].intTwo);
        }
    }
    /* deallocate the memory */
    delete [] data;
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    twoIntsStruct * data;
    data = new twoIntsStruct[10];
    /* POTENTIAL FLAW: Partially initialize data */
    {
        int i;
        for(i=0; i<(10/2); i++)
        {
            data[i].intOne = i;
            data[i].intTwo = i;
        }
    }
    /* FIX: Ensure data is initialized before use */
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].intOne = i;
            data[i].intTwo = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].intOne);
            printIntLine(data[i].intTwo);
        }
    }
    /* deallocate the memory */
    delete [] data;
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

using namespace CWE457_Use_of_Uninitialized_Variable__new_struct_array_partial_init_01; /* so that we can use good and bad easily */

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
