tree = {1:[2,3],2:[4,5],3:[6,7],4:[9,10],5:[11,12]}
start = 1
destination = 6
limit = 3
flag = False

visited = [0 for x in range(50)]

def DLS(u,deep):
    global flag
    print str(u)+"      "+str(deep)
    if u==destination:
        flag=True
        return
    if deep>=limit:
        return
    visited[u] = 1
    if tree.has_key(u):
        for child in tree[u]:
            if visited[child] == 0 and flag==False:
                DLS(child,deep+1)


print "path depth"
print "---- -----"
DLS(1,1)
if flag == False:
    print "Not reachable"
else:
    print "-Reached-"