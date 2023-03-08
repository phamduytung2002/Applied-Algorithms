"""
    Auto judge for cpp solutions
    Used in command line: python run.py [-l] [-d] [-tl TIMELIMIT]
        -l: compile with local mode (file input and output)
        -d: compile with debug mode (print things)
"""

import os
import argparse
import filecmp
import time
import sys


def removeendlineatendfile(filetoremove: str):
    """
        Remove '\\n' at the end of output files
        Parameters:
            input:
                filetoremove: path string
            output:
                None
    """
    with open(filetoremove, "r+", encoding="utf-8") as my_file:
        content = my_file.read()
        content = content.rstrip('\n')
        my_file.seek(0)

        my_file.write(content)
        my_file.truncate()


parser = argparse.ArgumentParser()
parser.add_argument('filename')
parser.add_argument('-l', '--offline',
                    action='store_true', default=False)
parser.add_argument('-d', '--debug',
                    action='store_true', default=False)
parser.add_argument('-tl', '--time_limit', type=float, default=1.)


config = parser.parse_args()
file = '20200573_BAI' + config.filename  # change solution files name here
offline = config.offline
debug = config.debug
probNum = config.filename

if offline and debug:
    C = ' a'
elif not offline and debug:
    C = ' b'
elif offline and not debug:
    C = ' c'
elif not offline and not debug:
    C = ' d'
else:
    C = ''


os.system(f'g++ -o a.exe {file}.cpp')

if not os.path.exists('a.exe'):
    print('!!Compile error!!')
    sys.exit()

N_TEST = 0
N_CORRECT = 0
for testFileInput in os.listdir(f'b{probNum}'):
    if testFileInput.find('in') != -1 and \
       not testFileInput.endswith('.out'):
        # if there are another patterns between input, output and
        # your results, fix the below lines
        testFileInput = f'b{probNum}\\' + testFileInput
        testFileOutput = testFileInput.replace('input', 'result')
        myOutputFile = testFileInput + ".out"

        N_TEST += 1
        print(f'***Test {N_TEST}:')

        begin_time = time.time()
        os.system('a.exe' + C + ' ' + testFileInput)
        end_time = time.time()
        runTime = end_time - begin_time

        removeendlineatendfile(testFileOutput)
        removeendlineatendfile(myOutputFile)
        res = filecmp.cmp(testFileOutput, myOutputFile)

        if res:
            N_CORRECT += 1
            print('AC!')
        else:
            print('!WA')
        if runTime > 1.:
            print('!!TLE!!')
        print(f'time: {runTime}')
print(f'Total correct: {N_CORRECT}/{N_TEST}')
os.remove('a.exe')
