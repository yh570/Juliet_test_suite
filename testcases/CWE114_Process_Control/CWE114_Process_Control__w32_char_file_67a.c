/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE114_Process_Control__w32_char_file_67a.c
Label Definition File: CWE114_Process_Control__w32.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 114 Process Control
 * BadSource: file Read input from a file
 * GoodSource: Hard code the full pathname to the library
 * Sinks:
 *    BadSink : Load a dynamic link library
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#include <windows.h>

typedef struct _CWE114_Process_Control__w32_char_file_67_structType
{
    char * structFirst;
} CWE114_Process_Control__w32_char_file_67_structType;


/* bad function declaration */
void CWE114_Process_Control__w32_char_file_67b_badSink(CWE114_Process_Control__w32_char_file_67_structType myStruct);

void CWE114_Process_Control__w32_char_file_67_bad()
{
    char * data;
    CWE114_Process_Control__w32_char_file_67_structType myStruct;
    char dataBuffer[100] = "";
    data = dataBuffer;
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
    myStruct.structFirst = data;
    CWE114_Process_Control__w32_char_file_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE114_Process_Control__w32_char_file_67b_goodG2BSink(CWE114_Process_Control__w32_char_file_67_structType myStruct);

static void goodG2B()
{
    char * data;
    CWE114_Process_Control__w32_char_file_67_structType myStruct;
    char dataBuffer[100] = "";
    data = dataBuffer;
    /* FIX: Specify the full pathname for the library */
    strcpy(data, "C:\\Windows\\System32\\winsrv.dll");
    myStruct.structFirst = data;
    CWE114_Process_Control__w32_char_file_67b_goodG2BSink(myStruct);
}

void CWE114_Process_Control__w32_char_file_67_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE114_Process_Control__w32_char_file_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE114_Process_Control__w32_char_file_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
