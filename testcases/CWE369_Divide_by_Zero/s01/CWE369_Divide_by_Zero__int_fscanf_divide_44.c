/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_fscanf_divide_44.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sinks: divide
 *    GoodSink: Check for zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"


static void badSink(int data)
{
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

void CWE369_Divide_by_Zero__int_fscanf_divide_44_bad()
{
    int data;
    /* define a function pointer */
    void (*funcPtr) (int) = badSink;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    /* use the function pointer */
    funcPtr(data);
}



/* goodG2B() uses the GoodSource with the BadSink */
static void goodG2BSink(int data)
{
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

static void goodG2B()
{
    int data;
    void (*funcPtr) (int) = goodG2BSink;
    /* Initialize data */
    data = -1;
    /* FIX: Use a value not equal to zero */
    data = 7;
    funcPtr(data);
}

/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink(int data)
{
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
    void (*funcPtr) (int) = goodB2GSink;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    funcPtr(data);
}

void CWE369_Divide_by_Zero__int_fscanf_divide_44_good()
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
    CWE369_Divide_by_Zero__int_fscanf_divide_44_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE369_Divide_by_Zero__int_fscanf_divide_44_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
