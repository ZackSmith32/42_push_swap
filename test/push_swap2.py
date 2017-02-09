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

	def find_smallest_index(self):
		# pivot = 0
		# smallest = self.stack[pivot]
		# i = 1
		# for i in range(self.len()):
		# 	if self.stack[i] < smallest:
		# 		pivot = i
		# 		smallest = self.stack[pivot]
		# return pivot

		if self.stack[0] < self.stack[-1]:
			return 0
		for i in range(self.len() - 1):
			if self.stack[i] > self.stack[i + 1]:
				return i + 1
		return 1


	def find_smallest(self):
		return self.stack[self.find_smallest_index()]

	def find_largest_index(self):
		pivot = 0
		largest = self.stack[pivot]
		i = 0
		for i in range(self.len()):
			if self.stack[i] >= largest:
				largest = self.stack[i]
				pivot = i
		return pivot

	def find_largest(self):
		return self.stack[self.find_largest_index()]

	# must supply destination for correctly populating command list
	def pop_x(self, dest):
		commands.append('p' + dest.name)
		dest.stack.append(self.stack.pop())

	def rr(self):
		l = self.len()
		front = self.stack.pop()
		self.stack.insert(0, front)
	
	def r(self):
		self.rr()	
		commands.append('r' + self.name)

	def s(self):
		front = self.stack.pop()
		self.stack.insert(-1, front)
		commands.append('s' + self.name)

	def rrr(self):
		l = len(self.stack)
		i = 1
		temp = self.stack[0]
		while i < l:
			self.stack[i - 1] = self.stack[i]
			i += 1
		self.stack[i - 1] = temp

	def	r_rev(self):
		self.rrr()
		commands.append('rr' + self.name)

	def peak(self):
		l = len(self.stack)
		if l == 0:
			return
		return self.stack[l - 1]


def rr():
	stacka.rr()
	stackb.rr()
	commands.append('rr')

def rrr():
	stacka.rrr()
	stackb.rrr()
	commands.append('rrr')


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




'''
	last_b = index of last element
	must remember range is exclusive of top element, effectively creating a -1
'''

def calc_ops(i):
	last_a = stacka.len() - 1
	last_b = stackb.len() - 1
	num = stacka.stack[i]
	# print 'last_b =', last_b
	k = 0
	# print 'num =', num
	# print 'stackb =', stackb.stack
	# for if the stackb only has one element
	if last_b == 0:
		# print 'b == 0 or i + 1 == last_b'
		b_f_diff = 0
		b_r_diff = 0
		
	# if there are multi
	elif num in stackb.stack:
		# print 'dupliicate num =', num
		b_f_diff = 0
		b_r_diff = 0
		for l in range(last_b):
			# print 'l =', l
			if stackb.stack[l] != num and stackb.stack[l + 1] == num:
				b_r_diff = l + 1
			if stackb.stack[l] == num and stackb.stack[l + 1] != num:
				b_f_diff = last_b - l
		# break
	# if the num is the smallest
	elif num < stackb.find_smallest():
		# print 'num =', num, 'smallest =', stackb.find_smallest(), 'index =', stackb.find_smallest_index()
		b_f_diff = last_b - stackb.find_smallest_index() + 1
		b_r_diff = stackb.find_smallest_index()
		# break
	# if the num is the largest
	elif	num > stackb.find_largest():
		# print 'largest find_largest =', stackb.find_largest()
		b_f_diff = last_b - stackb.find_largest_index()
		b_r_diff = stackb.find_largest_index() + 1
		# break

	else:
		# print 'regular num =', num
		b_f_diff = 0
		b_r_diff = last_b + 1
		m = 0
		for m in range(last_b):
			if (	num > stackb.stack[m]  and
					num < stackb.stack[m + 1] ):
				# print 'num =', num, 'm =', m
				b_f_diff = last_b - m
				b_r_diff = m + 1
				break
	a_f_diff = last_a - i
	a_r_diff = i + 1

	print 'a_f_diff:', a_f_diff, 'b_r_diff', b_r_diff
	moves = ((	a_f_diff + b_r_diff,
				a_r_diff + b_f_diff,
				max([b_f_diff, a_f_diff]),
				max([b_r_diff, a_r_diff])
			), 
			(a_f_diff, a_r_diff, b_f_diff, b_r_diff))
	# moves = ((	999,
	# 			999,
	# 			999,
	# 			999
	# 		), 
	# 		(a_f_diff, a_r_diff, b_f_diff, b_r_diff))
	return moves

