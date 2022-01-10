import os
import os.path
import sys
import subprocess
import shutil
import multiprocessing

test_list = ["CWE121_Stack_Based_Buffer_Overflow", "CWE122_Heap_Based_Buffer_Overflow", "CWE123_Write_What_Where_Condition", "CWE124_Buffer_Underwrite", "CWE126_Buffer_Overread", "CWE127_Buffer_Underread", "CWE134_Uncontrolled_Format_String", "CWE194_Unexpected_Sign_Extension", "CWE195_Signed_to_Unsigned_Conversion_Error", "CWE242_Use_of_Inherently_Dangerous_Function", "CWE369_Divide_by_Zero", "CWE396_Catch_Generic_Exception", "CWE397_Throw_Generic_Exception", "CWE404_Improper_Resource_Shutdown", "CWE415_Double_Free", "CWE416_Use_After_Free", "CWE427_Uncontrolled_Search_Path_Element", "CWE440_Expected_Behavior_Violation", "CWE457_Use_of_Uninitialized_Variable", "CWE468_Incorrect_Pointer_Scaling", "CWE476_NULL_Pointer_Dereference", "CWE510_Trapdoor", "CWE562_Return_of_Stack_Variable_Address", "CWE587_Assignment_of_Fixed_Address_to_Pointer", "CWE588_Attempt_to_Access_Child_of_Non_Structure_Pointer", "CWE590_Free_Memory_Not_on_Heap", "CWE605_Multiple_Binds_Same_Port", "CWE617_Reachable_Assertion", "CWE665_Improper_Initialization", "CWE666_Operation_on_Resource_in_Wrong_Phase_of_Lifetime", "CWE672_Operation_on_Resource_After_Expiration_or_Release", "CWE675_Duplicate_Operations_on_Resource", "CWE676_Use_of_Potentially_Dangerous_Function", "CWE680_Integer_Overflow_to_Buffer_Overflow", "CWE685_Function_Call_With_Incorrect_Number_of_Arguments", "CWE688_Function_Call_With_Incorrect_Variable_or_Reference_as_Argument", "CWE758_Undefined_Behavior", "CWE761_Free_Pointer_Not_at_Start_of_Buffer", "CWE789_Uncontrolled_Mem_Alloc", "CWE843_Type_Confusion"]

path = "/home/klee/experiment/Juliet/testcases/"

def run_klee(fname):
    target = os.path.join(path, fname)
    subprocess.call(["/home/klee/experiment/juliet_tool/run_klee_juliet.sh", target])


f = open("/home/klee/experiment/find_nothing.log", "r")
lines = f.readlines()
f.close()
lines.pop(0)
output=[]
for l in lines:
    n = l.find(",    ")
    temp=l[n+5:-1]

    output.append(temp)
    
    for item in test_list:
        if temp.find(item) != -1:
            output.append(temp)
            break

pool_obj = multiprocessing.Pool(10)
pool_obj.map(run_klee, output)
