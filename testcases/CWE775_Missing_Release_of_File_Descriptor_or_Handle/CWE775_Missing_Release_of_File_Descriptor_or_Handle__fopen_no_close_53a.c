/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53a.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-53a.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53b_badSink(FILE * data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53_bad()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = fopen("BadSource_fopen.txt", "w+");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53b_badSink(data);
}



/* good function declarations */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53b_goodB2GSink(FILE * data);

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = fopen("BadSource_fopen.txt", "w+");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53b_goodB2GSink(data);
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53_good()
{
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_53_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
