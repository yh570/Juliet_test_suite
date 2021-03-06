/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64a.c
Label Definition File: CWE457_Use_of_Uninitialized_Variable.c_array.label.xml
Template File: sources-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 457 Use of Uninitialized Variable
 * BadSource: partial_init Initialize part, but not all of the array
 * GoodSource: Initialize data
 * Sinks: use
 *    GoodSink: Initialize then use data
 *    BadSink : Use data
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_badSink(void * dataVoidPtr);

void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64_bad()
{
    int * data;
    data = (int *)ALLOCA(10*sizeof(int));
    /* POTENTIAL FLAW: Partially initialize data */
    {
        int i;
        for(i=0; i<(10/2); i++)
        {
            data[i] = i;
        }
    }
    CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_goodG2BSink(void * dataVoidPtr);

static void goodG2B()
{
    int * data;
    data = (int *)ALLOCA(10*sizeof(int));
    /* FIX: Completely initialize data */
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i] = i;
        }
    }
    CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_goodG2BSink(&data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_goodB2GSink(void * dataVoidPtr);

static void goodB2G()
{
    int * data;
    data = (int *)ALLOCA(10*sizeof(int));
    /* POTENTIAL FLAW: Partially initialize data */
    {
        int i;
        for(i=0; i<(10/2); i++)
        {
            data[i] = i;
        }
    }
    CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_goodB2GSink(&data);
}

void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64_good()
{
    goodG2B();
    goodB2G();
}


/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
