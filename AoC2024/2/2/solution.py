from typing import List

lines = None
with open("input.txt") as f:
	lines = f.readlines()

def isSafe(l : List[int]):
	monotonic = l[0] < l[1]

	for i in range(1, len(l)):
		if monotonic != (l[i-1] < l[i]):
			return False
		
		if not (0 < abs(l[i] - l[i-1]) <= 3):
			return False

	return True

safeCount = 0
for line in lines:
	l = list(map(int, line.split(" ")))

	if isSafe(l):
		safeCount += 1
		continue

	for i in range(len(l)):
		if isSafe(l[:i] + l[i+1:]):
			safeCount += 1
			break

print(safeCount)