#include <string>
#include <vector>
using namespace std;
using ull = unsigned long long;

class KMP {
public:
	string str, pat;
	vector<ull> table;
	vector<ull> ans;

	void getTable() {
		table.resize(pat.length());
		ull left = 0;
		for (ull i = 1; i < pat.length(); i++) {
			while (left > 0 && pat[left] != pat[i]) {
				left = table[left - 1];
			}
			if (pat[left] == pat[i]) {
				table[i] = left + 1;
				left++;
			}
		}
	}

	void getAns() {
		getTable();
		ull patIdx = 0;
		for (ull strIdx = 0; strIdx < str.length(); strIdx++) {
			while (patIdx > 0 && pat[patIdx] != str[strIdx]) {
				patIdx = table[patIdx - 1];
			}
			if (pat[patIdx] == str[strIdx]) {
				if (patIdx == pat.length() - 1) {
					ans.push_back(strIdx - pat.length() + 1);
					patIdx = table[patIdx];
				}
				else {
					patIdx++;
				}
			}
		}
	}
};
