/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68a.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using fopen()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

FILE * CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_badDataForBadSink;

FILE * CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_badDataForGoodSink;


/* bad function declaration */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b_badSink();

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_bad()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Create a file handle using fopen() that may not be closed properly */
    data = fopen("BadSource_fopen.txt", "w+");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_badDataForBadSink = data;
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b_badSink();
}



/* good function declarations */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b_goodB2GSink();

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Create a file handle using fopen() that may not be closed properly */
    data = fopen("BadSource_fopen.txt", "w+");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_badDataForGoodSink = data;
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68b_goodB2GSink();
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_good()
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
