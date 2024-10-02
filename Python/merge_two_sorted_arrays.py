def mergearrays(li1,li2):
    li3=[]
    i,j=0,0
    while i<(len(li1)) and j<(len(li2)):
        if li1[i]<li2[j]:
            li3.append(li1[i])                                                      
            i=i+1                                                      
        elif li2[j]<=li1[i]:                                                      
            li3.append(li2[j])
            j=j+1
    while i<(len(li1)):
        li3.append(li1[i])
        i=i+1
    while j<(len(li2)):
        li3.append(li2[j])
        j=j+1
    return li3
        
print('Enter the number of test cases')
test_cases=int(input()) #Number of test cases
for r in range(test_cases):
    print('Length of list 1')
    n1=int(input())
    if n1!=0:  # Length of list 1
        print('Enter your list 1 with space separated inputs')
        li1=[int(x) for x in input().split()]
    else:
        li1=[]
    print('Length of list 2')
    n2=int(input())  #Length of list 2
    if n2!=0:
        print('Enter your list 2 with space separated inputs')
        li2=[int(y) for y in input().split()]
    else:
        li2=[]
    for k in mergearrays(li1,li2):
        print(k,end=' ')
    print()
    
    
    
                                                                                                         
