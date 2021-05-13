#include <iostream>
#include <vector>
#include <algorithm>
#define ENDL '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

template<typename T>
class Heap {
public:
	Heap<T>() {
		end = 1;
		tree.resize(1);
	}

	virtual void push(T value) = 0;
	virtual void pop() = 0;

	T top() {
		return tree[1];
	}

	bool empty() {
		return end == 1;
	}

	ull size() {
		return end;
	}

	void printAll(ostream& out) {
		vector<T> tempTree = tree;
		int tempEnd = end;

		while (!empty()) {
			out << top() << ' ';
			pop();
		}
		out << ENDL;

		end = tempEnd;
		for (int i = 1; i < end; i++) {
			tree[i] = tempTree[i];
		}
	}

protected:
	vector<T> tree;
	ull end;
};

template<typename T>
class MinHeap : public Heap<T> {
public:
	virtual void push(T value) {
		if (this->end == this->tree.size()) {
			this->tree.resize(this->tree.size() * 2);
		}
		this->tree[this->end++] = value;

		for (ull child = this->end - 1; child >= 1; child /= 2) {
			ull parent = child / 2;
			if (parent >= 1 && this->tree[parent] > this->tree[child]) {
				swap(this->tree[parent], this->tree[child]);
			}
			else {
				break;
			}
		}
	}

	virtual void pop() {
		this->tree[1] = this->tree[this->end - 1];
		this->end--;

		for (ull parent = 1; parent * 2 < this->end; ) {
			ull smallerChild;
			if (parent * 2 + 1 < this->end) {
				smallerChild = parent * 2 + (this->tree[parent * 2] < this->tree[parent * 2 + 1] ? 0 : 1);
			}
			else {
				smallerChild = parent * 2;
			}

			if (this->tree[smallerChild] < this->tree[parent]) {
				swap(this->tree[parent], this->tree[smallerChild]);
				parent = smallerChild;
			}
			else {
				break;
			}
		}
	}
};
