/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_loop_22b.cpp
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805.string.label.xml
Template File: sources-sink-22b.tmpl.cpp
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource:  Allocate using new[] and set data pointer to a small buffer
 * GoodSource: Allocate using new[] and set data pointer to a large buffer
 * Sink: loop
 *    BadSink : Copy string to data using a loop
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE122_Heap_Based_Buffer_Overflow__cpp_CWE805_wchar_t_loop_22
{


/* The global variable below is used to drive control flow in the source function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
extern int badGlobal;

wchar_t * badSource(wchar_t * data)
{
    if(badGlobal)
    {
        /* FLAW: Allocate using new[] and point data to a small buffer that is smaller than the large buffer used in the sinks */
        data = new wchar_t[50];
        data[0] = L'\0'; /* null terminate */
    }
    return data;
}



/* The global variables below are used to drive control flow in the source functions. Since they are in
a C++ namespace, they don't need globally unique names. */
extern int goodG2B1Global;
extern int goodG2B2Global;

/* goodG2B1() - use goodsource and badsink by setting the global variable to false instead of true */
wchar_t * goodG2B1Source(wchar_t * data)
{
    if(goodG2B1Global)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = new wchar_t[100];
        data[0] = L'\0'; /* null terminate */
    }
    return data;
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
wchar_t * goodG2B2Source(wchar_t * data)
{
    if(goodG2B2Global)
    {
        /* FIX: Allocate using new[] and point data to a large buffer that is at least as large as the large buffer used in the sink */
        data = new wchar_t[100];
        data[0] = L'\0'; /* null terminate */
    }
    return data;
}


} /* close namespace */
