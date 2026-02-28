import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("dft_output.csv")
plt.plot(data['k'], data['Magnitude'])
plt.title("Magnitude Spectrum")
plt.xlabel("Frequency Bin (k)")
plt.ylabel("Magnitude")
plt.grid(True)
plt.show()

