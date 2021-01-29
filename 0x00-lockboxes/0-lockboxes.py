#!/usr/bin/python3


def canUnlockAll(boxes):
    ''' Function to unlock boxes '''
    lenBoxes = len(boxes)
    openedBoxes = [1]
    keys = []
    for i in range(1, lenBoxes):
        openedBoxes.append(0)
    for box in boxes[0]:
        keys.append(box)
        openedBoxes[box] = 1
    posBox = 1
    while posBox < lenBoxes:
        if posBox in keys:
            for key in boxes[posBox]:
                keys.append(key)
                if openedBoxes[key] == 0 and key < posBox:
                    openedBoxes[key] = 1
                    posBox = key - 1
                    break
                openedBoxes[key] = 1
        posBox += 1
    if 0 in openedBoxes:
        return False
    return True
