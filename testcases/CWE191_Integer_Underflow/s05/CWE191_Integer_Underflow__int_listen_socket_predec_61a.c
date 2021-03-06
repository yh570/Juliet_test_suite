/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE191_Integer_Underflow__int_listen_socket_predec_61a.c
Label Definition File: CWE191_Integer_Underflow__int.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 191 Integer Underflow
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Set data to a small, non-zero number (negative two)
 * Sinks: decrement
 *    GoodSink: Ensure there will not be an underflow before decrementing data
 *    BadSink : Decrement data, which can cause an Underflow
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
#define CLOSE_SOCKET closesocket
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5
#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)


/* bad function declaration */
int CWE191_Integer_Underflow__int_listen_socket_predec_61b_badSource(int data);

void CWE191_Integer_Underflow__int_listen_socket_predec_61_bad()
{
    int data;
    /* Initialize data */
    data = 0;
    data = CWE191_Integer_Underflow__int_listen_socket_predec_61b_badSource(data);
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        --data;
        int result = data;
        printIntLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
int CWE191_Integer_Underflow__int_listen_socket_predec_61b_goodG2BSource(int data);

static void goodG2B()
{
    int data;
    /* Initialize data */
    data = 0;
    data = CWE191_Integer_Underflow__int_listen_socket_predec_61b_goodG2BSource(data);
    {
        /* POTENTIAL FLAW: Decrementing data could cause an underflow */
        --data;
        int result = data;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
int CWE191_Integer_Underflow__int_listen_socket_predec_61b_goodB2GSource(int data);

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = 0;
    data = CWE191_Integer_Underflow__int_listen_socket_predec_61b_goodB2GSource(data);
    /* FIX: Add a check to prevent an underflow from occurring */
    if (data > INT_MIN)
    {
        --data;
        int result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

void CWE191_Integer_Underflow__int_listen_socket_predec_61_good()
{
    goodG2B();
    goodB2G();
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
    CWE191_Integer_Underflow__int_listen_socket_predec_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE191_Integer_Underflow__int_listen_socket_predec_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
