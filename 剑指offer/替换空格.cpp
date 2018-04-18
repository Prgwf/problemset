#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
		if (str == nullptr or length <= 0) {
			return;
		}

		int cnt = 0, iRaw = 0;
		char *p = str;
		while (*p != '\0') {
			++iRaw;
			if (*p == ' ') {
				cnt++;
			}
			p++;
		}

		int iNew = iRaw + 2 * cnt;
		if (iNew > length) {
			return;
		}

		while (iRaw >= 0 && iNew > iRaw) {
			if (str[iRaw] == ' ') {
				str[iNew--] = '0';
				str[iNew--] = '2';
				str[iNew--] = '%';
			} else {
				str[iNew--] = str[iRaw];
			}
			--iRaw;
		}
	}
};

int main() {
	char *str = new char[50];
	for (int i = 0; i < 5; ++i) {
		if (i & 1) *(str + i) = ' ';
		else *(str + i) = 'a';
	}
	Solution().replaceSpace(str, 50);
	delete str;
}
