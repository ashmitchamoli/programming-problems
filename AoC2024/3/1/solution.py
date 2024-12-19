lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()

correctSeq = "mul(x,x)"

def check(line : str, index : int) -> tuple[int, int]:
	if line[index:index+4] == correctSeq[:4]:
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
for line in lines:
	for i in range(len(line)):
		i, val = check(line, i)
		ans += val

print(ans)