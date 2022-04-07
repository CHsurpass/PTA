// Shuffling Machine.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

string s = "SHCD";
stringstream ss;
string str;
struct node {
    string p;
    int id;
    bool operator<(const node& a) const {
        return id < a.id;
    }
}card[55];
int k;
int a[55];
int uid;
int eid;
int ff(string s) {
    int n;
    stringstream ss;
    ss << s;
    ss >> n;
    ss.clear();
    return n;
}
void Print() {
    for (int i = 1; i < uid; i++) {
        cout << card[i].p << ' ';
    }
    cout << card[uid].p << endl;
}
int main() {
    uid = eid = 0;
    cin >> k;
    cin.ignore();
    getline(cin, str);
    string c;
    ss << str;
    while (getline(ss, str, ' ')) {
        a[++eid] = ff(str) ;
    }
    ss.clear();
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {       
            ss << j;
            ss >> str;
            ss.clear();
            card[++uid] = { s[i] + str ,a[uid+1]};
        }
    }
    card[++uid] = { "J1",a[uid + 1] };
    card[++uid] = { "J2",a[uid + 1] };
    while (k--) {
        sort(card + 1, card + uid + 1);
        for (int i = 1; i <= uid; i++) {
            card[i].id = a[i];
        }
    }
    Print();
}
/*
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5

*/