/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_wchar_t_file_63a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-63a.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed string
 * Sinks:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <windows.h>
#include <Winldap.h>

#pragma comment(lib, "wldap32")


/* bad function declaration */
void CWE90_LDAP_Injection__w32_wchar_t_file_63b_badSink(wchar_t * * dataPtr);

void CWE90_LDAP_Injection__w32_wchar_t_file_63_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[256] = L"";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (256-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgetws(data+dataLen, (int)(256-dataLen), pFile) == NULL)
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    CWE90_LDAP_Injection__w32_wchar_t_file_63b_badSink(&data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE90_LDAP_Injection__w32_wchar_t_file_63b_goodG2BSink(wchar_t * * data);

static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[256] = L"";
    data = dataBuffer;
    /* FIX: Use a fixed file name */
    wcscat(data, L"Doe, XXXXX");
    CWE90_LDAP_Injection__w32_wchar_t_file_63b_goodG2BSink(&data);
}

void CWE90_LDAP_Injection__w32_wchar_t_file_63_good()
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
    CWE90_LDAP_Injection__w32_wchar_t_file_63_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE90_LDAP_Injection__w32_wchar_t_file_63_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
