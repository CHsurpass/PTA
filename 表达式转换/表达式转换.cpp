// 表达式转换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 10+5;
#define inf 0x3f3f3f3f

///是否是数字
int IsNumber(char a){
    return a>='0'&&a<='9';
}
///从字符串start处开始提取操作数或操作符，并返回下一次提取的开端和提取的结果
int getop(char* src,int start,int &nextstart,char* token){
    int i,j;
    if(IsNumber(src[start])){///是一个无符号数
        for(i=0;IsNumber(src[start+i])||src[start+i]=='.';i++){///复制给token
            token[i]=src[start+i];
        }token[i]=0;
        nextstart=start+i;///下一次提取的开端
        return 1;
    }
    else if((src[start]=='+'||src[start]=='-')&&(start==0||src[start-1]=='(')){///是一个有符号数
        if(src[start]=='-'){
            token[0]=src[start];j=1;
        }
        else{///去掉正号
            j=0;
        }
        for(i=1;IsNumber(src[start+i])||src[start+i]=='.';i++){///复制给token
            token[j++]=src[start+i];
        }token[j]=0;
        nextstart=start+i;///下一次提取的开端
        return 1;
    }else{///不是数
        token[0]=src[start];///复制操作符
        token[1]=0;
        nextstart=start+1;///下一次提取的开端
    }
    return 0;
}
///定义优先级。括号最低
int Prior(char ch){
    int pri=0;
    switch(ch){
    case '(':
        pri=1;break;
    case '+':
    case '-':
        pri=2;break;
    case '*':
    case '/':
        pri=3;break;
    }
    return pri;
}
///表达式转换
void Zhong2Hou(char* src,char* str){
    stack<char> stc;
    int i,j,nexti;char token[100];
    for(i=0,j=0;src[i];i=nexti){
        int isnumber=getop(src,i,nexti,token);///提取操作对象
        if(isnumber){///是个数
            int k=0;///复制到str后
            for(k=0;token[k];k++){
                str[j++]=token[k];
            }
            str[j++]=' ';///用空格分隔
        }else if(src[i]=='('){///左括号直接入栈
            stc.push(src[i]);
        }else if(src[i]==')'){///右括号则弹出栈中全部操作符并复制到str后，直到左括号为止
            while(stc.top()!='('){
                str[j++]=stc.top();stc.pop();
                str[j++]=' ';///用空格分隔
            }
            stc.pop();///弹出左括号
        }else{///是个一般的四则运算符
            while(!stc.empty()&&Prior(src[i])<=Prior(stc.top())){
                str[j++]=stc.top();
                stc.pop();
                str[j++]=' ';
            }
            stc.push(src[i]);///将该操作符入栈
        }
    }
    while(!stc.empty()){///弹出栈中全部元素
        str[j++]=stc.top();
        stc.pop();
        str[j++]=' ';
    }
    str[j-1]=0;///最后一个空格赋值为0
}
int main() {
    string s,c="";
    while(cin>>s) {
        stringstream ss;
        if(s[0]=='('&&s[1]=='+') {
            int id=1;
            while(s[++id]!=')') c+=s[id];
            s.erase(s.begin(),s.begin()+id+1);
            s = c + s;
        }
        char src[100]="",str[100]="";
        ss<<s;
        ss>>src;
        ss.clear();
        Zhong2Hou(src,str);///转换
        printf(str);///打印
        puts("");
    }
    return 0;
}
