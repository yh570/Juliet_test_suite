/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE404_Improper_Resource_Shutdown__open_fclose_43.cpp
Label Definition File: CWE404_Improper_Resource_Shutdown__open.label.xml
Template File: source-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 404 Improper Resource Shutdown or Release
 * BadSource:  Open a file using open()
 * Sinks: fclose
 *    GoodSink: Close the file using close()
 *    BadSink : Close the file using fclose()
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define OPEN _open
#define CLOSE _close
#else
#include <unistd.h>
#define OPEN open
#define CLOSE close
#endif

namespace CWE404_Improper_Resource_Shutdown__open_fclose_43
{


static void badSource(int &data)
{
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
}

void bad()
{
    int data;
    /* Initialize data */
    data = -1;
    badSource(data);
    if (data != -1)
    {
        /* FLAW: Attempt to close the file using fclose() instead of close() */
        fclose((FILE *)data);
    }
}



/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSource(int &data)
{
    /* POTENTIAL FLAW: Open a file - need to make sure it is closed properly in the sink */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
}

static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    goodB2GSource(data);
    if (data != -1)
    {
        /* FIX: Close the file using close() */
        CLOSE(data);
    }
}

void good()
{
    goodB2G();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE404_Improper_Resource_Shutdown__open_fclose_43; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
    return 0;
}

#endif
