class Solution {
public:
    bool isValidSerialization(string preorder) {
        int capacity = 1; // for root node

		auto i = preorder.begin();
		while (i!=preorder.end()) {
			auto j = i+1;
			while (j!=preorder.end() && *j != ',') {
				j++;
			}
			if (*i != '#') {
				capacity ++;
			} else {
				capacity --;
			}

			if (j == preorder.end()) break;

			if (capacity <= 0) return false; // if has no space, can not continue

			i = j+1;
		}

		return capacity == 0;
    }
};
