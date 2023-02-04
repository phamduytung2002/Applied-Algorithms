import os
import argparse
import shutil
import filecmp
import time


parser = argparse.ArgumentParser()
parser.add_argument('filename')
parser.add_argument('-l', '--offline',
                    action='store_true', default=False)
parser.add_argument('-d', '--debug',
                    action='store_true', default=False)
parser.add_argument('-t', '--num_test', type=int, default=5)


config = parser.parse_args()
file = '20200573_BAI' + config.filename
offline = config.offline
debug = config.debug
n_test = config.num_test

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

numcorrect = 0
for i in range(1, n_test+1):
    print(f'***Test {i}:')
    begin_time = time.time()
    os.system(f'a.exe' + c + f' b{config.filename}\{i}-input.txt')
    end_time = time.time()
    res = filecmp.cmp(f'b{config.filename}\{i}-result.txt', f'b{config.filename}\{i}-input.txt.out')
    if res:
        numcorrect += 1
        print('AC!')
    else:
        print('!WA')
    if end_time - begin_time > 1:
        print('!!TLE!!')
    print(f'time: {end_time - begin_time}')
print(f'Total correct: {numcorrect}/{n_test}')

os.remove('a.exe')