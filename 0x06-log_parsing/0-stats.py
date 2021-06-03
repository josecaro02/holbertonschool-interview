#!/usr/bin/python3
''' print stats program '''
import sys

status = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}

count = 0
fileSize = 0
try:
    for line in sys.stdin:
        splitLine = line.split()
        try:
            fileSize += int(splitLine[8])
        except:
            pass
        try:
            if splitLine[7] in status:
                status[splitLine[7]] += 1
        except:
            pass
        count += 1
        if count == 10:
            print("File size: {}".format(fileSize))
            for key, value in status.items():
                if status[key] != 0:
                    print("{}: {}".format(key, value))
            count = 0
    print("File size: {}".format(fileSize))
    for key, value in status.items():
        if status[key] != 0:
            print("{}: {}".format(key, value))
except KeyboardInterrupt:
    print("File size: {}".format(fileSize))
    for key, value in status.items():
        if status[key] != 0:
            print("{}: {}".format(key, value))
    raise
