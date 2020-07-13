import sys

for i in sys.stdin: #sys.stdin 이라는 함수에 대한 공부가 필요함
    a,b=map(int,i.split())
    print(a+b)