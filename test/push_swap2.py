from random import *
# from bubble_srt import bubble
import sys
import os


class stack:

	def __init__(self, name, arr):
		self.name = name
		self.stack = arr

	def len(self):
		return len(self.stack)

	# must supply destination for correctly populating command list
	def pop_x(self, dest):
		commands.append('p' + dest.name)
		dest.stack.append(self.stack.pop())

	def r(self):
		l = len(self.stack)
		front = self.stack.pop()
		self.stack.insert(0, front)
		commands.append('r' + self.name)

	def s(self):
		front = self.stack.pop()
		self.stack.insert(-1, front)
		commands.append('s' + self.name)

	def rr(self):
		l = len(self.stack)
		i = 1
		temp = self.stack[0]
		while i < l:
			self.stack[i - 1] = self.stack[i]
			i += 1
		self.stack[i - 1] = temp
		commands.append('rr' + self.name)

	def peak(self):
		l = len(self.stack)
		if l == 0:
			return
		return self.stack[l - 1]




'''	Questions
	when calling a method inside a class, do I need to preface with self

	**
	top of stack = last index
	smallest number at top of stack
	**
'''

'''
	> takes about 100 ops to move half the stack[100] to stack b

'''



num_digis = 100

stacka = stack('a', [])
stackb = stack('b', [])
commands = []
temp = []
for z in range(num_digis):
	temp.append(randint(1, 100))
# use list to make a duplicate of the list
sort_temp = list(temp)
sort_temp.sort()
median = sort_temp[num_digis / 2]
last_a = len(stacka.stack) - 1
last_b = len(stackb.stack) - 1

# remove dupes
sort_temp = list(set(sort_temp))

# change all values to their order number
for i in range(num_digis):
	k = sort_temp.index(temp[i])
	# create tupe with order and val, but val not necessary
	# stacka.stack.append((k, temp[i]))
	stacka.stack.append(k)
stacka.pop_x(stackb)


def calc_ops(i):
	num = stacka.stack[i]
	k = 0
	while k <= last_b:
		if last_b == 0:
			b_f_diff = 0
			b_r_diff = 0
			break
		if (	num > stackb.stack[k]  and
				num < stackb.stack[k + 1] ):
			b_f_diff = last_b - k
			b_r_diff = k + 1
	a_f_diff = last_a - i
	a_r_diff = i + 1

	moves = ([	a_f_diff + b_r_diff,
				a_r_diff + b_f_diff,
				max([b_f_diff, a_f_diff]),
				max([b_r_diff, a_r_diff])
			], 
			(b_f_diff, b_r_diff))
	return moves


def index_to_move():
	num_ops = []
	i = 0
	while i < len(stacka.stack):
		num_ops.append(min(calc_ops(i)[0]))
		i += 1
	print num_ops
	lowest = 0
	j = 0
	while j < len(num_ops):
		if (num_ops[j] < num_ops[lowest]):
			lowest = j
		j += 1
	times = calc_ops(lowest)[0]
	b_rot = calc_ops(lowest)[1]
	print 'times', times
	alg = times.index(min(times))
	return ((lowest, alg), b_rot)

def move_to_b(info):
	index = info[0]
	if (info[1] == 0):
		for i in range(last_a - index):
			stacka.r()
		for i in range(last_b - 1):
			PASS






# figure out how man opperations to get each element to place where it 
# needs to be in stack b.
# first attempt will not move over elements that are not right next to
# thier counterparts in stack b

'''
	optimizations: once stack a gets small enough change technique
'''

# while len(stacka.stack) > 1:
info = index_to_move()
# move_to_b(info)
	# continue
	# move(stacka.stack[index])

print 'index', index


# print ('stacka:' , stacka.stack)
# print ('stackb:' , stackb.stack)
# print ("commands.len() =", len(commands))
# print (commands)


exit()








	


























