# coding=UTF-8
from sys import argv
script, input_file = argv

def print_all(f):
    print f.read(),"\n"
def rewind(f):
    f.seek(0)   #seek(offset,where) offset偏移量，从where开始偏移(默认0从头开始，1从当前位置开始，2从文末开始)
def print_a_line(line_count, f):
    print line_count, f.readline()

current_file = open(input_file)
print "Lets print the whole file:\n"
print_all(current_file)
print "Now lets rewind, kind of like a tape."
rewind(current_file)
print "Lets print three lines:"
current_line = 1
print_a_line(current_line, current_file)
current_line += 1
print_a_line(current_line, current_file)
current_line += 1
print_a_line(current_line, current_file)
#cd PythonTest
#python t20.py in.txt