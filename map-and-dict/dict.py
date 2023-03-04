from sys import getsizeof
import time
import random

with open('out_py.txt', 'w') as file:
	for i in range(6):
		start = time.perf_counter() * 1000
		counter = {}
		n = 10**i
		for _ in range(0, n):
			counter[random.randint(0, 100000)] = random.randint(0, 100000)
		end = time.perf_counter() * 1000
		print(n, getsizeof(counter), int(end - start))

	# with open('out_py.txt', 'a') as file:
		file.write(str(n) + ' ' + str(getsizeof(counter)) + ' ' + str(int(end - start)) + '\n')