#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define base 200000
int Answer;

int a[5001]; //stores number
bool b[200001 + base]; // check if a number in i can be written as a sum of two number a[j] + a[k] 

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
    
	for(test_case = 0; test_case  < T; test_case++)
	{
        for(int i = 0; i < 200001 + base; i++)
            b[i] = false;
		Answer = 0;
		int n;
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            for(int j = 0; j < i; j++){ // lets say sum is x. We check if we can break x - a[j] can be broken into sum to two numbers
                if(b[a[i] - a[j]]){
                    Answer++;
                    break;
                }
            }
            for(int j = 0; j <= i; j++) // we keep track of numbers which can be written as sum of two numbers in the sequence
                b[a[i] + a[j]] = true;
        }
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}