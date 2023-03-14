#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int ans, l[N][N], r[N][N], h[N][N];
char a[N][N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j], l[i][j] = r[i][j] = j, h[i][j] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= m; ++j)
      if (a[i][j] == 'F' && a[i][j - 1] == 'F') l[i][j] = l[i][j - 1];
  for (int i = 1; i <= n; ++i)
    for (int j = m - 1; j >= 1; --j)
      if (a[i][j] == 'F' && a[i][j + 1] == 'F') r[i][j] = r[i][j + 1];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (i > 1 && a[i][j] == 'F' && a[i - 1][j] == 'F') {
        l[i][j] = max(l[i][j], l[i - 1][j]);
        r[i][j] = min(r[i][j], r[i - 1][j]);
        h[i][j] = h[i - 1][j] + 1;
      }
      ans = max(ans, (r[i][j] - l[i][j] + 1) * h[i][j]);
    }
  cout << ans * 3 << endl;
  return 0;
}