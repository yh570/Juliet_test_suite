/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_max_add_62a.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-62a.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: max Set data to the max value for char
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

namespace CWE190_Integer_Overflow__char_max_add_62
{


/* bad function declaration */
void badSource(char &data);

void bad()
{
    char data;
    data = ' ';
    badSource(data);
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        char result = data + 1;
        printHexCharLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSource(char &data);

static void goodG2B()
{
    char data;
    data = ' ';
    goodG2BSource(data);
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        char result = data + 1;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSource(char &data);

static void goodB2G()
{
    char data;
    data = ' ';
    goodB2GSource(data);
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < CHAR_MAX)
    {
        char result = data + 1;
        printHexCharLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
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

using namespace CWE190_Integer_Overflow__char_max_add_62; /* so that we can use good and bad easily */

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
