M,N,x1,y1,E1,N1,f1,x2,y2,E2,N2,f2 = map(int, input().split())
N1_dummy = N1
E1_dummy = E1
N2_dummy = N2
E2_dummy = E2

t = 1
exploded = False
while (f1 > 0 or f2 > 0):
    if (f1 > 0):
        if (N1_dummy > 0):
            y1 += 1
            N1_dummy -= 1
        else:
            x1 += 1
            E1_dummy -= 1
            if (E1_dummy == 0): # 往北又往東結束，重置
                N1_dummy = N1
                E1_dummy = E1

        # 檢查超出邊界
        if (x1 == M):
            x1 = 0
        if (y1 == N):
            y1 = 0

        f1 -= 1 # 記得扣燃料
    if (f2):
        if (E2_dummy > 0):
            x2 += 1
            E2_dummy -= 1
        else:
            y2 += 1
            N2_dummy -= 1
            if (N2_dummy == 0): # 往東又往北結束，重置
                E2_dummy = E2
                N2_dummy = N2

        # 檢查超出邊界
        if (x2 == M):
            x2 = 0
        if (y2 == N):
            y2 = 0

        f2 -= 1 # 記得扣燃料

    if (x1 == x2 and y1 == y2):
        exploded = True
        break

    t += 1

if (exploded):
    print("robots explode at time {}".format(t))
else:
    print("robots will not explode")
