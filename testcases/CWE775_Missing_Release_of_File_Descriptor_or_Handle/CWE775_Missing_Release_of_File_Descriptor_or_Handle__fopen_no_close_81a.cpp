/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81a.cpp
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-81a.tmpl.cpp
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */

#include "std_testcase.h"
#include "CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81.h"

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81
{


void bad()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = fopen("BadSource_fopen.txt", "w+");
    const CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81_base& baseObject = CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81_bad();
    baseObject.action(data);
}



/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Open a file without closing it */
    data = fopen("BadSource_fopen.txt", "w+");
    const CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81_base& baseObject = CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81_goodB2G();
    baseObject.action(data);
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

using namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_81; /* so that we can use good and bad easily */

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
