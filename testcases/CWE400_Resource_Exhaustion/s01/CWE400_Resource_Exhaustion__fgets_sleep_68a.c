/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fgets_sleep_68a.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(count) + 2)

#ifdef _WIN32
#include <windows.h>
#define SLEEP Sleep
#else
#include <unistd.h>
#define SLEEP usleep
#endif

int CWE400_Resource_Exhaustion__fgets_sleep_68_badData;
int CWE400_Resource_Exhaustion__fgets_sleep_68_goodG2BData;
int CWE400_Resource_Exhaustion__fgets_sleep_68_goodB2GData;


/* bad function declaration */
void CWE400_Resource_Exhaustion__fgets_sleep_68b_badSink();

void CWE400_Resource_Exhaustion__fgets_sleep_68_bad()
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
    CWE400_Resource_Exhaustion__fgets_sleep_68_badData = count;
    CWE400_Resource_Exhaustion__fgets_sleep_68b_badSink();
}



/* good function declarations */
void CWE400_Resource_Exhaustion__fgets_sleep_68b_goodG2BSink();
void CWE400_Resource_Exhaustion__fgets_sleep_68b_goodB2GSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int count;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    CWE400_Resource_Exhaustion__fgets_sleep_68_goodG2BData = count;
    CWE400_Resource_Exhaustion__fgets_sleep_68b_goodG2BSink();
}

/* goodB2G uses the BadSource with the GoodSink */
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
    CWE400_Resource_Exhaustion__fgets_sleep_68_goodB2GData = count;
    CWE400_Resource_Exhaustion__fgets_sleep_68b_goodB2GSink();
}

void CWE400_Resource_Exhaustion__fgets_sleep_68_good()
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
    CWE400_Resource_Exhaustion__fgets_sleep_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__fgets_sleep_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
