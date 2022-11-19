#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>


vector<string> strs;

void Add_test(string str) {
	strs.push_back(str);
}

void Run_test() {


    if (strs.size() <= 0) {
        cout << "ERROR::No_tests";
        return;
    }
    for (int i = 0; i < strs.size(); i++) {
        cout << strs[i] << endl;
        auto start = chrono::high_resolution_clock::now();
        Build_suffix_tree(strs[i]);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;
        cout << duration.count() << endl;

        auto start2 = chrono::high_resolution_clock::now();
        SuffixTree tree = SuffixTree(strs[i]);
        auto end2 = chrono::high_resolution_clock::now();
        chrono::duration<float> duration2 = end2 - start2;
        cout << duration2.count() << endl << endl;
    }
}