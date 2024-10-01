def is_palindrome_number(num):
    # Convert the number to string to easily check for palindrome
    str_num = str(num)
    # A palindrome reads the same forwards and backwards
    return str_num == str_num[::-1]

# Example usage
number = 121  # You can change this number to test other values
if is_palindrome_number(number):
    print(f"{number} is a palindrome.")
else:
    print(f"{number} is not a palindrome.")
