/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_04.c
Label Definition File: CWE273_Improper_Check_for_Dropped_Privileges__w32.label.xml
Template File: point-flaw-04.tmpl.c
*/
/*
 * @description
 * CWE: 273 Improper Check for Dropped Privileges
 * Sinks: RpcImpersonateClient
 *    GoodSink: Check the return value of RpcImpersonateClient() and handle it properly
 *    BadSink : Do not check if RpcImpersonateClient() fails
 * Flow Variant: 04 Control flow: if(STATIC_CONST_TRUE) and if(STATIC_CONST_FALSE)
 *
 * */

#include "std_testcase.h"

#include <windows.h>

#include <rpcdce.h>
# pragma comment(lib, "rpcrt4")

/* The two variables below are declared "const", so a tool should
   be able to identify that reads of these will always return their
   initialized values. */
static const int STATIC_CONST_TRUE = 1; /* true */
static const int STATIC_CONST_FALSE = 0; /* false */


void CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_04_bad()
{
    if(STATIC_CONST_TRUE)
    {
        RpcImpersonateClient(0);
        /* FLAW: Do not check if RpcImpersonateClient() fails */
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
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
        /* FIX: Check the return value of RpcImpersonateClient() for RPC_S_OK */
        if (RpcImpersonateClient(0) != RPC_S_OK)
        {
            exit(1);
        }
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(STATIC_CONST_TRUE)
    {
        /* FIX: Check the return value of RpcImpersonateClient() for RPC_S_OK */
        if (RpcImpersonateClient(0) != RPC_S_OK)
        {
            exit(1);
        }
        /* We'll leave out most of the implementation since it has nothing to do with the CWE
         * and since the checkers are looking for certain function calls anyway */
    }
}

void CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_04_good()
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
    CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_04_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE273_Improper_Check_for_Dropped_Privileges__w32_RpcImpersonateClient_04_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
