class Solution {
 public:
  int minimumTimeToInitialState(string word, int k) {
    const int n = word.length();
    const int maxOps = (n - 1) / k + 1;
    const vector<int> z = zFunction(word);
    for (int ans = 1; ans < maxOps; ++ans)
      if (z[ans * k] >= n - ans * k)
        return ans;
    return maxOps;
  }

  vector<int> zFunction(const string& s) {
    const int n = s.length();
    vector<int> z(n);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
      if (i < r)
        z[i] = min(r - i, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }
    return z;
  }
};
