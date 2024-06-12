# # name=input('Write your name:')
# # def greet(name):
# #     print('Hi! '+name)
# # greet(name)

# def square(x):
#     return x*x


# def sum(x, y):
#     return x*x+y*y


# def greet():
#     name = input('write name:')
#     return "Hi! "+name


# # greet()
# # g = greet()
# # print(g)

# import calendar ,math,random
# print(calendar.month(2023,1))
# print(math.sqrt(144))
# print (random.randint(1,100))
# # list can have elements of different data types
# list=("he",'das','sda','sad',32,'errwe')

# # list[1]="Hello"
# # print(list)

# # tuples are immutable thats it's values cannot be changed after it's created

# # oops

# class Book():
#     def __init__(self,name,pages,price):
#         self.name=name
#         self.pages=pages
#         self.price=price
#     def get_name(self):
#         print(self.name)

# book1=Book('Chariots of God',300,250)

# book1.get_name()

# book1.price+=20
# print(book1.price)

str = "my lily is poly"

words = str.split(' ')
# print( words )
res = []
for a in words:
    if 'ly' in a:
        res.append(a[:-2])
        print(a[:-2]+"->")
    else:
        res.append(a)
print(res)


class Solution:
    dp = {}

    def tribonacci(self, n: int) -> int:
        if n < 3:
            return n > 0
        if n in Solution.dp:
            return Solution.dp[n]
        Solution.dp[n] = Solution.tribonacci(
            self, n-1)+Solution.tribonacci(self, n-2)+Solution.tribonacci(self, n-3)


class Solution(object):
    def tribonacci(self, n):
        dp = {}

        def recur(n):
            if n < 3:
                return int(n > 0)
            if n in dp:
                return dp[n]
            dp[n] = recur(n-1)+recur(n-2)+recur(n-3)
            return dp[n]
        return recur(n)


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        map = {}
        for ch in s1:
            map[ch] += 1
        num = 0
        j = 0
        for i in range(len(s2)):
            if i-j >= len(s1):
                if map[s2[j]] >= 0:
                    num += 1
                map[s2[j]] += 1
                j += 1
            if map[s2[i]] > 0:
                num -= 1
            map[s2[i]] -= 1
            if num == 0:
                return True
        return False


class Solution(object):
    def findMinimumTime(self, tasks):
        line = [False]*2001
        tasks.sort(key=lambda x: x[1])
        for s, e, d in tasks:
            for t in range(s, e+1):
                d -= line[t]
                t -= 1
            end = e
            while d > 0:
                if not line[end]:
                    line[end] = True
                    d -= 1
                end -= 1
        return sum(line)
