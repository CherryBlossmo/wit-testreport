#include <iostream>
#include <string>

using namespace std;

template <class T>
class mqueue {
public:
	mqueue(int size = 100): 
		size(size),
		front(0), rear(0)
	{
		data = new T[this->size];
	}

	void add(const T& a) {
		data[rear] = a;
		rear = (rear + 1) % size;
		if (rear == front) {
			cout << "queue is full" << endl;
			return;
		}
	}

	const T pop() {
		if (front == rear) {
			cout << "queue is empty" << endl;
			return T(0);
		}
		int pos = front;
		front = (front + 1) % size;
		return data[pos];
	}

	const T peekFront() {
		if (isEmpty()) return T(0);
		return data[front];
	}

	const T peekRear() {
		if (isEmpty()) return T(0);
		int index = rear - 1;
		if (index == -1) {
			index = size - 1;
		}
		return data[index];
	}

	bool isEmpty() {
		return front == rear;
	}

	void print() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		} 
		int i = front;
		while (i != rear) {
			cout << data[i] << " | ";
			i = (i + 1) % size;
		}
		cout << endl;
	}

	~mqueue() {
		delete[] data;
	}
private:
	T* data;
	// 尾部头部指针
	int front;
	int rear;
	int size;
};

void solve(string row) {
	string out;
	mqueue<int> buffer[4];
	int newOut = 1;

	for (int i = 0; i < row.length(); ++i) {
		buffer[0].add(row[i] - '0');
	}
	
	while (out.length() < row.length()) {
		int tmp = 0;
		bool isFail = true;
		for (int i = 0; i < 4; ++i) {
			if (buffer[i].isEmpty()) continue;
			tmp = buffer[i].peekFront();
			if (tmp == newOut) {
				out.push_back(tmp + '0');
				buffer[i].pop();
				cout << "buffer " << i <<" match "  << tmp << endl;
				break;
			}
		}
		if (tmp == newOut) {
			newOut++;
			continue;
		} else {
			tmp = buffer[0].pop();

			for (int i = 1; i < 4; ++i) {
				int y = 0;
				if (! buffer[i].isEmpty()) {
					y = buffer[i].peekRear();
				} else {
					y = 0;
				}
				if (tmp > y) {
					buffer[i].add(tmp);
					cout << "buffer " << i << " add "<< tmp << endl;
					isFail = false;
					break;
				} else {
					
				}
			}
		}

		if (isFail) {
			cout << "failed!" << endl;
			break;
		}
		cout << endl << "=====buffer:====" << endl;
		buffer[0].print();
		buffer[1].print();
		buffer[2].print();
		buffer[3].print();
		cout << "================" << endl;
	}
	cout << "out: " <<out << endl;
}

int main() {
	solve("581742963");
	return 0;
}