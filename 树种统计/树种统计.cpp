// ����ͳ��.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f

int n;
map<string, int>mp;
string s;
int main() {
	cin >> n;
	cin.ignore();
	int _ = n;
	while( _-- ) {
		getline(cin, s);
		mp[s]++;
	}
	cout << fixed << setprecision(4);
	for( auto ret : mp ) {
		cout << ret.first << ' ' << 100.0 * ret.second / n << "%" << endl;
	}
	return 0;
}