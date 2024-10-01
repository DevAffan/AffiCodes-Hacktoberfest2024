def findResult(arr, k, x, l, r):
    if r>l:
        mid = l+(r-l)//2
        if (x-arr[mid]) > (arr[mid+k]-x):
            return findResult(arr, k, x, mid+1, r)
        else:
            return findResult(arr, k, x, l, mid)
    else:
        return arr[l:l+k]

def findClosestElements(arr, k, x):
    return findResult(arr, k, x, 0, len(arr)-k)

if __name__ == "__main__":
    arr, k, x = [1, 1, 2, 3, 4, 5], 4, -1
    result = findClosestElements(arr, k,x)
    print(result)