number = int(input())
mArr = str(input()).split(' ')

sum = 0
count = 0
for ii in range(number) :
    if (mArr[ii] == '0') :
        count = 0
        continue
    else :
        count += 1
        sum += count

print(sum)
