/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__wchar_t_realloc_51a.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-51a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 51 Data flow: data passed as an argument from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE690_NULL_Deref_From_Return__wchar_t_realloc_51b_badSink(wchar_t * data);

void CWE690_NULL_Deref_From_Return__wchar_t_realloc_51_bad()
{
    wchar_t * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (wchar_t *)realloc(data, 20*sizeof(wchar_t));
    CWE690_NULL_Deref_From_Return__wchar_t_realloc_51b_badSink(data);
}



/* good function declarations */
void CWE690_NULL_Deref_From_Return__wchar_t_realloc_51b_goodB2GSink(wchar_t * data);

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (wchar_t *)realloc(data, 20*sizeof(wchar_t));
    CWE690_NULL_Deref_From_Return__wchar_t_realloc_51b_goodB2GSink(data);
}

void CWE690_NULL_Deref_From_Return__wchar_t_realloc_51_good()
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
    CWE690_NULL_Deref_From_Return__wchar_t_realloc_51_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__wchar_t_realloc_51_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
