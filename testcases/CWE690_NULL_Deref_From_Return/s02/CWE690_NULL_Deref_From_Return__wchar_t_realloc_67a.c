/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__wchar_t_realloc_67a.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE690_NULL_Deref_From_Return__wchar_t_realloc_67_structType
{
    wchar_t * structFirst;
} CWE690_NULL_Deref_From_Return__wchar_t_realloc_67_structType;


/* bad function declaration */
void CWE690_NULL_Deref_From_Return__wchar_t_realloc_67b_badSink(CWE690_NULL_Deref_From_Return__wchar_t_realloc_67_structType myStruct);

void CWE690_NULL_Deref_From_Return__wchar_t_realloc_67_bad()
{
    wchar_t * data;
    CWE690_NULL_Deref_From_Return__wchar_t_realloc_67_structType myStruct;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (wchar_t *)realloc(data, 20*sizeof(wchar_t));
    myStruct.structFirst = data;
    CWE690_NULL_Deref_From_Return__wchar_t_realloc_67b_badSink(myStruct);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_From_Return__wchar_t_realloc_67b_goodB2GSink(CWE690_NULL_Deref_From_Return__wchar_t_realloc_67_structType myStruct);

static void goodB2G()
{
    wchar_t * data;
    CWE690_NULL_Deref_From_Return__wchar_t_realloc_67_structType myStruct;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (wchar_t *)realloc(data, 20*sizeof(wchar_t));
    myStruct.structFirst = data;
    CWE690_NULL_Deref_From_Return__wchar_t_realloc_67b_goodB2GSink(myStruct);
}

void CWE690_NULL_Deref_From_Return__wchar_t_realloc_67_good()
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
    CWE690_NULL_Deref_From_Return__wchar_t_realloc_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__wchar_t_realloc_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
