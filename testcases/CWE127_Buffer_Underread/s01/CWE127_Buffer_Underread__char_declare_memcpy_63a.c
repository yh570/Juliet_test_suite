/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__char_declare_memcpy_63a.c
Label Definition File: CWE127_Buffer_Underread.stack.label.xml
Template File: sources-sink-63a.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sinks: memcpy
 *    BadSink : Copy data to string using memcpy
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE127_Buffer_Underread__char_declare_memcpy_63b_badSink(char * * dataPtr);

void CWE127_Buffer_Underread__char_declare_memcpy_63_bad()
{
    char * data;
    char dataBuffer[100];
    memset(dataBuffer, 'A', 100-1);
    dataBuffer[100-1] = '\0';
    /* FLAW: Set data pointer to before the allocated memory buffer */
    data = dataBuffer - 8;
    CWE127_Buffer_Underread__char_declare_memcpy_63b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE127_Buffer_Underread__char_declare_memcpy_63b_goodG2BSink(char * * data);

static void goodG2B()
{
    char * data;
    char dataBuffer[100];
    memset(dataBuffer, 'A', 100-1);
    dataBuffer[100-1] = '\0';
    /* FIX: Set data pointer to the allocated memory buffer */
    data = dataBuffer;
    CWE127_Buffer_Underread__char_declare_memcpy_63b_goodG2BSink(&data);
}

void CWE127_Buffer_Underread__char_declare_memcpy_63_good()
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
    CWE127_Buffer_Underread__char_declare_memcpy_63_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__char_declare_memcpy_63_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
