/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54a.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using fopen()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54b_badSink(FILE * data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54_bad()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Create a file handle using fopen() that may not be closed properly */
    data = fopen("BadSource_fopen.txt", "w+");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54b_badSink(data);
}



/* good function declarations */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54b_goodB2GSink(FILE * data);

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    data = NULL;
    /* POTENTIAL FLAW: Create a file handle using fopen() that may not be closed properly */
    data = fopen("BadSource_fopen.txt", "w+");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54b_goodB2GSink(data);
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54_good()
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
