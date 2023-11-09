arr = [0]*31

for i in range(28):
    idx = int(input())
    arr[idx] = 1

for i in range(1,31):
    if arr[i] == 0:
        print(i)