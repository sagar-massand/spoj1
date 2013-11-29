#!/usr/bin/python
t=input()
for i in range(0,t):
	j=raw_input()
	firstName, lastName = j.split(' ', 1)
	x=int (firstName)
	n=int (lastName)
	ans=x
	while(x>=n):
		temp=(x/n)
		x%=n
		x+=temp
		ans+=temp
	print ans