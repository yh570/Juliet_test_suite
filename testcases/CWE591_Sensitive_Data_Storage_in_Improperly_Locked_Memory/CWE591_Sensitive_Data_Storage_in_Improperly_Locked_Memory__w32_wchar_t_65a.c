/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_65a.c
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-65a.tmpl.c
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserW()
 * Flow Variant: 65 Data/control flow: data passed as an argument from one function to a function in a different source file called via a function pointer
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#include <windows.h>

#pragma comment(lib, "advapi32.lib")


/* bad function declaration */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_65b_badSink(wchar_t * password);

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_65_bad()
{
    wchar_t * password;
    /* define a function pointer */
    void (*funcPtr) (wchar_t *) = CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_65b_badSink;
    /* Initialize Data */
    password = L"";
    password = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (password == NULL)
    {
        printLine("Memory could not be allocated");
        exit(1);
    }
    /* FLAW: Do not lock the memory */
    /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
    wcscpy(password, L"Password1234!");
    /* use the function pointer */
    funcPtr(password);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_65b_goodG2BSink(wchar_t * password);

static void goodG2B()
{
    wchar_t * password;
    void (*funcPtr) (wchar_t *) = CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_65b_goodG2BSink;
    /* Initialize Data */
    password = L"";
    password = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (password == NULL)
    {
        printLine("Memory could not be allocated");
        exit(1);
    }
    /* FIX: Use VirtualLock() to lock the buffer into memory */
    if(!VirtualLock(password, 100*sizeof(wchar_t)))
    {
        printLine("Memory could not be locked");
        exit(1);
    }
    /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
    wcscpy(password, L"Password1234!");
    funcPtr(password);
}

void CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_65_good()
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
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_65_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_wchar_t_65_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
