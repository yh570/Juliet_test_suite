/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_for_loop_54a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: for_loop
 *    GoodSink: Validate count before using it as the loop variant in a for loop
 *    BadSink : Use count as the loop variant in a for loop
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(count) + 2)


/* bad function declaration */
void CWE400_Resource_Exhaustion__fgets_for_loop_54b_badSink(int count);

void CWE400_Resource_Exhaustion__fgets_for_loop_54_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* POTENTIAL FLAW: Read count from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            count = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE400_Resource_Exhaustion__fgets_for_loop_54b_badSink(count);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE400_Resource_Exhaustion__fgets_for_loop_54b_goodG2BSink(int count);

static void goodG2B()
{
    int count;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    CWE400_Resource_Exhaustion__fgets_for_loop_54b_goodG2BSink(count);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE400_Resource_Exhaustion__fgets_for_loop_54b_goodB2GSink(int count);

static void goodB2G()
{
    int count;
    /* Initialize count */
    count = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        /* POTENTIAL FLAW: Read count from the console using fgets() */
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            /* Convert to int */
            count = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE400_Resource_Exhaustion__fgets_for_loop_54b_goodB2GSink(count);
}

void CWE400_Resource_Exhaustion__fgets_for_loop_54_good()
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
    CWE400_Resource_Exhaustion__fgets_for_loop_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fgets_for_loop_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
