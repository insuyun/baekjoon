import os
import subprocess

def run_test(testcase_file, expected_file):
    p = subprocess.Popen("./solve", stdin=open(testcase_file),
            stdout=subprocess.PIPE, stderr=open(os.devnull, "wb"))
    stdout, _ = p.communicate()
    exp = open(expected_file, "r").read()
    if stdout != exp:
        print("FAIL: %s" % testcase_file)

def main():
    dev_null = open(os.devnull, "wb")

    i = 1
    while True:
        testcase_file = os.path.join("testcases/tc%d.txt" % i)
        if not os.path.exists(testcase_file):
            break

        expected_file = os.path.join("testcases/exp%d.txt" % i)
        assert (os.path.exists(expected_file))

        run_test(testcase_file, expected_file)

        i = i + 1

if __name__ == "__main__":
    main()
