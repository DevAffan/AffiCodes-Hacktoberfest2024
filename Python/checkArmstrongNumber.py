def is_armstrong_number(num):
    # Convert the number to string to easily iterate over digits
    str_num = str(num)
    # Calculate the number of digits
    num_digits = len(str_num)
    # Calculate the sum of each digit raised to the power of the number of digits
    armstrong_sum = sum(int(digit) ** num_digits for digit in str_num)
    # Check if the sum equals the original number
    return armstrong_sum == num

# Example usage
number = 153  # You can change this number to test other values
if is_armstrong_number(number):
    print(f"{number} is an Armstrong number.")
else:
    print(f"{number} is not an Armstrong number.")
