/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53c.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-53c.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using fopen()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d_badSink(FILE * data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53c_badSink(FILE * data)
{
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d_badSink(data);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d_goodB2GSink(FILE * data);

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53c_goodB2GSink(FILE * data)
{
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_53d_goodB2GSink(data);
}

