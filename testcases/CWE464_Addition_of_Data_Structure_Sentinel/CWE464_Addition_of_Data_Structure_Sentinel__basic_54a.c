/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE464_Addition_of_Data_Structure_Sentinel__basic_54a.c
Label Definition File: CWE464_Addition_of_Data_Structure_Sentinel__basic.label.xml
Template File: sources-sink-54a.tmpl.c
*/
/*
 * @description
 * CWE: 464 Addition of Data Structure Sentinel
 * BadSource:  Read in data from the console and convert to an int
 * GoodSource: Set data to a fixed char
 * Sink:
 *    BadSink : Place data into and print an array
 * Flow Variant: 54 Data flow: data passed as an argument from one function through three others to a fifth; all five functions are in different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE464_Addition_of_Data_Structure_Sentinel__basic_54b_badSink(char data);

void CWE464_Addition_of_Data_Structure_Sentinel__basic_54_bad()
{
    char data;
    data = ' ';
    {
        char charArraySource[2];
        charArraySource[0] = (char)getc(stdin);
        charArraySource[1] = '\0';
        /* FLAW: If the character entered on the command line is not an int,
         * a null value will be returned */
        data = (char)atoi(charArraySource);
    }
    CWE464_Addition_of_Data_Structure_Sentinel__basic_54b_badSink(data);
}



/* good function declaration */
void CWE464_Addition_of_Data_Structure_Sentinel__basic_54b_goodG2BSink(char data);

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char data;
    data = ' ';
    /* FIX: Set data to be a char */
    data = 'a';
    CWE464_Addition_of_Data_Structure_Sentinel__basic_54b_goodG2BSink(data);
}

void CWE464_Addition_of_Data_Structure_Sentinel__basic_54_good()
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
    CWE464_Addition_of_Data_Structure_Sentinel__basic_54_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE464_Addition_of_Data_Structure_Sentinel__basic_54_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
