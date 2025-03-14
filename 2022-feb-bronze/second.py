N = int(input())
incorrect = [int(x) for x in input().split()]
correct = [int(x) for x in input().split()]

i = 0
c = 0
output = 0
blacklist = set()
while c < N:
    if incorrect[i] in blacklist:
        i += 1
    elif incorrect[i] == correct[c]:
        i += 1
        c += 1
    else:
        blacklist.add(correct[c])
        c += 1
        output += 1

print(output)
    
