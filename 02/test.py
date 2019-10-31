#/usr/bin/python3
import subprocess
import time

def run(command):
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    out = process.stdout.readlines()
    code = process.wait()
    return code, out

def test(command, expected_code, expected_value):
    print (command)
    code, out = run(command)
    if code != expected_code:
        print ('return value', expected_code, '(expected) !=', code)
        return
    i = 0
    for line in out:
        line = line.rstrip().decode("utf-8")
        try:
            if line != expected_value[i]:
                print (expected_value[i], '(expected) !=', line)
                return
            i += 1
        except ValueError:
            print ('invalid output')
            return
        except IndexError:
            print ('invalid output')
            return
    if i != len(expected_value):
        print ('empty output')
        return
    print ('OK')

print ('BEGIN\n')
print ('Test #1')
test('./main 10 alloc 11', 0, [ "Failed to allocate required memory.", "END." ])
print ('Test #2')
test('./main 10 alloc 10', 0, [ "Successful memory allocation.", "END." ])
print ('Test #3')
test('./main 10 alloc 5 alloc 6', 0, [ "Successful memory allocation.",
                                       "Failed to allocate required memory.",
                                       "END."])
print ('Test #4/n')
test('./main 10 alloc 10 reset alloc 10', 0, [ "Successful memory allocation.",
                                                "Successful memory allocation.",
                                                "END."])
print ('\nSUCCESS\n')
