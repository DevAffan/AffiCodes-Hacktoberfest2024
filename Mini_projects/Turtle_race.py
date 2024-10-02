from turtle import Turtle, Screen
import random

# Race setup
is_race_active = False
screen = Screen()
screen.setup(width=500, height=400)

# User input for bet
user_bet_color = screen.textinput(title="Make your bet", prompt="Which turtle will win the race? Enter a color: ")

# Define turtle colors and their vertical positions
turtle_colors = ["red", "orange", "yellow", "green", "blue", "purple"]
turtle_y_positions = [-70, -40, -10, 20, 50, 80]
all_racers = []

# Create finish line
finish_line = Turtle()
finish_line.penup()
finish_line.goto(x=230, y=-90)
finish_line.pendown()
finish_line.setheading(90)  # Point upwards
finish_line.forward(180)     # Draw vertical line
finish_line.hideturtle()

# Create turtles and position them
for index in range(len(turtle_colors)):
    racer_turtle = Turtle(shape="turtle")
    racer_turtle.penup()
    racer_turtle.color(turtle_colors[index])
    racer_turtle.goto(x=-230, y=turtle_y_positions[index])
    all_racers.append(racer_turtle)

if user_bet_color:
    is_race_active = True

# Start the race
while is_race_active:
    for racer in all_racers:
        # Check if a turtle crosses the finish line
        if racer.xcor() > 230:
            is_race_active = False
            winning_color = racer.pencolor()
            if winning_color == user_bet_color:
                print(f"You've won! The {winning_color} turtle is the winner!")
            else:
                print(f"You've lost! The {winning_color} turtle is the winner!")
            break  # Exit the for loop once the race is over

        # Move each turtle a random distance forward
        random_distance = random.randint(0, 10)
        racer.forward(random_distance)

screen.exitonclick()
