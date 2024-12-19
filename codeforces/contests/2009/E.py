from math import sqrt

def expr(x, b, c):
	return int(x * x + x * b - c)

_ = int(input())
for __ in range(_):
	n, k = map(int, input().split())
	c = (n * (n+2*k-1)) / 2
	b = 2 * k - 1

	x = (-b + sqrt(b*b + 4 * c)) // 2
	print(min(abs(expr(x, b, c)), min(abs(expr(x+1, b, c)), abs(expr(x-1, b, c)))))