import matplotlib.pyplot as plt
import subprocess as sb 

sb.run(['powershell','g++ insertionSort.cpp -o insertionSort'])
sb.run(['powershell','./insertionSort'])
# Retreive Sizes of Array
with open("insertionSize.txt") as f:
    size = f.read()

# Retreive Averages of Arrays
with open("insertionAverage.txt") as f:
    average = f.read()

size = list(map(int, size.split(",")))
average = [int(i) for i in list(average.split(","))]
plt.plot(size, average)
plt.xlabel("Sizes of Array")
plt.ylabel("Averages of Arrays")
plt.grid(True)
plt.show()
