/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__rand_fwrite_82_goodB2G.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-82_goodB2G.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE400_Resource_Exhaustion__rand_fwrite_82.h"

#define SENTENCE "This is the sentence we are printing to the file. "

namespace CWE400_Resource_Exhaustion__rand_fwrite_82
{

void CWE400_Resource_Exhaustion__rand_fwrite_82_goodB2G::action(int count)
{
    {
        size_t i = 0;
        FILE *pFile = NULL;
        const char *filename = "output_good.txt";
        /* FIX: Validate count before using it as the for loop variant to write to a file */
        if (count > 0 && count <= 20)
        {
            pFile = fopen(filename, "w+");
            if (pFile == NULL)
            {
                exit(1);
            }
            for (i = 0; i < (size_t)count; i++)
            {
                if (strlen(SENTENCE) != fwrite(SENTENCE, sizeof(char), strlen(SENTENCE), pFile)) exit(1);
            }
            if (pFile)
            {
                fclose(pFile);
            }
        }
    }
}

}
