/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_52b.c
Label Definition File: CWE122_Heap_Based_Buffer_Overflow__c_CWE129.label.xml
Template File: sources-sinks-52b.tmpl.c
*/
/*
 * @description
 * CWE: 122 Heap Based Buffer Overflow
 * BadSource: rand Set data to result of rand(), which may be zero
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 52 Data flow: data passed as an argument from one function to another to another in three different source files
 *
 * */

#include "std_testcase.h"


/* bad function declaration */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_52c_badSink(int data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_52b_badSink(int data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_52c_badSink(data);
}



/* goodG2B uses the GoodSource with the BadSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_52c_goodG2BSink(int data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_52b_goodG2BSink(int data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_52c_goodG2BSink(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_52c_goodB2GSink(int data);

void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_52b_goodB2GSink(int data)
{
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_rand_52c_goodB2GSink(data);
}

