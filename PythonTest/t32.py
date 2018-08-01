the_count = [1,2,3,4,5]
fruits = ['apple','orange','pear','apricot']
change = [1,'pennies',2,'dimes',3,'quarters']

for num in the_count:
    print "This is count %d" % num
for i in fruits:
    print "A fruit of type: %s" % i
for i in change:
    print "I got %r" % i

elements = []
j = "5"
for i in range(0, 6):
    print "Adding ", i, j, " to the list"
    elements.append(i)
for i in elements:
    print "Element was : %d" % i
