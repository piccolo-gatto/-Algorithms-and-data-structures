import time
import random
import glob

import hash as h

HASH_FUNCTIONS = [h.hash_crc, h.hash_pjw, h.hash_buz, hash]


def find_duplicates(files: list[str], hash_function: callable) -> list[str]:
    hash_to_file = {}
    duplicates = []
    for file_path in files:
        with open(file_path, 'rb') as file:
            file_data = file.read()
            file_hash = hash_function(file_data)
            if file_hash in hash_to_file:
                duplicates.append(file_path)
            else:
                hash_to_file[file_hash] = file_path
    return duplicates


files_finding_mask = 'out/' + '*.' + "txt"
files = glob.glob(files_finding_mask)
print("Function Name \t Duplicates \t Time")
for i in HASH_FUNCTIONS:
    start_time = time.time()
    dupicates = find_duplicates(files, i)
    end_time = time.time()
    print(f'{i.__name__} \t {len(dupicates)} \t {end_time - start_time}')


