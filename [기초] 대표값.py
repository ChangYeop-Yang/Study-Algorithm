data = {}
sum = 0
 
for i in range(10):
    ii = int(input())
    sum += ii # Add
    if ii in data.keys():
        data[ii] += 1
    else:
        data[ii] = 0
 
print("%d\n%d" %(sum/10, max(data, key=data.get))) # output
