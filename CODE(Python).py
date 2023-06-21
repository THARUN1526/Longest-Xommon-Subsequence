
n=int(input())
l=[int(i) for i in input().split()]
xors=[]
for i in range(n):
    for j in range(i+1,n):
        xors.append([l[i]^l[j],(i,j)])
xors.sort()

#print(xors)
upto=[0]*n 
for i in range(len(xors)):
    #a=xors[i][0]
    b,c=xors[i][1][0],xors[i][1][1]
    upto[c]=max(upto[c],upto[b]+1)
    
#print(upto)
    
print(max(upto)+1)