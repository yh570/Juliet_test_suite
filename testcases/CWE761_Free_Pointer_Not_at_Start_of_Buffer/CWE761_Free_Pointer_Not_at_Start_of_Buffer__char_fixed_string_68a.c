/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68a.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * BadSource: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define BAD_SOURCE_FIXED_STRING "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#define SEARCH_CHAR 'S'

char * CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68_badDataForBadSink;

char * CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68_badDataForGoodSink;


/* bad function declaration */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68b_badSink();

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68_bad()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0';
    /* POTENTIAL FLAW: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, BAD_SOURCE_FIXED_STRING);
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68_badDataForBadSink = data;
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68b_badSink();
}



/* good function declarations */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68b_goodB2GSink();

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0';
    /* POTENTIAL FLAW: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, BAD_SOURCE_FIXED_STRING);
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68_badDataForGoodSink = data;
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68b_goodB2GSink();
}

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68_good()
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
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_68_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
