from random import *
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

def	i_val(i, l):
	if i == l:
		return 0
	if i < 0:
		return (l - 1)
	return i
		
def check_rotated(lst):
	i = 0
	index = 0
	counter = 0
	l = len(lst.stack)
	if l == 0:
		return
	while (i + 1) < l:
		if lst.stack[i] < lst.stack[i + 1]:
			index = i
			counter += 1
		i += 1
	if lst.stack[i] <= lst.stack[0]:
		counter += 1
		index = i
	if counter <= 1:
		return index
	else:
		return -1

'''
	> pops out the smallest number in an array
	> could potentially use the find shortest path from the pivot reset on this
		> would mean breaking out the pivot reset to basically take an arg, then
		figure out the shortest path to get that arg to the top of the stack
'''
def pop_min(lst, dest):
	temp = list(lst.stack)
	temp.sort()
	min = temp[0]
	while 1:
		if lst.peak() == min:
			lst.pop_x(dest)
			return
		lst.r()

# finds the pivot of a sorted array, even if it is rotated
def pivot(lst):
	temp = list(lst)
	l = len(temp)
	while i < l:
		if lst[i] < lst[i_val(i + 1)] and lst[i] < lst[i_val(i - 1)]:
			return lst[i]
		i += 1

'''
	> rotate string until pivot is in the top spot of the stack (the last spot)
	> chose wheather to rotate or reverse rotate, whichever uses frewer commands
	> takes a stack object as its argument
'''
def pivot_reset(lst, pivot):
	l = lst.len()

	if (l - pivot - 1) <= pivot:
		print ("rotate right:l =",l , lst.stack)
		while pivot < (l - 1):
			print ("rotate while")
			lst.r()
			pivot += 1
	else:
		print ("rotate left:" , lst.stack)
		while pivot >= 0:
			lst.rr()
			pivot -= 1


stacka = stack('a', [])
z = 0
while z < 4:
	stacka.stack.append(randint(1, 100))
	z += 1
stackb = stack('b', [])
commands = []
sorta = list(stacka.stack)
sorta.sort()
min = sorta[0]

'''
	this loop pops the lowst item from stack a (using pop_min) until
	stack a is sorted.  Then rotates the list so that pivot is at the top
	of stack
'''
print ("starting stack:", stacka.stack)
while 1:
	pivot = check_rotated(stacka)
	if pivot != -1:
		print ("stack rotated. pivot = ", pivot, stacka.stack, stackb.stack)
		pivot_reset(stacka, pivot)
		print ("stack oriented to pivot", stacka.stack)
		break
	pop_min(stacka, stackb)

while len(stackb.stack) > 0:
	stackb.pop_x(stacka)

print ("ordered stacka:", stacka.stack)
print ("stackb:", stackb.stack)
print ("length = ", len(commands), commands)

	


























