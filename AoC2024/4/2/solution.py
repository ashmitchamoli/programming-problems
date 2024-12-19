lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

n = len(lines)
m = len(lines[0])
print(n, m)

def countOccurences(grid : list[str], i : int, j : int, targets : list[str]) -> int:
	if i == 0 or j == 0 or i == n-1 or j == m-1:
		return 0

	leftDiag = grid[i-1][j-1] + grid[i][j] + grid[i+1][j+1]
	rightDiag = grid[i-1][j+1] + grid[i][j] + grid[i+1][j-1]
	
	return (leftDiag in targets) and (rightDiag in targets)

ans = 0
for i in range(n):
	for j in range(m):
		ans += countOccurences(lines, i, j, ["MAS", "SAM"])

print(ans)