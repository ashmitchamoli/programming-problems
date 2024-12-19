with open("input.txt") as f:
	inp = f.readlines()
	l1, l2 = map(list, zip(*[list(map(int, line.split("   "))) for line in inp]))
	
	l1.sort()
	l2.sort()

	print(sum(abs(x - y) for x, y in zip(l1, l2)))