/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_83a.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE129.label.xml
Template File: sources-sinks-83a.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_83.h"

namespace CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_83
{


void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_83_bad badObject(data);
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_83_goodG2B goodG2BObject(data);
}

/* goodG2B uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_83_goodB2G goodB2GObject(data);
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

using namespace CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_83; /* so that we can use good and bad easily */

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
