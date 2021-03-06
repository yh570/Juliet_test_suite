/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE259_Hard_Coded_Password__w32_char_67a.c
Label Definition File: CWE259_Hard_Coded_Password__w32.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 259 Use of Hard-coded Password
 * BadSource:  Use a hardcoded password
 * GoodSource: Read the password from the console
 * Sinks:
 *    BadSink : Authenticate the user using LogonUserA()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define PASSWORD "ABCD1234!"

#include <windows.h>
#pragma comment(lib, "advapi32.lib")

typedef struct _CWE259_Hard_Coded_Password__w32_char_67_structType
{
    char * structFirst;
} CWE259_Hard_Coded_Password__w32_char_67_structType;


/* bad function declaration */
void CWE259_Hard_Coded_Password__w32_char_67b_badSink(CWE259_Hard_Coded_Password__w32_char_67_structType myStruct);

void CWE259_Hard_Coded_Password__w32_char_67_bad()
{
    char * password;
    CWE259_Hard_Coded_Password__w32_char_67_structType myStruct;
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    /* FLAW: Use a hardcoded password */
    strcpy(password, PASSWORD);
    myStruct.structFirst = password;
    CWE259_Hard_Coded_Password__w32_char_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE259_Hard_Coded_Password__w32_char_67b_goodG2BSink(CWE259_Hard_Coded_Password__w32_char_67_structType myStruct);

static void goodG2B()
{
    char * password;
    CWE259_Hard_Coded_Password__w32_char_67_structType myStruct;
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    {
        size_t passwordLen = 0;
        /* FIX: Read the password from the console */
        if (fgets(password, 100, stdin) == NULL)
        {
            printLine("fgets() failed");
            /* Restore NUL terminator if fgets fails */
            password[0] = '\0';
        }
        /* Remove the carriage return from the string that is inserted by fgets() */
        passwordLen = strlen(password);
        if (passwordLen > 0)
        {
            password[passwordLen-1] = '\0';
        }
    }
    myStruct.structFirst = password;
    CWE259_Hard_Coded_Password__w32_char_67b_goodG2BSink(myStruct);
}

void CWE259_Hard_Coded_Password__w32_char_67_good()
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
    CWE259_Hard_Coded_Password__w32_char_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE259_Hard_Coded_Password__w32_char_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
