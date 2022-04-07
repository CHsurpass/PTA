// 合并排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
///数据范围是2e6,毒瘤题
//数据范围是2e6
#include <bits/stdc++.h>
const int N = 6e6 + 5;
using namespace std;

int a[N], b[N >> 1], c[N];
int n;
int read() {
	int X = 0, w = 0; char ch = 0;
	while (!isdigit(ch)) { w |= ch == '-'; ch = getchar(); }
	while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
	return w ? -X : X;
}
void Input(int* a) {
	n = read();
	*a = n;
	for (int j = 1; j <= n; j++) {
		a++;
		*a = read();
	}
}
void Sort(int* a, int* b, int* c) {
	*c = *a + *b;
	a++;
	b++;
	c++;
	while (*a && *b) {
		if (*a < *b) {
			*c = *a;
			a++;
		}
		else {
			*c = *b;
			b++;
		}
		c++;
	}
	while (*a) {
		*c = *a;
		a++;
		c++;
	}
	while (*b) {
		*c = *b;
		b++;
		c++;
	}
	return;
}
void Swap(int* a, int* c) {
	while (*c) {
		*a = *c;
		a++;
		c++;
	}
}
void Print(int* ret) {
	bool v = false;
	ret++;
	while (*ret) {
		if (v) printf(" ");
		v = true;
		printf("%d", *ret);
		ret++;
	}
	puts("");
}
int main() {
	Input(a);
	Input(b);
	Sort(a, b, c);
	Swap(a, c);
	memset(b, 0, sizeof b);
	memset(c, 0, sizeof c);
	Input(b);
	Sort(a, b, c);
	Print(c);
}
