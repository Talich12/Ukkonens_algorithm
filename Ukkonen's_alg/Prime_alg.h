#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>



struct Vertex {
    int l, r, ind;

    Vertex(int l, int r, int ind) {
        this->ind = ind;
        this->l = l;
        this->r = r;
    }

    Vertex() {
        this->ind = -1;
        this->l = -1;
        this->r = -1;
    }
};

Vertex Zero = Vertex(-1, -1, -1);
map<char, Vertex> Zero_map;

void Create_vertex(vector<map<char, Vertex>>& go, string str, int Current_ver, int l, int r, int& count) {
    go.push_back(Zero_map);
    count++;
    go[Current_ver][str[l]].ind = count;
    go[Current_ver][str[l]].l = l;
    go[Current_ver][str[l]].r = r;
}

void Insert(int l, int r, vector<map<char, Vertex>>& go, string str, int& count) {
    int Current_ver = 0;
    while (l < r) {
        if (go[Current_ver][str[l]].ind == -1) {
            Create_vertex(go, str, Current_ver, l, r, count);
        }
        else {
            int start = go[Current_ver][str[l]].l;
            int finish = go[Current_ver][str[l]].r;
            bool hasCut = false;
            for (int j = start; j < finish; j++) {
                if (l + j - start < str.length()) {
                    if (str[l + j - start] != str[j]) {
                        go[Current_ver][str[l]].r = j - 1;
                        Current_ver = go[Current_ver][str[l]].ind;

                        Create_vertex(go, str, Current_ver, j, r, count);
                        Create_vertex(go, str, Current_ver, l + j - start, r, count);
                        hasCut = true;
                        break;
                    }
                }
            }
            if (!hasCut) {
                Current_ver = go[Current_ver][str[l]].ind;
                l = l + finish - start;
            }
            else {
                break;
            }
        }
    }
}

void Build_suffix_tree(string str) {
    int count = 0;
    vector<map<char, Vertex>> go;
    go.push_back(Zero_map);

    for (int i = 0; i < str.length(); i++) {
        Insert(i, str.length(), go, str, count);
    }
}