/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_17.c
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-17.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: w32CloseHandle
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using CloseHandle
 * Flow Variant: 17 Control flow: for loops
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


void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_17_bad()
{
    int j;
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    for(j = 0; j < 1; j++)
    {
        if (data != -1)
        {
            /* FLAW: Attempt to close the file using CloseHandle() instead of close() */
            CloseHandle((HANDLE)data);
        }
    }
}



/* goodB2G() - use the goodsink in the for statement */
static void goodB2G()
{
    int k;
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    for(k = 0; k < 1; k++)
    {
        if (data != -1)
        {
            /* FIX: Close the file using close() */
            CLOSE(data);
        }
    }
}

void CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_17_good()
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
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__open_w32CloseHandle_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
