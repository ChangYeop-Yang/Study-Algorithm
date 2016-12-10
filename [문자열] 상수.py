string = str(input()).split()

A1 = list(string[0])
A2 = list(string[1])
A1.reverse()
A2.reverse()

A3 = int("".join(A1))
A4 = int("".join(A2))

print(max(A3, A4))