'''
	itterate through all numbers in stack a, call the function that
	calcs the optimal number of operations, then identify the index
	of the list item that takes the fewes number of operations to get
	it into its sorted order in b
'''
def index_to_move():
	
	num_ops = []
	i = 0
	print 'index_to_move len():', stacka.len()
	while i < stacka.len():
		ops = calc_ops(i)
		# print 'index_to_move i =', i
		# print 'ops =', ops
		# print '\n'
		num_ops.append(min(ops[0]))
		i += 1
	# print 'num ops', num_ops, 'i =', i - 1
	lowest = 0
	j = 0
	while j < len(num_ops):
		if (num_ops[j] < num_ops[lowest]):
			lowest = j
		j += 1
	times = calc_ops(lowest)[0]
	rot = calc_ops(lowest)[1]
	alg = times.index(min(times))
	print 'num =', stacka.stack[lowest]
	# print 'num_ops =', num_ops
	print 'lowest =' , lowest
	print 'index to move return: ', ((lowest, alg), rot)
	print 'index stackb =', stackb.stack
	print '\n'
	# print 'index stacka =', stacka.stack
	return ((lowest, alg), rot)


# info = (index, operation), 
# rot = (a_f_diff, a_r_diff, b_f_diff, b_r_diff)
def move_to_b(info, rot):
	index = info[0]
	a_f_diff = rot[0]
	a_r_diff = rot[1]
	b_f_diff = rot[2]
	b_r_diff = rot[3]
	if (info[1] == 0):
		for i in range(a_f_diff):
			stacka.r()
		for i in range(b_r_diff):
			stackb.r_rev()
	if (info[1] == 1):
		for i in range(a_r_diff):
			stacka.r_rev()
		for i in range(b_f_diff):
			stackb.r()
	if (info[1] == 2):
		rot = a_f_diff - b_f_diff
		if rot < 0:
			for i in range(a_f_diff):
				rr()
			for i in range(abs(rot)):
				stackb.r()
		else:
			for i in range(b_f_diff):
				rr()
			for i in range(abs(rot)):
				stacka.r()
	if (info[1] == 3):
		rot = a_r_diff - b_r_diff
		if rot < 0:
			for i in range(a_r_diff):
				rrr()
			for i in range(abs(rot)):
				stackb.r_rev()
		else:
			for i in range(b_r_diff):
				rrr()
			for i in range(abs(rot)):
				stacka.r_rev()
	stacka.pop_x(stackb)


def in_order(stack):
	count = 0
	for i in range(len(stack) - 1):
		if (stack[i] > stack[i + 1]):
			count += 1
	if (stack[0] < stack[-1]):
		count += 1
	if count != 1:
		return 'false: not ordered'
	return 'true: in order'


num_digis = 100

stacka = stack('a', [])
stackb = stack('b', [])
commands = []
temp = []
for z in range(num_digis):
	temp.append(randint(0, 100))
# use list to make a duplicate of the list
sort_temp = list(temp)
sort_temp.sort()
median = sort_temp[num_digis / 2]

# remove dupes
sort_temp = list(set(sort_temp))

# change all values to their order number
for i in range(num_digis):
	k = sort_temp.index(temp[i])
	# create tupe with order and val, but val not necessary
	# stacka.stack.append((k, temp[i]))
	stacka.stack.append(k)
stacka.pop_x(stackb)
stacka.pop_x(stackb)



# figure out how man opperations to get each element to place where it 
# needs to be in stack b.
# first attempt will not move over elements that are not right next to
# thier counterparts in stack b

'''
	optimizations: once stack a gets small enough change technique
'''

while stacka.len() > 1:
	print 'stacka.len() =',  stacka.len()
	info = index_to_move()
	move_to_b(info[0], info[1])

'''
	test stacks
'''

# stacktest = stack('test', [100, 16, 1, 17, 2, 3,15,25,  4, 5, 6, 7, 8])
# print 'largest ret =', stacktest.find_largest()
# print 'largest index =', stacktest.find_largest_index()


# print ('stacka:' , stacka.stack)
print ('stackb:' , stackb.stack)
print ("commands.len() =", len(commands))
# print (commands)
print in_order(stackb.stack)

exit()






	


























