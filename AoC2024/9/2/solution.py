lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

def getChecksum(s : list[str]):
	checksum = 0
	for i in range(len(s)):
		if s[i] == '.':
			continue
		checksum += i * int(s[i])
	

for diskMap in lines:
	pass
	# print(''.join(finalString))