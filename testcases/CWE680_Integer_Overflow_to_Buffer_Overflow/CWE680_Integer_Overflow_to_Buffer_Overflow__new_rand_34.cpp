/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_34.cpp
Label Definition File: CWE680_Integer_Overflow_to_Buffer_Overflow__new.label.xml
Template File: sources-sink-34.tmpl.cpp
*/
/*
 * @description
 * CWE: 680 Integer Overflow to Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Small number greater than zero that will not cause an integer overflow in the sink
 * Sinks:
 *    BadSink : Attempt to allocate array using length value from source
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

namespace CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_34
{

typedef union
{
    int unionFirst;
    int unionSecond;
} unionType;


void bad()
{
    int data;
    unionType myUnion;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Set data to a random value */
    data = RAND32();
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        {
            size_t dataBytes,i;
            int *intPointer;
            /* POTENTIAL FLAW: dataBytes may overflow to a small value */
            dataBytes = data * sizeof(int); /* sizeof array in bytes */
            intPointer = (int*)new char[dataBytes];
            for (i = 0; i < (size_t)data; i++)
            {
                intPointer[i] = 0; /* may write beyond limit of intPointer if integer overflow occured above */
            }
            printIntLine(intPointer[0]);
            delete [] intPointer;
        }
    }
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    unionType myUnion;
    /* Initialize data */
    data = -1;
    /* FIX: Set data to a relatively small number greater than zero */
    data = 20;
    myUnion.unionFirst = data;
    {
        int data = myUnion.unionSecond;
        {
            size_t dataBytes,i;
            int *intPointer;
            /* POTENTIAL FLAW: dataBytes may overflow to a small value */
            dataBytes = data * sizeof(int); /* sizeof array in bytes */
            intPointer = (int*)new char[dataBytes];
            for (i = 0; i < (size_t)data; i++)
            {
                intPointer[i] = 0; /* may write beyond limit of intPointer if integer overflow occured above */
            }
            printIntLine(intPointer[0]);
            delete [] intPointer;
        }
    }
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */
#ifdef INCLUDEMAIN

using namespace CWE680_Integer_Overflow_to_Buffer_Overflow__new_rand_34; /* so that we can use good and bad easily */

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
