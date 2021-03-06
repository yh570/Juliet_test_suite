/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_52b.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-52b.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sink:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

#pragma comment(lib, "advapi32.lib")

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_52c_badSink(char * password);

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_52b_badSink(char * password)
{
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_52c_badSink(password);
}



/* good function declaration */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_52c_goodG2BSink(char * password);

/* goodG2B uses the GoodSource with the BadSink */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_52b_goodG2BSink(char * password)
{
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_52c_goodG2BSink(password);
}

