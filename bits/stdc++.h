#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
auto &operator<<(ostream &os, const pair<A, B> &p) { 
  return os << "(" << p.first << ", " << p.second << ")"; 
}
template <typename T_container,
          typename T = typename std::enable_if<
              !std::is_same<T_container, std::string>::value,
              typename T_container::value_type>::type>
auto &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v)
    os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T> void debug_out(const std::string &s, T t) {
  cout << "[" << s << ": " << t << "]\n";
}
template <typename T, typename... U>
void debug_out(const std::string &s, T t, U... u) {
  size_t w = 0;
  size_t c = 0;
  while (w < s.size()) {
    if (s[w] == '(') {
      c++;
    }
    if (s[w] == ')') {
      c--;
    }
    if (!c and s[w] == ',') {
      break;
    }
    w++;
  }
  cout << "[" << s.substr(0, w) << ": " << t << "] ";
  debug_out(s.substr(w + 2, s.size() - w - 1), u...);
}
#define dbg(x...) debug_out(#x, x)
