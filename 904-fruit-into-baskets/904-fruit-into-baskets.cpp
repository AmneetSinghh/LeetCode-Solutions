class Solution {
  public:
    int totalFruit(vector < int > & fruits) {
      int n = fruits.size();
      int ans = 0;
      int slidingPointer = 0, slidingStart = 0;
      unordered_map < int, int > st;
      while (slidingPointer < n) {
        ++st[fruits[slidingPointer]];
        while (st.size() > 2) {
          --st[fruits[slidingStart]];
          if (st[fruits[slidingStart]] == 0) st.erase(fruits[slidingStart]);
          ++slidingStart;
        }
         ans = max(ans, (slidingPointer - slidingStart + 1));
        ++slidingPointer;
      }
      return ans;
    }
};