
def merge(arr,low,mid,high):
    i=low
    j=mid+1
    k=low

    newarr = []

    while i<= mid and j<=high:
        if arr[i]<arr[j]:
            newarr.insert(k,arr[i])
            k+1,i+1
        else:
            newarr.insert(k,arr[i])
            k+1,j+1
    
    while i<= mid:
        newarr.insert(k,arr[i])
        k+1,i+1

    while j<=high:
        newarr.insert(k,arr[i])
        k+1,j+1
    
    arr = newarr

def mergeSort(arr,high,low=0):
    if(low<high):
        mid = (high+low)//2
        mergeSort(arr,mid,low)
        mergeSort(arr,high,mid+1)
        merge(arr,low,mid,high)
    

num = int(input("Enter size of array : "))

arr = []
for i in range(num):
    arr.insert(i,int(input()))

for i in arr:
    print(i,end=" ")
print()

mergeSort(arr,num)

for i in arr:
    print(i,end=" ")
print()
