#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
    cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        int n;
        cin>>n;
        int a[n];
        int m = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(a[i] > m)    
                m = a[i];
        }
        m++;
        for(int i = 0; i < n; i++)
            if(a[i] + n >= m)
                Answer++;
        
        
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}