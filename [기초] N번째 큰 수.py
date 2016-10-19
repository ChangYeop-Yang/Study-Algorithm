number = int(input())

for ii in range(number) :
    string = [int(item) for item in str(input()).split(" ") if item != ""]
    string.sort(reverse=True)
    print(string[2])
