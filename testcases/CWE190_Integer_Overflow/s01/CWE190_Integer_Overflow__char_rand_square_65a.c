/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_rand_square_65a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: rand Set data to result of rand()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <math.h>


/* bad function declaration */
void CWE190_Integer_Overflow__char_rand_square_65b_badSink(char data);

void CWE190_Integer_Overflow__char_rand_square_65_bad()
{
    char data;
    /* define a function pointer */
    void (*funcPtr) (char) = CWE190_Integer_Overflow__char_rand_square_65b_badSink;
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_rand_square_65b_goodG2BSink(char data);

static void goodG2B()
{
    char data;
    void (*funcPtr) (char) = CWE190_Integer_Overflow__char_rand_square_65b_goodG2BSink;
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    funcPtr(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_rand_square_65b_goodB2GSink(char data);

static void goodB2G()
{
    char data;
    void (*funcPtr) (char) = CWE190_Integer_Overflow__char_rand_square_65b_goodB2GSink;
    data = ' ';
    /* POTENTIAL FLAW: Use a random value */
    data = (char)RAND32();
    funcPtr(data);
}

void CWE190_Integer_Overflow__char_rand_square_65_good()
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
    CWE190_Integer_Overflow__char_rand_square_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_rand_square_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
