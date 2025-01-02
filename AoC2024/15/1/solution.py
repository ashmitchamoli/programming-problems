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

n = len(grid)
m = len(grid[0])
commandMap = {
	">": (0, 1),
	"<": (0, -1),
	"^": (-1, 0),
	"v": (1, 0)
}
def move(grid : list[list[str]], currentPos : tuple[int, int], command : str) -> tuple[int, int]:
	x, y = currentPos
	dx, dy = commandMap[command]

	while 0 <= x + dx < n and 0 <= y + dy < m and grid[x + dx][y + dy] == 'O':
		x += dx
		y += dy
	
	if (not (0 <= x + dx < n and 0 <= y + dy < m)) or grid[x + dx][y + dy] == '#':
		return currentPos
	
	grid[x+dx][y+dy] = 'O'
	grid[currentPos[0]][currentPos[1]] = '.'
	grid[currentPos[0] + dx][currentPos[1] + dy] = '@'

	return currentPos[0] + dx, currentPos[1] + dy

currentPos = None
for y, line in enumerate(grid):
	for x, char in enumerate(line):
		if char == '@':
			currentPos = (x, y)
			break
for command in commands:
	currentPos = move(grid, currentPos, command)

getGpsCoord = lambda x, y: 100*x + y
ans = 0
for x, line in enumerate(grid):
	for y, char in enumerate(line):
		if char == 'O':
			ans += getGpsCoord(x, y)

print(ans)