/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66a.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile.label.xml
Template File: source-sinks-66a.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using CreateFile()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>


/* bad function declaration */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66b_badSink(HANDLE dataArray[]);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66_bad()
{
    HANDLE data;
    HANDLE dataArray[5];
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Create a file handle using CreateFile() that may not be closed properly */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    /* put data in array */
    dataArray[2] = data;
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66b_badSink(dataArray);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66b_goodB2GSink(HANDLE dataArray[]);

static void goodB2G()
{
    HANDLE data;
    HANDLE dataArray[5];
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Create a file handle using CreateFile() that may not be closed properly */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    dataArray[2] = data;
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66b_goodB2GSink(dataArray);
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66_good()
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__w32CreateFile_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
