/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_63b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close.label.xml
Template File: source-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using fopen()
 * Sinks:
 *    GoodSink: Close the file using fclose()
 *    BadSink : Do not close file
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"


void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_63b_badSink(FILE * * dataPtr)
{
    FILE * data = *dataPtr;
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE775_Missing_Release_of_File_Descriptor_or_Handle__fopen_no_close_63b_goodB2GSink(FILE * * dataPtr)
{
    FILE * data = *dataPtr;
    /* FIX: If the file is still opened, close it */
    if (data != NULL)
    {
        fclose(data);
    }
}

