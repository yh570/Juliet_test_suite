/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fscanf_square_66a.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <math.h>


/* bad function declaration */
void CWE190_Integer_Overflow__char_fscanf_square_66b_badSink(char dataArray[]);

void CWE190_Integer_Overflow__char_fscanf_square_66_bad()
{
    char data;
    char dataArray[5];
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%c", &data);
    /* put data in array */
    dataArray[2] = data;
    CWE190_Integer_Overflow__char_fscanf_square_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__char_fscanf_square_66b_goodG2BSink(char dataArray[]);

static void goodG2B()
{
    char data;
    char dataArray[5];
    data = ' ';
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    dataArray[2] = data;
    CWE190_Integer_Overflow__char_fscanf_square_66b_goodG2BSink(dataArray);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__char_fscanf_square_66b_goodB2GSink(char dataArray[]);

static void goodB2G()
{
    char data;
    char dataArray[5];
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%c", &data);
    dataArray[2] = data;
    CWE190_Integer_Overflow__char_fscanf_square_66b_goodB2GSink(dataArray);
}

void CWE190_Integer_Overflow__char_fscanf_square_66_good()
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
    CWE190_Integer_Overflow__char_fscanf_square_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__char_fscanf_square_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
