/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__int_listen_socket_square_67b.c
Label Definition File: CWE190_Integer_Overflow__int.label.xml
Template File: sources-sinks-67b.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: square
 *    GoodSink: Ensure there will not be an overflow before squaring data
 *    BadSink : Square data, which can lead to overflow
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
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

#include <math.h>

typedef struct _CWE190_Integer_Overflow__int_listen_socket_square_67_structType
{
    int structFirst;
} CWE190_Integer_Overflow__int_listen_socket_square_67_structType;


void CWE190_Integer_Overflow__int_listen_socket_square_67b_badSink(CWE190_Integer_Overflow__int_listen_socket_square_67_structType myStruct)
{
    int data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: if (data*data) > INT_MAX, this will overflow */
        int result = data * data;
        printIntLine(result);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE190_Integer_Overflow__int_listen_socket_square_67b_goodG2BSink(CWE190_Integer_Overflow__int_listen_socket_square_67_structType myStruct)
{
    int data = myStruct.structFirst;
    {
        /* POTENTIAL FLAW: if (data*data) > INT_MAX, this will overflow */
        int result = data * data;
        printIntLine(result);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE190_Integer_Overflow__int_listen_socket_square_67b_goodB2GSink(CWE190_Integer_Overflow__int_listen_socket_square_67_structType myStruct)
{
    int data = myStruct.structFirst;
    /* FIX: Add a check to prevent an overflow from occurring */
    if (data > INT_MIN && abs(data) < (long)sqrt((double)INT_MAX))
    {
        int result = data * data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}

