/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_22a.cpp
Label Definition File: CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array.label.xml
Template File: sources-sinks-22a.tmpl.cpp
*/
/*
 * @description
 * CWE: 762 Mismatched Memory Management Routines
 * BadSource:  Allocate data using strdup()
 * GoodSource: Allocate data using new []
 * Sinks:
 *    GoodSink: Deallocate data using free()
 *    BadSink : Deallocate data using delete []
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_22
{


/* The global variable below is used to drive control flow in the sink function. Since it is in
a C++ namespace, it doesn't need a globally unique name. */
int badGlobal = 0;

void badSink(char * data);

void bad()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = strdup(myString);
    }
    badGlobal = 1; /* true */
    badSink(data);
}



/* The global variables below are used to drive control flow in the sink functions. Since they are in
a C++ namespace, they don't need globally unique names. */
int goodB2G1Global = 0;
int goodB2G2Global = 0;
int goodG2B1Global = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
void goodB2G1Sink(char * data);

static void goodB2G1()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = strdup(myString);
    }
    goodB2G1Global = 0; /* false */
    goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
void goodB2G2Sink(char * data);

static void goodB2G2()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    {
        char myString[] = "myString";
        /* POTENTIAL FLAW: Allocate memory with a function that requires free() to free the memory */
        data = strdup(myString);
    }
    goodB2G2Global = 1; /* true */
    goodB2G2Sink(data);
}

/* goodG2B1() - use goodsource and badsink */
void goodG2B1Sink(char * data);

static void goodG2B1()
{
    char * data;
    /* Initialize data*/
    data = NULL;
    /* FIX: Allocate memory from the heap using new [] */
    data = new char[100];
    goodG2B1Global = 1; /* true */
    goodG2B1Sink(data);
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE762_Mismatched_Memory_Management_Routines__strdup_delete_array_char_22; /* so that we can use good and bad easily */

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
