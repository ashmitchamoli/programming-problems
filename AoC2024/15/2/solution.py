lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines if line != '']

readingCommands = False
grid = []
commands = ""
for line in lines:
	readingCommands = line == '' or readingCommands

	if not readingCommands:
		grid.append(list(line))
	else:
		commands += line

def transformGrid(grid : list[list[str]]) -> list[list[str]]:
	newGrid = []
	for y, line in enumerate(grid):
		newLine = []
		for x, char in enumerate(line):
			if char == 'O':
				newLine.extend(['[', ']'])
			elif char == '.':
				newLine.extend(['.', '.'])
			elif char == '#':
				newLine.extend(['#', '#'])
			elif char == '@':
				newLine.extend(['@', '.'])
		newGrid.append(newLine)
	return newGrid

grid = transformGrid(grid)

for row in grid:
	print(''.join(row))
print()

n = len(grid)
m = len(grid[0])
commandMap = {
	">": (0, 1),
	"<": (0, -1),
	"^": (-1, 0),
	"v": (1, 0)
}

def getCluster(grid : list[list[str]], 
			   currentPos : tuple[int, int], 
			   direction : tuple[int, int]) -> set[tuple[int, int]]:
	x, y = currentPos
	if grid[x][y] not in '[]':
		return set()
	
	dx, dy = direction
	disp = +1 if grid[x][y] == '[' else -1
	cluster = set([(x, y), (x, y+disp)])

	if 0 <= x+dx < n and 0 <= y+dy < m and (x+dx, y+dy) not in cluster:
		cluster |= getCluster(grid, (x+dx, y+dy), direction)

	if 0 <= x+dx < n and 0 <= y+dy+disp < m and (x+dx, y+disp+dy) not in cluster:
		cluster |= getCluster(grid, (x+dx, y+disp+dy), direction)
	
	return cluster

def movable(grid : list[list[str]], cluster : set[int], direction : tuple[int, int]) -> bool:
	dx, dy = direction
	for coord in cluster:
		x, y = coord
		if grid[x][y] not in "[]":
			return False

		if not ((0 <= x+dx < n and 0 <= y+dy < m) and (grid[x+dx][y+dy] in "[].")):
			return False

	return True
 
def moveCluster(grid : list[list[str]], cluster : set[int], direction : tuple[int, int]):
	dx, dy = direction
	storage = {} # to store what was in the coordinate before overwriting
	newCoords = {}

	for point in cluster:
		x, y = point
		nextX, nextY = x+dx, y+dy

		# if I am going to modify these points, I must store them first
		if point not in storage:
			storage[point] = grid[x][y]
		if (nextX, nextY) not in storage:
			storage[(nextX, nextY)] = grid[nextX][nextY]

		# set self to empty
		if point not in newCoords:
			newCoords[point] = "."

		# set next to myself
		newCoords[(nextX, nextY)] = storage[point]
	
	for (x, y) in newCoords:
		grid[x][y] = newCoords[(x, y)]
	

playerPos = None
for x, row in enumerate(grid):
	for y, char in enumerate(row):
		if char == '@':
			playerPos = (x, y)
			break

for command in commands:
	dir = commandMap[command]
	x, y = playerPos
	target = x+dir[0], y+dir[1]

	cluster = None
	if (0 <= target[0] < n and 0 <= target[1] < m):
		cluster = getCluster(grid, target, dir)
	# print(cluster)

	if cluster is not None and movable(grid, cluster, dir):
		moveCluster(grid, cluster, dir)
		if grid[x+dir[0]][y+dir[1]] == '.':
			grid[x][y] = '.'
			grid[x+dir[0]][y+dir[1]] = '@'
			playerPos = x+dir[0], y+dir[1]

for row in grid:
	print(''.join(row))
print()


getGpsCoord = lambda x, y: 100*x + y
ans = 0
for x, line in enumerate(grid):
	for y, char in enumerate(line):
		if char == '[':
			ans += getGpsCoord(x, y)

print(ans)
# print(getCluster(grid, (3, 6),  (1, 0)))