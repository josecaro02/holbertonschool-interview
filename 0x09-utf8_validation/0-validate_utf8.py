#!/user/bin/python3


def validUTF8(data):
    '''Validate utf8'''
    for i in range(0, len(data)):
        numBytes = 0
        val = data[i]

        if val >= 255:
            return False
        elif val & 128 == 0:
            numBytes = 1
        elif val & 224 == 192:
            numBytes = 2
        elif val & 240 == 224:
            numBytes = 3
        elif val & 248 == 240:
            numBytes = 4
        else:
            return False

        for j in range(1, numBytes):
            if j+i >= len(data):
                return False
            elif data[i+j] & 192 != 128:
                return False

        i = i+numBytes-1

    return True
