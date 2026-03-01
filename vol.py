import matplotlib.pyplot as plt
import numpy as np

# Define y values
y = np.linspace(1, 2, 400)

# Define x = 2/y and x = 2y
x1 = 2 / y
x2 = 2 * y

# Create the plot
plt.figure(figsize=(8, 6))
plt.plot(x1, y, label=r"$x = \frac{2}{y}$", color='blue')
plt.plot(x2, y, label=r"$x = 2y$", color='red')

# Fill the region between the curves
plt.fill_betweenx(y, x1, x2, where=(x2 > x1), color='gray', alpha=0.5)

# Draw lines for y = 1 and y = 2
plt.axhline(y=1, color='black', linestyle='--', linewidth=1)
plt.axhline(y=2, color='black', linestyle='--', linewidth=1)

# Labels and title
plt.xlabel("x")
plt.ylabel("y")
plt.title("Region Bounded by $x=\\frac{2}{y}$, $x=2y$, $y=1$, and $y=2$")
plt.legend()
plt.grid(True)
plt.xlim(0, 5)
plt.ylim(0.5, 2.5)
plt.gca().set_aspect('auto')

plt.show()
