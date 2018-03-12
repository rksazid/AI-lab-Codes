tree = {1:[2,3],2:[4,5],3:[6,7],4:[9,10],5:[11,12]}
fringe = []

def DLS(start,dest,deep):
	if start == dest:
		return True
	if deep <= 0:
		return False

	if tree.has_key(start):
		for child in tree[start]:
			if DLS(child,dest,deep-1):
				fringe.append(child)
				return True
		return False

def ItDeep(start,dest,deep):
	for i in range(deep):
		if DLS(start,dest,i):
			fringe.append(start)
			return True
	return False

start = 1
dest = 12
deep = 4

if ItDeep(start,dest,deep)==True:
	print "Reachable"
	print "Path : ",
	for i in reversed(fringe):
		print i,
else:
	print "Not reachable"
