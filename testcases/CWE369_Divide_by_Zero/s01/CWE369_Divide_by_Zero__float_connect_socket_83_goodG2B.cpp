/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__float_connect_socket_83_goodG2B.cpp
Label Definition File: CWE369_Divide_by_Zero__float.label.xml
Template File: sources-sinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: A hardcoded non-zero number (two)
 * Sinks:
 *    GoodSink: Check value of or near zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE369_Divide_by_Zero__float_connect_socket_83.h"

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#include <direct.h>
#pragma comment(lib, "ws2_32") /* include ws2_32.lib when linking */
#define CLOSE_SOCKET closesocket
#else /* NOT _WIN32 */
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
#define CHAR_ARRAY_SIZE 20
#define IP_ADDRESS "127.0.0.1"

namespace CWE369_Divide_by_Zero__float_connect_socket_83
{
CWE369_Divide_by_Zero__float_connect_socket_83_goodG2B::CWE369_Divide_by_Zero__float_connect_socket_83_goodG2B(float dataCopy)
{
    data = dataCopy;
    /* FIX: Use a hardcoded number that won't a divide by zero */
    data = 2.0F;
}

CWE369_Divide_by_Zero__float_connect_socket_83_goodG2B::~CWE369_Divide_by_Zero__float_connect_socket_83_goodG2B()
{
    {
        /* POTENTIAL FLAW: Possibly divide by zero */
        int result = (int)(100.0 / data);
        printIntLine(result);
    }
}
}
