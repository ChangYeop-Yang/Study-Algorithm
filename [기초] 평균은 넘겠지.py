number1 = int(input())

total = list()
for ii in range(number1) :
    score = [int(item) for item in str(input()).split(" ")]
    average = sum(score[1:])/score[0]
    counts = [item for item in score[1:] if average < item]
    total.append( (len(counts) / score[0]) * 100 )

for ii in range(number1) :
    print("%.3f%%" %total[ii])
