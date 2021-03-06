/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-45.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 45 Data flow: data passed as a static global variable from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

#include <windows.h>

static int CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45_badData;
static int CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45_goodB2GData;


static void badSink()
{
    int data = CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45_badData;
    if (data != -1)
    {
        /* FLAW: Attempt to close the file using CloseHandle() instead of close() */
        CloseHandle((HANDLE)data);
    }
}

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45_badData = data;
    badSink();
}



/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSink()
{
    int data = CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45_goodB2GData;
    if (data != -1)
    {
        /* FIX: Close the file using close() */
        CLOSE(data);
    }
}

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45_goodB2GData = data;
    goodB2GSink();
}

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45_good()
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
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_45_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
