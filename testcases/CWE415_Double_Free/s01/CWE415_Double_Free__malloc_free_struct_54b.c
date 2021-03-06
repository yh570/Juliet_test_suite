/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__malloc_free_struct_54b.c
Label Definition File: CWE415_Double_Free__malloc_free.label.xml
Template File: sources-sinks-54b.tmpl.c
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using malloc() and Deallocate data using free()
 * GoodSource: Allocate data using malloc()
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using free()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE415_Double_Free__malloc_free_struct_54c_badSink(twoIntsStruct * data);

void CWE415_Double_Free__malloc_free_struct_54b_badSink(twoIntsStruct * data)
{
    CWE415_Double_Free__malloc_free_struct_54c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE415_Double_Free__malloc_free_struct_54c_goodG2BSink(twoIntsStruct * data);

void CWE415_Double_Free__malloc_free_struct_54b_goodG2BSink(twoIntsStruct * data)
{
    CWE415_Double_Free__malloc_free_struct_54c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE415_Double_Free__malloc_free_struct_54c_goodB2GSink(twoIntsStruct * data);

void CWE415_Double_Free__malloc_free_struct_54b_goodB2GSink(twoIntsStruct * data)
{
    CWE415_Double_Free__malloc_free_struct_54c_goodB2GSink(data);
}

