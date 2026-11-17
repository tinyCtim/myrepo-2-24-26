
import matplotlib.pyplot as plt

# Read the data file

# Ask for the name of the data file

print("What is the name of the data file, e.g. pop.dat ", end="") 
filename = str(input())

with open(filename, "r") as file:
    lines = file.readlines()

# First line contains the number of data values
n = int(lines[0].strip())

# Read the remaining data values
data = [float(line.strip()) for line in lines[1:n+1]]

# Check that the correct number of values was read
if len(data) != n:
    raise ValueError("Incorrect number of data values")

# Generate the vertical bar graph
x = range(1, n + 1)

plt.figure(figsize=(12, 6))
plt.bar(x, data, width=0.8)

plt.xlabel("Generation number")
plt.ylabel("Population")
plt.title("Population Bar Graph. Starting Life pattern : ?? cells in a row on a ??x?? board")
plt.grid(axis="y", linestyle="--", alpha=0.5)
plt.tight_layout()
plt.show()
