import functools

lines = None
with open("input.txt", "r") as f:
	lines = f.readlines()

rules : list[str] = []
updates : list[str] = []
sepDone = False
for line in lines:
	if line.strip() == "":
		sepDone = True
		continue
	
	if sepDone:
		updates.append(line)
	else:
		rules.append(line)


ordering : dict[int, set[int]] = {}

for line in rules:
	a, b = map(int, line.strip().split("|"))
	if b not in ordering:
		ordering[b] = set()
	ordering[b].add(a)

ans = 0
for update in updates:
	isCorrect = True
	done = set()
	update = list(map(int, update.strip().split(',')))
	for i in range(len(update)-1, -1, -1):
		if update[i] not in ordering:
			done.add(update[i])
			continue

		if len(ordering[update[i]].intersection(done)) != 0:
			isCorrect = False
			break

		done.add(update[i])

		if not isCorrect:
			break

	if not isCorrect:
		def customCmp(x : int, y : int):
			if x in ordering and y in ordering[x]:
				return 1
			elif y in ordering and x in ordering[y]:
				return -1
			else:
				return 0
		correct = sorted(update, key=functools.cmp_to_key(customCmp))
		ans += correct[len(correct)//2]

print(ans)	