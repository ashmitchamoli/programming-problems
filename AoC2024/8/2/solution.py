import math

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
				unitVector = loc[0] - i, loc[1] - j

				# compute hcf to reduce
				gcd = math.gcd(*list(map(abs, unitVector)))
				unitVector = (unitVector[0] /  gcd, unitVector[1] / gcd)

				# compute all points on line
				x1, y1 = loc
				while (0 <= x1 < n and 0 <= y1 < m):
					antinodes.add((x1, y1))

					x1 += unitVector[0]
					y1 += unitVector[1]
				
				x2, y2 = i, j
				while (0 <= x2 < n and 0 <= y2 < m):
					antinodes.add((x2, y2))

					x2 -= unitVector[0]
					y2 -= unitVector[1]

			signalMap[lines[i][j]].append((i, j))
		
		else:
			signalMap[lines[i][j]] = [(i, j)]

print(len(antinodes))