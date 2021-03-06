/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_listen_socket_system_67b.c
Label Definition File: CWE78_OS_Command_Injection.one_string.label.xml
Template File: sources-sink-67b.tmpl.c
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Fixed string
 * Sinks: system
 *    BadSink : Execute command in data using system()
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FULL_COMMAND "dir "
#else
#include <unistd.h>
#define FULL_COMMAND "ls "
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
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define CLOSE_SOCKET close
#define SOCKET int
#endif

#define TCP_PORT 27015
#define LISTEN_BACKLOG 5

#ifdef _WIN32
#define SYSTEM system
#else /* NOT _WIN32 */
#define SYSTEM system
#endif

typedef struct _CWE78_OS_Command_Injection__char_listen_socket_system_67_structType
{
    char * structFirst;
} CWE78_OS_Command_Injection__char_listen_socket_system_67_structType;


void CWE78_OS_Command_Injection__char_listen_socket_system_67b_badSink(CWE78_OS_Command_Injection__char_listen_socket_system_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Execute command in data possibly leading to command injection */
    if (SYSTEM(data) != 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE78_OS_Command_Injection__char_listen_socket_system_67b_goodG2BSink(CWE78_OS_Command_Injection__char_listen_socket_system_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    /* POTENTIAL FLAW: Execute command in data possibly leading to command injection */
    if (SYSTEM(data) != 0)
    {
        printLine("command execution failed!");
        exit(1);
    }
}

