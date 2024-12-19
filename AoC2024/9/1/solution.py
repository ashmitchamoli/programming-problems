lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

for diskMap in lines:
	finalString = []
	for i in range(len(diskMap)):
		finalString += (['.'] if i%2 else [str(i // 2)]) * int(diskMap[i])

	j = len(finalString) - 1
	i = 0
	while j >= 0 and i < len(finalString) and j > i:
		while i < len(finalString) and  finalString[i] != ".":
			i += 1
			continue

		while j >= 0 and finalString[j] == ".":
			j -= 1
			continue

		if i >= len(finalString) or j < 0 or j <= i:
			break
		
		finalString[i], finalString[j] = finalString[j], finalString[i]
		# print(i, j, finalString)
		i += 1
		j -= 1

	checksum = 0
	for i in range(len(finalString)):
		if finalString[i] == '.':
			break
		checksum += i * int(finalString[i])


	print(checksum)
	# print(''.join(finalString))