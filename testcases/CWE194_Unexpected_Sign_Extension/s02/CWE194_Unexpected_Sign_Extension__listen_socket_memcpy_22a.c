/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22a.c
Label Definition File: CWE194_Unexpected_Sign_Extension.label.xml
Template File: sources-sink-22a.tmpl.c
*/
/*
 * @description
 * CWE: 194 Unexpected Sign Extension
 * BadSource: listen_socket Read data using a listen socket (server side)
 * GoodSource: Positive integer
 * Sink: memcpy
 *    BadSink : Copy strings using memcpy() with the length of data
 * Flow Variant: 22 Control flow: Flow controlled by value of a global variable. Sink functions are in a separate file from sources.
 *
 * */

#include "std_testcase.h"


/* The global variable below is used to drive control flow in the source function */
int CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_badGlobal = 0;

short CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_badSource(short data);

void CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_bad()
{
    short data;
    /* Initialize data */
    data = 0;
    CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_badGlobal = 1; /* true */
    data = CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_badSource(data);
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign extension could result in a very large number */
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
    }
}



/* The global variables below are used to drive control flow in the source functions. */
int CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_goodG2B1Global = 0;
int CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_goodG2B2Global = 0;

/* goodG2B1() - use goodsource and badsink by setting the static variable to false instead of true */
short CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_goodG2B1Source(short data);

static void goodG2B1()
{
    short data;
    /* Initialize data */
    data = 0;
    CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_goodG2B1Global = 0; /* false */
    data = CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_goodG2B1Source(data);
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign extension could result in a very large number */
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if in the source function */
short CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_goodG2B2Source(short data);

static void goodG2B2()
{
    short data;
    /* Initialize data */
    data = 0;
    CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_goodG2B2Global = 1; /* true */
    data = CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_goodG2B2Source(data);
    {
        char source[100];
        char dest[100] = "";
        memset(source, 'A', 100-1);
        source[100-1] = '\0';
        if (data < 100)
        {
            /* POTENTIAL FLAW: data is interpreted as an unsigned int - if its value is negative,
             * the sign extension could result in a very large number */
            memcpy(dest, source, data);
            dest[data] = '\0'; /* NULL terminate */
        }
        printLine(dest);
    }
}

void CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_good()
{
    goodG2B1();
    goodG2B2();
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
    CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE194_Unexpected_Sign_Extension__listen_socket_memcpy_22_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
