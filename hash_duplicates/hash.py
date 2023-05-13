import random


R = [random.randint(0, 2**32-1) for _ in range(256)]


def hash_crc(key: bytes) -> int:
    h = 0
    for ki in key:
        h = h ^ ki
        for i in range(8):
            if h & 1:
                h = (h >> 1) ^ 0xEDB88320
            else:
                h = h >> 1
    return h


def hash_pjw(key: bytes) -> int:
    h = 0
    for ki in key:
        h = (h << 4) + ki
        g = h & 0xF0000000
        if g != 0:
            h ^= (g >> 24) ^ g
    return h


def hash_buz(key: bytes) -> int:
    h = 0
    for ki in key:
        highorder = h & 0x80000000
        h = h << 1
        h = h ^ (highorder >> 31)
        h = h ^ R[ki]
    return h