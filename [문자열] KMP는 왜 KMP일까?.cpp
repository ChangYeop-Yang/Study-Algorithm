string = str(input()).split('-')

qq = ""
for ii in range(len(string)):
    qq += string[ii][0]

print(qq)
