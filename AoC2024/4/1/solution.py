lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()

	lines = [line.strip() for line in lines]

n = len(lines)
m = len(lines[0])
print(n, m)

target = "XMAS"
rTarget = str(reversed(target))
targets = [target, rTarget]

def countOccurences(grid : list[str], i : int, j : int, targets : list[str]) -> int:
	count = 0
	
	for dirX in [-1, 0, 1]:
		for dirY in [-1, 0, 1]:
			if dirX == 0 and dirY == 0:
				continue
			
			dummy = ""
			for step in range(len(target)):
				if not ((0 <= i + dirX * step < n) and (0 <= j + dirY * step < m)):
					break
				dummy += grid[i + dirX * step][j + dirY * step]
			
			count += dummy in targets

	return count

ans = 0
for i in range(n):
	for j in range(m):
		ans += countOccurences(lines, i, j, targets)

print(ans)