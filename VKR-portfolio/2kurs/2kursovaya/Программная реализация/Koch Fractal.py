import turtle


def koch(t, iterations, length, shortening_factor, angle):
    if iterations == 0:
        t.forward(length)
    else:
        iterations = iterations - 1
        length = length / shortening_factor
        koch(t, iterations, length, shortening_factor, angle)
        t.left(angle)
        koch(t, iterations, length, shortening_factor, angle)
        t.right(angle * 2)
        koch(t, iterations, length, shortening_factor, angle)
        t.left(angle)
        koch(t, iterations, length, shortening_factor, angle)


t = turtle.Turtle()
t.hideturtle()

for i in range(3):
    koch(t, 4, 50, 2, 60)
    t.right(120)

turtle.mainloop()