//
//  print.hpp
//  ATC
//
//  Created by yuki on 2022/04/17.
//

#ifndef print_h
#define print_h

#define debug(...) print(#__VA_ARGS__, "=", __VA_ARGS__)

#include <bits/stdc++.h>
using namespace std;

template<class T> auto desc(vector<T> v);
template<class T, class U> auto desc(pair<T, U> v);
template<class T, class C> auto desc(multiset<T, C> v);
template<class T> auto desc(unordered_set<T> v);
template<class T> auto desc(set<T> v);

template<class T> auto desc(T v) {
    cout << v;
}
template<class T, class U> auto desc(pair<T, U> v) {
    cout << "("; desc(v.first); cout << ", "; desc(v.second); cout << ")";
}
template<class T> auto desc(vector<T> v) {
    auto f = true; cout << "{ ";
    for(auto t: v) { if (f) f = 0; else cout << ", "; desc(t); } cout << " }";
}
template<class K, class V> auto desc(map<K, V> v) {
    auto f = true; cout << "{ ";
    for(auto t: v) { if (f) f = 0; else cout << ", "; desc(t.first); cout << ": "; desc(t.second); } cout << " }";
}
template<class T> auto desc(vector<vector<T>> v) {
    cout << "{" << endl; for(auto t: v) { cout << "\t"; desc(t); cout << endl; } cout << "}";
}
template<class K, class V> auto desc(unordered_map<K, V> v) {
    desc(map(v.begin(), v.end()));
}
template<class T> auto desc(unordered_set<T> v) {
    desc(vector(v.begin(), v.end()));
}
template<class T> auto desc(set<T> v) {
    desc(vector(v.begin(), v.end()));
}
template<class T> auto desc(unordered_multiset<T> v) {
    desc(vector(v.begin(), v.end()));
}
template<class T, class C> auto desc(multiset<T, C> v) {
    desc(vector(v.begin(), v.end()));
}
template<class T> auto desc(queue<T> v) {
    vector<T> vec; while(v.size()) { vec.push_back(v.front()); v.pop(); }
    desc(vec);
}
auto desc(vector<string> v) {
    for(auto &t: v) { desc(t); cout << endl; }
}

template<class T> auto print(T v) { desc(v); cout << endl; }

template<class Head, class... Tail> auto print(Head head, Tail... tail) {
    desc(head); cout << " "; print(tail...);
}

#endif /* print_h */
