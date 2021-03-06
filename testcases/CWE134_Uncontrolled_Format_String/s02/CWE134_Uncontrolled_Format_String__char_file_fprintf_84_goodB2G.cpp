/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_file_fprintf_84_goodB2G.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-84_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: file Read input from a file
 * GoodSource: Copy a fixed string into data
 * Sinks: fprintf
 *    GoodSink: fprintf with "%s" as the second argument and data as the third
 *    BadSink : fprintf with data as the second argument
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__char_file_fprintf_84.h"

#ifdef _WIN32
#define FILENAME "C:\\temp\\A"
#else
#define FILENAME "A"
#endif

namespace CWE134_Uncontrolled_Format_String__char_file_fprintf_84
{
CWE134_Uncontrolled_Format_String__char_file_fprintf_84_goodB2G::CWE134_Uncontrolled_Format_String__char_file_fprintf_84_goodB2G(char * dataCopy)
{
    data = dataCopy;
    {
        /* Read input from a file */
        size_t dataLen = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgets(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
                fclose(pFile);
            }
        }
    }
}

CWE134_Uncontrolled_Format_String__char_file_fprintf_84_goodB2G::~CWE134_Uncontrolled_Format_String__char_file_fprintf_84_goodB2G()
{
    /* FIX: Specify the format disallowing a format string vulnerability */
    fprintf(stdout, "%s\n", data);
}
}
