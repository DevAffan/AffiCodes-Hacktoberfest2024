import random

def generate_random_number(minimum, maximum):
    return random.randint(minimum, maximum)

# Define the range
min_value = int(input("Enter the minimum value: "))
max_value = int(input("Enter the maximum value: "))

# Generate and display the random number
random_number = generate_random_number(min_value, max_value)
print(f"Random number between {min_value} and {max_value}: {random_number}")
