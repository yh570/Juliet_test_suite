/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE135_52a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-52a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define WIDE_STRING L"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
#define CHAR_STRING "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"


/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE135_52b_badSink(void * data);

void CWE121_Stack_Based_Buffer_Overflow__CWE135_52_bad()
{
    void * data;
    data = NULL;
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = (void *)WIDE_STRING;
    CWE121_Stack_Based_Buffer_Overflow__CWE135_52b_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE135_52b_goodG2BSink(void * data);

static void goodG2B()
{
    void * data;
    data = NULL;
    /* FIX: Set data to point to a char string */
    data = (void *)CHAR_STRING;
    CWE121_Stack_Based_Buffer_Overflow__CWE135_52b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE121_Stack_Based_Buffer_Overflow__CWE135_52b_goodB2GSink(void * data);

static void goodB2G()
{
    void * data;
    data = NULL;
    /* POTENTIAL FLAW: Set data to point to a wide string */
    data = (void *)WIDE_STRING;
    CWE121_Stack_Based_Buffer_Overflow__CWE135_52b_goodB2GSink(data);
}

void CWE121_Stack_Based_Buffer_Overflow__CWE135_52_good()
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
    CWE121_Stack_Based_Buffer_Overflow__CWE135_52_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE121_Stack_Based_Buffer_Overflow__CWE135_52_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
