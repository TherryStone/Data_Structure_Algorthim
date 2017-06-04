#include "stdio.h"
#include "math.h"
#include "iostream"

//Example: http://www.spoj.com/PTIT/problems/PTIT122F/
using namespace std;
long checkNumber(char *w, char *p, int h){
	
	if(*w ==0) return 0;
	if(*w == '?'){
		return (9 -(*p -'0'))* (long )pow(10, h-1)+ checkNumber(w+1, p+1, h-1);
	}
	else if(*w < *p) return 0;
	else if(*w > *p) return (long)pow(10, h);
	return checkNumber(w+1, p+1, h);
	
}
main(){
	
	int T = 0, h;
	char w[1000], p[1000], *r;
	long k[5000];
	
	do
    {
        h=0;
        cin>>w;
        if(*w=='#') break;
        cin>> p;
        for(r=w;*r;r++) if(*r=='?') h++;
        T++;
        k[T] = checkNumber(w, p, h);
    }while(1);
    for(int i=1;i<=T;i++){
		
		cout<<k[i]<<"\n";
	}
}

