#  Aida Colovic
#  Kattis Problem   : Three Powers
#  Problem ID       : threepowers
#  CPU Time limit   : 1 sec
#  Memory limit     : 1024 MB
#  Difficultiy      : 2.3

def solve(n):
    begin = True
    shift = 0

    print('{', end='')

    while(n > 0):
        if(n & 1 == 1):
            if begin == True:
                print(' {:d}'.format(3**shift), end='')
                begin = False
            else:
                print(', {:d}'.format(3**shift), end='')
        n >>= 1
        shift += 1
    print(' }')


while True:
    n = int(input())
    if(n == 0):
        break
    solve(n-1)
