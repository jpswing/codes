t = int(input())
input()

m = int(input())
lines = []
for i in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    lines.append(((x1, y1), (x2, y2))) 
n = int(input())
pts = []
for i in range(n):
    x, y = map(int, input().split())
    pts.append((x, y))

