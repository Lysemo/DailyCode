def BubbleSort(arr, reversed=True):
    """
    BubbleSort
    TimeComplex O(n^2)  SpaceComplex O(1)
    :param arr: list:arr
    :param reversed: increase or decrease
    :return: sorted[arr]
    """
    lens = len(arr)
    if reversed:
        for i in range(lens - 1):
            for j in range(lens - i - 1):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j+1], arr[j]
    else:
        for i in range(lens - 1):
            for j in range(lens - i - 1):
                if arr[j] < arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j+1], arr[j]
    return arr


# Sample
lis = [5, 4, 7, 9, 6, 8, 2]
print(BubbleSort(lis, reversed=False))
