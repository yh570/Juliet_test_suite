/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE511_Logic_Time_Bomb__w32CompareFileTime_07.c
Label Definition File: CWE511_Logic_Time_Bomb.label.xml
Template File: point-flaw-07.tmpl.c
*/
/*
 * @description
 * CWE: 511 Logic Time Bomb
 * Sinks: w32CompareFileTime
 *    GoodSink: After a certain date, do something harmless
 *    BadSink : After a certain date, do something bad
 * Flow Variant: 07 Control flow: if(staticFive==5) and if(staticFive!=5)
 *
 * */

#include "std_testcase.h"

#ifdef _WIN32
#define UNLINK _unlink
#else
#include <unistd.h>
#define UNLINK unlink
#endif

#include <windows.h>

/* The variable below is not declared "const", but is never assigned
   any other value so a tool should be able to identify that reads of
   this will always give its initialized value. */
static int staticFive = 5;


void CWE511_Logic_Time_Bomb__w32CompareFileTime_07_bad()
{
    if(staticFive==5)
    {
        {
            SYSTEMTIME setTime, currentTime;
            FILETIME setTimeAsFileTime, currentTimeAsFileTime;
            /* Jan 1, 2008 12:00:00 PM */
            setTime.wYear         = 2008; /* Year */
            setTime.wMonth        = 1;    /* January */
            setTime.wDayOfWeek    = 0;    /* Ignored */
            setTime.wDay          = 1;    /* The first of the month */
            setTime.wHour         = 12;   /* 12 PM */
            setTime.wMinute       = 0;    /* 0 minutes into the hour */
            setTime.wSecond       = 0;    /* 0 seconds into the minute */
            setTime.wMilliseconds = 0;    /* 0 milliseconds into the second */
            GetSystemTime(&currentTime);
            /* Must convert to FILETIME for comparison */
            SystemTimeToFileTime(&currentTime, &currentTimeAsFileTime);
            SystemTimeToFileTime(&setTime, &setTimeAsFileTime);
            /* FLAW: After a certain date, delete a file */
            if (CompareFileTime(&currentTimeAsFileTime, &setTimeAsFileTime) == 1)
            {
                UNLINK("important_file.txt");
            }
        }
    }
}



/* good1() uses if(staticFive!=5) instead of if(staticFive==5) */
static void good1()
{
    if(staticFive!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            SYSTEMTIME setTime, currentTime;
            FILETIME setTimeAsFileTime, currentTimeAsFileTime;
            /* Jan 1, 2008 12:00:00 PM */
            setTime.wYear         = 2008; /* Year */
            setTime.wMonth        = 1;    /* January */
            setTime.wDayOfWeek    = 0;    /* Ignored */
            setTime.wDay          = 1;    /* The first of the month */
            setTime.wHour         = 12;   /* 12 PM */
            setTime.wMinute       = 0;    /* 0 minutes into the hour */
            setTime.wSecond       = 0;    /* 0 seconds into the minute */
            setTime.wMilliseconds = 0;    /* 0 milliseconds into the second */
            GetSystemTime(&currentTime);
            /* Must convert to FILETIME for comparison */
            SystemTimeToFileTime(&currentTime, &currentTimeAsFileTime);
            SystemTimeToFileTime(&setTime, &setTimeAsFileTime);
            /* FIX: After a certain date, print to the console */
            if (CompareFileTime(&currentTimeAsFileTime, &setTimeAsFileTime) == 1)
            {
                printLine("Happy New Year!");
            }
        }
    }
}

/* good2() reverses the bodies in the if statement */
static void good2()
{
    if(staticFive==5)
    {
        {
            SYSTEMTIME setTime, currentTime;
            FILETIME setTimeAsFileTime, currentTimeAsFileTime;
            /* Jan 1, 2008 12:00:00 PM */
            setTime.wYear         = 2008; /* Year */
            setTime.wMonth        = 1;    /* January */
            setTime.wDayOfWeek    = 0;    /* Ignored */
            setTime.wDay          = 1;    /* The first of the month */
            setTime.wHour         = 12;   /* 12 PM */
            setTime.wMinute       = 0;    /* 0 minutes into the hour */
            setTime.wSecond       = 0;    /* 0 seconds into the minute */
            setTime.wMilliseconds = 0;    /* 0 milliseconds into the second */
            GetSystemTime(&currentTime);
            /* Must convert to FILETIME for comparison */
            SystemTimeToFileTime(&currentTime, &currentTimeAsFileTime);
            SystemTimeToFileTime(&setTime, &setTimeAsFileTime);
            /* FIX: After a certain date, print to the console */
            if (CompareFileTime(&currentTimeAsFileTime, &setTimeAsFileTime) == 1)
            {
                printLine("Happy New Year!");
            }
        }
    }
}

void CWE511_Logic_Time_Bomb__w32CompareFileTime_07_good()
{
    good1();
    good2();
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
    CWE511_Logic_Time_Bomb__w32CompareFileTime_07_good();
    printLine("Finished good()");
    printLine("Calling bad()...");
    CWE511_Logic_Time_Bomb__w32CompareFileTime_07_bad();
    printLine("Finished bad()");
    return 0;
}

#endif
