/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_fwrite_83_goodG2B.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-83_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 83 Data flow: data passed to class constructor and destructor by declaring the class object on the stack
 *
 * */

#include "std_testcase.h"
#include "CWE400_Resource_Exhaustion__fscanf_fwrite_83.h"

#define SENTENCE "This is the sentence we are printing to the file. "

namespace CWE400_Resource_Exhaustion__fscanf_fwrite_83
{
CWE400_Resource_Exhaustion__fscanf_fwrite_83_goodG2B::CWE400_Resource_Exhaustion__fscanf_fwrite_83_goodG2B(int countCopy)
{
    count = countCopy;
    /* FIX: Use a relatively small number */
    count = 20;
}

CWE400_Resource_Exhaustion__fscanf_fwrite_83_goodG2B::~CWE400_Resource_Exhaustion__fscanf_fwrite_83_goodG2B()
{
    {
        size_t i = 0;
        FILE *pFile = NULL;
        const char *filename = "output_bad.txt";
        pFile = fopen(filename, "w+");
        if (pFile == NULL)
        {
            exit(1);
        }
        /* POTENTIAL FLAW: For loop using count as the loop variant and no validation
         * This can cause a file to become very large */
        for (i = 0; i < (size_t)count; i++)
        {
            if (strlen(SENTENCE) != fwrite(SENTENCE, sizeof(char), strlen(SENTENCE), pFile))
            {
                exit(1);
            }
        }
        if (pFile)
        {
            fclose(pFile);
        }
    }
}
}
