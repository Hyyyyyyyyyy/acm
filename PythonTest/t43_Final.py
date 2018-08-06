# -*- coding: UTF-8 -*-
from sys import exit
from random import randint

class Scene(object):
    def enter(self):
        print "This scene is not yet configured. Subclass it and implement enter()."
        exit(1)


class Death(Scene):
    quips = ["You died. You kinda suck at this.",
        "Your mom would be proud... if she were smarter",
        "Such a luser.", 
        "I have a small puppy that's better at this."]
    def enter(self):
        print Death.quips[randint(0, len(self.quips)-1)]
        exit(1)

class CentralCorridor(Scene):
    def enter(self):
        print """The Gothons of Planet Percal #25 have invaded your ship and destroyed
        your entire crew. You are the last surviving member and your last
        mission is to get the neutron destruct bomb from the Weapons Armoy,
        put it in the bridge, and blow the ship up after gettting into an
        escape pod.\n
        You're running dowm the central corridor to the Weapons Armoy when
        a Gothon jumps out, red scaly skin, dark grimy teeth, and evil clown costume
        flowing around his hate filled body, He's blocking the door to the
        Armoy and about to pull a weapon to blast you."""

        action = raw_input("> ")
        if action == "shoot!":
            print "Shoot it"
            return 'death'
        elif action == 'dodge!':
            print "Dodge"
            return 'death'
        elif action == "tell a joke":
            print "tell a joke"
            return 'laser_weapon_armory'
        else:
            print "DOES NOT COMPUTE!"
            return 'central_corridor'

class LaserWeaponArmory(Scene):
    def enter(self):
        print "get the bomb, The code is 3 digits."
        code = "666"
        guess = raw_input("> ")
        guesses = 0

        while guess != code and guesses < 9:
            print "BZZZZZZEDDD!"
            guesses += 1
            guess = raw_input("> ")
        if guess == code:
            print "bingo"
            return 'the_bridge'
        else:
            print "sorry"
            return 'death'

class TheBridge(Scene):
    def enter(self):
        action = raw_input("> ")
        if action == "throw the bomb":
            return 'death'
        elif action == "slowly place the bomb":
            return 'escape_pod'
        else:
            return "the_bridge"

class EscapePod(Scene):
    def enter(self):
        print "do u take?"
        good_pod = "Sure"
        guess = raw_input(">")

        if guess != good_pod:
            return 'death'
        else:
            return 'finished'

class Pass(Scene):
    def enter(self):
        print "Congratulations! You beat the Gothon!"
        exit(0)

class Map(object):
    scenes = {
        'central_corridor': CentralCorridor(),
        'laser_weapon_armory': LaserWeaponArmory(),
        'the_bridge': TheBridge(),
        'escape_pod': EscapePod(),
        'death': Death(),
        'finished': Pass()
    }

    def __init__(self, start_scene):
        self.start_scene = start_scene
    def next_scene(self, scene_name):
        return Map.scenes.get(scene_name)
    def opening_scene(self):
        return self.next_scene(self.start_scene)

class Engine(object):
    def __init__(self, scene_map):
        self.scene_map = scene_map
    def play(self):
        current_scene = self.scene_map.opening_scene()
        while True:
            print "\n--------"
            next_scene_name = current_scene.enter()
            current_scene = self.scene_map.next_scene(next_scene_name)

a_map = Map('central_corridor')
a_game = Engine(a_map)
a_game.play()