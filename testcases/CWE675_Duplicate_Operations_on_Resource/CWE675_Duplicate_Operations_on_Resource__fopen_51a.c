/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__fopen_51a.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource.label.xml
Template File: sources-sinks-51a.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource: fopen Open and close a file using fopen() and flose()
 * GoodSource: Open a file using fopen()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE675_Duplicate_Operations_on_Resource__fopen_51b_badSink(FILE * data);

void CWE675_Duplicate_Operations_on_Resource__fopen_51_bad()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = fopen("BadSource_fopen.txt", "w+");
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
    CWE675_Duplicate_Operations_on_Resource__fopen_51b_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE675_Duplicate_Operations_on_Resource__fopen_51b_goodG2BSink(FILE * data);

static void goodG2B()
{
    FILE * data;
    data = NULL; /* Initialize data */
    /* FIX: Open, but do not close the file in the source */
    data = fopen("GoodSource_fopen.txt", "w+");
    CWE675_Duplicate_Operations_on_Resource__fopen_51b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE675_Duplicate_Operations_on_Resource__fopen_51b_goodB2GSink(FILE * data);

static void goodB2G()
{
    FILE * data;
    data = NULL; /* Initialize data */
    data = fopen("BadSource_fopen.txt", "w+");
    /* POTENTIAL FLAW: Close the file in the source */
    fclose(data);
    CWE675_Duplicate_Operations_on_Resource__fopen_51b_goodB2GSink(data);
}

void CWE675_Duplicate_Operations_on_Resource__fopen_51_good()
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
    CWE675_Duplicate_Operations_on_Resource__fopen_51_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE675_Duplicate_Operations_on_Resource__fopen_51_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
