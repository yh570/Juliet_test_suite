/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE367_TOC_TOU__access_02.c
Label Definition File: CWE367_TOC_TOU.label.xml
Template File: point-flaw-02.tmpl.c
*/
/*
 * @description
 * CWE: 367 Time-of-Check Time-Of-Use Race Condition
 * Sinks: access
 *    GoodSink: Open the file without checking the status information
 *    BadSink : Get status information on file using access(), open, write to, and close the file
 * Flow Variant: 02 Control flow: if(1) and if(0)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define STAT _stat
#define OPEN _open
#define WRITE _write
#define O_RDWR _O_RDWR
#define CLOSE _close
#else
#include <unistd.h>
#define STAT stat
#define OPEN open
#define WRITE write
#define CLOSE close
#endif

#define BAD_SINK_STRING "Bad Sink..."
#define GOOD_SINK_STRING "Good Sink..."

#ifdef _WIN32
#define ACCESS _access
#define W_OK 02
#else
#define ACCESS access
#endif


void CWE367_TOC_TOU__access_02_bad()
{
    if(1)
    {
        {
            char filename[100] = "";
            int fileDesc = -1;
            if (fgets(filename, 100, stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                filename[0] = '\0';
            }
            if (strlen(filename) > 0)
            {
                filename[strlen(filename)-1] = '\0'; /* remove newline */
            }
            /* FLAW: Open and write to the file after checking the status information */
            if (ACCESS(filename, W_OK) == -1)
            {
                exit(1);
            }
            fileDesc  = OPEN(filename, O_RDWR);
            if (fileDesc == -1)
            {
                exit(1);
            }
            if (WRITE(fileDesc, BAD_SINK_STRING, strlen(BAD_SINK_STRING)) == -1)
            {
                exit(1);
            }
            if (fileDesc != -1)
            {
                CLOSE(fileDesc);
            }
        }
    }
}



/* good1() uses if(0) instead of if(1) */
static void good1()
{
    if(0)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char filename[100] = "";
            int fileDesc = -1;
            if (fgets(filename, 100, stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                filename[0] = '\0';
            }
            if (strlen(filename) > 0)
            {
                filename[strlen(filename)-1] = '\0'; /* remove newline */
            }
            /* FIX: Open the file without checking the status information */
            fileDesc  = OPEN(filename, O_RDWR);
            if (fileDesc == -1)
            {
                exit(1);
            }
            if (WRITE(fileDesc, GOOD_SINK_STRING, strlen(GOOD_SINK_STRING)) == -1)
            {
                exit(1);
            }
            if (fileDesc != -1)
            {
                CLOSE(fileDesc);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(1)
    {
        {
            char filename[100] = "";
            int fileDesc = -1;
            if (fgets(filename, 100, stdin) == NULL)
            {
                printLine("fgets() failed");
                /* Restore NUL terminator if fgets fails */
                filename[0] = '\0';
            }
            if (strlen(filename) > 0)
            {
                filename[strlen(filename)-1] = '\0'; /* remove newline */
            }
            /* FIX: Open the file without checking the status information */
            fileDesc  = OPEN(filename, O_RDWR);
            if (fileDesc == -1)
            {
                exit(1);
            }
            if (WRITE(fileDesc, GOOD_SINK_STRING, strlen(GOOD_SINK_STRING)) == -1)
            {
                exit(1);
            }
            if (fileDesc != -1)
            {
                CLOSE(fileDesc);
            }
        }
    }
}

void CWE367_TOC_TOU__access_02_good()
{
    good1();
    good2();
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
    CWE367_TOC_TOU__access_02_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE367_TOC_TOU__access_02_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
