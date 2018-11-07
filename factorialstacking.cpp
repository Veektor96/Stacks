/*
 *   Functia: Factorial
 *
 *   f : N* ----> N*
 *
 *           | 1, daca n=1
 *   f(x) = -|
 *           | f(x-1)*x, daca x>1
 */

#include<iostream>
using namespace std;
int x;

class stack{
    public:
    stack(){top=0;}
        int push(int value){
            if(top<maxsize){
                top++;
                S[top]=value;
                return 1;}
            return 0;}
        int pop(int *old){
            if(isempty()){return 0;}
            *old=S[top];
            top--;
            return 1;}
        int whathight(){return top;}
        int isempty(){return(top<1);}
        private:
        int top;
        int maxsize=100;
        int S[100];};

stack somestack;

int main(){
    cout<<"x = ";cin>>x;
    somestack.push(x);
    int direction=1;
    int oldval1,oldval2;
    while(somestack.whathight()){
        cout<<somestack.whathight()<<endl;
        if(direction==1){
            somestack.pop(&oldval1);
            somestack.push(oldval1);
            somestack.push(oldval1-1);
            if(oldval1-1==1){direction=0;}}
        else{
            somestack.pop(&oldval1);
            if(somestack.pop(&oldval2)){
                somestack.push(oldval1*oldval2);}}}
    cout<<"f("<<x<<") = "<<oldval1;
    return 1;}
