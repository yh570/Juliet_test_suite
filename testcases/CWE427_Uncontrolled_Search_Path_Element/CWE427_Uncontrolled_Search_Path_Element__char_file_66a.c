/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE427_Uncontrolled_Search_Path_Element__char_file_66a.c
Label Definition File: CWE427_Uncontrolled_Search_Path_Element.label.xml
Template File: sources-sink-66a.tmpl.c
*/
/*
 * @description
 * CWE: 427 Uncontrolled Search Path Element
 * BadSource: file Read input from a file
 * GoodSource: Use a hardcoded path
 * Sinks:
 *    BadSink : Set the environment variable
 * Flow Variant: 66 Data flow: data passed in an array from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>
#ifdef _WIN32
#define NEW_PATH "%SystemRoot%\\system32"
#define PUTENV _putenv
#else
#define NEW_PATH "/bin"
#define PUTENV putenv
#endif

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif


/* bad function declaration */
void CWE427_Uncontrolled_Search_Path_Element__char_file_66b_badSink(char * dataArray[]);

void CWE427_Uncontrolled_Search_Path_Element__char_file_66_bad()
{
    char * data;
    char * dataArray[5];
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    {
        /* Read input from a file */
        size_t dataLen = strlen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (250-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgets(data+dataLen, (int)(250-dataLen), pFile) == NULL)
                {
                    printLine("fgets() failed");
                    /* Restore NUL terminator if fgets fails */
                    data[dataLen] = '\0';
                }
                fclose(pFile);
            }
        }
    }
    /* put data in array */
    dataArray[2] = data;
    CWE427_Uncontrolled_Search_Path_Element__char_file_66b_badSink(dataArray);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE427_Uncontrolled_Search_Path_Element__char_file_66b_goodG2BSink(char * dataArray[]);

static void goodG2B()
{
    char * data;
    char * dataArray[5];
    char dataBuffer[250] = "PATH=";
    data = dataBuffer;
    /* FIX: Set the path as the "system" path */
    strcat(data, NEW_PATH);
    dataArray[2] = data;
    CWE427_Uncontrolled_Search_Path_Element__char_file_66b_goodG2BSink(dataArray);
}

void CWE427_Uncontrolled_Search_Path_Element__char_file_66_good()
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
    CWE427_Uncontrolled_Search_Path_Element__char_file_66_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE427_Uncontrolled_Search_Path_Element__char_file_66_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
