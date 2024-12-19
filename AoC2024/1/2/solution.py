from collections import Counter

with open("input.txt") as f:
	inp = f.readlines()
	l1, l2 = map(list, zip(*[list(map(int, line.split("   "))) for line in inp]))
	
	l1 = Counter(l1)
	l2 = Counter(l2)

	print(sum([num * l2[num] * l1[num] for num in l1]))