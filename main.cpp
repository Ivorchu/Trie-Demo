#include <iostream>
#include <string.h>
using namespace std;

const int MAXn = 2e5 + 5;

int nxt[MAXn][26], idx[MAXn], nodeCnt, wordcnt;

int newNode() {
    ++nodeCnt;
    for (int i = 0; i < 26; i++)
        nxt[nodeCnt][i] = 0;
    return nodeCnt;
}

void insert(int root, string &s) {
    int cur = root;
    for (int i = 0; i < (int)s.size(); i++) {
        int nxtIdx = s[i] - 'a'; // 字元的ascii碼 - 第一個ascii碼(a) = 第幾個英文字母
        if (i == s.size()-1) {
            if (!nxt[cur][nxtIdx]) {
                nxt[cur][nxtIdx] = newNode(); // 若結點不存在 創新節點
                idx[cur] = wordcnt;
                cout << "New! " << idx[cur] << "\n";
                wordcnt++;
            } else {
                cout << "Old! " << idx[cur] << "\n";
            }
        }
        if (!nxt[cur][nxtIdx])
                    nxt[cur][nxtIdx] = newNode(); // 若結點不存在 創新節點
        cur = nxt[cur][nxtIdx];
    }
}

int main() {
    ios_base::sync_with_stdio(0); // cin的後續處理比scanf慢 所以把cin當scanf用 兩個function再輸入時會先讀取一大段資料進buffer 再切割一段一段給程式 這樣就要把兩個function的buffer同時混用
    cin.tie(0); // 預設再輸入時把輸出清空
    int n;
    while (cin >> n) {
        nodeCnt = 0;
        wordcnt = 1;
        int root = newNode();
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            insert(root, s);
        }
    }
    return 0;
}
