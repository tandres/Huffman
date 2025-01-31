#python test script for huffman project
import os
import time
#function declarations
#selftest just runs the file without input
def selftest(dut):
	time1 = time.time()
	os.system("./%s" %(dut))
	return time1 - time.time()
def testcase(dut, filename):
	time1 = time.time()
	print "./%s ./Samples/%s" %(dut,filename)
	os.system("./%s ./Samples/%s" %(dut,filename))
	#os.system("./%s ./Samples/%s > ./testresults/testrun-%s-%s.txt" %(dut,filename,time.strftime("%b%d_%H:%M:%S"),filename))
	return time1 - time.time()
#test code
saucename = "huff"
unsaucename = "unhuff"

#output file
#f = open("./testresults/testrun-%s" % (time.strftime("%b%d_%H:%M:%S")),'w')
#f.write("Huffman test Run Result")

#attempt to compile c source
#gccres = os.system("gcc -Wall -Werror -o3 ./%s.h ./%s.c -o ./%s" % (saucename,saucename,saucename))
hgccres = os.system("gcc -Wall -Werror -o3 ./%s.c -o ./%s" % (saucename,saucename))
ugccres = os.system("gcc -Wall -Werror -o3 ./%s.c -o ./%s" % (unsaucename,unsaucename))
if hgccres == 0 and ugccres == 0:
	print "**Compilation FTW!**"
else:
	print "**Compilation Fail!**"
#main code
if hgccres == 0 and ugccres == 0:
	testcase(saucename,"small1.txt")
	testcase(unsaucename,"small1.txt.huff")
