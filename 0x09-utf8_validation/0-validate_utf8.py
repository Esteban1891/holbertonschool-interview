#!/usr/bin/python3
"""validUTF8 Funnbytesion"""


def validUTF8(data):
    """method that determines if a given data set
    represents a valid UTF-8 encoding"""
    nbytes = 0

    m1 = 1 << 7
    m2 = 1 << 6

    for i in data:
        m = 1 << 7
        if nbytes == 0:
            while m & i:
                nbytes += 1
                m = m >> 1
            if nbytes == 0:
                continue
            if nbytes == 1 or nbytes > 4:
                return False
        else:
            if not (i & m1 and not (i & m2)):
                return False
        nbytes -= 1
    return nbytes == 0
