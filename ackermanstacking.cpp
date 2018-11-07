/*
 *   Functia: Ackermann-Péter
 *
 *             | n+1, daca m=0
 *   A(m,n) = -| A(m-1,1), daca m>0 si n=0
 *             | A(m-1,A(m,n-1)), daca m>0 si n>0
 *
 */

#include<iostream>
using namespace std;
int m,n;

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

int ack(int x,int y){
    if(x==0){
        return y+1;}
    else if(y==0&&x>0){
        return ack(x-1,1);}
    else{return ack(x-1,ack(x,y-1));}}

int main(){
    cout<<"m = ";cin>>m;
    somestack.push(m);
    cout<<"n = ";cin>>n;
    somestack.push(n);
    short unsigned int direction=1;
    int oldval1,oldval2;
    while(somestack.whathight()){
        cout<<somestack.whathight()<<endl;
        if(direction==1){
            somestack.pop(&oldval1);
            somestack.push(oldval1);
            somestack.push(oldval1-1);
            if(oldval1==1){direction=0;}}
    cout<<"A("<<m<<","<<n<<") = ";
    return 1;}
