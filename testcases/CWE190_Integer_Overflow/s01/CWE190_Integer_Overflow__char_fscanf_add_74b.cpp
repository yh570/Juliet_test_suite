/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fscanf_add_74b.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE190_Integer_Overflow__char_fscanf_add_74
{


void badSink(map<int, char> dataMap)
{
    /* copy data out of dataMap */
    char data = dataMap[2];
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        char result = data + 1;
        printHexCharLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, char> dataMap)
{
    char data = dataMap[2];
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        char result = data + 1;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, char> dataMap)
{
    char data = dataMap[2];
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


} /* close namespace */
