/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE135_73b.cpp
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE135.label.xml
Template File: sources-sinks-73b.tmpl.cpp
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Void pointer to a wchar_t array
 * GoodSource: Void pointer to a char array
 * Sinks:
 *    GoodSink: Allocate memory using wcslen() and copy data
 *    BadSink : Allocate memory using strlen() and copy data
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE121_Stack_Based_Buffer_Overflow__CWE135_73
{


void badSink(list<void *> dataList)
{
    /* copy data out of dataList */
    void * data = dataList.back();
    {
        /* POTENTIAL FLAW: treating pointer as a char* when it may point to a wide string */
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)ALLOCA((dataLen+1) * sizeof(wchar_t));
        (void)wcscpy((wchar_t *)dest, (wchar_t *)data);
        printLine((char *)dest);
    }
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<void *> dataList)
{
    void * data = dataList.back();
    {
        /* POTENTIAL FLAW: treating pointer as a char* when it may point to a wide string */
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)ALLOCA((dataLen+1) * 1);
        (void)strcpy((char *)dest, (char *)data);
        printLine((char *)dest);
    }
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<void *> dataList)
{
    void * data = dataList.back();
    {
        /* FIX: treating pointer like a wchar_t*  */
        size_t dataLen = wcslen((wchar_t *)data);
        void * dest = (void *)ALLOCA((dataLen+1) * sizeof(wchar_t));
        (void)wcscpy((wchar_t *)dest, (wchar_t *)data);
        printWLine((wchar_t *)dest);
    }
}


} /* close namespace */
