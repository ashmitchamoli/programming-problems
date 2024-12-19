from typing import Literal

lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

n = len(lines)
m = len(lines[0])

dirTransform = {
	(0, 1): (1, 0),
	(1, 0): (0, -1),
	(0, -1): (-1, 0),
	(-1, 0): (0, 1)
}

def updateLoc(grid : list[str], i : int, j : int, dir : tuple[int, int]):
	if not ((0 <= i + dir[0] < n) and (0 <= j + dir[1] < m)):
		return (-1, -1), dir
	
	if grid[i + dir[0]][j + dir[1]] == '#':
		dir = dirTransform[dir]
		return (i, j), dir
	
	return (i + dir[0], j + dir[1]), dir

currPos = None
for i in range(len(lines)):
	for j in range(len(lines[i])):
		if lines[i][j] == '^':
			currPos = (i, j)
			break

currDir = (-1, 0)
path = {currPos: 1}
ans = 0
while currPos != (-1, -1):
	currPos, currDir = updateLoc(lines, *currPos, currDir)

	if currPos != (-1, -1):
		if currPos not in path:
			path[currPos] = 1
		else:
			ans += 1
			path[currPos] += 1

for i in range(len(lines)):
	for j in range(len(lines[i])):
		if (i, j) in path:
			print('X', end='')
		else:
			print(lines[i][j], end='')
	print()
print()

print(ans)