/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_82a.cpp
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-82a.tmpl.cpp
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * BadSource: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 82 Data flow: data passed in a parameter to an virtual method called via a pointer
 *
 * */

#include "std_testcase.h"
#include "CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_82.h"

#define BAD_SOURCE_FIXED_STRING L"Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#define SEARCH_CHAR L'S'

namespace CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_82
{


void bad()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0';
    /* POTENTIAL FLAW: Initialize data to be a fixed string that contains the search character in the sinks */
    wcscpy(data, BAD_SOURCE_FIXED_STRING);
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_82_base* baseObject = new CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_82_bad;
    baseObject->action(data);
    delete baseObject;
}



/* goodB2G uses the BadSource with the GoodSink */
static void goodB2G()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0';
    /* POTENTIAL FLAW: Initialize data to be a fixed string that contains the search character in the sinks */
    wcscpy(data, BAD_SOURCE_FIXED_STRING);
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_82_base* baseObject = new CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_82_goodB2G;
    baseObject->action(data);
    delete baseObject;
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

using namespace CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_fixed_string_82; /* so that we can use good and bad easily */

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
