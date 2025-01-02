from collections import Counter

lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines if line != '']

class Robot:
	def __init__(self, pos : tuple[int, int], vel : tuple[int, int]):
		self.startPos = pos
		self.vel = vel
		self.currentPos = list(pos)
	
	def calcPos(self, gridSize : tuple[int, int], time : int):
		pos = self.currentPos
		for _ in range(time):
			for i in [0, 1]:
				c, lim = pos[i], gridSize[i]

				c += self.vel[i]
				if c < 0:
					c += lim
				elif c >= lim:
					c -= lim

				pos[i] = c

		self.currentPos = pos
		return tuple(self.currentPos)

def readBot(bot : str):
	p, v = bot.split()
	p = tuple(map(int, p.split('=')[1].split(',')))
	v = tuple(map(int, v.split('=')[1].split(',')))

	return Robot(p, v)

gridSize = 101, 103

final = Counter()
for bot in lines:
	bot = readBot(bot)
	finalPos = bot.calcPos(gridSize, 100)
	if (finalPos[0] == gridSize[0] // 2) or (finalPos[1] == gridSize[1] // 2):
		continue

	final[finalPos] += 1

def getQuadrant(coord : tuple[int, int]) -> int:
	x = coord[0] > (gridSize[0] // 2)
	y = coord[1] > (gridSize[1] // 2)

	return x + 2*y

quadrants = [0, 0, 0, 0]
for tile in final:
	quadrants[getQuadrant(tile)] += 1

ans = 1
for num in quadrants:
	ans *= num
print(ans)