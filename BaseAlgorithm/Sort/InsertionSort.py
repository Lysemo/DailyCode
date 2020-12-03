def InsertSort(arr, reversed=True):
    """
    InsertSort
    TimeComplex O(n^2)  SpaceComplex O(1)
    :param arr: list:arr
    :param reversed: increase or decrease
    :return: sorted[arr]
    """
    lens = len(arr)
    if reversed:
        for i in range(lens):
            preIndex = i - 1
            current = arr[i]
            while preIndex >= 0 and arr[preIndex] > current:
                arr[preIndex + 1] = arr[preIndex]
                preIndex -= 1
            arr[preIndex + 1] = current
    else:
        for i in range(lens):
            preIndex = i - 1
            current = arr[i]
            while preIndex >= 0 and arr[preIndex] < current:
                arr[preIndex + 1] = arr[preIndex]
                preIndex -= 1
            arr[preIndex + 1] = current
    return arr


# Sample
lis = [5, 4, 2.0, 9, 6, 8, 2]
print(InsertSort(lis, reversed=False))
