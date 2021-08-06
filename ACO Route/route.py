import turtle
RATIO = 10
myTurtle = turtle.Turtle()
route = []

file_handler = open('hasil.txt','r')

file = file_handler.readlines()

for x in file:
    route.append(x.rstrip('\n').split(' '))


print(route)
myTurtle.penup()
for x in route:
    myTurtle.goto(int(x[1]) * RATIO, int(x[2]) * RATIO)
    myTurtle.write(x[0],True, align="center")
    myTurtle.pendown()

input()