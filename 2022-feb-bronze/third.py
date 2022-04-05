N = int(input())
dices = []
words = []
for _ in range(4):
    dice = list(input())
    dices.append(dice)
for _ in range(N):
    word = list(input())
    words.append("".join(sorted(word)))

total = []

for a in dices[0]:
    for b in dices[1]:
        for c in dices[2]:
            for d in dices[3]:
                temp = [a, b, c, d]
                total.append("".join(sorted(temp)))

for a in dices[0]:
    for b in dices[1]:
        for c in dices[2]:
            temp = [a, b, c]
            total.append("".join(sorted(temp)))

for a in dices[0]:
    for b in dices[1]:
        for c in dices[3]:
            temp = [a, b, c]
            total.append("".join(sorted(temp)))

for a in dices[1]:
    for b in dices[2]:
        for c in dices[3]:
            temp = [a, b, c]
            total.append("".join(sorted(temp)))

for a in dices[0]:
    for b in dices[2]:
        for c in dices[3]:
            temp = [a, b, c]
            total.append("".join(sorted(temp)))
            
for a in dices[0]:
    for b in dices[1]:
        temp = [a, b]
        total.append("".join(sorted(temp)))

for a in dices[0]:
    for b in dices[2]:
        temp = [a, b]
        total.append("".join(sorted(temp)))

for a in dices[0]:
    for b in dices[3]:
        temp = [a, b]
        total.append("".join(sorted(temp)))

for a in dices[1]:
    for b in dices[2]:
        temp = [a, b]
        total.append("".join(sorted(temp)))

for a in dices[1]:
    for b in dices[3]:
        temp = [a, b]
        total.append("".join(sorted(temp)))

for a in dices[2]:
    for b in dices[3]:
        temp = [a, b]
        total.append("".join(sorted(temp)))

for a in dices[0]:
    temp = [a, b]
    total.append("".join(sorted(temp)))

for a in dices[1]:
    temp = [a, b]
    total.append("".join(sorted(temp)))

for a in dices[2]:
    temp = [a, b]
    total.append("".join(sorted(temp)))

for a in dices[3]:
    temp = [a, b]
    total.append("".join(sorted(temp)))

for word in words:
    if word in total:
        print("YES")
    else: 
        print("NO")
