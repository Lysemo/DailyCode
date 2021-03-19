class Solution:
    def findMaxButton(self,buttons):
        res = len(buttons)
        for i in range(len(buttons)):
            res+=(buttons[i]-1)*(i+1)
        return res


if __name__ == '__main__':
    button =eval(input())
    solve = Solution()
    print(solve.findMaxButton(button))