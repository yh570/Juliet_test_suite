/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE377_Insecure_Temporary_File__char_mktemp_04.c
Label Definition File: CWE377_Insecure_Temporary_File.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 377 Insecure Temporary File
 * Sinks: mktemp
 *    GoodSink: Create and open a temporary file more securely, with mkstemp()
 *    BadSink : Create and open a temporary file, created with mktemp(), insecurely
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#define MKTEMP mktemp
// to run on Windows, supply a replacement for Unix mkstemp()
#define MKSTEMP _mkstemp
static int _mkstemp(const char * t){
  size_t l = strlen(t) + 1;
  char s[50];
  strncpy(s, t, l);
  return _mktemp_s(s, l) ? -1 : _open(s, _O_CREAT|_O_EXCL);
}

#define O_RDWR _O_RDWR
#define O_CREAT _O_CREAT
#define O_EXCL _O_EXCL
#define S_IREAD _S_IREAD
#define S_IWRITE _S_IWRITE
#else
#define OPEN open
#define CLOSE close
#define MKTEMP mktemp
#define MKSTEMP mkstemp
#endif

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */


void CWE377_Insecure_Temporary_File__char_mktemp_04_bad()
{
    if(STATIC_CONST_TRUE)
    {
        {
            char * filename;
            char tmpl[] = "fnXXXXXX";
            int fileDesc;
            filename = MKTEMP(tmpl);
            if (filename == NULL)
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



/* good1() uses if(STATIC_CONST_FALSE) instead of if(STATIC_CONST_TRUE) */
static void good1()
{
    if(STATIC_CONST_FALSE)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char filename[] = "/tmp/fileXXXXXX"; // mutable store for filename
            // FIX: Use mkstemp(). This is not a perfect solution, since file
            // names are too predictable, but it is a vast improvement.
            int fileDesc = MKSTEMP(filename);
            printLine(filename);
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
    if(STATIC_CONST_TRUE)
    {
        {
            char filename[] = "/tmp/fileXXXXXX"; // mutable store for filename
            // FIX: Use mkstemp(). This is not a perfect solution, since file
            // names are too predictable, but it is a vast improvement.
            int fileDesc = MKSTEMP(filename);
            printLine(filename);
            if (fileDesc != -1)
            {
                printLine("Temporary file was opened...now closing file");
                CLOSE(fileDesc);
            }
        }
    }
}

void CWE377_Insecure_Temporary_File__char_mktemp_04_good()
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
    CWE377_Insecure_Temporary_File__char_mktemp_04_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE377_Insecure_Temporary_File__char_mktemp_04_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
