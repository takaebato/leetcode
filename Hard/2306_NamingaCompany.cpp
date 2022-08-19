#include <bits/stdc++.h>
using namespace std;

/*
  n<=5*10^4, s.length<=10
  答えとしてあり得るで絞り込む考え方に近い
  suffixはn通りあり得るが、prefixはアルファベットの25種しかない。
  普通に考えるとsuffixでグルーピングしてしまうが、これだとsuffix分の2重ループを回さなければならない。
  prefixでグルーピングすると、prefixの2重ループで済む。suffix分は集合演算で高速化出来る。

  数が少ない方でループを回して、数が多い方はデータ構造や計算を上手く使って高速化するという考え方は汎用性高いと思う。
*/
class Solution {
   public:
    long long distinctNames(vector<string>& ideas) {}
};
