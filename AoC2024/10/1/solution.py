lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

memoize = [[-1]*len(line) for line in lines]
isVisited = [[False]*len(line) for line in lines]

def score(grid : list[str], i : int, j : int, progress : int, isVisited) -> set[int]:
	if isVisited[i][j]:
		return set()

	if progress == 10:
		if grid[i][j] == '9':
			return set([(i, j)])
		return set()
	
	if memoize[i][j] != -1:
		return memoize[i][j]

	# isVisited.add((i, j))
	isVisited[i][j] = True

	ans = set()
	def move(grid, i, j, progress, isVisited):
		if (0 <= i < len(grid)) and (0 <= j < len(grid[0])) and grid[i][j] == str(progress):
			return score(grid, i, j, progress+1, isVisited)
		else:
			return set()
	
	ans |= move(grid, i-1, j, progress, isVisited)
	ans |= move(grid, i+1, j, progress, isVisited)
	ans |= move(grid, i, j-1, progress, isVisited)
	ans |= move(grid, i, j+1, progress, isVisited)

	isVisited[i][j] = False

	memoize[i][j] = ans
	return memoize[i][j]

total = 0
for i in range(len(lines)):
	for j in range(len(lines[0])):
		if lines[i][j] == '0':
			temp = score(lines, i, j, 1, isVisited)
			print(i, j, temp)
			total += len(temp)

print(total)