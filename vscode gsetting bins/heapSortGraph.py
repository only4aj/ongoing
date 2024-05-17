import matplotlib.pyplot as plt 
import subprocess as sb 

sb.run(['powershell','g++ heapSort.cpp -o heapSort'])
sb.run(['powershell','./heapSort'])

with open("heapSortSizes.txt") as f:
    sizes = f.read()

with open("heapSortAverages.txt") as f:
    averages = f.read()

sizes = [int(i) for i in sizes.split(",")]
averages = [int(i) for i in averages.split(",")]

plt.plot(sizes,averages)
plt.title("Heap Sort Graph")
plt.xlabel("Sizes of Array")
plt.ylabel("Averages of Arrays")
plt.grid(True)
plt.show()