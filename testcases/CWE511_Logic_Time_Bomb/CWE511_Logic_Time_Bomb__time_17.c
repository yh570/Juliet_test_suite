/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE511_Logic_Time_Bomb__time_17.c
Label Definition File: CWE511_Logic_Time_Bomb.label.xml
Template File: point-flaw-17.tmpl.c
*/
/*
 * @description
 * CWE: 511 Logic Time Bomb
 * Sinks: time
 *    GoodSink: After a certain date, do something harmless
 *    BadSink : After a certain date, do something bad
 * Flow Variant: 17 Control flow: for loops
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define UNLINK _unlink
#else
#include <unistd.h>
#define UNLINK unlink
#endif

#include <time.h>

#define TIME_CHECK ((time_t)1199163600) /* Jan 1, 2008 12:00:00 AM */


void CWE511_Logic_Time_Bomb__time_17_bad()
{
    int j;
    for(j = 0; j < 1; j++)
    {
        {
            time_t currentTime;
            /* FLAW: After a certain date, delete a file */
            time(&currentTime);
            if (currentTime > TIME_CHECK)
            {
                UNLINK("important_file.txt");
            }
        }
    }
}



/* good1() uses the GoodSinkBody in the for statements */
static void good1()
{
    int k;
    for(k = 0; k < 1; k++)
    {
        {
            time_t currentTime;
            /* FIX: After a certain date, print to the console */
            time(&currentTime);
            if (currentTime > TIME_CHECK)
            {
                printLine("Happy New Year!");
            }
        }
    }
}

void CWE511_Logic_Time_Bomb__time_17_good()
{
    good1();
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
    CWE511_Logic_Time_Bomb__time_17_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE511_Logic_Time_Bomb__time_17_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
