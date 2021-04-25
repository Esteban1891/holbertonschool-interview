#!/usr/bin/python3
"""
    Determine wether all boxes can be unlocked by other boxes' values
    @boxes: 2d array of boxes with values inside them
    Returns: True or False
"""


def canUnlockAll(boxes):
    stack = [0]
    unlocked = [1] + [0] * (len(boxes) - 1)
    i = 0

    if len(boxes) == 0:
        return True
    if not isinstance(boxes, list):
        return False
    while stack:
        p = stack.pop()
        for key in boxes[p]:
            if key > 0 and key < len(boxes) and unlocked[key] == 0:
                unlocked[key] = 1
                stack.append(key)
        i = i + 1

    if 0 in unlocked:
        return False
    else:
        return True
