/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__listen_socket_sleep_05.c
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-05.tmpl.c
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Assign count to be a relatively small number
 * Sinks: sleep
 *    GoodSink: Validate count before using it as a parameter in sleep function
 *    BadSink : Use count as the parameter for sleep withhout checking it's size first
 * Flow Variant: 05 Control flow: if(staticTrue) and if(staticFalse)
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
#define CHAR_ARRAY_SIZE (3 * sizeof(count) + 2)

#ifdef _WIN32
#define SLEEP Sleep
#else
#define SLEEP usleep
#endif

/* The two variables below are not defined as "const", but are never
   assigned any other value, so a tool should be able to identify that
   reads of these will always return their initialized values. */
static int staticTrue = 1; /* true */
static int staticFalse = 0; /* false */


void CWE400_Resource_Exhaustion__listen_socket_sleep_05_bad()
{
    int count;
    /* Initialize count */
    count = -1;
    if(staticTrue)
    {
        {
#ifdef _WIN32
            WSADATA wsaData;
            int wsaDataInit = 0;
#endif
            int recvResult;
            struct sockaddr_in service;
            SOCKET listenSocket = INVALID_SOCKET;
            SOCKET acceptSocket = INVALID_SOCKET;
            char inputBuffer[CHAR_ARRAY_SIZE];
            do
            {
#ifdef _WIN32
                if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
                {
                    break;
                }
                wsaDataInit = 1;
#endif
                /* POTENTIAL FLAW: Read count using a listen socket */
                listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (listenSocket == INVALID_SOCKET)
                {
                    break;
                }
                memset(&service, 0, sizeof(service));
                service.sin_family = AF_INET;
                service.sin_addr.s_addr = INADDR_ANY;
                service.sin_port = htons(TCP_PORT);
                if (bind(listenSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
                {
                    break;
                }
                if (listen(listenSocket, LISTEN_BACKLOG) == SOCKET_ERROR)
                {
                    break;
                }
                acceptSocket = accept(listenSocket, NULL, NULL);
                if (acceptSocket == SOCKET_ERROR)
                {
                    break;
                }
                /* Abort on error or the connection was closed */
                recvResult = recv(acceptSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0);
                if (recvResult == SOCKET_ERROR || recvResult == 0)
                {
                    break;
                }
                /* NUL-terminate the string */
                inputBuffer[recvResult] = '\0';
                /* Convert to int */
                count = atoi(inputBuffer);
            }
            while (0);
            if (listenSocket != INVALID_SOCKET)
            {
                CLOSE_SOCKET(listenSocket);
            }
            if (acceptSocket != INVALID_SOCKET)
            {
                CLOSE_SOCKET(acceptSocket);
            }
#ifdef _WIN32
            if (wsaDataInit)
            {
                WSACleanup();
            }
#endif
        }
    }
    if(staticTrue)
    {
        /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
        SLEEP(count);
        printLine("Sleep time possibly too long");
    }
}



/* goodB2G1() - use badsource and goodsink by changing the second staticTrue to staticFalse */
static void goodB2G1()
{
    int count;
    /* Initialize count */
    count = -1;
    if(staticTrue)
    {
        {
#ifdef _WIN32
            WSADATA wsaData;
            int wsaDataInit = 0;
#endif
            int recvResult;
            struct sockaddr_in service;
            SOCKET listenSocket = INVALID_SOCKET;
            SOCKET acceptSocket = INVALID_SOCKET;
            char inputBuffer[CHAR_ARRAY_SIZE];
            do
            {
#ifdef _WIN32
                if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
                {
                    break;
                }
                wsaDataInit = 1;
#endif
                /* POTENTIAL FLAW: Read count using a listen socket */
                listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (listenSocket == INVALID_SOCKET)
                {
                    break;
                }
                memset(&service, 0, sizeof(service));
                service.sin_family = AF_INET;
                service.sin_addr.s_addr = INADDR_ANY;
                service.sin_port = htons(TCP_PORT);
                if (bind(listenSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
                {
                    break;
                }
                if (listen(listenSocket, LISTEN_BACKLOG) == SOCKET_ERROR)
                {
                    break;
                }
                acceptSocket = accept(listenSocket, NULL, NULL);
                if (acceptSocket == SOCKET_ERROR)
                {
                    break;
                }
                /* Abort on error or the connection was closed */
                recvResult = recv(acceptSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0);
                if (recvResult == SOCKET_ERROR || recvResult == 0)
                {
                    break;
                }
                /* NUL-terminate the string */
                inputBuffer[recvResult] = '\0';
                /* Convert to int */
                count = atoi(inputBuffer);
            }
            while (0);
            if (listenSocket != INVALID_SOCKET)
            {
                CLOSE_SOCKET(listenSocket);
            }
            if (acceptSocket != INVALID_SOCKET)
            {
                CLOSE_SOCKET(acceptSocket);
            }
#ifdef _WIN32
            if (wsaDataInit)
            {
                WSACleanup();
            }
#endif
        }
    }
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Validate count before using it as a parameter in the sleep function */
        if (count > 0 && count <= 2000)
        {
            SLEEP(count);
            printLine("Sleep time OK");
        }
        else
        {
            printLine("Sleep time too long");
        }
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int count;
    /* Initialize count */
    count = -1;
    if(staticTrue)
    {
        {
#ifdef _WIN32
            WSADATA wsaData;
            int wsaDataInit = 0;
#endif
            int recvResult;
            struct sockaddr_in service;
            SOCKET listenSocket = INVALID_SOCKET;
            SOCKET acceptSocket = INVALID_SOCKET;
            char inputBuffer[CHAR_ARRAY_SIZE];
            do
            {
#ifdef _WIN32
                if (WSAStartup(MAKEWORD(2,2), &wsaData) != NO_ERROR)
                {
                    break;
                }
                wsaDataInit = 1;
#endif
                /* POTENTIAL FLAW: Read count using a listen socket */
                listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if (listenSocket == INVALID_SOCKET)
                {
                    break;
                }
                memset(&service, 0, sizeof(service));
                service.sin_family = AF_INET;
                service.sin_addr.s_addr = INADDR_ANY;
                service.sin_port = htons(TCP_PORT);
                if (bind(listenSocket, (struct sockaddr*)&service, sizeof(service)) == SOCKET_ERROR)
                {
                    break;
                }
                if (listen(listenSocket, LISTEN_BACKLOG) == SOCKET_ERROR)
                {
                    break;
                }
                acceptSocket = accept(listenSocket, NULL, NULL);
                if (acceptSocket == SOCKET_ERROR)
                {
                    break;
                }
                /* Abort on error or the connection was closed */
                recvResult = recv(acceptSocket, inputBuffer, CHAR_ARRAY_SIZE - 1, 0);
                if (recvResult == SOCKET_ERROR || recvResult == 0)
                {
                    break;
                }
                /* NUL-terminate the string */
                inputBuffer[recvResult] = '\0';
                /* Convert to int */
                count = atoi(inputBuffer);
            }
            while (0);
            if (listenSocket != INVALID_SOCKET)
            {
                CLOSE_SOCKET(listenSocket);
            }
            if (acceptSocket != INVALID_SOCKET)
            {
                CLOSE_SOCKET(acceptSocket);
            }
#ifdef _WIN32
            if (wsaDataInit)
            {
                WSACleanup();
            }
#endif
        }
    }
    if(staticTrue)
    {
        /* FIX: Validate count before using it as a parameter in the sleep function */
        if (count > 0 && count <= 2000)
        {
            SLEEP(count);
            printLine("Sleep time OK");
        }
        else
        {
            printLine("Sleep time too long");
        }
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first staticTrue to staticFalse */
static void goodG2B1()
{
    int count;
    /* Initialize count */
    count = -1;
    if(staticFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use a relatively small number */
        count = 20;
    }
    if(staticTrue)
    {
        /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
        SLEEP(count);
        printLine("Sleep time possibly too long");
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int count;
    /* Initialize count */
    count = -1;
    if(staticTrue)
    {
        /* FIX: Use a relatively small number */
        count = 20;
    }
    if(staticTrue)
    {
        /* POTENTIAL FLAW: Sleep function using count as the parameter with no validation */
        SLEEP(count);
        printLine("Sleep time possibly too long");
    }
}

void CWE400_Resource_Exhaustion__listen_socket_sleep_05_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
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
    CWE400_Resource_Exhaustion__listen_socket_sleep_05_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE400_Resource_Exhaustion__listen_socket_sleep_05_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
