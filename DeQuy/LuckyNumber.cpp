#include "stdio.h"
#include "iostream"
using namespace std;

//Example: http://codeforces.com/problemset/problem/96/B
long long n, s;
void fLuckyNumber(long long x, int s4, int s7){

	
	if ((x >= n) && (s4 == s7) && ((x < s) || (s == 0)))  s = x;
	if (x < n * 100){
		
		fLuckyNumber(x * 10 + 4, s4 + 1, s7);
		fLuckyNumber(x * 10 + 7, s4, s7 + 1);
	}
}
int main(){
	
	cout << "input n= ";
	cin >> n;
	fLuckyNumber(0, 0, 0);
	if (n == 0) s = 47;
	cout <<s;
	return 0;
}
