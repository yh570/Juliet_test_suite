/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__wchar_t_popen_22a.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sink: popen
 *    BadSink : Execute the wpopen function
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define BAD_OS_COMMAND L"cmd.exe /c dir"

/* REVIEWERS NOTE:
 * This hard-coded path is probably incorrect for Windows systems, as it will
 * function improperly on 9x/NT/2K, possibly on XP+ systems upgraded from 2K,
 * and could introduce code execution vulnerabilities on Windows systems that
 * have a system drive on an alternate drive letter (e.g., d:\windows)
 */
#define GOOD_OS_COMMAND L"c:\\windows\\system32\\cmd.exe /c dir"
#else /* NOT _WIN32 */
#define BAD_OS_COMMAND L"ls -la"
#define GOOD_OS_COMMAND L"/usr/bin/ls -la"
#endif /* end NOT _WIN32 */

#ifdef _WIN32
#define POPEN _wpopen
#define PCLOSE _pclose
#else /* NOT _WIN32 */
#define POPEN popen
#define PCLOSE pclose
#endif


/* The global variable below is used to drive control flow in the source function */
int CWE426_Untrusted_Search_Path__wchar_t_popen_22_badGlobal = 0;

wchar_t * CWE426_Untrusted_Search_Path__wchar_t_popen_22_badSource(wchar_t * data);

void CWE426_Untrusted_Search_Path__wchar_t_popen_22_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    CWE426_Untrusted_Search_Path__wchar_t_popen_22_badGlobal = 1; /* true */
    data = CWE426_Untrusted_Search_Path__wchar_t_popen_22_badSource(data);
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Executing the wpopen() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        pipe = POPEN(data, L"wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}



/* The global variables below are used to drive control flow in the source functions. */
int CWE426_Untrusted_Search_Path__wchar_t_popen_22_goodG2B1Global = 0;
int CWE426_Untrusted_Search_Path__wchar_t_popen_22_goodG2B2Global = 0;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
wchar_t * CWE426_Untrusted_Search_Path__wchar_t_popen_22_goodG2B1Source(wchar_t * data);

static void goodG2B1()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    CWE426_Untrusted_Search_Path__wchar_t_popen_22_goodG2B1Global = 0; /* false */
    data = CWE426_Untrusted_Search_Path__wchar_t_popen_22_goodG2B1Source(data);
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Executing the wpopen() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        pipe = POPEN(data, L"wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
wchar_t * CWE426_Untrusted_Search_Path__wchar_t_popen_22_goodG2B2Source(wchar_t * data);

static void goodG2B2()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    CWE426_Untrusted_Search_Path__wchar_t_popen_22_goodG2B2Global = 1; /* true */
    data = CWE426_Untrusted_Search_Path__wchar_t_popen_22_goodG2B2Source(data);
    {
        FILE *pipe;
        /* POTENTIAL FLAW: Executing the wpopen() function without specifying the full path to the executable
         * can allow an attacker to run their own program */
        pipe = POPEN(data, L"wb");
        if (pipe != NULL)
        {
            PCLOSE(pipe);
        }
    }
}

void CWE426_Untrusted_Search_Path__wchar_t_popen_22_good()
{
    goodG2B1();
    goodG2B2();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE426_Untrusted_Search_Path__wchar_t_popen_22_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE426_Untrusted_Search_Path__wchar_t_popen_22_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
