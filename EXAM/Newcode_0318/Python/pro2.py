num = int(input())
str= ' '+input()        # 前缀和

sum =[0]*(num+1)
for i in range(1,num+1):
    sum[i] = sum[i-1]+int(str[i])
res = num
for i in range(num+1):
    res = min(res, i-sum[i]+sum[-1]-sum[i])
print(res)
