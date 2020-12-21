s = input().rstrip()
vars = {}

nums = [int(n) for n in s]
nums.reverse()

length = len(nums)

for i in range(length):
    for j in range(i + 1, length):
        if nums[i] > nums[j]:
            vars[i] = j
            break

vars_list = list(vars.items())

if vars_list:
    vars_list.sort(key=lambda k: k[1])

    i = vars_list[0][1]
    j_variants = [n[0] for n in vars_list if n[1] == i]

    values = [nums[n] for n in j_variants]
    j = j_variants[values.index(min(values))]

    nums[i], nums[j] = nums[j], nums[i]

    s = nums[0:i]
    s.sort(reverse=True)

    nums[0:i] = s
    nums.reverse()
    nums = [str(n) for n in nums]

    ans = ''.join(nums)
    print(ans)
else:
    print('-1')