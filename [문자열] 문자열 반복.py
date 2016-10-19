number = int(input())

for ii in range(number) :
    Listing = list(str(input()).split(" "))
    string = list(Listing[1])
    for jj in range(len(string)) :
        print(string[jj] * int(Listing[0]), end="")
    print()
