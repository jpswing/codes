x = []
y = []

for i in range(3):
    x0, y0 = map(int, input().split(' '))
    x.append(x0)
    y.append(y0)

if all(x[0] == x0 for x0 in x) or all(y[0] == y0 for y0 in y):
    print(1)
    exit()

for i in range(3):
    for j in range(3):
        if i == j: continue
        k = 3 - i - j
        if (x[i] == x[k] and min(y[i], y[j]) <= y[k] <= max(y[i], y[j])) or (y[i] == y[k] and min(x[i], x[j]) <= x[k] <= max(x[i], x[j])):
            print(2)
            exit()

print(3)

