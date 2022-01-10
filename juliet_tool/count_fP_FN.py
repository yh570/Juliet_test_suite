import os
import collections
import sys
import os.path

"""
 True positive.
The scanner reports an existing error.
 False positive.
The scanner reports a non-existing error.
 Wrong positive.
The scanner reports a specific error at the location of an error with a different type.
 True negative.
The scanner does not report an error where in fact there is none.
 False negative.
There is an error in the source code, but the scanner does not find and report it.
"""

def read_log(path, target, target_list):
    f = open(path, 'r')
    s = f.readlines()
    f.close()

    for l in s:
        find_rand = l.find("_rand_")
        if find_rand != -1:
            continue
        a = l.find(target)
        if a == -1:
            continue
        a = l.find(",    ")
        string = l[:a]
        if string not in target_list:
            target_list.append(string)


def read_err_file(target_list, end):
    tp = []
    fp_io = []
    fp = []
    
    for path in target_list:
        full_path = "/home/klee/experiment/Juliet_3/C/" + path 
        for dirpath, dirnames, filenames in os.walk(full_path):
            for file in filenames:
                if file.endswith(end):
                    fname = dirpath + '/' +  file
                    f = open(fname, 'r')
                    s = f.read()
                    f.close()
                    if "bad" in s:
                        tp.append(path)
                    #elif "stdio" in s:
                    #    fp_io.append(path)
                    #elif "stdlib" in s:
                    #    fp_io.append(path)
                    else:
                        fp.append(path)
    #res = []
    #[res.append(x) for x in tp if x not in res]
    #res_fp = []
    #[res_fp.append(x) for x in fp if x not in res_fp]

    return tp, fp, fp_io


def count_tp_fp(target, log_file, error_type):
    klee_list = []
    read_log(log_file, target, klee_list)
    #print("total " + error_type + " bug number: " + str(len(klee_list)))

    tp, fp, fp_io = read_err_file(klee_list, error_type)
    #print(error_type + " TP number: " + str(len(tp)) + "; " + error_type + " FP number: " + str(len(fp)) + "\n")
    return tp, fp, fp_io
    

CWE_list = next(os.walk("/home/klee/experiment/Juliet_3/C/output/"))[1]
CWEDict = {key: {"TP": 0, "FP": 0} for key in CWE_list}

count_list = ["abort_fail.log", "assert_fail.log", "div_0.log", "free_error.log", "memory_err.log", "ptr_err.log"]

fp_log_list = ["con_sym_size.log", "exec_err.log", "external_err.log"]


fp_dict = {}

for key, value in CWEDict.items():
    tp = 0
    fp = 0
    fp_list = []
    for log_file in count_list:
        if log_file == "abort_fail.log":
            error_type = "abort.err"
        elif log_file == "assert_fail.log":
            error_type = "assert.err"
        elif log_file == "div_0.log":
            error_type = "div.err"
        elif log_file == "free_error.log":
            error_type = "free.err"
        elif log_file == "memory_err.log":
            error_type = "readonly.err"
        elif log_file == "ptr_err.log":
            error_type = "ptr.err"
        tp_temp, fp_temp, fp_io_temp = count_tp_fp(key, log_file, error_type)
        tp += len(tp_temp)
        fp += len(fp_temp) + len(fp_io_temp)
        for item in fp_temp:
            fp_list.append(item)
    CWEDict[key]["TP"] = tp
    CWEDict[key]["FP"] = fp
    fp_dict[key] = fp_list



# ------------------------   if counting exec external and mode error --------------------
for key, value in CWEDict.items():
    fp = 0

    for path in fp_log_list:
        f = open(path, 'r')
        s = f.readlines()
        f.close()
        for l in s:
            find_rand = l.find("_rand_")
            if find_rand != -1:
                continue
            a = l.find(key)
            if a == -1:
                continue
            fp += 1
    temp = CWEDict[key]["FP"]
    CWEDict[key]["FP"] = temp + fp
# --------------------------  end -----------------------------




od = collections.OrderedDict(sorted(CWEDict.items()))

f = open("false_positive.log","w")
for k, v in od.items():
    sorted_v = collections.OrderedDict(sorted(v.items()))
    f.write(str(k))
    for ok, ov in sorted_v.items():
        f.write(', ' + str(ok) + ', '+ str(ov))
    f.write('\n')
f.close()


od = collections.OrderedDict(sorted(fp_dict.items()))
f = open("fp_list.log", "w")
for k, v in od.items():
    f.write(str(k) + "\n")
    for item in v:
        f.write(str(item)+'\n')
    f.write("\n=============================================================\n")
f.close()
