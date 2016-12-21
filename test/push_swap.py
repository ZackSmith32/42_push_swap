import random
import sys
import os

stacka = [3, 5, 7, 99, 0, 47, 4]
stackb = []
commands = []
lena = len(stacka)

def pb():
	stackb.append(stacka.pop())
	commands.append('pb')

def pa():
	stacka.append(stackb.pop())
	commands.append('pa')

def ra():
	l = len(stacka)
	stacka.insert(0, stacka.pop(l - 1))
	commands.append('ra')

def rb():
	l = len(stacka)
	stackb.insert(0, stackb.pop(l - 1))
	commands.append('rb')

def peak(lst):
	l = len(lst)
	if l == 0:
		return
	return lst[l - 1]


sorta = list(stacka)
sorta.sort()
min = sorta[0]

while (1):
	print ("first while loop")
	if peak(stacka) == min:
		pb()
		break
	ra()

while (1):
	if peak(stacka) > peak(stackb):
		print ("in peak")
		print ("pre pb" , stackb)
		pb()
		print ("post pb", stackb)
		continue
	if len(stacka) == 0:
		break
	pa()
	print ("pre ra =" , stacka)
	ra()
	print ("postra =" , stacka)


print ("stacka:", stacka)
print ("stackb:", stackb)
print ("commands:" , commands)



























