/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_64a.c
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-64a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE690_NULL_Deref_From_Return__w32_wfopen_64b_badSink(void * dataVoidPtr);

void CWE690_NULL_Deref_From_Return__w32_wfopen_64_bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
    CWE690_NULL_Deref_From_Return__w32_wfopen_64b_badSink(&data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_From_Return__w32_wfopen_64b_goodB2GSink(void * dataVoidPtr);

static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
    CWE690_NULL_Deref_From_Return__w32_wfopen_64b_goodB2GSink(&data);
}

void CWE690_NULL_Deref_From_Return__w32_wfopen_64_good()
{
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
    CWE690_NULL_Deref_From_Return__w32_wfopen_64_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__w32_wfopen_64_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
