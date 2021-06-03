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
        fileSize += int(splitLine[8])
        if splitLine[7] in status:
            status[splitLine[7]] += 1
        count += 1
        if count == 10:
            print("File size: {:d}".format(fileSize))
            for key, value in sorted(status.items()):
                if status[key] != 0:
                    print("{}: {:d}".format(key, value))
            count = 0
    print("File size: {:d}".format(fileSize))
    for key, value in sorted(status.items()):
        if status[key] != 0:
            print("{}: {:d}".format(key, value))
except KeyboardInterrupt:
    print("File size: {:d}".format(fileSize))
    for key, value in sorted(status.items()):
        if status[key] != 0:
            print("{}: {:d}".format(key, value))
    raise
