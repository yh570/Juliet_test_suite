/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__wchar_t_tmpnam_11.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-11.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: tmpnam
 *    GoodSink: Create and open a temporary file, created with _wtmpnam(), more securely
 *    BadSink : Create and open a temporary file, created with _wtmpnam(), insecurely
 * Flow Variant: 11 Control flow: if(globalReturnsTrue()) and if(globalReturnsFalse())
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#ifdef _WIN32
#define OPEN _wopen
#define CLOSE _close
#define TMPNAM _wtmpnam
#define O_RDWR _O_RDWR
#define O_CREAT _O_CREAT
#define O_EXCL _O_EXCL
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE
#else
#define OPEN open
#define CLOSE close
#define TMPNAM tmpnam
#endif


void CWE377_Insecure_Temporary_File__wchar_t_tmpnam_11_bad()
{
    if(globalReturnsTrue())
    {
        {
            wchar_t * filename;
            int fileDesc;
            filename = TMPNAM(NULL);
            if (filename == NULL)
            {
                exit(1);
            }
            printWLine(filename);
            /* FLAW: Open a temporary file using open() and flags that do not prevent a race condition */
            fileDesc = OPEN(filename, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
            if (fileDesc != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fileDesc);
            }
        }
    }
}



/* good1() uses if(globalReturnsFalse()) instead of if(globalReturnsTrue()) */
static void good1()
{
    if(globalReturnsFalse())
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            wchar_t * filename;
            int fileDesc;
            filename = TMPNAM(NULL);
            if (filename == NULL)
            {
                exit(1);
            }
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fileDesc = OPEN(filename, O_RDWR|O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fileDesc != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fileDesc);
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(globalReturnsTrue())
    {
        {
            wchar_t * filename;
            int fileDesc;
            filename = TMPNAM(NULL);
            if (filename == NULL)
            {
                exit(1);
            }
            printWLine(filename);
            /* FIX: Open a temporary file using open() and the O_CREAT and O_EXCL flags
             * NOTE: This is not a perfect solution, but it is the base case scenario */
            fileDesc = OPEN(filename, O_RDWR|O_CREAT|O_EXCL, S_IREAD|S_IWRITE);
            if (fileDesc != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fileDesc);
            }
        }
    }
}

void CWE377_Insecure_Temporary_File__wchar_t_tmpnam_11_good()
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
    CWE377_Insecure_Temporary_File__wchar_t_tmpnam_11_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__wchar_t_tmpnam_11_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
