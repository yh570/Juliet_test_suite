/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66a.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>


/* bad function declaration */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66b_badSink(HANDLE dataArray[]);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66_bad()
{
    HANDLE data;
    HANDLE dataArray[5];
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    /* put data in array */
    dataArray[2] = data;
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66b_badSink(dataArray);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66b_goodB2GSink(HANDLE dataArray[]);

static void goodB2G()
{
    HANDLE data;
    HANDLE dataArray[5];
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    dataArray[2] = data;
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66b_goodB2GSink(dataArray);
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66_good()
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
