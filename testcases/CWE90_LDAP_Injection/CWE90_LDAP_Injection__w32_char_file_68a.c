/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_file_68a.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

char * CWE90_LDAP_Injection__w32_char_file_68_badData;
char * CWE90_LDAP_Injection__w32_char_file_68_goodG2BData;


/* bad function declaration */
void CWE90_LDAP_Injection__w32_char_file_68b_badSink();

void CWE90_LDAP_Injection__w32_char_file_68_bad()
{
    char * data;
    char dataBuffer[256] = "";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (256-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgets(data+dataLen, (int)(256-dataLen), pFile) == NULL)
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
                fclose(pFile);
            }
        }
    }
    CWE90_LDAP_Injection__w32_char_file_68_badData = data;
    CWE90_LDAP_Injection__w32_char_file_68b_badSink();
}



/* good function declarations */
void CWE90_LDAP_Injection__w32_char_file_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char dataBuffer[256] = "";
    data = dataBuffer;
    /* FIX: Use a fixed file name */
    strcat(data, "Doe, XXXXX");
    CWE90_LDAP_Injection__w32_char_file_68_goodG2BData = data;
    CWE90_LDAP_Injection__w32_char_file_68b_goodG2BSink();
}

void CWE90_LDAP_Injection__w32_char_file_68_good()
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
    CWE90_LDAP_Injection__w32_char_file_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE90_LDAP_Injection__w32_char_file_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
