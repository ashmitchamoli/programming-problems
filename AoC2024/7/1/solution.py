lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

ans = 0
for line in lines:
	final, vars = line.split(":")
	final = int(final)
	nums = list(map(int, vars.strip().split(' ')))

	# 0 means * and 1 means +
	isCorrect = False
	for bitmap in range(1 << (len(nums) - 1)):
		comp = nums[0]
		for i in range(1, len(nums)):
			if ((bitmap >> (i-1)) & 1) == 1:
				comp += nums[i]
			else:
				comp *= nums[i]
			
			if comp > final:
				break
		
		if comp == final:
			isCorrect = True
			break
	
	if isCorrect:
		ans += final

print(ans)
