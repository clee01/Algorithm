class Solution {
 public:
  bool isMatch(string s, string p) {
    if (p.empty()) {
      if (s.empty()) {
        return true;
      }
      return false;
    }

    if (p[0] == '*') {
      s = string("a") + s;
      p = string("a") + p;
    }
    if (p[p.size() - 1] == '*') {
      s += "a";
      p += "a";
    }

    std::vector<string> vs = splitPattern(p);

    return doMatch(s, vs, 0);
  }

  std::vector<string> splitPattern(const std::string& p) {
    std::vector<string> res;
    for (int i = 0; i < p.size(); ++i) {
      std::string out;
      while (p[i] != '*' && i < p.size()) {
        out += p[i++];
      }
      if (!out.empty()) {
        res.emplace_back(out);
      }
    }
    return res;
  }

  bool doMatch(const std::string& s, const std::vector<std::string>& vs,
               int index) {
    if (index >= vs.size()) {
      if (s.empty()) {
        return true;
      }
      return false;
    }
    if (!index) {
      if (isNotMatch(s.substr(0, vs[0].size()), vs[0])) {
        return false;
      }
      return doMatch(s.substr(vs[0].size()), vs, 1);
    }

    if (index == vs.size() - 1) {
      if (isNotMatch1(s, vs[index])) {
        return false;
      }
      return true;
    }

    int find_index = Find(s, vs[index]);
    if (find_index >= 0) {
      return doMatch(s.substr(find_index + vs[index].size()), vs, index + 1);
    }
    return false;
  }

  int Find(const std::string& left, const std::string& right) {
    if (left.size() < right.size()) {
      return -1;
    }

    for (int i = 0; i <= left.size() - right.size(); ++i) {
      if (isDoMatch(left, right, i)) {
        return i;
      }
    }
    return -1;
  }

  bool isDoMatch(const std::string& left, const std::string& right, int pos) {
    for (int i = 0; i < right.size(); ++i) {
      if (right[i] != '?' && left[i + pos] != right[i]) {
        return false;
      }
    }
    return true;
  }

  bool isNotMatch(const std::string& left, const std::string& right) {
    if (left.size() != right.size()) {
      return true;
    }
    for (int i = 0; i < left.size(); ++i) {
      if (right[i] != '?' && left[i] != right[i]) {
        return true;
      }
    }
    return false;
  }

  bool isNotMatch1(const std::string& left, const std::string& right) {
    if (left.size() < right.size()) {
      return true;
    }

    int gap = left.size() - right.size();

    for (int i = right.size() - 1; i >= 0; --i) {
      if (right[i] != '?' && left[i + gap] != right[i]) {
        return true;
      }
    }
    return false;
  }
};