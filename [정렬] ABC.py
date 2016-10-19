number = list(str(input()).split(" "))
 
total = list()
for ii in range(len(number)) :
    total.append(int(number[ii]))
 
total.sort()
 
string = list(str(input()))
string[string.index('A')] = total[0]
string[string.index('B')] = total[1]
string[string.index('C')] = total[2]
 
print("%d %d %d" %(string[0], string[1], string[2]))
