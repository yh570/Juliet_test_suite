/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__w32CreateFile_06.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__w32CreateFile.label.xml
Template File: sources-sinks-06.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using CreateFile() and CloseHandle()
 * GoodSource: Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;


void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_06_bad()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(STATIC_CONST_FIVE==5)
    {
        data = CreateFile("BadSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        /* POTENTIAL FLAW: Close the file in the source */
        CloseHandle(data);
    }
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodB2G1()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(STATIC_CONST_FIVE==5)
    {
        data = CreateFile("BadSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        /* POTENTIAL FLAW: Close the file in the source */
        CloseHandle(data);
    }
    if(STATIC_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* Do nothing */
        /* FIX: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(STATIC_CONST_FIVE==5)
    {
        data = CreateFile("BadSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        /* POTENTIAL FLAW: Close the file in the source */
        CloseHandle(data);
    }
    if(STATIC_CONST_FIVE==5)
    {
        /* Do nothing */
        /* FIX: Don't close the file in the sink */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodG2B1()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(STATIC_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Open, but do not close the file in the source */
        data = CreateFile("GoodSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
    }
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    HANDLE data;
    data = INVALID_HANDLE_VALUE; /* Initialize data */
    if(STATIC_CONST_FIVE==5)
    {
        /* FIX: Open, but do not close the file in the source */
        data = CreateFile("GoodSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
    }
    if(STATIC_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Close the file in the sink (it may have been closed in the Source) */
        CloseHandle(data);
    }
}

void CWE675_Duplicate_Operations_on_Resource__w32CreateFile_06_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_06_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE675_Duplicate_Operations_on_Resource__w32CreateFile_06_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
