class Song():
    def __init__(self, ly):
        self.ly = ly
    def sing_me(self):
        for line in self.ly:
            print line

happy_day = Song(["happy birthday to you", "I dont want to get sued", "So I'll stop right there"])
bulls = Song(["They rally around the family", "With pockets full of shells"])

happy_day.sing_me()
bulls.sing_me()
