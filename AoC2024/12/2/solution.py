lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

n = len(lines)
m = len(lines[0])

isVisited = [[False] * m for _ in range(n)] 

def traverse(i : int, j : int):
	if isVisited[i][j]:
		return set()

	isVisited[i][j] = True

	region = set([(i, j)])

	# up
	if i - 1 >= 0 and lines[i][j] == lines[i-1][j]:
		region |= traverse(i-1, j)

	# down
	if i + 1 < n and lines[i][j] == lines[i+1][j]:
		region |= traverse(i+1, j)

	# left
	if j-1 >= 0 and lines[i][j] == lines[i][j-1]:
		region |= traverse(i, j-1)
	
	# right
	if j+1 < m and lines[i][j] == lines[i][j+1]:
		region |= traverse(i, j+1)
	
	return region

def getCost(region : set[int]) -> int:
	total = 0
	donePlots = set()
	for plot in region:
		if plot in donePlots:
			continue

		donePlots.add(plot)
		peri = 4
		for x in [-1, 0, 1]:
			for y in [-1, 0, 1]:
				if (x*y != 0) or x == y:
					continue

				if (plot[0] - x, plot[1] - y) in region:
					peri -= 1
		
		
	return total * len(region)

ans = 0
for i in range(n):
	for j in range(m):
		if isVisited[i][j]:
			continue

		region = traverse(i, j)
		ans += getCost(region)

print(ans)
