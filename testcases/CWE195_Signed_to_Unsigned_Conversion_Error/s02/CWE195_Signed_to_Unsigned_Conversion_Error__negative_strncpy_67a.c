/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67a.c
Label Definition File: CWE195_Signed_to_Unsigned_Conversion_Error.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 195 Signed to Unsigned Conversion Error
 * BadSource: negative Set data to a fixed negative number
 * GoodSource: Positive integer
 * Sinks: strncpy
 *    BadSink : Copy strings using strncpy() with the length of data
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

typedef struct _CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67_structType
{
    int structFirst;
} CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67_structType;


/* bad function declaration */
void CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67b_badSink(CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67_structType myStruct);

void CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67_bad()
{
    int data;
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* FLAW: Use a negative number */
    data = -1;
    myStruct.structFirst = data;
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67b_badSink(myStruct);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67b_goodG2BSink(CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67_structType myStruct);

static void goodG2B()
{
    int data;
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67_structType myStruct;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than &InitialDataSize&*/
    data = 100-1;
    myStruct.structFirst = data;
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67b_goodG2BSink(myStruct);
}

void CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67_good()
{
    goodG2B();
}


/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    printLine("Calling good()...");
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE195_Signed_to_Unsigned_Conversion_Error__negative_strncpy_67_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
