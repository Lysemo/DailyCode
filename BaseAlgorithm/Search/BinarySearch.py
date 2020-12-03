def BinarySearch(left, right, key, lis):
    """
    BinarySearch
    TimeComplex O(log n)
    :param left:Left border
    :param right:Right border
    :param key: search key
    :param lis:list [arr]
    :return: lis.index(key) or None
    """
    if right >= left:
        mid = int(left + (right - left) / 2)
        if lis[mid] == key:
            return mid
        elif lis[mid] > key:
            return BinarySearch(left, mid-1, key, lis)
        else:
            return BinarySearch(mid + 1, right, key, lis)
    else:
        return -1


#example
lens = 100
key = 97
arr = [3,3,4,4,4,5,6,6,6,7,8,8,12,13,15,16,21,21,22,24,24,27,28,32,34,35,35,36,36,39,40,41,41,42,44,44,45,45,47,47,47,47,48,48,50,51,51,53,53,53,54,54,54,56,56,57,59,60,60,60,60,61,62,63,65,65,65,65,67,67,68,70,71,71,74,75,75,79,81,84,84,86,86,87,90,90,90,90,91,92,93,94,94,94,95,97,97,98,98,99]
print(BinarySearch(0, lens-1, key, arr))