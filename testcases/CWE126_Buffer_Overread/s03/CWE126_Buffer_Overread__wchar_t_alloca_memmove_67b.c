/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__wchar_t_alloca_memmove_67b.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sinks: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE126_Buffer_Overread__wchar_t_alloca_memmove_67_structType
{
    wchar_t * structFirst;
} CWE126_Buffer_Overread__wchar_t_alloca_memmove_67_structType;


void CWE126_Buffer_Overread__wchar_t_alloca_memmove_67b_badSink(CWE126_Buffer_Overread__wchar_t_alloca_memmove_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: using memmove with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memmove(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE126_Buffer_Overread__wchar_t_alloca_memmove_67b_goodG2BSink(CWE126_Buffer_Overread__wchar_t_alloca_memmove_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        wchar_t dest[100];
        wmemset(dest, L'C', 100-1);
        dest[100-1] = L'\0'; /* null terminate */
        /* POTENTIAL FLAW: using memmove with the length of the dest where data
         * could be smaller than dest causing buffer overread */
        memmove(dest, data, wcslen(dest)*sizeof(wchar_t));
        dest[100-1] = L'\0';
        printWLine(dest);
    }
}

