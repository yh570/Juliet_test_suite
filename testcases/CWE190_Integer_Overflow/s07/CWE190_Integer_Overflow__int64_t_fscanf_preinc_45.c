/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int64_t_fscanf_preinc_45.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: increment
 *    GoodSink: Ensure there will not be an overflow before incrementing data
 *    BadSink : Increment data, which can cause an overflow
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include <inttypes.h>
#include "std_testcase.h"

static int64_t CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_badData;
static int64_t CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_goodG2BData;
static int64_t CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_goodB2GData;


static void badSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_badData;
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
}

void CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_bad()
{
    int64_t data;
    data = 0LL;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%" SCNd64, &data);
    CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_badData = data;
    badSink();
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_goodG2BData;
    {
        /* POTENTIAL FLAW: Incrementing data could cause an overflow */
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
}

static void goodG2B()
{
    int64_t data;
    data = 0LL;
    /* FIX: Use a small, non-zero value that will not cause an overflow in the sinks */
    data = 2;
    CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_goodG2BData = data;
    goodG2BSink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_goodB2GData;
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data < LLONG_MAX)
    {
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

static void goodB2G()
{
    int64_t data;
    data = 0LL;
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%" SCNd64, &data);
    CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_goodB2GData = data;
    goodB2GSink();
}

void CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_good()
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
    CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE190_Integer_Overflow__int64_t_fscanf_preinc_45_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
