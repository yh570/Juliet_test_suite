/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_fgets_modulo_66a.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fgets Read data from the console using fgets()
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)


/* bad function declaration */
void CWE369_Divide_by_Zero__int_fgets_modulo_66b_badSink(int dataArray[]);

void CWE369_Divide_by_Zero__int_fgets_modulo_66_bad()
{
    int data;
    int dataArray[5];
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
    /* put data in array */
    dataArray[2] = data;
    CWE369_Divide_by_Zero__int_fgets_modulo_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__int_fgets_modulo_66b_goodG2BSink(int dataArray[]);

static void goodG2B()
{
    int data;
    int dataArray[5];
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    dataArray[2] = data;
    CWE369_Divide_by_Zero__int_fgets_modulo_66b_goodG2BSink(dataArray);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__int_fgets_modulo_66b_goodB2GSink(int dataArray[]);

static void goodB2G()
{
    int data;
    int dataArray[5];
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
    dataArray[2] = data;
    CWE369_Divide_by_Zero__int_fgets_modulo_66b_goodB2GSink(dataArray);
}

void CWE369_Divide_by_Zero__int_fgets_modulo_66_good()
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
    CWE369_Divide_by_Zero__int_fgets_modulo_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__int_fgets_modulo_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
