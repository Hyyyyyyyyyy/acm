# coding=UTF-8
from sys import argv
script, filename  = argv

print "We're going to create %r." % filename
print "If you don't want that, hit CTRL-C(^C)."
print "If you do want that, hit RETURN."

raw_input("?")

print "Opening the file..."
target = open(filename, 'w')
print "Truncate the file. Goodbye!"
target.truncate()   #清空文件
print "Now I'm going to ask you for three lines."
line1 = raw_input("line1: ")
line2 = raw_input("line2: ")
line3 = raw_input("line3: ")
print "I'm going to write these to the file."
target.write(line1)
target.write("\n")
target.write(line2+"\n")
target.write(line3+"\n")
print "And family, we close it."
target.close()
#cd PythonTest
#python t16.py Out.txt