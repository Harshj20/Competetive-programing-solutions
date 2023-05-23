#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;


typedef struct athlete{
    long long int s;
    long long int d;
    long long int l;
}athlete;

void swap(long long int&a, long long int&b){
    auto t = a;
    a = b;
    b = t;
}

long long int gcd(long long int a, long long int b){
    if(a < b){
        swap(a, b);
    }
    while (b != 0) 
        swap(b, a%b);

    return a;
}

pair<long long int, long long int> egcd(int a, int b){
    if(b == 0)
        return {1, 0};
    auto t = egcd(b, a%b);
    return {t.second, t.first - t.second*(a/b)};
}

long long int lcm(long long int a, long long int b){
    auto g = gcd(a, b);
    return (a/g)*b;
}

long long int modinv(long long int a, long long int m) {
	return (egcd(a, m).first + m) % m;
}

void change(int a, int &b, int &n) {
    int gd = gcd(a, n);
    if(b%gd){
        //suppose gcd(a, n) = d;
        // then a = d.q1
        //      n = d.q2
        //      b = d.q3 + r
        // now the equation a*x = b (mod n) will have a solution only when a*x - b = n*q
        // this means d.q1.x - d.q3 - d.q2 = r = d.c
        // hence b must be divisible by gcd(a, n)
        cout<<"Solution can not be found"<<endl;
        exit(0);
    }
    a /= gd;
    b /= gd;
    n /= gd;
    b = (b*modinv(a, n))%n;
}

void calculate(athelete*arr, int n){
    long long int ans = 0;
    for(int i = 0; i < n; i++){
        int s = arr[i].s;
        int l = arr[i].l;
        int d = (l-arr[i].d)%l;
        // the equation is (T.s + d)%l = 0 for all atheletes
        // T.s = -d (mod l) = (l-d) mod l
        // we need to convert it to T = [modinver(s)*(l-d)] mod L
        change(s, d, l);
        arr[i].d = d;
        arr[i].l = l;
    }
    // we need to find the smallest T such that T = d[i] (mod l[i]) for all i
    // we can use the chinese remainder theorem to find the smallest T
    ans = arr[0].d;
    for(int i = 0; i < n; i++){
        auto [p, q] = egcd(arr[i].l, arr[i].d);
        long long int inv = ans % arr[i].d;
        ans = (ans * arr[i].l * inv + arr[i].d * inv) % (arr[i].l * inv);
        if (ans == 0)
            ans += arr[i].l * inv;
        else if (ans < 0)
            ans += math.ceil(abs(X) / (arr[i].l * inv)) * arr[i].l * inv
    }
    cout<<ans<<endl;
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
		
		cout<<"case #"<<test_case+1<<endl;
        calculate(athlete, n);
	}

	return 0;//Your program should return 0 on normal termination.
}