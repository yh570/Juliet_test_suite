/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__short_rand_multiply_74b.cpp
Label Definition File: CWE191_Integer_Underflow.label.xml
Template File: sources-sinks-74b.tmpl.cpp
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an underflow before multiplying data by 2
 *    BadSink : If data is negative, multiply by 2, which can cause an underflow
 * Flow Variant: 74 Data flow: data passed in a map from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <map>

using namespace std;

namespace CWE191_Integer_Underflow__short_rand_multiply_74
{


void badSink(map<int, short> dataMap)
{
    /* copy data out of dataMap */
    short data = dataMap[2];
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < SHRT_MIN, this will underflow */
        short result = data * 2;
        printIntLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(map<int, short> dataMap)
{
    short data = dataMap[2];
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* POTENTIAL FLAW: if (data * 2) < SHRT_MIN, this will underflow */
        short result = data * 2;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(map<int, short> dataMap)
{
    short data = dataMap[2];
    if(data < 0) /* ensure we won't have an overflow */
    {
        /* FIX: Add a check to prevent an underflow from occurring */
        if (data > (SHRT_MIN/2))
        {
            short result = data * 2;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too small to perform multiplication.");
        }
    }
}


} /* close namespace */
