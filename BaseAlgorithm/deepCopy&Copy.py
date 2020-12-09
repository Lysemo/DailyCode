"""
在Python中一个数据有三种结构：值、内存地址、对象标识

浅拷贝：指的是重新分配一块内存，创建一个新的对象，但里面的元素是原对象中各个子对象的引用。
深拷贝：指重新分配一块内存，创建一个新的对象，并且将原对象中的元素，以递归的方式，通过创建新的子对象拷贝到新对象中。

如果一个类拥有指针类型的成员变量，那么绝大部分情况下就需要深拷贝，
因为只有这样，才能将指针指向的内容再复制出一份来，让原有对象和新生对象相互独立，彼此之间不受影响。
如果类的成员变量没有指针，一般浅拷贝足以

Python  不可变数据类型：字符串、数值型、布尔值        深拷贝和浅拷贝效果一样
        可变数据类型：列表、字典、集合              深拷贝是变量对应的值复制到新的内存地址中，浅拷贝是复制数据对应的内存地址。

参考自 https://www.pythonf.cn/read/168326
"""

# example for deepcopy & copy

# 赋值
lis =[1,2,3]
lis2 = lis                    # 赋值操作
print(lis == lis2)            # == 判断数值是否相同                               True
print(lis is lis2)            # is 判断对象标识是否相同（23lines lis=lis）             True
print(id(lis)==id(lis2))      # id() 判断内存地址是否相同                          True

lis.append(4)
print(lis)                  # [1,2,3,4]
print(lis2)                 # [1,2,3,4]  lis2和 lis是同一对象

# 浅拷贝
import copy
# 不可变类型的浅拷贝
strs ='Hallo World'
strs2 = copy.copy(strs)
print(id(strs))                  # 2505499529264
print(id(strs2))                 # 2505499529264 浅拷贝的对象和原数据对象是相同的内存地址

# 可变类型的浅拷贝
lists = [1,3,5,7]
lists2 = copy.copy(lists)
print(id(lists))                  # 1893108584640
print(id(lists2))                 # 1893108584768 浅拷贝的对象和原数据对象是不同的内存地址

# 深拷贝
# 不可变类型的深拷贝
strs ='HalloWorld！'
strs2 = copy.deepcopy(strs)
print(id(strs))                  # 2118202162064
print(id(strs2))                 # 2118202162064 深拷贝的对象和原数据对象是相同的内存地址

# 可变类型的深拷贝
lists = [1,3,5,7]
lists2 = copy.deepcopy(lists)
print(id(lists))                  # 2118203379200
print(id(lists2))                 # 2118203379264 深拷贝的对象和原数据对象是不同的内存地址