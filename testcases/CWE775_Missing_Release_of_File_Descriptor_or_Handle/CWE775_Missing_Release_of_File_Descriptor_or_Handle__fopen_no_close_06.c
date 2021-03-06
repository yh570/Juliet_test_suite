/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_06.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-06.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 06 Control flow: if(STATIC_CONST_FIVE==5) and if(STATIC_CONST_FIVE!=5)
 *
 * */

#include "std_testcase.h"

/* The variable below is declared "const", so a tool should be able
   to identify that reads of this will always give its initialized
   value. */
static const int STATIC_CONST_FIVE = 5;


void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_06_bad()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = fopen("BadSource_fopen.txt", "w+");
    if(STATIC_CONST_FIVE==5)
    {
        /* FLAW: No attempt to close the file */
        ; /* empty statement needed for some flow variants */
    }
}



/* goodB2G1() - use badsource and goodsink by changing STATIC_CONST_FIVE==5 to STATIC_CONST_FIVE!=5 */
static void goodB2G1()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = fopen("BadSource_fopen.txt", "w+");
    if(STATIC_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: If the file is still opened, close it */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing statements in if  */
static void goodB2G2()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = fopen("BadSource_fopen.txt", "w+");
    if(STATIC_CONST_FIVE==5)
    {
        /* FIX: If the file is still opened, close it */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_06_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_06_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_06_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
