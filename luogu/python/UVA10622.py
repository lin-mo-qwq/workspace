from math import *
n = 0 
while True:
	x = int(input())
	if x == 0:
		break
	elif x < 0:
		x = fabs(x) 
		i = 31
		while i > 0:
			tmp = pow(x, 1 / i)
			if fabs(tmp - round(tmp)) <= 0.00000000001:
				print(i)
				break
			i -= 2
	else:
		i = 32
		while i > 0:
			tmp = pow(x, 1 / i)
			if fabs(tmp - round(tmp)) <= 0.00000000001:
				print(i)
				break
			i -= 1
