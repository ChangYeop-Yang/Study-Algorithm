number = int(input())

total_List = list()
for ii in range(number):
    XY = str(input()).split(" ")
    temp1 = [int(x) for x in XY]
    total_List.append(temp1)

total_List.sort(key=lambda x: x[0])
total_List.sort(key=lambda x: x[1])

for ii in range(number) :
    print("%d %d" %(total_List[ii][0], total_List[ii][1]))
