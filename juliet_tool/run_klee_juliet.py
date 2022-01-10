import os
import os.path
import sys
import subprocess
import shutil
import multiprocessing
#fname = open("false_negative.log")
#s = fname.readlines()
#fname.close

def run_klee(fname):
    subprocess.call(["/home/klee/experiment/juliet_tool/run_klee_juliet.sh", fname])

test_cases = []
path = "/home/klee/experiment/Juliet/testcases"
for dirpath, dirnames, filenames in os.walk(path):
    if dirpath.find("klee-") != -1:
        continue
    for l in filenames:
        if l.find("out.bc") == -1 or l.find("socket")!=-1 or l.find("rand") != -1 or l.find("CWE") == -1 or l.find("scanf") != -1:
            continue
        else:
            target = os.path.join(dirpath, l)
            test_cases.append(target)

pool_obj = multiprocessing.Pool(10)
pool_obj.map(run_klee, test_cases)
