//
//  main.cpp
//  DSHomework4
//
//  Created by apple on 16/10/15.
//  Copyright © 2016年 YangZhiZhuang. All rights reserved.
//

#include <iostream>
class charStack
{
public:
    charStack(int size=100)
    {
        stack=(char*)malloc(sizeof(char)*size);
        maxSize=size;
        topPos=-1;
    }
    ~charStack()
    {
        delete[] stack;
    }
    void push(char c)
    {
        if(topPos==maxSize-1)
            std::cout<<"Stack is full."<<std::endl;
        else
            stack[++topPos]=c;
    }
    char pop()
    {
        if(topPos==-1)
        {
            std::cout<<"stack is empty."<<std::endl;
            return 0;
        }
        else
            return stack[topPos--];
    }
    char top()
    {
        if(topPos==-1)
        {
            std::cout<<"stack is empty."<<std::endl;
            return 0;
        }
        else
            return stack[topPos];
    }
    bool isEmpty()
    {
        if(topPos==-1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(topPos==maxSize-1)
            return true;
        else
            return false;
    }
private:
    int maxSize;
    int topPos;
    char *stack;
};
int match(charStack *st)
{
    int big=0;
    int mid=0;
    int lit=0;
    char temp=0;
    int res=0;  //0 1 2 3 4 5 6 7
    while(!st->isEmpty())
    {
        temp=st->pop();
        switch(temp)
               {
                   case '{':
                       big--;
                       break;
                   case '[':
                       mid--;
                       break;
                   case '(':
                       lit--;
                       break;
                   case '}':
                       big++;
                       break;
                   case ']':
                       mid++;
                       break;
                   case ')':
                       lit++;
                       break;
                   default:
                       break;
               }
    }
    if(lit!=0)
        res+=1;
    if(mid!=0)
        res+=2;
    if(big!=0)
        res+=4;
    return res;
}
int main(int argc, const char * argv[])
{
    charStack st(100);
    std::string temp;
    std::cout<<"please input the string to test:"<<std::endl;
    std::cin>>temp;
    const char *ca=temp.c_str();
    while(*ca)
    {
        st.push(*ca);
        ca++;
    }
    switch(match(&st))
    {
        case 1:
            std::cout<<"() doesn't match."<<std::endl;
            break;
        case 2:
            std::cout<<"[] doesn't match."<<std::endl;
            break;
        case 3:
            std::cout<<"()&[] doesn't match."<<std::endl;
            break;
        case 4:
            std::cout<<"{} doesn't match."<<std::endl;
            break;
        case 5:
            std::cout<<"()&{} doesn't match."<<std::endl;
            break;
        case 6:
            std::cout<<"[]&{} doesn't match."<<std::endl;
            break;
        case 7:
            std::cout<<"All doesn't match."<<std::endl;
            break;
        default:
            std::cout<<"All matched."<<std::endl;
            break;
    }
    return 0;
}
