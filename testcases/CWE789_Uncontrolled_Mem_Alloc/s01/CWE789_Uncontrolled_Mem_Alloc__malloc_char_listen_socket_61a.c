/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61a.c
Label Definition File: CWE789_Uncontrolled_Mem_Alloc__malloc.label.xml
Template File: sources-sinks-61a.tmpl.c
*/
/*
 * @description
 * CWE: 789 Uncontrolled Memory Allocation
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Small number greater than zero
 * Sinks:
 *    GoodSink: Allocate memory with malloc() and check the size of the memory to be allocated
 *    BadSink : Allocate memory with malloc(), but incorrectly check the size of the memory to be allocated
 * Flow Variant: 61 Data flow: data returned from one function to another in different source files
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
#define CHAR_ARRAY_SIZE (3 * sizeof(data) + 2)

#define HELLO_STRING "hello"


/* bad function declaration */
size_t CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61b_badSource(size_t data);

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61_bad()
{
    size_t data;
    /* Initialize data */
    data = 0;
    data = CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61b_badSource(data);
    {
        char * myString;
        /* POTENTIAL FLAW: No MAXIMUM limitation for memory allocation, but ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > strlen(HELLO_STRING))
        {
            myString = (char *)malloc(data*sizeof(char));
            if (myString == NULL) {exit(-1);}
            /* Copy a small string into myString */
            strcpy(myString, HELLO_STRING);
            printLine(myString);
            free(myString);
        }
        else
        {
            printLine("Input is less than the length of the source string");
        }
    }
}



/* goodG2B uses the GoodSource with the BadSink */
size_t CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61b_goodG2BSource(size_t data);

static void goodG2B()
{
    size_t data;
    /* Initialize data */
    data = 0;
    data = CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61b_goodG2BSource(data);
    {
        char * myString;
        /* POTENTIAL FLAW: No MAXIMUM limitation for memory allocation, but ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > strlen(HELLO_STRING))
        {
            myString = (char *)malloc(data*sizeof(char));
            if (myString == NULL) {exit(-1);}
            /* Copy a small string into myString */
            strcpy(myString, HELLO_STRING);
            printLine(myString);
            free(myString);
        }
        else
        {
            printLine("Input is less than the length of the source string");
        }
    }
}

/* goodB2G uses the BadSource with the GoodSink */
size_t CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61b_goodB2GSource(size_t data);

static void goodB2G()
{
    size_t data;
    /* Initialize data */
    data = 0;
    data = CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61b_goodB2GSource(data);
    {
        char * myString;
        /* FIX: Include a MAXIMUM limitation for memory allocation and a check to ensure data is large enough
         * for the strcpy() function to not cause a buffer overflow */
        /* INCIDENTAL FLAW: The source could cause a type overrun in data or in the memory allocation */
        if (data > strlen(HELLO_STRING) && data < 100)
        {
            myString = (char *)malloc(data*sizeof(char));
            if (myString == NULL) {exit(-1);}
            /* Copy a small string into myString */
            strcpy(myString, HELLO_STRING);
            printLine(myString);
            free(myString);
        }
        else
        {
            printLine("Input is less than the length of the source string or too large");
        }
    }
}

void CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61_good()
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
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE789_Uncontrolled_Mem_Alloc__malloc_char_listen_socket_61_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
