num = int(input())

aa = str(input()).split()

Dict = {}
for ii in range(num):
    if aa[ii] in Dict.keys():
        Dict[aa[ii]] += 1
    else :
        Dict[aa[ii]] = 0

find = int(input())
if str(find) in Dict : print(Dict.get(str(find)) + 1)
else : print(0)
