import os
import os.path
import sys
import subprocess
import shutil


test_list = ["CWE121_Stack_Based_Buffer_Overflow", "CWE122_Heap_Based_Buffer_Overflow", "CWE123_Write_What_Where_Condition", "CWE124_Buffer_Underwrite", "CWE126_Buffer_Overread", "CWE127_Buffer_Underread", "CWE134_Uncontrolled_Format_String", "CWE194_Unexpected_Sign_Extension", "CWE195_Signed_to_Unsigned_Conversion_Error", "CWE369_Divide_by_Zero", "CWE404_Improper_Resource_Shutdown", "CWE415_Double_Free", "CWE416_Use_After_Free", "CWE457_Use_of_Uninitialized_Variable", "CWE476_NULL_Pointer_Dereference", "CWE587_Assignment_of_Fixed_Address_to_Pointer", "CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer", "CWE590_Free_Memory_Not_on_Heap", "CWE617_Reachable_Assertion", "CWE665_Improper_Initialization", "CWE675_Duplicate_Operations_on_Resource", "CWE680_Integer_Overflow_to_Buffer_Overflow", "CWE685_Function_Call_With_Incorrect_Number_of_Arguments", "CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument"]


f = open("/home/klee/experiment/Juliet_4bytes/C/result/32byte/find_nothing.log", "r")
lines = f.readlines()
f.close()
lines.pop(0)
output=[]
for l in lines:
    n = l.find(",    ")
    temp=l[n+5:-1]
    for item in test_list:
        if temp.find(item) >= 0:
            output.append(temp)
            break


path = "/home/klee/experiment/Juliet_4bytes/C/testcases/"
for f in output:
    target = os.path.join(path, f)
    subprocess.call(["/home/klee/experiment/Juliet_4bytes/run_klee_juliet.sh", target])
