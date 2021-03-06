/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__freopen_w32_close_34.c
Label Definition File: CWE404_Improper_Resource_Shutdown.label.xml
Template File: source-sinks-34.tmpl.c
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource: freopen Open a file using freopen()
 * Sinks: w32_close
 *    GoodSink: Close the file using fclose()
 *    BadSink : Close the file using close()
 * Flow Variant: 34 Data flow: use of a union containing two methods of accessing the same data (within the same function)
 *
 * */

#include "std_testcase.h"

typedef union
{
    FILE * unionFirst;
    FILE * unionSecond;
} CWE404_Improper_Resource_Shutdown__freopen_w32_close_34_unionType;


void CWE404_Improper_Resource_Shutdown__freopen_w32_close_34_bad()
{
    FILE * data;
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_34_unionType myUnion;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    myUnion.unionFirst = data;
    {
        FILE * data = myUnion.unionSecond;
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
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_34_unionType myUnion;
    /* Initialize data */
    data = NULL;
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = freopen("BadSource_freopen.txt","w+",stdin);
    myUnion.unionFirst = data;
    {
        FILE * data = myUnion.unionSecond;
        if (data != NULL)
        {
            /* FIX: Close the file using fclose() */
            fclose(data);
        }
    }
}

void CWE404_Improper_Resource_Shutdown__freopen_w32_close_34_good()
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
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_34_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE404_Improper_Resource_Shutdown__freopen_w32_close_34_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
