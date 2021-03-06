/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE426_Untrusted_Search_Path__wchar_t_popen_52a.c
Label Definition File: CWE426_Untrusted_Search_Path.label.xml
Template File: sources-sink-52a.tmpl.c
*/
/*
 * @description
 * CWE: 426 Untrusted Search Path
 * BadSource:  Don't specify the full path in the OS command
 * GoodSource: Specify the full path in the OS command
 * Sink: popen
 *    BadSink : Execute the wpopen function
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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


/* bad function declaration */
void CWE426_Untrusted_Search_Path__wchar_t_popen_52b_badSink(wchar_t * data);

void CWE426_Untrusted_Search_Path__wchar_t_popen_52_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FLAW: the full path is not specified */
    wcscpy(data, BAD_OS_COMMAND);
    CWE426_Untrusted_Search_Path__wchar_t_popen_52b_badSink(data);
}



/* good function declaration */
void CWE426_Untrusted_Search_Path__wchar_t_popen_52b_goodG2BSink(wchar_t * data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100] = L"";
    data = dataBuffer;
    /* FIX: full path is specified */
    wcscpy(data, GOOD_OS_COMMAND);
    CWE426_Untrusted_Search_Path__wchar_t_popen_52b_goodG2BSink(data);
}

void CWE426_Untrusted_Search_Path__wchar_t_popen_52_good()
{
    goodG2B();
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
    CWE426_Untrusted_Search_Path__wchar_t_popen_52_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE426_Untrusted_Search_Path__wchar_t_popen_52_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
