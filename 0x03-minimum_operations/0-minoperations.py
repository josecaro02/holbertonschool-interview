#!/usr/bin/python3

"""
Minimum operations function
"""

def minOperations(n):
    actualNum = 1
    copyNum = 0
    numOperations = 0
    while n != actualNum:
        if n % actualNum == 0:                                                                                                                              
            numOperations += 2
            copyNum = actualNum
            actualNum += copyNum
        elif n % actualNum != 0:
            numOperations += 1
            actualNum += copyNum                                                                                                                                 
    return numOperations                                                                                                                                                      
                                                                                                                                                      
               