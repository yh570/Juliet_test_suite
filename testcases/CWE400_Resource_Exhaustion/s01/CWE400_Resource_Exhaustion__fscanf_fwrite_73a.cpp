/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE400_Resource_Exhaustion__fscanf_fwrite_73a.cpp
Label Definition File: CWE400_Resource_Exhaustion.label.xml
Template File: sources-sinks-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 400 Resource Exhaustion
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Assign count to be a relatively small number
 * Sinks: fwrite
 *    GoodSink: Write to a file count number of times, but first validate count
 *    BadSink : Write to a file count number of times
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

using namespace std;

namespace CWE400_Resource_Exhaustion__fscanf_fwrite_73
{


/* bad function declaration */
void badSink(list<int> countList);

void bad()
{
    int count;
    list<int> countList;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    /* Put count in a list */
    countList.push_back(count);
    countList.push_back(count);
    countList.push_back(count);
    badSink(countList);
}



/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<int> countList);

static void goodG2B()
{
    int count;
    list<int> countList;
    /* Initialize count */
    count = -1;
    /* FIX: Use a relatively small number */
    count = 20;
    /* Put count in a list */
    countList.push_back(count);
    countList.push_back(count);
    countList.push_back(count);
    goodG2BSink(countList);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<int> countList);

static void goodB2G()
{
    int count;
    list<int> countList;
    /* Initialize count */
    count = -1;
    /* POTENTIAL FLAW: Read count from the console using fscanf() */
    fscanf(stdin, "%d", &count);
    countList.push_back(count);
    countList.push_back(count);
    countList.push_back(count);
    goodB2GSink(countList);
}

void good()
{
    goodG2B();
    goodB2G();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE400_Resource_Exhaustion__fscanf_fwrite_73; /* so that we can use good and bad easily */

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
