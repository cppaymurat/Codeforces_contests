#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for(int test = 1; test <= t; test += 1) {
    int n, m;
    cin >> n >> m;
    vector<int> k(n);
    for(int i = 0; i < n; i += 1) {
      cin >> k[i];
      k[i] -= 1;
    }
    sort(k.begin(), k.end());
    reverse(k.begin(), k.end());
    vector<int> c(m);
    for(int i = 0; i < m; i += 1) {
      cin >> c[i];
    }
    int cheapest_id = 0;
    long long result = 0;
    for(int friend_id = 0; friend_id < n; friend_id += 1) {
      int first_variant = c[k[friend_id]];
      if (cheapest_id >= m) {
        result += first_variant;
      } else {
        int second_variant = c[cheapest_id];
        if (first_variant >= second_variant) {
          result += second_variant;
          cheapest_id += 1;
        } else {
          result += first_variant;
        }
      }
    }
    cout << result << endl;
  }
  return 0;
}
