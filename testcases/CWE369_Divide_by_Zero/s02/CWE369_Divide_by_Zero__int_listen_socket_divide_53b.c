/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_listen_socket_divide_53b.c
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-53b.tmpl.c
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Non-zero
 * Sinks: divide
 *    GoodSink: Check for zero before dividing
 *    BadSink : Divide a constant by data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
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
void CWE369_Divide_by_Zero__int_listen_socket_divide_53c_badSink(int data);

void CWE369_Divide_by_Zero__int_listen_socket_divide_53b_badSink(int data)
{
    CWE369_Divide_by_Zero__int_listen_socket_divide_53c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE369_Divide_by_Zero__int_listen_socket_divide_53c_goodG2BSink(int data);

void CWE369_Divide_by_Zero__int_listen_socket_divide_53b_goodG2BSink(int data)
{
    CWE369_Divide_by_Zero__int_listen_socket_divide_53c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE369_Divide_by_Zero__int_listen_socket_divide_53c_goodB2GSink(int data);

void CWE369_Divide_by_Zero__int_listen_socket_divide_53b_goodB2GSink(int data)
{
    CWE369_Divide_by_Zero__int_listen_socket_divide_53c_goodB2GSink(data);
}

