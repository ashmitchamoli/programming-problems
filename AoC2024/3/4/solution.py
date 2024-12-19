lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()

correctSeq = "mul(x,x)"
doCmd = "do()"
dontCmd = "don't()"

def checkDo(line : str, index : int):
	if line[index:index + len(doCmd)] == doCmd:
		return index + len(doCmd)-1
	else:
		return index

def checkDont(line : str, index : int):
	if line[index:index + len(dontCmd)] == dontCmd:
		return index + len(dontCmd)-1
	else:
		return index

def checkMul(line : str, index : int) -> tuple[int, int]:
	if line[index:index + 4] == correctSeq[:4]:
		index += 4

		num1 = ""
		while index < len(line) and line[index].isdigit() and len(num1) <= 3:
			num1 += line[index]
			index += 1
		if index == len(line) or line[index] != ',':
			return index-1, 0
		
		index += 1
		num2 = ""
		while index < len(line) and line[index].isdigit() and len(num2) <= 3:
			num2 += line[index]
			index += 1
		if index == len(line) or line[index] != ')':
			return index-1, 0
		
		return index, int(num1) * int(num2)
	else:
		return index, 0

ans = 0
enabled = True
for line in lines:
	for i in range(len(line)):
		newInd = checkDo(line, i)
		if newInd != i:
			enabled = True
			i = newInd
			continue

		newInd = checkDont(line, i)
		if newInd != i:
			enabled = False
			i = newInd
			continue
		
		i, val = checkMul(line, i)
		if enabled:
			ans += val

print(ans)