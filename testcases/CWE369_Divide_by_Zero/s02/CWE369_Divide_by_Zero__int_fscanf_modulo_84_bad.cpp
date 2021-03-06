/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE369_Divide_by_Zero__int_fscanf_modulo_84_bad.cpp
Label Definition File: CWE369_Divide_by_Zero__int.label.xml
Template File: sources-sinks-84_bad.tmpl.cpp
*/
/*
 * @description
 * CWE: 369 Divide by Zero
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Non-zero
 * Sinks: modulo
 *    GoodSink: Check for zero before modulo
 *    BadSink : Modulo a constant with data
 * Flow Variant: 84 Data flow: data passed to class constructor and destructor by declaring the class object on the heap and deleting it after use
 *
 * */

#include "std_testcase.h"
#include "CWE369_Divide_by_Zero__int_fscanf_modulo_84.h"

namespace CWE369_Divide_by_Zero__int_fscanf_modulo_84
{
CWE369_Divide_by_Zero__int_fscanf_modulo_84_bad::CWE369_Divide_by_Zero__int_fscanf_modulo_84_bad(int dataCopy)
{
    data = dataCopy;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
}

CWE369_Divide_by_Zero__int_fscanf_modulo_84_bad::~CWE369_Divide_by_Zero__int_fscanf_modulo_84_bad()
{
    /* POTENTIAL FLAW: Possibly divide by zero */
    printIntLine(100 % data);
}
}
