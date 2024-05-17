import matplotlib.pyplot as plt
import subprocess as sb 

sb.run(['powershell','g++ mergeSort.cpp -o mergeSort'])
sb.run(['powershell','./mergeSort'])
# Retreive Sizes of Array
with open("mergeSizes.txt") as f:
    size = f.read()

# Retreive Averages of Arrays
with open("mergeAverages.txt") as f:
    average = f.read()

size = list(map(int,size.split(",")))
average = list(map(int,map(float,average.split(","))))

plt.plot(size,average)
plt.xlabel("Sizes of Array")
plt.ylabel("Averages of Arrays")
plt.grid(True)
plt.show()
