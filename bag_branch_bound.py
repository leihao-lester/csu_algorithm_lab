#-*- coding:utf8 -*-
import copy
from collections import deque

# 用分枝定界法解决0/1背包问题
def brunch_bound(w, p, c):
    plan = list()
    buffer = deque([[copy.copy(w), [], []]])  # [waiting, explored, values]
    while len(buffer):
        cur = buffer.popleft()
        for i in range(0, len(cur[0])):
            weight = cur[0][i]
            n = copy.deepcopy(cur)
            n[0].remove(weight)
            n[1].append(weight)
            n[2].append(p[i])
            if sum(n[1]) > c:
                continue  # overloaded
            buffer.append(copy.deepcopy(n))
        plan.append(cur)
    return plan

if __name__ == '__main__':
    w = [20, 15, 15]
    p = [40, 25, 25]
    c = 30
    plan = brunch_bound(w,p,c)
    l = sorted(plan, key=lambda x:sum(x[2]), reverse=True)  # l[0] is the most value plan
    for e in l:
        print(e)