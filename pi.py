
# pi.py - 7/3,11/24
# fixed by Aaron West

import mpmath

def machin_formula(precision):
    mpmath.mp.dps = precision  # Set the precision (number of decimal places)

    # Machin's formula: pi/4 = 4 * arctan(1/5) - arctan(1/239)
    pi_approx = 4 * (4 * mpmath.atan(mpmathify("1/5")) - mpmath.atan(mpmathify("1/239")))
    return pi_approx

# Calculate pi with up to n digits of precision
print("How many digits do you want?")
n = input()
pi_approximation = machin_formula(n)

print("Approximation of pi using Machin's formula")
print(pi_approximation)

