lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines if line != '']

def readButton(line : str) -> tuple[int, int]:
	x = line.split(':')[1].split(',')
	x = tuple(int(c.split('+')[1]) for c in x)

	return x

def readPrize(line : str) -> tuple[int, int]:
	x = line.split(':')[1].split(',')
	x = tuple(int(c.split('=')[1]) for c in x)

	return x

i = 0
total = 0
while i < len(lines):
	x1, y1 = readButton(lines[i])
	x2, y2 = readButton(lines[i+1])
	x, y = readPrize(lines[i+2])
	
	a = (y * x2 - x * y2) // (x2 * y1 - y2 * x1)
	b = (y * x1 - x * y1) // (x1 * y2 - y1 * x2)
	if (a * x1 + b * x2 == x) and (a * y1 + b * y2 == y) and (a > 0) and (b > 0):
		total += 3*a + b

	i += 4

print(total)