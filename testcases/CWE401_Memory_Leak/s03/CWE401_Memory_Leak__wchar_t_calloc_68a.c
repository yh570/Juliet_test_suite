/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__wchar_t_calloc_68a.c
Label Definition File: CWE401_Memory_Leak.c.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource: calloc Allocate data using calloc()
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call free() on data
 *    BadSink : no deallocation of data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

wchar_t * CWE401_Memory_Leak__wchar_t_calloc_68_badData;
wchar_t * CWE401_Memory_Leak__wchar_t_calloc_68_goodG2BData;
wchar_t * CWE401_Memory_Leak__wchar_t_calloc_68_goodB2GData;


/* bad function declaration */
void CWE401_Memory_Leak__wchar_t_calloc_68b_badSink();

void CWE401_Memory_Leak__wchar_t_calloc_68_bad()
{
    wchar_t * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (wchar_t *)calloc(100, sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_calloc_68_badData = data;
    CWE401_Memory_Leak__wchar_t_calloc_68b_badSink();
}



/* good function declarations */
void CWE401_Memory_Leak__wchar_t_calloc_68b_goodG2BSink();
void CWE401_Memory_Leak__wchar_t_calloc_68b_goodB2GSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    /* FIX: Use memory allocated on the stack with ALLOCA */
    data = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_calloc_68_goodG2BData = data;
    CWE401_Memory_Leak__wchar_t_calloc_68b_goodG2BSink();
}

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    data = NULL;
    /* POTENTIAL FLAW: Allocate memory on the heap */
    data = (wchar_t *)calloc(100, sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    /* Initialize and make use of data */
    wcscpy(data, L"A String");
    printWLine(data);
    CWE401_Memory_Leak__wchar_t_calloc_68_goodB2GData = data;
    CWE401_Memory_Leak__wchar_t_calloc_68b_goodB2GSink();
}

void CWE401_Memory_Leak__wchar_t_calloc_68_good()
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
    CWE401_Memory_Leak__wchar_t_calloc_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE401_Memory_Leak__wchar_t_calloc_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
