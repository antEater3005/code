from calendar import c
from imaplib import Int2AP
from multiprocessing.connection import answer_challenge
import numbers
from platform import freedesktop_os_release
import string
from tkinter import W
from traceback import StackSummary
from tracemalloc import start
from turtle import down, st
from wsgiref.validate import InputWrapper
from xml.sax.xmlreader import InputSource
import math
from xmlrpc.client import MAXINT, boolean
# name = "Programming"
# print(name.lower())
# print(name.upper())
# print(name.find('S'))  # it return the index if present else return -1
# print(name.find("Avinash"))  # if input is string it return the starting index
# print(name.replace("Avinash", "aNitish"))  # used to replace a part of string
# # it checks wether a string is part of main string or not
# love = input("Write something...")
# if "Programming " in love:
#     print("I Love U Programming 💕")
# elif "Programming " in love:
#     print("I still love you Programming 💖")
# else:
#     print("I Love U So much Programming ❤")

# Calculator

# a = input("Enter first number:")
# b = input("Enter second number:")
# op = input("Enter operator:")
# a = int(a)
# b = int(b)

# if op == "+":
#     print(a+b)
# elif op == "-":
#     print(a-b)
# elif op == "*":
#     print(a*b)
# elif op == "/":
#     print(a/b)
# elif op == "%":
#     print(a % b)
# else:
#     print("Invalid operator")
# d=range(4) # range function return a list of number from 0 to n-1

# for i in d:
#   print(i)

# for i in range(5):
#    print((4-i) * " "+(i+1)*"*")
#    i = i + 1

# List in python there are two indexing forward and backward forward indexing is done from 0 to n-1 and backward indexing is done from -1 to -n;
# List can contain items of different datatype
marks = ["english", 95, "chemistry", 98, "maths", 89]
marks.append("Hindi")

# print(*marks, sep=":") # '*' operator is used to print list items in single line;

# first = 'Programming '
# last = 'Cp'
# msg = f'{first}{last} is coder'
# print(msg)


# string methods
# course = 'Hello welcome to this amazing python course'
# print(course)
# print(course.lower())
# print(course.find('amazing'))
# print('PYTHON' in course.upper())


# Arithmetic operations
# print(10 / 3)  # this returns a floating point number
# print(10 // 3)  # this returns a integer point number
# print(10 % 3)  # return remainder
# print(2 ** 5)  # return 10 to the power 2

# x = 18
# x = x+2
# x += 2  #augmented assignment operator
# print(x)

# operator precedence
#  exponentiation >> multiplication or division >>addition or subtraction

# x=-2.444
# print(round(x))
# print(abs(x))


# print(math.floor(2.99))

# weight converter
# weight = int(input('Weight:'))
# unit = input('L for lbs/K for kg:').upper()

# if unit == 'K':
#     print(f'Your weight is {weight*2.20462262} pounds.')
# else:
#     print(f'Your weight is {weight // 2.20462262} pounds.')

# Loops

# prev = 'STOP'
# while 1:
#     str = input('> ').upper()
#     if str == 'HELP':
#         print("""
#     start - to start the car
#     stop - to stop the car
#     quit - to exit
#        """)
#     elif str == 'START':
#         if prev != 'START':
#             prev = str
#             print('Car started... Ready to go!')
#         else:
#             print('Car already running!')
#     elif str == 'STOP':
#         if prev != 'STOP':
#             prev = str
#             print('Car stopped')
#         else:
#             print('Car is already stopped.')
#     elif str == 'QUIT':
#         break
#     else:
#         print("I don't understand that...")


# for loop

# for item in  range(4,8,3):   #range function can take three arguments (start,end,steps);start and steps are optional and taken as 0 and 1 respectively.
#     print(item)

# lists

prices = [10, 20, 30]
# total =0
# for price in prices:
#     total+=price
# print(f'Total: {total}')

# for price in prices:
#     for c in str(price):
#         print(c ,end=' ')    # the second argument to print function if optional and end= is used to print all the char in same line.
# for x in range(4):
#     for y in range(4):
#         print(x,y)

# numbers=[5,2,5,2,2]

# for i in numbers:
#     str=''
#     for j in range(i):
#         str+='X'
#     print(str)

# names = ['John', 'Sarah', 'Patrick', 'Mosh', 'Michael', 'Marry', 'Bob']
# names[0]='Avinash'
# print(names[:])

# nums = [32, 65, 7, 34, 675, 87, 233, 3, 757]
# num=3
# for i in nums:
#     num =max(num,i)
# print(num)

# 2D list(matrix)

# matrix = [[1, 2, 3],
#           [4, 5, 6],
#           [7, 8, 9]]
# for list in matrix:
#     for items in list:
#         print(items, end=' ')
#     print()


# continue from time= 02:05

s = input()
k = int(input())


class Solution:
    def kPeriodic(self, s, k):
        freq = [0 for freq in range(26)]

        for i in range(len(s)):
            freq[ord(s[i])-97] = freq[ord(s[i])-97] + 1
        ans = ""
        for i in range(26):
            if freq[i] != 0 and freq[i] != k:
                return ""
            elif freq[i] != 0:
                ans = ans + chr(i+97)
        return ans*k


d = Solution()
print(d.kPeriodic(s, k))


 