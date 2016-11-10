# -*- coding: utf-8 -*-
"""
Created on Fri Sep 18 10:49:57 2015

@author: Administrator
"""

import ctypes
ll = ctypes.cdll.LoadLibrary 
lib = ll("./libpycall.so")  
#lib = ll("D:/test/c/py call c/libpycall.so")#全路径
print(lib.foo(3, 3))
print('***finish***')


