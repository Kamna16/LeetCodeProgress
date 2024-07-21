#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
	stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
       s1.push(x); 
    }
    
    int pop() {
        while(!s1.empty())
		{
			int elem = s1.top();
			s1.pop();
			s2.push(elem);
		};
		int elem =  s2.top();
		s2.pop();
		while(!s2.empty())
		{
			int elem = s2.top();
			s2.pop();
			s1.push(elem);
		};
		return elem;
    }
    
    int peek() {
        while(!s1.empty())
		{
			int elem = s1.top();
			s1.pop();
			s2.push(elem);
		};
		int elem =  s2.top();
		while(!s2.empty())
		{
			int elem = s2.top();
			s2.pop();
			s1.push(elem);
		};
		return elem;
    }
    
    bool empty() {
        return s1.empty();
    }
};
