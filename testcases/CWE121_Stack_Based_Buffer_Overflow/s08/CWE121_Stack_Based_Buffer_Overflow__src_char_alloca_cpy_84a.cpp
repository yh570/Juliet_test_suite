/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_84a.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.label.xml
Template File: sources-sink-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: cpy
 *    BadSink : Copy data to string using strcpy
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_84.h"

namespace CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_84
{


void bad()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_84_bad * badObject = new CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_84_bad(data);
    delete badObject;
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_84_goodG2B * goodG2BObject =  new CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_84_goodG2B(data);
    delete goodG2BObject;
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

using namespace CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_84; /* so that we can use good and bad easily */

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
