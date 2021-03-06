/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__fopen_w32_close_32.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: fopen Open a file using fopen()
 * Sinks: w32_close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 32 Data flow: two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"


void CWE404_Improper_Resource_Shutdown__fopen_w32_close_32_bad()
{
    FILE * data;
    FILE * *dataPtr1 = &data;
    FILE * *dataPtr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        FILE * data = *dataPtr1;
        /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
        data = fopen("BadSource_fopen.txt", "w+");
        *dataPtr1 = data;
    }
    {
        FILE * data = *dataPtr2;
        if (data != NULL)
        {
            /* FLAW: Attempt to close the file using close() instead of fclose() */
            _close((int)data);
        }
    }
}



/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    FILE * *dataPtr1 = &data;
    FILE * *dataPtr2 = &data;
    /* Initialize data */
    data = NULL;
    {
        FILE * data = *dataPtr1;
        /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
        data = fopen("BadSource_fopen.txt", "w+");
        *dataPtr1 = data;
    }
    {
        FILE * data = *dataPtr2;
        if (data != NULL)
        {
            /* FIX: Close the file using fclose() */
            fclose(data);
        }
    }
}

void CWE404_Improper_Resource_Shutdown__fopen_w32_close_32_good()
{
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
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__fopen_w32_close_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
