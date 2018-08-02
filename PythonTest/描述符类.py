# coding=UTF-8
#描述符Str
class Str:
    def __get__(self, instance, owner):
        print('Str调用')
    def __set__(self, instance, value):
        print('Str设置...')
    def __delete__(self, instance):
        print('Str删除...')
 
 
#描述符Int
class Int:
    def __get__(self, instance, owner):
        print('Int调用')
    def __set__(self, instance, value):
        print('Int设置...')
    def __delete__(self, instance):
        print('Int删除...')
 
 
class People:
    name=Str()
    age=Int()
    def __init__(self,name,age): #name被Str类代理,age被Int类代理,
        self.name=name
        self.age=age
    def printname(self):
        print self.name
    def printage(self):
        print self.age

p1=People
#描述符Str的使用
p1.name
# p1.printname()
p1.name='egon'
# p1.printname()
del p1.name
# p1.printname()