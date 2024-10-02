def spiral(string):
    n,m=int(string[0]),int(string[1])
    li=[[int(x) for x in input().split()] for i in range(n)]
    for k in range(0,(n//2)+1,1):
        if(k<(m//2)+1):
            i=k
            for j in range(k,m-k,1):
                print(li[i][j],end=" ")
            j=m-1-k
            for i in range(k+1,n-k,1):
                print(li[i][j],end=" ")
            i=n-1-k
            for j in range(m-2-k,-1+k,-1):
                print(li[i][j],end=" ")
            j=k
            for i in range(n-2-k,k,-1):
                print(li[i][j],end=" ")
print('Enter the number of test cases')
test_cases=int(input())
for r in range(test_cases):
    print('Enter the rows and columns separated with a space')
    string=input().split()
    spiral(string)
    print()
    