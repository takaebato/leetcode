#include <bits/stdc++.h>
using namespace std;

/*
  dequeをうまく使えばO(k)でいけた
*/
class TextEditor {
    deque<char> l;
    deque<char> r;

   public:
    TextEditor() {}

    void addText(string text) {
        for (char c : text) {
            l.emplace_back(c);
        }
    }

    int deleteText(int k) {
        int cnt = 0;
        while (!l.empty() && cnt < k) {
            l.pop_back();
            cnt++;
        }
        return cnt;
    }

    string cursorLeft(int k) {
        int cnt = 0;
        while (!l.empty() && cnt < k) {
            r.emplace_front(l.back());
            l.pop_back();
            cnt++;
        }
        string s;
        auto itr = l.end();
        if (itr == l.begin()) return s;
        for (int i = 0; i < 10; i++) {
            itr--;
            s = *itr + s;
            if (itr == l.begin()) break;
        }
        return s;
    }

    string cursorRight(int k) {
        int cnt = 0;
        while (!r.empty() && cnt < k) {
            l.emplace_back(r.front());
            r.pop_front();
            cnt++;
        }
        string s;
        auto itr = l.end();
        if (itr == l.begin()) return s;
        for (int i = 0; i < 10; i++) {
            itr--;
            s = *itr + s;
            if (itr == l.begin()) break;
        }
        return s;
    }
};

/*
  愚直に配列操作した解。
  多分合ってはいるが、TLE.
  各操作でsubstrが必要で、それがおそらくO(t.length)かかるから間に合わないと思う。
*/
// class TextEditor {
//     string t;
//     int c;

//    public:
//     TextEditor() {
//         t = "";
//         c = 0;
//     }

//     void addText(string text) {
//         string tmp;
//         tmp = t.substr(0, c);
//         tmp += text;
//         tmp += t.substr(c);
//         t = tmp;
//         c += text.length();
//     }

//     int deleteText(int k) {
//         if (c < k) k = c;
//         string tmp;
//         tmp = t.substr(0, c - k);
//         tmp += t.substr(c);
//         t = tmp;
//         c -= k;
//         return k;
//     }

//     string cursorLeft(int k) {
//         if (c >= k)
//             c -= k;
//         else
//             c = 0;

//         return t.substr(max(0, c - 10), min(10, c));
//     }

//     string cursorRight(int k) {
//         if (c + k >= t.length())
//             c = t.length();
//         else
//             c += k;

//         return t.substr(max(0, c - 10), min(10, c));
//     }
// };

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
