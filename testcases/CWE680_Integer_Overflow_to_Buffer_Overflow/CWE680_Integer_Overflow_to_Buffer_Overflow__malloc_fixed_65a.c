/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_65a.c
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__malloc.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: fixed Fixed value that will cause an integer overflow in the sink
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_65b_badSink(int data);

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_65_bad()
{
    int data;
    /* define a function pointer */
    void (*funcPtr) (int) = CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_65b_badSink;
    /* Initialize data */
    data = -1;
    /* FLAW: Set data to a value that will cause an integer overflow in the call to malloc() in the sink */
    data = INT_MAX / 2 + 2; /* 1073741825 */
    /* NOTE: This value will cause the sink to only allocate 4 bytes of memory, however
     * the for loop will attempt to access indices 0-1073741824 */
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_65b_goodG2BSink(int data);

static void goodG2B()
{
    int data;
    void (*funcPtr) (int) = CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_65b_goodG2BSink;
    /* Initialize data */
    data = -1;
    /* FIX: Set data to a relatively small number greater than zero */
    data = 20;
    funcPtr(data);
}

void CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_65_good()
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
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE680_Integer_Overflow_to_Buffer_Overflow__malloc_fixed_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
