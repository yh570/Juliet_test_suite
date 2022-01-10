/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE193.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Point data to a buffer that does not have space for a NULL terminator
 * GoodSource: Point data to a buffer that includes space for a NULL terminator
 * Sinks: cpy
 *    BadSink : Copy string to data using wcscpy()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

/* MAINTENANCE NOTE: The length of this string should equal the 10 */
#define SRC_STRING L"AAAAAAAAAA"

typedef struct _CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67_structType
{
    wchar_t * structFirst;
} CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67_structType;


/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67b_badSink(CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67_structType myStruct);

void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67_bad()
{
    wchar_t * data;
    CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67_structType myStruct;
    wchar_t dataBadBuffer[10];
    wchar_t dataGoodBuffer[10+1];
    /* FLAW: Set a pointer to a buffer that does not leave room for a NULL terminator when performing
     * string copies in the sinks  */
    data = dataBadBuffer;
    data[0] = L'\0'; /* null terminate */
    myStruct.structFirst = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67b_goodG2BSink(CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67_structType myStruct);

static void goodG2B()
{
    wchar_t * data;
    CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67_structType myStruct;
    wchar_t dataBadBuffer[10];
    wchar_t dataGoodBuffer[10+1];
    /* FIX: Set a pointer to a buffer that leaves room for a NULL terminator when performing
     * string copies in the sinks  */
    data = dataGoodBuffer;
    data[0] = L'\0'; /* null terminate */
    myStruct.structFirst = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67b_goodG2BSink(myStruct);
}

void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
