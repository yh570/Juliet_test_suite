/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__char_w32GetTempFileName_09.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-09.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: w32GetTempFileName
 *    GoodSink: Create and open a temporary file, created with GetTempFileNameA(), more securely
 *    BadSink : Create and open a temporary file, created with GetTempFileNameA(), insecurely
 * Flow Variant: 09 Control flow: if(GLOBAL_CONST_TRUE) and if(GLOBAL_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#include <windows.h>

#define OPEN _open
#define CLOSE _close
#define O_RDWR _O_RDWR
#define O_CREAT _O_CREAT
#define O_EXCL _O_EXCL
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE


void CWE377_Insecure_Temporary_File__char_w32GetTempFileName_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            char filename[MAX_PATH] = "";
            int fileDesc;
            /* FLAW: Passing 0 in for uUnique tells GetTempFileName to create and then close the file,
            * leading to an inescapable race condition when we try to open it again. */
            if (GetTempFileNameA(".", "bad", 0, filename) == 0)
            {
                exit(1);
            }
            printLine(filename);
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



/* good1() uses if(GLOBAL_CONST_FALSE) instead of if(GLOBAL_CONST_TRUE) */
static void good1()
{
    if(GLOBAL_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char filename[MAX_PATH] = "";
            int fileDesc;
            /* FIX: Passing a non-zero value in for uUnique prevents GetTempFileName from creating
             * and then closing the file, at the cost of no longer guaranteeing the name is unique. */
            /* INCIDENTAL CWE338 Weak PRNG - use of rand() as a PRNG */
            if (GetTempFileNameA(".", "good", rand() + 1, filename) == 0)
            {
                exit(1);
            }
            printLine(filename);
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
    if(GLOBAL_CONST_TRUE)
    {
        {
            char filename[MAX_PATH] = "";
            int fileDesc;
            /* FIX: Passing a non-zero value in for uUnique prevents GetTempFileName from creating
             * and then closing the file, at the cost of no longer guaranteeing the name is unique. */
            /* INCIDENTAL CWE338 Weak PRNG - use of rand() as a PRNG */
            if (GetTempFileNameA(".", "good", rand() + 1, filename) == 0)
            {
                exit(1);
            }
            printLine(filename);
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

void CWE377_Insecure_Temporary_File__char_w32GetTempFileName_09_good()
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
    CWE377_Insecure_Temporary_File__char_w32GetTempFileName_09_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__char_w32GetTempFileName_09_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
