/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE476_NULL_Pointer_Dereference__int64_t_67b.c
Label Definition File: CWE476_NULL_Pointer_Dereference.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 476 NULL Pointer Dereference
 * BadSource:  Set data to NULL
 * GoodSource: Initialize data
 * Sinks:
 *    GoodSink: Check for NULL before attempting to print data
 *    BadSink : Print data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE476_NULL_Pointer_Dereference__int64_t_67_structType
{
    int64_t * structFirst;
} CWE476_NULL_Pointer_Dereference__int64_t_67_structType;


void CWE476_NULL_Pointer_Dereference__int64_t_67b_badSink(CWE476_NULL_Pointer_Dereference__int64_t_67_structType myStruct)
{
    int64_t * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLongLine(*data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE476_NULL_Pointer_Dereference__int64_t_67b_goodG2BSink(CWE476_NULL_Pointer_Dereference__int64_t_67_structType myStruct)
{
    int64_t * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Attempt to use data, which may be NULL */
    printLongLongLine(*data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE476_NULL_Pointer_Dereference__int64_t_67b_goodB2GSink(CWE476_NULL_Pointer_Dereference__int64_t_67_structType myStruct)
{
    int64_t * data = myStruct.structFirst;
    /* FIX: Check for NULL before attempting to print data */
    if (data != NULL)
    {
        printLongLongLine(*data);
    }
    else
    {
        printLine("data is NULL");
    }
}

