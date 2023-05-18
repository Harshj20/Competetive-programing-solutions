#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct edge{
    int to;
    int from;
}edge;


bool isCyclic(int src, vector<deque<int>>&graph){
    int n = graph.size();
    vector<bool>visited(n, false);
    stack<int>st;
    st.push(src);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(visited[curr]){
            if(curr == src)
                return true;
            else continue;
        }
        visited[curr] = true;
        for(auto &i : graph[curr]){
            st.push(i);
        }
    }
    return false;
}

void evaluate(vector<deque<int>>&graph, vector<edge>&edges){
    for(auto &i : edges){
        int src = i.from;
        int dst = i.to;
        graph[src].push_back(dst);
        if(isCyclic(src, graph)){
            cout<<'1';
            graph[src].pop_back();
            graph[dst].push_back(src);
        }
        else{
            cout<<'0';
        }
    }
}

int main(int argc, char** argv)
{
	int T, test_case, n, m, k, a, b;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{   
        cin>>n>>m>>k;
        vector<deque<int>>graph(n);
        vector<edge>edges(k);
        for(int i = 0; i < m; i++){
            cin>>a>>b;
            graph[a-1].push_back(b-1);
        }
        for(int i = 0; i < k; i++){
            cin>>a>>b;
            edges[i].to = b-1;
            edges[i].from = a-1;
        }
		cout << "Case #" << test_case+1 << endl;
        evaluate(graph, edges);
        cout<<endl;
	}

	return 0;//Your program should return 0 on normal termination.
}