/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_64b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close.label.xml
Template File: source-sinks-64b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using open()
 * Sinks:
 *    GoodSink: Close the file using close()
 *    BadSink : Do not close file
 * Flow Variant: 64 Data flow: void pointer to data passed from one function to another in different source files
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


void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_64b_badSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * dataPtr = (int *)dataVoidPtr;
    /* dereference dataPtr into data */
    int data = (*dataPtr);
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__open_no_close_64b_goodB2GSink(void * dataVoidPtr)
{
    /* cast void pointer to a pointer of the appropriate type */
    int * dataPtr = (int *)dataVoidPtr;
    /* dereference dataPtr into data */
    int data = (*dataPtr);
    /* FIX: If the file is still opened, close it */
    if (data != -1)
    {
        CLOSE(data);
    }
}

