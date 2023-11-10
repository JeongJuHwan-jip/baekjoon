a, b, c = map(int, input().split())

if a==b and b==c:
    ans = 10000 + 1000 * a
elif a==b or b==c:
    ans = 1000 + 100 * b
elif a==c:
    ans = 1000 + 100 * a
elif a > b and a > c:
    ans = a * 100
elif b > a and b > c:
    ans = b * 100
else:
    ans = c * 100

print(ans)