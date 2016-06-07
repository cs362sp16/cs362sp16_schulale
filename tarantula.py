from __future__ import division
import subprocess
import sys
import os


def severityGreen(message):
    print '\033[92m' + message + '\033[0m'

def severityRed(message):
    print '\033[91m' + message + '\033[0m'

def severityYellow(message):
    print '\033[93m' + message + '\033[0m'

def getDigits(x):
    count = 0
    while x != 0:
        count += 1
        x = x // 10
    return count

def getResults(message):
    return not message.startswith('Verify362')

def getLines(file):
    return len(open(file, 'r').readlines())

def suspiciousness(passed, failed, totalpassed, totalfailed):
    if (totalfailed == 0 or totalpassed == 0):
        return 0
    else:
        numerator = failed / totalfailed
        denominator = passed / totalpassed + numerator
        return numerator / denominator

def main():
    maxunittests = 4 #defines max number of tests
    maxcardtests = 3
    sourceFile = 'dominion.c'
    #define the test suite
    cardtests = ['cardtest' + str(i) for i in range(1, maxcardtests + 1)]
    unittests = ['unittest' + str(i) for i in range(1, maxunittests + 1)]
    alltests = unittests + cardtests
    #define variables used to compute suspiciousness of coverage unit
    count = getLines(sourceFile)
    passed = [0 for i in range(count + 1)]
    failed = [0 for i in range(count + 1)]
    totalpassed = 0
    totalfailed = 0
    #run test suite and log results
    for test in alltests:
        #compile and execute unit test
        subprocess.call(['make', 'clean'])
        subprocess.call(['make', test])
	with open(test + '.out', 'r') as f:
		temp = f.readline()
        if (temp.startswith('+')):
            totalpassed += 1
            results = 1
        else:
            totalfailed += 1
	    results = 0
        subprocess.call(['gcov', sourceFile])
        for lines in open(sourceFile + '.gcov', 'r').readlines():
            temp = lines.split(':')
            x = temp[0].lstrip()
            i = int(temp[1])
            if x.startswith('-') or x.startswith('#') or x.startswith('='):
                continue
            elif results:
                passed[i] += 1
            else:
                failed[i] += 1
    width = getDigits(count)
    i = 1
    for lines in open(sourceFile, 'r').readlines():
        message = str(i).rjust(width) + ':' + lines[:-1]
        if passed[i] > 0 or failed[i] > 0:
            temp = suspiciousness(passed[i], failed[i], totalpassed, totalfailed)
            if temp == 0:
                severityGreen(message)
            elif temp <= 0.5:
                severityYellow(message)
            else:
                severityRed(message)
        else:
            print message
        i += 1

if __name__ == '__main__':
    main()
