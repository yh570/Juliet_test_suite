/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE90_LDAP_Injection__w32_char_file_52b.c
Label Definition File: CWE90_LDAP_Injection__w32.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 90 LDAP Injection
 * BadSource: file Read input from a file
 * GoodSource: Use a fixed string
 * Sink:
 *    BadSink : data concatenated into LDAP search, which could result in LDAP Injection
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE90_LDAP_Injection__w32_char_file_52c_badSink(char * data);

void CWE90_LDAP_Injection__w32_char_file_52b_badSink(char * data)
{
    CWE90_LDAP_Injection__w32_char_file_52c_badSink(data);
}



/* good function declaration */
void CWE90_LDAP_Injection__w32_char_file_52c_goodG2BSink(char * data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE90_LDAP_Injection__w32_char_file_52b_goodG2BSink(char * data)
{
    CWE90_LDAP_Injection__w32_char_file_52c_goodG2BSink(data);
}

