import matplotlib.pyplot as plt

# Data: (value, frequency) pairs
data = [(16, 994), (17, 882), (18, 752), (19, 596),
        (20, 521), (21, 471), (22, 410), (23, 374)]

# Separate the data into two lists for plotting
values = [pair[0] for pair in data]
frequencies = [pair[1] for pair in data]

# Create the plot
plt.bar(values, frequencies)

# Label the axes and title the plot
plt.xlabel('Value')
plt.ylabel('Frequency')
plt.title('Value vs Frequency')

# Show the plot
plt.show()
