/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_32.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 32 Data flow: two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"

#include <windows.h>


void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_32_bad()
{
    HANDLE data;
    HANDLE *dataPtr1 = &data;
    HANDLE *dataPtr2 = &data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    {
        HANDLE data = *dataPtr1;
        /* POTENTIAL FLAW: Open a file without closing it */
        data = CreateFile("BadSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        *dataPtr1 = data;
    }
    {
        HANDLE data = *dataPtr2;
        /* FLAW: No attempt to close the file */
        ; /* empty statement needed for some flow variants */
    }
}



/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    HANDLE data;
    HANDLE *dataPtr1 = &data;
    HANDLE *dataPtr2 = &data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    {
        HANDLE data = *dataPtr1;
        /* POTENTIAL FLAW: Open a file without closing it */
        data = CreateFile("BadSource_w32CreateFile.txt",
                          (GENERIC_WRITE|GENERIC_READ),
                          0,
                          NULL,
                          OPEN_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
        *dataPtr1 = data;
    }
    {
        HANDLE data = *dataPtr2;
        /* FIX: If the file is still opened, close it */
        if (data != INVALID_HANDLE_VALUE)
        {
            CloseHandle(data);
        }
    }
}

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_32_good()
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
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
