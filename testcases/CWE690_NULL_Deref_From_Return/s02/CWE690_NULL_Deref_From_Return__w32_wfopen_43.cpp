/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE690_NULL_Deref_From_Return__w32_wfopen_43.cpp
Label Definition File: CWE690_NULL_Deref_From_Return.fclose.label.xml
Template File: source-sinks-43.tmpl.cpp
*/
/*
 * @description
 * CWE: 690 Unchecked Return Value To NULL Pointer
 * BadSource: w32_wfopen Open data with wfopen()
 * Sinks: 0
 *    GoodSink: Check data for NULL
 *    BadSink : Do not check data for NULL
 * Flow Variant: 43 Data flow: data flows using a C++ reference from one function to another in the same source file
 *
 * */

#include "std_testcase.h"

namespace CWE690_NULL_Deref_From_Return__w32_wfopen_43
{


static void badSource(FILE * &data)
{
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
}

void bad()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    badSource(data);
    /* FLAW: if the fopen failed, data will be NULL here */
    fclose(data);
}



/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2GSource(FILE * &data)
{
    /* POTENTIAL FLAW: Open a file without checking the return value for NULL */
    data = _wfopen(L"file.txt", L"w+");
}

static void goodB2G()
{
    FILE * data;
    /* Initialize data */
    data = NULL;
    goodB2GSource(data);
    /* FIX: check the return value */
    if (data != NULL)
    {
        fclose(data);
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

using namespace CWE690_NULL_Deref_From_Return__w32_wfopen_43; /* so that we can use good and bad easily */

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
