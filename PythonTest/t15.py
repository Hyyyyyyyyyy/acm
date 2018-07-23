# coding=UTF-8
from sys import argv
script, filename = argv
txt = open(filename)    #open()返回一个指向文件开头的指针
print "Here's your file %r:" % filename
print txt.read()        #read()返回从字符串中读取的字节，可以有参数int 代表需要读几个字符

print "Type the filename again:"
file_again = raw_input("> ")

txt_again = open(file_again)

print txt_again.read()
#cd PythonTest
#python t15.py aa.txt
#aa.txt