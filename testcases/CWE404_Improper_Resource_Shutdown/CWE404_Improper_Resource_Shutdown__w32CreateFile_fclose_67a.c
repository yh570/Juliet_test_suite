/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67a.c
Label Definition File: CWE404_Improper_Resource_Shutdown__w32CreateFile.label.xml
Template File: source-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using CreateFile()
 * Sinks: fclose
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

typedef struct _CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType
{
    HANDLE structFirst;
} CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType;


/* bad function declaration */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b_badSink(CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType myStruct);

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_bad()
{
    HANDLE data;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType myStruct;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    myStruct.structFirst = data;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b_badSink(myStruct);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b_goodB2GSink(CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType myStruct);

static void goodB2G()
{
    HANDLE data;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_structType myStruct;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = CreateFile("BadSource_w32CreateFile.txt",
                      (GENERIC_WRITE|GENERIC_READ),
                      0,
                      NULL,
                      OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
    myStruct.structFirst = data;
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67b_goodB2GSink(myStruct);
}

void CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_good()
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
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__w32CreateFile_fclose_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
