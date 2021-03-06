/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE675_Duplicate_Operations_on_Resource__open_53a.c
Label Definition File: CWE675_Duplicate_Operations_on_Resource__open.label.xml
Template File: sources-sinks-53a.tmpl.c
*/
/*
 * @description
 * CWE: 675 Duplicate Operations on Resource
 * BadSource:  Open and close a file using open() and close()
 * GoodSource: Open a file using open()
 * Sinks:
 *    GoodSink: Do nothing
 *    BadSink : Close the file
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
# define OPEN _open
# define CLOSE _close
#else
#include <unistd.h>
# define OPEN open
# define CLOSE close
#endif


/* bad function declaration */
void CWE675_Duplicate_Operations_on_Resource__open_53b_badSink(int data);

void CWE675_Duplicate_Operations_on_Resource__open_53_bad()
{
    int data;
    data = -1; /* Initialize data */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* POTENTIAL FLAW: Close the file in the source */
    CLOSE(data);
    CWE675_Duplicate_Operations_on_Resource__open_53b_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE675_Duplicate_Operations_on_Resource__open_53b_goodG2BSink(int data);

static void goodG2B()
{
    int data;
    data = -1; /* Initialize data */
    /* FIX: Open, but do not close the file in the source */
    data = OPEN("GoodSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE675_Duplicate_Operations_on_Resource__open_53b_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE675_Duplicate_Operations_on_Resource__open_53b_goodB2GSink(int data);

static void goodB2G()
{
    int data;
    data = -1; /* Initialize data */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    /* POTENTIAL FLAW: Close the file in the source */
    CLOSE(data);
    CWE675_Duplicate_Operations_on_Resource__open_53b_goodB2GSink(data);
}

void CWE675_Duplicate_Operations_on_Resource__open_53_good()
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
    CWE675_Duplicate_Operations_on_Resource__open_53_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE675_Duplicate_Operations_on_Resource__open_53_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
