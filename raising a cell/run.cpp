#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int Answer;

struct cord{
    long long int x, y;
};
bool sort_x(struct cord a, struct cord b){
    return a.x < b.x;
}

bool sort_y(struct cord a, struct cord b){
    return a.y < b.y;
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;

        // loading data
		int n;
        long long int l, r;
        cin>>l>>r;
        cin>>n;
        vector<struct cord> pos(n+2);
        int i;
        pos[i].x = min(0, 2*l);
        for(i = 1; i <= n; i++){
            cin>>pos[i].x>>pos[i].y;
        }
        pos[i].x = max(0, 2*r);
        // solve
        sort(pos.begin(), pos.end(), sort_x);

        long long x = l;
        i = 0;
        while(x <= r){
            if(i > n)
                break;
            
        }
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}