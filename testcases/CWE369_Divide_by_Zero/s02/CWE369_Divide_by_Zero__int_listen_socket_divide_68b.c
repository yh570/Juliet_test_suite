/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_listen_socket_divide_68b.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Non-zero
 * Sinks: divide
 *    GoodSink: Check for zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
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

extern int CWE369_Divide_by_Zero__int_listen_socket_divide_68_badData;
extern int CWE369_Divide_by_Zero__int_listen_socket_divide_68_goodG2BData;
extern int CWE369_Divide_by_Zero__int_listen_socket_divide_68_goodB2GData;


void CWE369_Divide_by_Zero__int_listen_socket_divide_68b_badSink()
{
    int data = CWE369_Divide_by_Zero__int_listen_socket_divide_68_badData;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__int_listen_socket_divide_68b_goodG2BSink()
{
    int data = CWE369_Divide_by_Zero__int_listen_socket_divide_68_goodG2BData;
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 / data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__int_listen_socket_divide_68b_goodB2GSink()
{
    int data = CWE369_Divide_by_Zero__int_listen_socket_divide_68_goodB2GData;
    /* FIX: test for a zero denominator */
    if( data != 0 )
    {
        printIntLine(100 / data);
    }
    else
    {
        printLine("This would result in a divide by zero");
    }
}

