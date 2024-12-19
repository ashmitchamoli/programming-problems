lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

signalMap : dict[str, list] = {}

n = len(lines)
m = len(lines[0])
antinodes = set()
for i in range(n):
	for j in range(m):
		if lines[i][j] == '.':
			continue

		if lines[i][j] in signalMap:
			for loc in signalMap[lines[i][j]]:
				x1 = 2 * i - loc[0]
				y1 = 2 * j - loc[1]
				if 0 <= x1 < n and 0 <= y1 < m:
					antinodes.add((x1, y1))

				x2 = 2 * loc[0] - i
				y2 = 2 * loc[1] - j 
				if 0 <= x2 < n and 0 <= y2 < m:
					antinodes.add((x2, y2))
			signalMap[lines[i][j]].append((i, j))
		
		else:
			signalMap[lines[i][j]] = [(i, j)]

print(len(antinodes))