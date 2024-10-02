def factorial(n):
    if n < 0:
        return "Factorial is not defined for negative numbers."
    elif n == 0 or n == 1:
        return 1
    else:
        result = 1
        for i in range(2, n + 1):
            result *= i
        return result

# Get user input
number = int(input("Enter a number to find its factorial: "))
fact = factorial(number)

print(f"The factorial of {number} is: {fact}")
