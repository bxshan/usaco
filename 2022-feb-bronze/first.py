import math

T = int(input())
N_list = []
sleep = []
for _ in range(T):
    N = int(input())
    N_list.append(N)
    line = [int(x) for x in input().split()]
    sleep.append(line)

for i in range(T):
    sleep_sum = sum(sleep[i])
    sum_p = []
    for j in range(N, 0, -1):
        if sleep_sum % j == 0:
            sum_p.append(j)

    for l in sum_p:
        val = 0
        number = sleep_sum / l
        n = 0
        output = 0
        while n < N_list[i]:
            val += sleep[i][n]
            if val == number: 
                n += 1
                val = 0
            elif val > number: break
            elif val < number: n += 1
        if n == N_list[i]:
           print(N_list[i]-l)
           break
