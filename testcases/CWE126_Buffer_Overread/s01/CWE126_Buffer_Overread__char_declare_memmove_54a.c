/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE126_Buffer_Overread__char_declare_memmove_54a.c
Label Definition File: CWE126_Buffer_Overread.stack.label.xml
Template File: sources-sink-54a.tmpl.c
*/
/*
 * @description
 * CWE: 126 Buffer Over-read
 * BadSource:  Set data pointer to a small buffer
 * GoodSource: Set data pointer to a large buffer
 * Sink: memmove
 *    BadSink : Copy data to string using memmove
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>


/* bad function declaration */
void CWE126_Buffer_Overread__char_declare_memmove_54b_badSink(char * data);

void CWE126_Buffer_Overread__char_declare_memmove_54_bad()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    memset(dataBadBuffer, 'A', 50-1); /* fill with 'A's */
    dataBadBuffer[50-1] = '\0'; /* null terminate */
    memset(dataGoodBuffer, 'A', 100-1); /* fill with 'A's */
    dataGoodBuffer[100-1] = '\0'; /* null terminate */
    /* FLAW: Set data pointer to a small buffer */
    data = dataBadBuffer;
    CWE126_Buffer_Overread__char_declare_memmove_54b_badSink(data);
}



/* good function declaration */
void CWE126_Buffer_Overread__char_declare_memmove_54b_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    memset(dataBadBuffer, 'A', 50-1); /* fill with 'A's */
    dataBadBuffer[50-1] = '\0'; /* null terminate */
    memset(dataGoodBuffer, 'A', 100-1); /* fill with 'A's */
    dataGoodBuffer[100-1] = '\0'; /* null terminate */
    /* FIX: Set data pointer to a large buffer */
    data = dataGoodBuffer;
    CWE126_Buffer_Overread__char_declare_memmove_54b_goodG2BSink(data);
}

void CWE126_Buffer_Overread__char_declare_memmove_54_good()
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
    CWE126_Buffer_Overread__char_declare_memmove_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE126_Buffer_Overread__char_declare_memmove_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
