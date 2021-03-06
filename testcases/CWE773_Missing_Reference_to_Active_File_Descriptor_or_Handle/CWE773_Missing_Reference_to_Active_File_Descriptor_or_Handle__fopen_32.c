/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_32.c
Label Definition File: CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen.label.xml
Template File: source-sinks-32.tmpl.c
*/
/*
 * @description
 * CWE: 773 Missing Reference to Active File Descriptor or Handle
 * BadSource:  Create a file handle using fopen()
 * Sinks:
 *    GoodSink: Close the file handle before reusing it
 *    BadSink : Reassign the file handle before closing it
 * Flow Variant: 32 Data flow: two pointers to the same value within the same function
 *
 * */

#include "std_testcase.h"


void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_32_bad()
{
    FILE * data;
    FILE * *dataPtr1 = &data;
    FILE * *dataPtr2 = &data;
    data = NULL;
    {
        FILE * data = *dataPtr1;
        /* POTENTIAL FLAW: Create a file handle using fopen() that may not be closed properly */
        data = fopen("BadSource_fopen.txt", "w+");
        *dataPtr1 = data;
    }
    {
        FILE * data = *dataPtr2;
        /* FLAW: Point data to another file handle without closing the handle from the source */
        data = fopen("BadSink_fopen.txt", "w+");
        /* avoid incidental for not closing the file handle */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}



/* goodB2G() uses the BadSource with the GoodSink */
static void goodB2G()
{
    FILE * data;
    FILE * *dataPtr1 = &data;
    FILE * *dataPtr2 = &data;
    data = NULL;
    {
        FILE * data = *dataPtr1;
        /* POTENTIAL FLAW: Create a file handle using fopen() that may not be closed properly */
        data = fopen("BadSource_fopen.txt", "w+");
        *dataPtr1 = data;
    }
    {
        FILE * data = *dataPtr2;
        /* FIX: Close the file from the source before pointing data to a new file handle */
        if (data != NULL)
        {
            fclose(data);
        }
        data = fopen("GoodSink_fopen.txt", "w+");
        /* avoid incidental for not closing the file handle */
        if (data != NULL)
        {
            fclose(data);
        }
    }
}

void CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_32_good()
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
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_32_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE773_Missing_Reference_to_Active_File_Descriptor_or_Handle__fopen_32_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
