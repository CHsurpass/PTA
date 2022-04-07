// QQ帐户的申请与登陆.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e5 + 5;
#define inf 0x3f3f3f3f

int n;
string s, pwd;
ll num;
map<ll, string>mp;
int main() {
	cin >> n;
	while( n-- ) {
		cin >> s >> num >> pwd;
		if( s == "N" ) {
			if( mp[num] != "" ) {
				cout << "ERROR: Exist" << endl;
			} else {
				mp[num] = pwd;
				cout << "New: OK" << endl;
			}
		}
		if( s == "L" ) {
			if( mp[num] == pwd ) {
				cout << "Login: OK" << endl;
			} else if( mp[num] != "" ) {
				cout << "ERROR: Wrong PW" << endl;
			} else {
				cout << "ERROR: Not Exist" << endl;
			}
		}
	}
	return 0;
}