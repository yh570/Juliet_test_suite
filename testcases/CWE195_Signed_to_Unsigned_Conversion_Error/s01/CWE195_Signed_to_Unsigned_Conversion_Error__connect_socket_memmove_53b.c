/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memmove_53b.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-53b.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Positive integer
 * Sink: memmove
 *    BadSink : Copy strings using memmove() with the length of data
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
#define IP_ADDRESS "127.0.0.1"
#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memmove_53c_badSink(int data);

void CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memmove_53b_badSink(int data)
{
    CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memmove_53c_badSink(data);
}



/* good function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memmove_53c_goodG2BSink(int data);

/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memmove_53b_goodG2BSink(int data)
{
    CWE195_Signed_to_Unsigned_Conversion_Error__connect_socket_memmove_53c_goodG2BSink(data);
}

