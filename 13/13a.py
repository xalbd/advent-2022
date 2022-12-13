f = open("13input.txt", "r")
count = 0
output = 0


def comp(list1, list2):
    if isinstance(list1, int) and isinstance(list2, int):
        if list1 < list2:
            return 1
        elif list1 > list2:
            return 0
        else:
            return 3

    elif isinstance(list1, list) and isinstance(list2, list):
        for a in range(min(len(list1), len(list2))):
            if comp(list1[a], list2[a]) != 3:
                return comp(list1[a], list2[a])
        if len(list1) < len(list2):
            return 1
        elif len(list1) > len(list2):
            return 0
        else:
            return 3

    else:
        if isinstance(list1, int):
            return comp([list1], list2)
        else:
            return comp(list1, [list2])


while True:
    count += 1
    line = f.readline()
    if not line:
        break

    value1 = eval(line)
    value2 = eval(f.readline())
    f.readline()

    if comp(value1, value2) == 1:
        print(count)
        output += count

print(output)
