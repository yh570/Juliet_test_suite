/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE23_Relative_Path_Traversal__wchar_t_connect_socket_ofstream_54c.cpp
Label Definition File: CWE23_Relative_Path_Traversal.label.xml
Template File: sources-sink-54c.tmpl.cpp
*/
/*
 * @description
 * CWE: 23 Relative Path Traversal
 * BadSource: connect_socket Read data using a connect socket (client side)
 * GoodSource: Use a fixed file name
 * Sink: ofstream
 *    BadSink : Open the file named in data using ofstream::open()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define BASEPATH L"c:\\temp\\"
#else
#include <wchar.h>
#define BASEPATH L"/tmp/"
#endif

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

#include <fstream>
using namespace std;

namespace CWE23_Relative_Path_Traversal__wchar_t_connect_socket_ofstream_54
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


/* bad function declaration */
void badSink_d(wchar_t * data);

void badSink_c(wchar_t * data)
{
    badSink_d(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_d(wchar_t * data);

void goodG2BSink_c(wchar_t * data)
{
    goodG2BSink_d(data);
}


} /* close namespace */
