/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_21.c
Label Definition File: CWE761_Free_Pointer_Not_at_Start_of_Buffer.label.xml
Template File: source-sinks-21.tmpl.c
*/
/*
 * @description
 * CWE: 761 Free Pointer not at Start of Buffer
 * BadSource: file Read input from a file
 * Sinks:
 *    GoodSink: free() memory correctly at the start of the buffer
 *    BadSink : free() memory not at the start of the buffer
 * Flow Variant: 21 Control flow: Flow controlled by value of a static global variable. All functions contained in one file.
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifdef _WIN32
#define FILENAME "C:\\temp\\file.txt"
#else
#define FILENAME "/tmp/file.txt"
#endif

#define SEARCH_CHAR L'S'


/* The static variable below is used to drive control flow in the sink function */
static int badStatic = 0;

static void badSink(wchar_t * data)
{
    if(badStatic)
    {
        /* FLAW: We are incrementing the pointer in the loop - this will cause us to free the
         * memory block not at the start of the buffer */
        for (; *data != L'\0'; data++)
        {
            if (*data == SEARCH_CHAR)
            {
                printLine("We have a match!");
                break;
            }
        }
        free(data);
    }
}

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_21_bad()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0';
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgetws(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    badStatic = 1; /* true */
    badSink(data);
}



/* The static variables below are used to drive control flow in the sink functions. */
static int goodB2G1Static = 0;
static int goodB2G2Static = 0;

/* goodB2G1() - use badsource and goodsink by setting the static variable to false instead of true */
static void goodB2G1Sink(wchar_t * data)
{
    if(goodB2G1Static)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            size_t i;
            /* FIX: Use a loop variable to traverse through the string pointed to by data */
            for (i=0; i < wcslen(data); i++)
            {
                if (data[i] == SEARCH_CHAR)
                {
                    printLine("We have a match!");
                    break;
                }
            }
            free(data);
        }
    }
}

static void goodB2G1()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0';
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgetws(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    goodB2G1Static = 0; /* false */
    goodB2G1Sink(data);
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the if in the sink function */
static void goodB2G2Sink(wchar_t * data)
{
    if(goodB2G2Static)
    {
        {
            size_t i;
            /* FIX: Use a loop variable to traverse through the string pointed to by data */
            for (i=0; i < wcslen(data); i++)
            {
                if (data[i] == SEARCH_CHAR)
                {
                    printLine("We have a match!");
                    break;
                }
            }
            free(data);
        }
    }
}

static void goodB2G2()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data[0] = L'\0';
    {
        /* Read input from a file */
        size_t dataLen = wcslen(data);
        FILE * pFile;
        /* if there is room in data, attempt to read the input from a file */
        if (100-dataLen > 1)
        {
            pFile = fopen(FILENAME, "r");
            if (pFile != NULL)
            {
                /* POTENTIAL FLAW: Read data from a file */
                if (fgetws(data+dataLen, (int)(100-dataLen), pFile) == NULL)
                {
                    printLine("fgetws() failed");
                    /* Restore NUL terminator if fgetws fails */
                    data[dataLen] = L'\0';
                }
                fclose(pFile);
            }
        }
    }
    goodB2G2Static = 1; /* true */
    goodB2G2Sink(data);
}

void CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_21_good()
{
    goodB2G1();
    goodB2G2();
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
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_21_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE761_Free_Pointer_Not_at_Start_of_Buffer__wchar_t_file_21_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
