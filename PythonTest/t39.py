states = {
    'Oregon': 'OR',
    'Florida': 'FL',
    'California': 'CA',
    'New York': 'NY',
    'Michigan': 'MI'
}

cities = {
    'CA': 'San Francisco',
    'MI': 'Detroit',
    'FL': 'Jacksonville'
}

cities['NY'] = 'New York'
cities['OR'] = 'Portland'

print '-'*10
print "NY State has: ", cities['NY']
print "OR State has: ", cities['OR']
print '-'*10

print "Michigan's abbreviation is: ", states['Michigan']
print "Florida's abbreviation is: ", states['Florida']
print '-'*10

print "Michigan has: ", cities[states['Michigan']]
print "Florida has: ", cities[states['Florida']]
print '-'*10

for state,abbr in states.items():
    print "%s is abbreviated %s" % (state, abbr)
print '-'*10

for abbr,city in cities.items():
    print "%s has city %s" % (abbr, city)
print '-'*10

print '-'*10
for state, abbr in states.items():
    print "%s state is abbreviated %s and has city %s" % (state, abbr, cities[abbr])
print '-'*10

state = states.get('Texas', None)
if not state:
    print "NO Texas"

city = cities.get('TX', 'NOT EXIT')
print "The city for the state 'TX' is: %s" % city
