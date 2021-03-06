/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65a.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-65a.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <windows.h>


/* bad function declaration */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65b_badSink(HANDLE data);

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65_bad()
{
    HANDLE data;
    /* define a function pointer */
    void (*funcPtr) (HANDLE) = CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65b_badSink;
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
    /* use the function pointer */
    funcPtr(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65b_goodB2GSink(HANDLE data);

static void goodB2G()
{
    HANDLE data;
    void (*funcPtr) (HANDLE) = CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65b_goodB2GSink;
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
    funcPtr(data);
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65_good()
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
