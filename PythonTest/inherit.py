class Parent(object):
    def __init__(self):
        self.parent = "I'm the parent"
        print "Parent"
    def bar(self, message):
        print "%s from parent" % message

class Child(Parent):
    def __init__(self):
        super(Child, self).__init__()
        print "Child"
    def bar(self, message):
        super(Child, self).bar(message)
        print "Child bar function"
        print self.parent
if __name__ == '__main__':
    child = Child()
    child.bar("Hello world")
