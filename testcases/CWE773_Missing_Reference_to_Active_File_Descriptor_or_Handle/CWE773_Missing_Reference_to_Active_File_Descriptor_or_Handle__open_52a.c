/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52a.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open.label.xml
Template File: source-sinks-52a.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file descriptor using open()
 * Sinks:
 *    GoodSink: Close the file before reusing the file descriptor
 *    BadSink : Reassign the file descriptor before closing the file
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
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


/* bad function declaration */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b_badSink(int data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Create a file descriptor using open() that may not be closed properly */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b_badSink(data);
}



/* good function declarations */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b_goodB2GSink(int data);

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Create a file descriptor using open() that may not be closed properly */
    data = OPEN("BadSource_open.txt", O_RDWR|O_CREAT, S_IREAD|S_IWRITE);
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52b_goodB2GSink(data);
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52_good()
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__open_52_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
