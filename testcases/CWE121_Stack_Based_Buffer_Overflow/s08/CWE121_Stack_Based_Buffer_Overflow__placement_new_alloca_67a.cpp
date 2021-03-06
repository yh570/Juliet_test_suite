/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__placement_new_alloca_67a.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__placement_new.label.xml
Template File: sources-sinks-67a.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data to a small buffer
 * GoodSource: Initialize data to a buffer large enough to hold a TwoIntsClass
 * Sinks:
 *    GoodSink: Allocate a new class using placement new and a buffer that is large enough to hold the class
 *    BadSink : Allocate a new class using placement new and a buffer that is too small
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE121_Stack_Based_Buffer_Overflow__placement_new_alloca_67
{

typedef struct _structType
{
    char * structFirst;
} structType;


/* bad function declaration */
void badSink(structType myStruct);

void bad()
{
    char * data;
    structType myStruct;
    char * dataBadBuffer = (char *)ALLOCA(sizeof(OneIntClass));
    char * dataGoodBuffer = (char *)ALLOCA(sizeof(TwoIntsClass));
    /* POTENTIAL FLAW: Initialize data to a buffer smaller than the sizeof(TwoIntsClass) */
    data = dataBadBuffer;
    myStruct.structFirst = data;
    badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(structType myStruct);

static void goodG2B()
{
    char * data;
    structType myStruct;
    char * dataBadBuffer = (char *)ALLOCA(sizeof(OneIntClass));
    char * dataGoodBuffer = (char *)ALLOCA(sizeof(TwoIntsClass));
    /* FIX: Initialize to a buffer at least the sizeof(TwoIntsClass) */
    data = dataGoodBuffer;
    myStruct.structFirst = data;
    goodG2BSink(myStruct);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(structType myStruct);

static void goodB2G()
{
    char * data;
    structType myStruct;
    char * dataBadBuffer = (char *)ALLOCA(sizeof(OneIntClass));
    char * dataGoodBuffer = (char *)ALLOCA(sizeof(TwoIntsClass));
    /* POTENTIAL FLAW: Initialize data to a buffer smaller than the sizeof(TwoIntsClass) */
    data = dataBadBuffer;
    myStruct.structFirst = data;
    goodB2GSink(myStruct);
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

using namespace CWE121_Stack_Based_Buffer_Overflow__placement_new_alloca_67; /* so that we can use good and bad easily */

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
