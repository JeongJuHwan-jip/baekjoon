N, M = map(int, input().split())
arr = [i for i in range(0, N+1)]

for i in range(M):
    a, b = map(int, input().split())
    for j in range((b-a+1) // 2):
        arr[a+j], arr[b-j] = arr[b-j], arr[a+j]

for i in range(1, N+1):
    print(arr[i])
