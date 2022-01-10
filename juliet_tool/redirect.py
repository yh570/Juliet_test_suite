import os.path
import sys
#fname = open("false_negative.log")
#s = fname.readlines()
#fname.close

text_pattern = ["important_file.txt", "/tmp/file.txt", "BadSink_open.txt", "GoodSink_open.txt", "BadSource_fopen.txt", "BadSink_fopen.txt", "GoodSink_fopen.txt", "BadSource_open.txt", "file.txt", "oldbadfilename.txt", "output_bad.txt", "output_good.txt", "GoodSource_open.txt", "GoodSource_fopen.txt", "BadSource_freopen.txt", "removemebad.txt", "removemegood.txt", "newbadfilename.txt", "newgoodfilename.txt", "oldgoodfilename.txt"]


def redirect(fname):
    file1 = open(fname, 'r')
    Lines = file1.readlines()
    file1.close()

    output = []
    for line in Lines:
        for item in text_pattern:
            if item in line:
                print(fname)
                line = line.replace(item, "A")
        output.append(line)

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
            redirect(fname)
