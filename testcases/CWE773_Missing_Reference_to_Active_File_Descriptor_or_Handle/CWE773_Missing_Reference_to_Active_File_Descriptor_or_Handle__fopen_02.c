/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_02.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-02.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using fopen()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"


void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_02_bad()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Create a file handle using fopen() that may not be closed properly */
    data = fopen("BadSource_fopen.txt", "w+");
    if(1)
    {
        /* FLAW: Point data to another file handle without closing the handle from the source */
        data = fopen("BadSink_fopen.txt", "w+");
        /* avoid incidental for not closing the file handle */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}



/* goodB2G1() - use badsource and goodsink by changing 1 to 0 */
static void goodB2G1()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Create a file handle using fopen() that may not be closed properly */
    data = fopen("BadSource_fopen.txt", "w+");
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Close the file from the source before pointing data to a new file handle */
        if (data != NULL)
        {
            fclose(data);
        }
        data = fopen("GoodSink_fopen.txt", "w+");
        /* avoid incidental for not closing the file handle */
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
    /* POTENTIAL FLAW: Create a file handle using fopen() that may not be closed properly */
    data = fopen("BadSource_fopen.txt", "w+");
    if(1)
    {
        /* FIX: Close the file from the source before pointing data to a new file handle */
        if (data != NULL)
        {
            fclose(data);
        }
        data = fopen("GoodSink_fopen.txt", "w+");
        /* avoid incidental for not closing the file handle */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_02_good()
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_02_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_02_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
