from alive_progress import alive_bar
from time import time
from collections import Counter

lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

blinks = 75
start = time()
total = 0
for stones in lines:
	stones = stones.split(' ')

	for stone in stones:
		switchList = [Counter([stone]), Counter()]
		turn = True

		for _ in range(blinks):
			for x in switchList[not turn]:
				if x == '0':
					switchList[turn]['1'] += switchList[not turn]['0']
				elif len(x)%2 == 0:
					temp = len(x)
					switchList[turn][str(int(x[:temp//2]))] += switchList[not turn][x]
					switchList[turn][str(int(x[temp//2:]))] += switchList[not turn][x]
				else:
					switchList[turn][str(int(x)*2024)] += switchList[not turn][x]

			switchList[not turn] = Counter()
			turn = not turn	

		total += switchList[not turn].total()

print(total)
end = time()
print(end - start)