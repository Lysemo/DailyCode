n = int(input())
a = input()
b = input()
c = input()

x,y,z =0,0,0
for i in a: x = max(x,a.count(i))
for i in b: y = max(y,b.count(i))
for i in c: z = max(z,c.count(i))
lens =len(a)
x = min(x+n, lens)
y = min(y+n, lens)
z = min(z+n, lens)

if x>y and x>z:
    print("xiaoming")
elif y>x and y>z:
    print("xiaowang")
elif z>x and z>y:
    print("xiaoli")
else:print("draw")
