/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__struct_realloc_65a.c
Label Definition File: CWE690_NULL_Deref_From_Return.free.label.xml
Template File: source-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: realloc Allocate data using realloc()
 * Sinks:
 *    GoodSink: Check to see if the data allocation failed and if not, use data
 *    BadSink : Don't check for NULL and use data
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE690_NULL_Deref_From_Return__struct_realloc_65b_badSink(twoIntsStruct * data);

void CWE690_NULL_Deref_From_Return__struct_realloc_65_bad()
{
    twoIntsStruct * data;
    /* define a function pointer */
    void (*funcPtr) (twoIntsStruct *) = CWE690_NULL_Deref_From_Return__struct_realloc_65b_badSink;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (twoIntsStruct *)realloc(data, 1*sizeof(twoIntsStruct));
    /* use the function pointer */
    funcPtr(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE690_NULL_Deref_From_Return__struct_realloc_65b_goodB2GSink(twoIntsStruct * data);

static void goodB2G()
{
    twoIntsStruct * data;
    void (*funcPtr) (twoIntsStruct *) = CWE690_NULL_Deref_From_Return__struct_realloc_65b_goodB2GSink;
    data = NULL; /* Initialize data */
    /* POTENTIAL FLAW: Allocate memory without checking if the memory allocation function failed */
    data = (twoIntsStruct *)realloc(data, 1*sizeof(twoIntsStruct));
    funcPtr(data);
}

void CWE690_NULL_Deref_From_Return__struct_realloc_65_good()
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
    CWE690_NULL_Deref_From_Return__struct_realloc_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE690_NULL_Deref_From_Return__struct_realloc_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
