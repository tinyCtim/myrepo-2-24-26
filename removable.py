import numpy as np
import matplotlib.pyplot as plt

# Define the function (excluding x=5)
def f(x):
    return (-x**2 + 9*x - 20)/(x-5)

# Values for x avoiding the discontinuity
x = np.linspace(0, 10, 400)
x = x[x != 5]

y = f(x)

plt.figure(figsize=(7,5))
plt.plot(x, y, label=r"$y=\frac{-x^2+9x-20}{x-5}$")
plt.axvline(5, color='red', linestyle='--', label="x=5 (hole)")

# Show the removable discontinuity (hole)
plt.scatter(5, -1, color='white', edgecolor='black', s=100, zorder=5, label="hole at (5,-1)")

plt.ylim(-10, 10)
plt.xlim(0, 10)
plt.xlabel("x")
plt.ylabel("y")
plt.title("Graph of $y = \\frac{-x^2+9x-20}{x-5}$")
plt.legend()
plt.grid(True)
plt.show()

