/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE176_Improper_Handling_of_Unicode_Encoding__w32_63b.c
Label Definition File: CWE176_Improper_Handling_of_Unicode_Encoding__w32.label.xml
Template File: sources-sinks-63b.tmpl.c
*/
/*
 * @description
 * CWE: 176 Improper Handling of Unicode Encoding
 * BadSource:  Initialize data as a large unicode string
 * GoodSource: Initialize data as a small unicode string
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 63 Data flow: pointer to data passed from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#pragma comment( lib, "advapi32" )


void CWE176_Improper_Handling_of_Unicode_Encoding__w32_63b_badSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    {
        char convertedText[10] = "";
        int requiredSize;
        requiredSize = WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, 0, 0, 0);
        /* POTENTIAL FLAW: Do not check that the size of the destination buffer for the conversion is large enough. */
        WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, requiredSize , 0, 0);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_63b_goodG2BSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    {
        char convertedText[10] = "";
        int requiredSize;
        requiredSize = WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, 0, 0, 0);
        /* POTENTIAL FLAW: Do not check that the size of the destination buffer for the conversion is large enough. */
        WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, requiredSize , 0, 0);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE176_Improper_Handling_of_Unicode_Encoding__w32_63b_goodB2GSink(wchar_t * * dataPtr)
{
    wchar_t * data = *dataPtr;
    {
        char convertedText[10] = "";
        int requiredSize;
        requiredSize = WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, 0, 0, 0);
        /* FIX: Check that the size of the destination buffer for the conversion is large enough. */
        if (requiredSize < 10)
        {
            WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK, data, -1, convertedText, requiredSize , 0, 0);
        }
        else
        {
            printLine("Destination buffer not large enough to perform conversion.");
        }
    }
}

