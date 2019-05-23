#include <iostream>
#include <cstring>

using namespace std;

// 线性表实现
template <class T>
class SqList {
public:
    SqList(int defaultSize = 10) {
        list = new T[10];
        length = 0;
        size = 10;
    }
    void reSize(int size) {
        if (size <= length) return;
        T* tmp = new T[size];
        memcpy(tmp, list, sizeof(T) * length);
        delete list;
        this->list = tmp;
        this->size = size;
    }
    void append(const T& a) {
        if (length + 1 > size) {
            reSize(size + 10);
        }
        list[length++] = a;
    }

    // 删除第n个
    void removeLoopN(int n)
    {
        for (int i = 0; i < length; ++i) {
            cout << list[i] << endl;
        }
        int num = length;
        int i = 0, j = 1;
        while (num > 0) {
            while (j <= n) {

                if (i == length) {
                    i = 0;
                }
                
                if (list[i] == -1) {
                    ++i;
                    continue;
                }

                ++i;
                ++j;
            }

            cout << list[i] << " \n"[num == 0];
            list[i] = -1;
            j = 1;
            --num;

            //cout << "=======" << endl;
            //for (int i = 0; i < length; ++i) {
            //cout << list[i] << endl;
            //}
        }
    }

    bool isEmpty() {
        return length == 0;
    }

    ~SqList() {
        delete list;
    }
private:
    int size;
    int length;
    T* list;
};


int main() {
    SqList<int> list;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        list.append(i);
    }
    list.removeLoopN(m);
    return 0;
}