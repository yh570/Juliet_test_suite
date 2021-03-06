/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_fgets_divide_45.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sinks: divide
 *    GoodSink: Check for zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

static int CWE369_Divide_by_Zero__int_fgets_divide_45_badData;
static int CWE369_Divide_by_Zero__int_fgets_divide_45_goodG2BData;
static int CWE369_Divide_by_Zero__int_fgets_divide_45_goodB2GData;


static void badSink()
{
    int data = CWE369_Divide_by_Zero__int_fgets_divide_45_badData;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

void CWE369_Divide_by_Zero__int_fgets_divide_45_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* POTENTIAL FLAW: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE369_Divide_by_Zero__int_fgets_divide_45_badData = data;
    badSink();
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink()
{
    int data = CWE369_Divide_by_Zero__int_fgets_divide_45_goodG2BData;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    CWE369_Divide_by_Zero__int_fgets_divide_45_goodG2BData = data;
    goodG2BSink();
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    int data = CWE369_Divide_by_Zero__int_fgets_divide_45_goodB2GData;
    /* FIX: test for a zero denominator */
    if( data != 0 )
    {
        printIntLine(100 / data);
    }
    else
    {
        printLine("This would result in a divide by zero");
    }
}

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* POTENTIAL FLAW: Read data from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE369_Divide_by_Zero__int_fgets_divide_45_goodB2GData = data;
    goodB2GSink();
}

void CWE369_Divide_by_Zero__int_fgets_divide_45_good()
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
    CWE369_Divide_by_Zero__int_fgets_divide_45_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__int_fgets_divide_45_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
