/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_72a.cpp
Label Definition File: CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32.label.xml
Template File: sources-sink-72a.tmpl.cpp
*/
/*
 * @description
 * CWE: 591 Sensitive Data Storage in Improperly Locked Memory
 * BadSource:  Allocate memory for sensitive data without using VirtualLock() to lock the buffer into memory
 * GoodSource: Allocate memory for sensitive data and use VirtualLock() to lock the buffer into memory
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 72 Data flow: data passed in a vector from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <vector>

#include <wchar.h>
#include <windows.h>

using namespace std;

namespace CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_72
{


/* bad function declaration */
void badSink(vector<char *> passwordVector);

void bad()
{
    char * password;
    vector<char *> passwordVector;
    /* Initialize Data */
    password = "";
    password = (char *)malloc(100*sizeof(char));
    if (password == NULL)
    {
        printLine("Memory could not be allocated");
        exit(1);
    }
    /* FLAW: Do not lock the memory */
    /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
    strcpy(password, "Password1234!");
    /* Put password in a vector */
    passwordVector.insert(passwordVector.end(), 1, password);
    passwordVector.insert(passwordVector.end(), 1, password);
    passwordVector.insert(passwordVector.end(), 1, password);
    badSink(passwordVector);
}



/* good function declarations */

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(vector<char *> passwordVector);

static void goodG2B()
{
    char * password;
    vector<char *> passwordVector;
    /* Initialize Data */
    password = "";
    password = (char *)malloc(100*sizeof(char));
    if (password == NULL)
    {
        printLine("Memory could not be allocated");
        exit(1);
    }
    /* FIX: Use VirtualLock() to lock the buffer into memory */
    if(!VirtualLock(password, 100*sizeof(char)))
    {
        printLine("Memory could not be locked");
        exit(1);
    }
    /* INCIDENTAL FLAW: CWE-259 Hardcoded Password */
    strcpy(password, "Password1234!");
    /* Put password in a vector */
    passwordVector.insert(passwordVector.end(), 1, password);
    passwordVector.insert(passwordVector.end(), 1, password);
    passwordVector.insert(passwordVector.end(), 1, password);
    goodG2BSink(passwordVector);
}

void good()
{
    goodG2B();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

using namespace CWE591_Sensitive_Data_Storage_in_Improperly_Locked_Memory__w32_char_72; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
    return 0;
}

#endif
