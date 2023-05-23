#include <iostream>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

typedef struct athlete {
    int s;
    int d;
    int l;
} athlete;

void customSwap(__int128& a, __int128& b) {
    auto t = a;
    a = b;
    b = t;
}

__int128 gcd(__int128 a, __int128 b) {
    if (a < b) {
        customSwap(a, b);
    }
    while (b != 0) {
        a = a%b;
        customSwap(a, b);
    }
    return a;
}

pair<__int128, __int128> egcd(__int128 a, __int128 b) {
    if (b == 0)
        return { 1, 0 };
    auto t = egcd(b, a % b);
    return { t.second, t.first - t.second * (a / b) };
}

__int128 lcm(__int128 a, __int128 b) {
    auto g = gcd(a, b);
    return (a / g) * b;
}

__int128 modinv(__int128 a, __int128 m) {
    return (egcd(a, m).first + m) % m;
}

void change(int a, int& b, int& n) {
    int gd = gcd(a, n);
    if (b % gd) {
        //suppose gcd(a, n) = d;
        // then a = d.q1
        //      n = d.q2
        //      b = d.q3 + r
        // now the equation a*x = b (mod n) will have a solution only when a*x - b = n*q
        // this means d.q1.x - d.q3 - d.q2 = r = d.c
        // hence b must be divisible by gcd(a, n)
        cout << "Solution cannot be found" << endl;
        exit(0);
    }
    a /= gd;
    b /= gd;
    n /= gd;
    b = (b * modinv(a, n)) % n;
}

void calculate(athlete* arr, int n) {
    for (int i = 0; i < n; i++) {
        int s = arr[i].s;
        int l = arr[i].l;
        int d = (l - arr[i].d) % l;

        // the equation is (T.s + d)%l = 0 for all atheletes
        // T.s = -d (mod l) = (l-d) mod l
        // we need to convert it to T = [modinver(s)*(l-d)] mod L

        change(s, d, l);
        arr[i].d = d;
        arr[i].l = l;
    }

    // we need to find the smallest T such that T = d[i] (mod l[i]) for all i
    // we can use the chinese remainder theorem to find the smallest T

    long long int a1 = arr[0].d;
    long long int m1 = arr[0].l; 
    for ( int i = 1; i < n; i++ ) {
        long long int a2 = arr[i].d;
        long long int m2 = arr[i].l;
 
        long long int g = gcd(m1, m2);
        if ( a1 % g != a2 % g ) {/** No solution exists*/
            cout<<"No Solution"<<endl;
            exit(0);
        }
 
        /** Merge the two equations*/
        pair<__int128, __int128> t = egcd(m1/g, m2/g);
        __int128 p = t.first, q = t.second;
        __int128 mod = m1 / g * m2; /** LCM of m1 and m2*/
 
        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        __int128 x = (a1*(m2/g)*q % mod + a2*(m1/g)*p % mod) % mod;
 
        /** Merged equation*/
        a1 = x;
        if (a1 <= 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    cout<< a1 << endl;
}

int main(void) {
    int T, test_case;

    setbuf(stdout, NULL);

    cin >> T;
    for (test_case = 0; test_case < T; test_case++) {
        int n;
        cin >> n;
        athlete arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i].s >> arr[i].l >> arr[i].d;

        cout << "Case #" << test_case + 1 << endl;
        calculate(arr, n);
    }

    return 0;
}
