/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_54a.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-54a.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * BadSource: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define BAD_SOURCE_FIXED_STRING L"Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#define SEARCH_CHAR L'S'


/* bad function declaration */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_54b_badSink(wchar_t * data);

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_54_bad()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0';
    /* POTENTIAL FLAW: Initialize data to be a fixed string that contains the search character in the sinks */
    wcscpy(data, BAD_SOURCE_FIXED_STRING);
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_54b_badSink(data);
}



/* good function declarations */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_54b_goodB2GSink(wchar_t * data);

/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0';
    /* POTENTIAL FLAW: Initialize data to be a fixed string that contains the search character in the sinks */
    wcscpy(data, BAD_SOURCE_FIXED_STRING);
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_54b_goodB2GSink(data);
}

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_54_good()
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
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
