#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
int Answer;


typedef struct athlete{
    int s;
    int d;
    int l;
}athlete;

typedef struct no{
    int num;
    int denom;
}no;

void swap(int*a, int*b){
    int t = *a;
        *a = *b;
        *b = t;
}

int gcd(int a, int b){
    if(a < b){
        swap(&a, &b);
    }
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long int lcm(int a, int b){
    int g = gcd(a, b);
    return (a/g)*b;
}

pair<ll, ll> egcd(ll a, ll b) {
	if (b == 0) return { 1, 0 };
	auto t = egcd(b, a % b);
	return { t.second, t.first - t.second * (a / b) };
}

inline ll modinv(ll a, ll m) {
	return (egcd(a, m).first % m + m) % m;
}

int findIntegerM(int a, int b, int n) {
    int gd = gcd(a, n);
    if(b%gd)
        return -1;
    a /= gd;
    b /= gd;
    n /= gd;
    b = (b*modinv(a, n))%n;

    return b;
}
no find_lcm_of_fractions(int numerator1, int denominator1, int numerator2, int denominator2) {
    no ret;
    ret.num = lcm(numerator1, numerator2);
    ret.denom = gcd(denominator1, denominator2);
    return ret;
}
no find(no a, no b, no c, int d){
    long long int num_c = b.num*c.denom*a.denom - d*b.denom*a.denom;
    long long int mul_c = c.num*b.denom*a.denom;
    long long int denom = c.denom*b.denom*a.num;
    if(num_c > 0)
        num_c = (denom-num_c)%denom;
    else 
        num_c *=-1;
    int m = findIntegerM(mul_c, num_c, denom);
    // int m = 0;
    // int num = 0;
    // cout<<mul_c<<" "<<num_c<<" "<<denom<<endl;
    // while(1){
    //     num = m*mul_c + num_c;
    //     if(num >= 0 && num%denom == 0)
    //         break;
    //     m++;
    // }
    // cout<<"m is "<<m<<endl;
    // cout<<"n is "<<((m*mul_c + num_c)/denom)<<endl;
    no ret;
    ret.num = m*c.num-d;
    ret.denom = c.denom;
    return ret;
}

int main(void)
{
	int T, test_case;

	setbuf(stdout, NULL);

	cin>>T;
	for(test_case = 0; test_case < T; test_case++)
	{
		int n;
		cin>>n;
		athlete arr[n];
		for(int i = 0; i < n; i++)
		    cin>>arr[i].s>>arr[i].l>>arr[i].d;
		
		no t1 = find({arr[0].l, arr[0].s}, {arr[0].d, arr[0].s}, {arr[1].l,arr[1].s}, arr[1].d);
		no t2 = find_lcm_of_fractions(arr[0].l, arr[0].s, arr[1].l, arr[1].s);
		if(t1.num%t1.denom==0){
		    t1.num /= t1.denom;
		    t1.denom = 1;
		}
		if(t2.num%t2.denom==0){
		    t2.num /= t2.denom;
		    t2.denom = 1;
		}
		// cout<<"for 1 and 2 t1 is "<<t1.num<<" "<<t1.denom<<endl;
		// cout<<"t2 is "<<t2.num<<" "<<t2.denom<<endl;
		for(int i = 2; i < n; i++){
		    t1.num *= -1;
		    t1 = find(t2, t1, {arr[i].l, arr[i].s}, arr[i].d);
		    t2 = find_lcm_of_fractions(t2.num, t2.denom, arr[i].l, arr[i].s);
		    if(t1.num%t1.denom==0){
    		    t1.num /= t1.denom;
    		    t1.denom = 1;
    		}
    		if(t2.num%t2.denom==0){
    		    t2.num /= t2.denom;
    		    t2.denom = 1;
    		}
		//    cout<<"for new t1 is "<<t1.num<<" "<<t1.denom<<endl;
		//    cout<<"t2 is "<<t2.num<<" "<<t2.denom<<endl;
		}
		Answer = t1.num/t1.denom;
		cout<<"Case #"<<(test_case+1)<<endl;
	    cout<<Answer<<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}