lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()
	lines = [line.strip() for line in lines]

def explore(current : int, nums : list[int], index : int, golden : int):
	if current > golden:
		return 0

	if index == len(nums):
		return current == golden

	ans = 0
	nextNum = nums[index]

	# *
	ans += explore(current*nextNum, nums, index+1, golden)
	# +
	ans += explore(current+nextNum, nums, index+1, golden)
	# ||
	ans += explore(int(str(current) + str(nextNum)), nums, index+1, golden)

	return ans

ans = 0
for line in lines:
	final, vars = line.split(":")
	final = int(final)
	nums = list(map(int, vars.strip().split(' ')))

	if explore(nums[0], nums, 1, final) > 0:
		ans += final

print(ans)
