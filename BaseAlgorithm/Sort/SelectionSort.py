def SelectSort(arr, reversed=True):
    """
    SelectSort
    TimeComplex O(n^2)  SpaceComplex O(1)
    :param arr: list:arr
    :param reversed: increase or decrease
    :return: sorted[arr]
    """
    lens = len(arr)
    if reversed:
        for i in range(lens - 1):
            # 记录最小数的索引
            minIndex = i
            for j in range(i + 1, lens):
                if arr[j] < arr[minIndex]:
                    minIndex = j
            # i 不是最小数时，将 i 和最小数进行交换
            if i != minIndex:
                arr[i], arr[minIndex] = arr[minIndex], arr[i]
    else:
        for i in range(lens - 1):
            # 记录最大数的索引
            maxIndex = i
            for j in range(i + 1, lens):
                if arr[j] > arr[maxIndex]:
                    maxIndex = j
            # i 不是最大数时，将 i 和最小数进行交换
            if i != maxIndex:
                arr[i], arr[maxIndex] = arr[maxIndex], arr[i]
    return arr


# Sample
lis = [5, 4, 2.0, 9, 6, 8, 2]
print(SelectSort(lis, reversed=True))
