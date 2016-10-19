class student:
    def __init__(self, age, name, rank):
        self.name = str(name)
        self.age = int(age)
        self.rank = int(rank)

    def print(self):
        print("%d %s" % (self.age, self.name))


number = int(input())

total = list()
for ii in range(number):
    temp = str(input()).split(" ")
    total.append(student(temp[0], temp[1], ii))

total.sort(key=lambda x: (x.age, x.rank))

for ii in range(len(total)):
    total[ii].print()
