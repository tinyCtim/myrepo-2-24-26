import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad

#-------------------------------------------------------
# Upper and lower branches
#-------------------------------------------------------
def y_upper(x):
    return 0.5*x*(3 + np.sqrt(9 - 4*x))

def y_lower(x):
    return 0.5*x*(3 - np.sqrt(9 - 4*x))

#-------------------------------------------------------
# Derivatives
#-------------------------------------------------------
def dy_upper(x):
    s = np.sqrt(9 - 4*x)
    return (3 + s)/2 - x/s

def dy_lower(x):
    s = np.sqrt(9 - 4*x)
    return (3 - s)/2 + x/s

#-------------------------------------------------------
# Arc-length integrands
#-------------------------------------------------------
def integrand_upper(x):
    return np.sqrt(1 + dy_upper(x)**2)

def integrand_lower(x):
    return np.sqrt(1 + dy_lower(x)**2)

#-------------------------------------------------------
# Compute arc lengths
#-------------------------------------------------------
L_upper, err1 = quad(integrand_upper, 1, 2)
L_lower, err2 = quad(integrand_lower, 1, 2)

print()
print("Arc Lengths")
print("----------------------------")
print(f"Upper branch = {L_upper:.10f}")
print(f"Lower branch = {L_lower:.10f}")

#-------------------------------------------------------
# Table
#-------------------------------------------------------
print("\nTable of Values")
print("-"*65)
print(f"{'x':>5} {'Upper y':>12} {'Lower y':>12} {'Upper dy/dx':>14} {'Lower dy/dx':>14}")

xs = np.arange(1.0, 2.01, 0.1)

for x in xs:
    print(f"{x:5.1f}"
          f"{y_upper(x):12.6f}"
          f"{y_lower(x):12.6f}"
          f"{dy_upper(x):14.6f}"
          f"{dy_lower(x):14.6f}")

#-------------------------------------------------------
# Plot
#-------------------------------------------------------
x = np.linspace(1,2,400)

plt.figure(figsize=(8,6))
plt.plot(x, y_upper(x), label='Upper branch')
plt.plot(x, y_lower(x), label='Lower branch')

plt.title(r'$y^2-3xy+x^3=0$')
plt.xlabel('x')
plt.ylabel('y')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()

