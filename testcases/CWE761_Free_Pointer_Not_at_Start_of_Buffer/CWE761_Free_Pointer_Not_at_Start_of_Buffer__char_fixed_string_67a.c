/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67a.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-67a.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * BadSource: fixed_string Initialize data to be a fixed string
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#define BAD_SOURCE_FIXED_STRING "Fixed String" /* MAINTENANCE NOTE: This string must contain the SEARCH_CHAR */

#define SEARCH_CHAR 'S'

typedef struct _CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67_structType
{
    char * structFirst;
} CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67_structType;


/* bad function declaration */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67b_badSink(CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67_structType myStruct);

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67_bad()
{
    char * data;
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67_structType myStruct;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0';
    /* POTENTIAL FLAW: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, BAD_SOURCE_FIXED_STRING);
    myStruct.structFirst = data;
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67b_badSink(myStruct);
}



/* goodB2G uses the BadSource with the GoodSink */
void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67b_goodB2GSink(CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67_structType myStruct);

static void goodB2G()
{
    char * data;
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67_structType myStruct;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0';
    /* POTENTIAL FLAW: Initialize data to be a fixed string that contains the search character in the sinks */
    strcpy(data, BAD_SOURCE_FIXED_STRING);
    myStruct.structFirst = data;
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67b_goodB2GSink(myStruct);
}

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67_good()
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
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__char_fixed_string_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
