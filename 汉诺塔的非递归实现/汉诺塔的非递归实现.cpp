// ��ŵ���ķǵݹ�ʵ��.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f
int n;
void DFS(int n, char a, char b, char c) {
    if( n <= 1 ) {
        printf("%c -> %c\n", a, c);
        return;
    }
    DFS(n - 1, a, c, b);
    DFS(1, a, b, c);
    DFS(n - 1, b, a, c);
}
int main() {
    cin >> n;
    DFS(n, 'a', 'b', 'c');
    return 0;
}
