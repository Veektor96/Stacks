/*
 *   Functia: Manna Pnueli
 *
 *   f : Z ----> Z
 *
 *           | x-1, daca x>=12
 *   f(x) = -|
 *           | f(f(x+2)), daca x<12
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
    int isempty(){return (top<1);}
    private :
    int top;
    int S[100];
    int maxsize=100;};

stack somestack;

int manna(int n){
    if(n>=12){
        return n-1;}
    else{
    return manna(manna(n+2));}}

int main(){
    cout<<"x = ";cin>>x;
    somestack.push(x);
    short unsigned int direction=1;
    int oldval;
    while(somestack.whathight()){
        cout<<somestack.whathight()<<endl;
        if(direction==1){
            somestack.pop(&oldval);
            somestack.push(oldval);
            somestack.push(oldval-1);
            if(oldval==1){direction=0;}}
        else{
            if(x>=12){
                somestack.pop(&oldval);
                somestack.pop(&oldval);
                somestack.push(x-1);
                somestack.pop(&oldval);}
            else{
                somestack.pop(&oldval);
                somestack.push(manna(x+2));
                somestack.pop(&oldval);}}}
    cout<<"f("<<x<<") = "<<oldval;
    return 1;}
