#a = int(input())
#b = int(input())
#Runtime error
#input 은 한 줄을 입력 받는 함수라, 숫자와 숫자 사이가 공백으로 나눠져있으면 int(input())의 에러가 난다.

a,b = map(int, input().split())

print(a+b)