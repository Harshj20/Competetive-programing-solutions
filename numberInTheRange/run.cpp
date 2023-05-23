#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int Answer;
long long int maxx;

int main(int argc, char **argv)
{
    int T, test_case;
    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {

        Answer = maxx = 0;  
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        set<int> sortedSet;
        unordered_map<int, int> countMap;
        int po = pow(10, k-1);
        int element = atoi(s.substr(0, k).c_str());
        for (int j = k-1; j < n-1; j++)
        {
            auto it = sortedSet.find(element);
            if (it != sortedSet.end())
            {
                countMap[element]++;
            }
            else
            {
                sortedSet.insert(element);
                countMap[element] = 1;
            }
            element = (element%po)*10 + s[j+1] - '0';
        }

        auto lt = sortedSet.begin();
        auto rt = sortedSet.begin();
        int l = 0, r = countMap[*rt];
        while (rt != sortedSet.end())
        {
            while (*rt - *lt > m)
            {
                l += countMap[*lt];
                advance(lt, 1);
            }
            if (maxx < r - l)
                maxx = r - l;
            advance(rt, 1);
            r += countMap[*rt];
        }

        if (Answer < maxx)
            Answer = maxx;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                continue;
            // vector<int> v;
            maxx = 0;
            vector<int> v_old, v_new;
            int l = max(i - k+1, 0);
            int r = min(i, n - k);
            int element1 = atoi(s.substr(l, k).c_str());
            char c = s[i];
            s[i] = '1';
            int element2 = atoi(s.substr(l, k).c_str());
            s[i] = c;
            for (int j = l; j <= r; j++)
            {
                v_old.push_back(element1);
                v_new.push_back(element2);
                element1 = (element1%po)*10 + s[j+k] - '0';
                element2 = (element2%po)*10 + s[j+k] - '0';
            }
            int size = v_old.size();
            for (auto j = v_old.begin(); j != v_old.end(); j++)
            {
                countMap[*j]--;
                if (!countMap[*j])
                    sortedSet.erase(*j);
            }
            for (auto j = v_new.begin(); j != v_new.end(); j++)
            {
                if (!countMap[*j])
                    sortedSet.insert(*j);
                countMap[*j]++;
            }

            for(auto j = v_new.begin(); j != v_new.end(); j++){
                lt = std::lower_bound(sortedSet.begin(), sortedSet.end(), *j - m);
                auto deadEnd = std::upper_bound(sortedSet.begin(), sortedSet.end(), *j + m);
                rt = lt;
                int l = 0, r = countMap[*rt];
                while(rt != deadEnd){
                    while(*rt - *lt > m){
                        l += countMap[*lt];
                        advance(lt, 1);
                    }
                    if(maxx < r - l) maxx = r - l;
                    advance(rt, 1);
                    r += countMap[*rt];
                }
            }
            if(Answer < maxx)
                Answer = maxx;
            for (auto j = v_new.begin(); j != v_new.end(); j++)
            {
                countMap[*j]--;
                if (!countMap[*j])
                    sortedSet.erase(*j), countMap.erase(*j);
            }
            for (auto j = v_old.begin(); j != v_old.end(); j++)
            {
                if (!countMap[*j])
                    sortedSet.insert(*j);
                countMap[*j]++;
            }
        }

        cout << "Case #" << test_case + 1 << endl;
        cout << Answer << endl;
    }
    return 0; // Your program should return 0 on normal termination.
}



