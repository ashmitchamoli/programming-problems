lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

blinks = 25

for stones in lines:
	stones = list(map(int, stones.split(' ')))

	for _ in range(blinks):
		newStones = []
		for stone in stones:
			if stone == 0:
				newStones.append(1)
			elif len(str(stone))%2 == 0:
				temp = len(str(stone))
				newStones.extend((int(str(stone)[:temp//2]), 
					  			  int(str(stone)[temp//2:])))
			else:
				newStones.append(stone*2024)
		stones = newStones
	
	print(len(newStones))