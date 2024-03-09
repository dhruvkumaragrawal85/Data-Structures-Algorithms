from decimal import Decimal, getcontext

# Set the precision
getcontext().prec = 1001

# Calculate the square root of 2
sqrt_2 = Decimal(2).sqrt()

print(sqrt_2)
