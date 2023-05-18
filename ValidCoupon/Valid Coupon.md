A coupon is a string of characters from a-z. An empty string is considered valid. 
For a particular string to be considered valid, following conditions must be met:
  1. the string is of the form XAX where A is a valid coupon and X is any character from a-z.
                    OR
  2. the string is of the form AB where A and B are valif coupon.
  
Input Format :
The first line will contain an integer n denoting the number of queries. The following n lines will contain n strings to be checked for validity.

Output Format :
The output will be given in the form of n different lines displaying the validity of n input strings. If the string is a valid coupon print 1, else print 0.

Constraints :
0 < |s| < 20, where |s| denote the length of string s.
0 < n < 100 where n is the number of queries.

Example :
```
Input 1
2
aa
abaaba 

output 1
1
1
```
```
Input 2
2
abcabc
adaadbba

Output 2
0
1
```

Note: The solution is a very straighforward naive solution which can be categorised under Greedy algorithms. Hence it may not be the best Optimal solution.
