/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE134_Uncontrolled_Format_String__char_environment_printf_84a.cpp
Label Definition File: CWE134_Uncontrolled_Format_String.label.xml
Template File: sources-sinks-84a.tmpl.cpp
*/
/*
 * @description
 * CWE: 134 Uncontrolled Format String
 * BadSource: environment Read input from an environment variable
 * GoodSource: Copy a fixed string into data
 * Sinks: printf
 *    GoodSink: printf with "%s" as the first argument and data as the second
 *    BadSink : printf with only data as an argument
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE134_Uncontrolled_Format_String__char_environment_printf_84.h"

namespace CWE134_Uncontrolled_Format_String__char_environment_printf_84
{


void bad()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE134_Uncontrolled_Format_String__char_environment_printf_84_bad * badObject = new CWE134_Uncontrolled_Format_String__char_environment_printf_84_bad(data);
    delete badObject;
}



/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE134_Uncontrolled_Format_String__char_environment_printf_84_goodG2B * goodG2BObject = new CWE134_Uncontrolled_Format_String__char_environment_printf_84_goodG2B(data);
    delete goodG2BObject;
}

/* goodG2B uses the BadSource with the GoodSink */
static void goodB2G()
{
    char * data;
    char dataBuffer[100] = "";
    data = dataBuffer;
    CWE134_Uncontrolled_Format_String__char_environment_printf_84_goodB2G * goodB2GObject = new CWE134_Uncontrolled_Format_String__char_environment_printf_84_goodB2G(data);
    delete goodB2GObject;
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

using namespace CWE134_Uncontrolled_Format_String__char_environment_printf_84; /* so that we can use good and bad easily */

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
