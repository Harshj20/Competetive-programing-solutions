#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long int Answer;
long long int ans;
int l[3];
vector<int> w(4);

inline void swap(int&a, int&b){
    int _ = a;
    a = b;
    b = _;
}

int main(int argc, char** argv)
{
	int T, test_case;
	
	scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++)
	{   
		Answer = 0;
        ans = 0;

        for(int i = 0; i < 3; i++)
            l[i] = 0;

        int n, m, s, temp, x = 0;
        scanf("%d %d", &n, &m);
        vector<vector<int>>w_odd;

        for(int lamba = 0; lamba < n; lamba++){
            scanf("%d ", &s);
            for(int i = 0; i < 4; i++)
                w[i] = INT_MAX;

            for(int i = 0; i < s; i++){
                scanf("%d", &temp);
                if(temp < w[3]){
                    w[3] = temp;
                    if(w[2] > w[3])
                        swap(w[2], w[3]);
                    if(w[1] > w[2])
                        swap(w[1], w[2]);
                    if(w[0] > w[1])
                        swap(w[0], w[1]);
                }
            }

            if(s&1){
                Answer += (2*w[0] + w[1] + w[2] + w[3]);
                if(x < 2)
                    w_odd.push_back(w);
                x++;
            }
            else{
                Answer += (w[0] + w[1] + w[2] + w[3]);
                ans += (w[0] + w[1]);
            }

            if(l[2] < w[2] + w[3]){
                l[2] = w[2] + w[3];
                if(l[1] < l[2]){
                    swap(l[1], l[2]);
                    if(l[0] < l[1])
                        swap(l[1], l[0]);
                }
            }
        }

        if(x == 0 || x == n || x > 2){
            Answer -= (l[0] + l[1]);
        }
        else{
            if(l[0] + l[1] == w_odd[0][2] + w_odd[0][3] + w_odd[1][2] + w_odd[1][3]){
                if(ans + l[2] < l[1])
                    Answer  = Answer + ans - l[0] - l[1];
                else 
                    Answer = Answer - l[0] - l[2];
            }
            else{
                Answer = Answer - l[0] - l[1];
            }
        }
		printf("Case #%d\n%lld\n", test_case+1, Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}