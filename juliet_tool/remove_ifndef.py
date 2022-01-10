
import os.path
import sys
#fname = open("false_negative.log")
#s = fname.readlines()
#fname.close

def remove_ifndef(fname):
    file1 = open(fname, 'r')
    Lines = file1.readlines()
    file1.close()

    output = []
    count_bad = 0
    count_good = 0
    for line in Lines:
        if "#ifndef OMITBAD" in line:
            count_bad += 1
            continue
        if "#endif /* OMITBAD */" in line:
            if count_bad != 1:
                print("error!!!!")
            else:
                count_bad = 0
                continue
        if "#ifndef OMITGOOD" in line:
            count_good += 1
            continue
        if "#endif /* OMITGOOD */" in line:
            if count_good != 1:
                print("error!!!!")
            else:
                count_good = 0
                continue
        if "srand" in line:
            continue

        output.append(line)

    if count_bad >0 or count_good >0:
        print("error!!!" + str(fname))
    file1 = open(fname, 'w')
    file1.writelines(output)
    file1.close()


path = "/home/klee/experiment/Juliet/testcases"
for dirpath, dirnames, filenames in os.walk(path):
    if dirpath.find("klee-") != -1:
        continue
    for l in filenames:
        if l.endswith(".c") or l.endswith(".cpp"):
            fname = os.path.join(dirpath, l) 
            remove_ifndef(fname)
