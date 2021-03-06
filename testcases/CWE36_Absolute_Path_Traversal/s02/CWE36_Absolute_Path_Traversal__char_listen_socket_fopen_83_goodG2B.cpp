/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE36_Absolute_Path_Traversal__char_listen_socket_fopen_83_goodG2B.cpp
Label Definition File: CWE36_Absolute_Path_Traversal.label.xml
Template File: sources-sink-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 36 Absolute Path Traversal
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Full path and file name
 * Sinks: fopen
 *    BadSink : Open the file named in data using fopen()
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE36_Absolute_Path_Traversal__char_listen_socket_fopen_83.h"

#ifdef _WIN32
#define FOPEN fopen
#else
#define FOPEN fopen
#endif

namespace CWE36_Absolute_Path_Traversal__char_listen_socket_fopen_83
{
CWE36_Absolute_Path_Traversal__char_listen_socket_fopen_83_goodG2B::CWE36_Absolute_Path_Traversal__char_listen_socket_fopen_83_goodG2B(char * dataCopy)
{
    data = dataCopy;
#ifdef _WIN32
    /* FIX: Use a fixed, full path and file name */
    strcat(data, "c:\\temp\\file.txt");
#else
    /* FIX: Use a fixed, full path and file name */
    strcat(data, "/tmp/file.txt");
#endif
}

CWE36_Absolute_Path_Traversal__char_listen_socket_fopen_83_goodG2B::~CWE36_Absolute_Path_Traversal__char_listen_socket_fopen_83_goodG2B()
{
    {
        FILE *pFile = NULL;
        /* POTENTIAL FLAW: Possibly opening a file without validating the file name or path */
        pFile = FOPEN(data, "wb+");
        if (pFile != NULL)
        {
            fclose(pFile);
        }
    }
}
}
