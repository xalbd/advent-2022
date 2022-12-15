from functools import cmp_to_key


def comp(list1, list2):
    if type(list1) == type(list2) == int:
        if list1 < list2:
            return -1
        elif list1 > list2:
            return 1
        else:
            return 0

    elif type(list1) == type(list2) == list:
        for a in range(min(len(list1), len(list2))):
            if comp(list1[a], list2[a]) != 0:
                return comp(list1[a], list2[a])
        if len(list1) < len(list2):
            return -1
        elif len(list1) > len(list2):
            return 1
        else:
            return 0

    elif type(list1) == list:
        return comp(list1, [list2])
    elif type(list2) == list:
        return comp([list1], list2)


def solve(filename):
    f = open(filename, "r")
    inputs = [[[2]], [[6]]]

    while True:
        try:
            inputs.append(eval(f.readline()))
            inputs.append(eval(f.readline()))
            f.readline()
        except:
            break

    inputs = sorted(inputs, key=cmp_to_key(comp))
    print((inputs.index([[2]]) + 1) * (inputs.index([[6]]) + 1))


solve("13example.txt")
solve("13input.txt")
