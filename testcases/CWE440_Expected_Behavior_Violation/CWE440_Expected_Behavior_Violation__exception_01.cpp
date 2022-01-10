/*
 * @description Expected Behavior Violation.  In this case, the function throws an exception, despite declaring that it doesn't.
 * 
 * */

#include "std_testcase.h"
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

namespace CWE440_Expected_Behavior_Violation__exception_01 
{


/* maintenance note: this may generate a warning in MSVC++, because MSVC++ ignores exception specifiers */
void bad() throw () /* FLAW: Declare that the function does not throw any exceptions, when it actually does */
{
	throw range_error("Test"); 
}



/* maintenance note: line below may generate a warning in MSVC++, 
 * because MSVC++ ignores exception specifiers */
static void good1() throw (range_error) /* FIX: Declare that function throws an  exception */
{
	throw range_error("Test");
}

void good() 
{
    good1();
}


} /* close namespace */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one *
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

using namespace CWE440_Expected_Behavior_Violation__exception_01; /* so that we can use good and bad easily */

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
