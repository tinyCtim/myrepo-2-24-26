
# exponential function curve fitting in Python

# https://www.geeksforgeeks.org/how-to-do-exponential-and-logarithmic-curve-fitting-in-python/

# pip install matplotlib

import numpy as np
import matplotlib.pyplot as plt

x_data = np.array([45, 35, 25, 15, 5]) # lrb
print(x_data)

y_data = np.array([205, 60, 30, 16, 6]) # lrb
print(y_data)

ylog_data = np.log(y_data)
print(ylog_data)

curve_fit = np.polyfit(x_data, ylog_data, 1) # lrb
print(curve_fit)

y = np.exp(0.69) * np.exp(0.085*x_data)
print(y)

# Blue 
plt.plot(x_data, y_data)

# best fit in orange
plt.plot(x_data, y)

