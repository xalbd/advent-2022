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
    count = 0
    output = 0

    while True:
        try:
            count += 1
            if comp(eval(f.readline()), eval(f.readline())) == -1:
                output += count
            f.readline()
        except:
            break

    print(output)


solve("13example.txt")
solve("13input.txt")
