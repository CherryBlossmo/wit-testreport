#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXSIZE = 100;

struct Triple {
    int i, j;
    int e;
};

struct TSMat {
    Triple data[MAXSIZE + 1];

    /// 矩阵的行数、列数和非零元个数
    int mu, nu, tu;
};

void printMat(TSMat& m) {
    cout << "i:" << m.mu <<
    " j:" << m.nu << " num:" << m.tu
    << endl;


    for (int i = 1; i <= m.mu; i++) {
        for (int j = 1; j <= m.nu; j++) {
            bool has = false;
            for (int k = 0; k < m.tu; ++k) {
                if (m.data[k].i == i && m.data[k].j == j) {
                    cout << m.data[k].e;
                    has = true;
                }
            }
            if (! has) {
                cout << '0';
            }
        }
        cout << endl;
    }
}

TSMat& transpose(TSMat& mat, TSMat& out) {
    out.mu = mat.nu;
    out.nu = mat.mu;
    out.tu = mat.tu;

    if (out.tu) {
        int q = 0;
        for (int col = 1; col <= mat.mu; col++) {
            for (int p = 0; p <= mat.tu; p++) {
                if (mat.data[p].j == col) {
                    out.data[q].i = mat.data[p].j;
                    out.data[q].j = mat.data[p].i;
                    out.data[q].e = mat.data[p].e;
                    ++q;
                }
            }
        }
    }

    return out;
}

TSMat& fastTranspose(TSMat& mat, TSMat& out) {
    out.mu = mat.nu;
    out.nu = mat.mu;
    out.tu = mat.tu;

    if (out.tu) {
        int* num = new int[out.tu];
        int* cpot = new int[out.tu + 1];
        /// 初始化num数组
        memset(num, 0, sizeof(int) * out.tu);
        for (int t = 0; t < out.tu; t++) {
            int j = mat.data[t].j;
            num[j]++;
        }

        cpot[1] = 1;
        for (int col = 2; col <= mat.mu; col++) {
            cpot[col] = cpot[col - 1] + num[col - 1];
        }

        /// 存放
        for (int p = 0; p < mat.tu; p++) {
            int col = mat.data[p].j;
            int q = cpot[col];

            out.data[q - 1].i = mat.data[p].j;
            out.data[q - 1].j = mat.data[p].i;
            out.data[q - 1].e = mat.data[p].e;

            ++cpot[col];
        }


        delete[] num;
        delete[] cpot;
    }

    return out;
}

int main() {
    TSMat M;
    M.mu=3;
    M.nu=3 ;
    M.tu=4;

    M.data[0].i=1;
    M.data[0].j=2;
    M.data[0].e=1;

    M.data[1].i=2;
    M.data[1].j=2;
    M.data[1].e=3;

    M.data[2].i=3;
    M.data[2].j=1;
    M.data[2].e=6;

    M.data[3].i=3;
    M.data[3].j=2;
    M.data[3].e=5;

    cout << "matrix before:" << endl;
    printMat(M);

    cout << "trans" << endl;
    TSMat t1;
    transpose(M, t1);
    printMat(t1);


    cout << "ftrans" << endl;
    TSMat t2;
    fastTranspose(M, t2);
    printMat(t2);

    return 0;
}

/*

matrix before:
i:3 j:3 num:4
010
030
650
trans
i:3 j:3 num:4
006
135
000
ftrans
i:3 j:3 num:4
006
135
000

*/
