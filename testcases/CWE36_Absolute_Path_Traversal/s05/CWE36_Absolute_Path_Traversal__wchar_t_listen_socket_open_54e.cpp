/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_open_54e.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-54e.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Full path and file name
 * Sink: open
 *    BadSink : Open the file named in data using open()
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

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

#ifdef _WIN32
#define OPEN _wopen
#define CLOSE _close
#else
#define OPEN open
#define CLOSE close
#endif

namespace CWE36_Absolute_Path_Traversal__wchar_t_listen_socket_open_54
{

/* all the sinks are the same, we just want to know where the hit originated if a tool flags one */


void badSink_e(wchar_t * data)
{
    {
        int fileDesc;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        fileDesc = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fileDesc != -1)
        {
            CLOSE(fileDesc);
        }
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_e(wchar_t * data)
{
    {
        int fileDesc;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        fileDesc = OPEN(data, O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
        if (fileDesc != -1)
        {
            CLOSE(fileDesc);
        }
    }
}


} /* close namespace */
