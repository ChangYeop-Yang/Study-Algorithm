string = list(str(input()))
 
List = list()
for ii in range(len(string)):
    aa = (((ord(string[ii])-65)-3) % 26)+65
    List.append(chr(aa))
 
print("".join(List))
