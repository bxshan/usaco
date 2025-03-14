#include <iostream>
#include <unordered_set>
#include <utility>  // For std::pair

using namespace std;

int main() {
  string s1 = "pizzzahut";
  string s2 = "papajohns";

  unordered_set<pair<char, char>, std::hash<int>> swaps;

  // Compare the two strings and track the swaps
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] != s2[i]) {
      // Add the swap as a pair (smallest, largest) to avoid duplication
      char first = min(s1[i], s2[i]);
      char second = max(s1[i], s2[i]);
      swaps.insert({first, second});
    }
  }

  // The number of unique swaps needed is the size of the set
  cout << "Minimum number of magical paints: " << swaps.size() << endl;

  return 0;
}

