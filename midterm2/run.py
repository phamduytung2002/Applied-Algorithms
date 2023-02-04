import os
import argparse
import filecmp
import time


def removeEndlineAtEndFile(file):
    my_file =  open(file, "r+")
    content = my_file.read()
    content = content.rstrip('\n')
    my_file.seek(0)

    my_file.write(content)
    my_file.truncate()
    my_file.close()


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
    c = ' a'
elif not offline and debug:
    c = ' b'
elif offline and not debug:
    c = ' c'
elif not offline and not debug:
    c = ' d'
else:
    c = ''


os.system(f'g++ -o a.exe {file}.cpp')

if not os.path.exists('a.exe'):
    print('!!Compile error!!')
    exit()

n_test = 0
n_correct = 0
for testFileInput in os.listdir(f'b{probNum}'):
    if testFileInput.find('in') != -1 and \
       not testFileInput.endswith('.out'):
        # if there are another patterns between input, output and 
        # your results, fix the below lines
        testFileInput = f'b{probNum}\\' + testFileInput
        testFileOutput = testFileInput.replace('input', 'result')
        myOutputFile = testFileInput + ".out"

        n_test += 1
        print(f'***Test {n_test}:')

        begin_time = time.time()
        os.system(f'a.exe' + c + ' ' + testFileInput)
        end_time = time.time()
        runTime = end_time - begin_time

        removeEndlineAtEndFile(testFileOutput)
        removeEndlineAtEndFile(myOutputFile)
        res = filecmp.cmp(testFileOutput, myOutputFile)

        if res:
            n_correct += 1
            print('AC!')
        else:
            print('!WA')
        if runTime > 1.:
            print('!!TLE!!')
        print(f'time: {runTime}')
print(f'Total correct: {n_correct}/{n_test}')

os.remove('a.exe')