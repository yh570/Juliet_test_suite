/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_multiply_73b.cpp
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: multiply
 *    GoodSink: Ensure there will not be an overflow before multiplying data by 2
 *    BadSink : If data is positive, multiply by 2, which can cause an overflow
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE190_Integer_Overflow__char_rand_multiply_73
{


void badSink(list<char> dataList)
{
    /* copy data out of dataList */
    char data = dataList.back();
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > CHAR_MAX, this will overflow */
        char result = data * 2;
        printHexCharLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<char> dataList)
{
    char data = dataList.back();
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* POTENTIAL FLAW: if (data*2) > CHAR_MAX, this will overflow */
        char result = data * 2;
        printHexCharLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<char> dataList)
{
    char data = dataList.back();
    if(data > 0) /* ensure we won't have an underflow */
    {
        /* FIX: Add a check to prevent an overflow from occurring */
        if (data < (CHAR_MAX/2))
        {
            char result = data * 2;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}


} /* close namespace */
