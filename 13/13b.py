from functools import cmp_to_key

f = open("13input.txt", "r")
count = 0
output = 1


def comp(list1, list2):
    if isinstance(list1, int) and isinstance(list2, int):
        if list1 < list2:
            return -1
        elif list1 > list2:
            return 1
        else:
            return 0

    elif isinstance(list1, list) and isinstance(list2, list):
        for a in range(min(len(list1), len(list2))):
            if comp(list1[a], list2[a]) != 3:
                return comp(list1[a], list2[a])
        if len(list1) < len(list2):
            return -1
        elif len(list1) > len(list2):
            return 1
        else:
            return 0

    else:
        if isinstance(list1, int):
            return comp([list1], list2)
        else:
            return comp(list1, [list2])


inputs = [[[2]], [[6]]]
while True:
    line = f.readline()
    if not line:
        break
    inputs.append(eval(line))
    inputs.append(eval(f.readline()))
    f.readline()

inputs = sorted(inputs, key=cmp_to_key(comp))

for i in range(0, len(inputs)):
    if inputs[i] == [[2]] or inputs[i] == [[6]]:
        print(i)
        output *= (i + 1)

print(output)
