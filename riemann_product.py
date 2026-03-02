import sympy as sp
# written by ChatGPT

"""
how many terms must you use in the product formula for the Riemann zeta
function of 2 to approximate pi^2/6 to 2 decimal places?
"""

# Value of zeta(2) = pi^2 / 6
true_value = sp.pi**2 / 6
true_value_flt = float(true_value)

# Define the required accuracy (2 decimal places => within 0.005)
tolerance = 0.005

# Generate prime numbers and compute partial product
partial_product = 1
num_terms = 0

for p in sp.primerange(2, 200):  # Check primes up to 200
    term = 1 / (1 - 1 / (p**2))
    partial_product *= term
    num_terms += 1

    if abs(partial_product - true_value_flt) < tolerance:
        break

print(f"Number of primes needed: {num_terms}")
print(f"Partial product approximation: {partial_product}")
print(f"True value (pi^2/6): {true_value_flt}")  # minor edit lrb - 9/5/25

