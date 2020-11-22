#include<bits/stdc++.h>
using namespace std;

typedef pair<string, int> P;

struct CustomOrder {
    bool operator()(P const &a, P const &b) const {
        return a.second < b.second;
    }
};

class Solution {
    priority_queue<P, vector<P>, CustomOrder> heap;
    unordered_map<string, int> freqMap;
    unordered_set<string> banSet;
    
    void tokenize(string p){
        string token = "";
        for(char &c : p) {
            if(isalpha(c)) {
                token += tolower(c);
            }
            else if(token != ""){
                if(freqMap.count(token) == 0)
                    freqMap[token] = 1;
                else
                    freqMap[token]++;
                token = "";
            }
        }
        if(token != "")
            if(freqMap.count(token) == 0)
                freqMap[token] = 1;
            else
                freqMap[token]++;
                
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        tokenize(paragraph);
        for(string &w : banned)
            banSet.insert(w);
        
        for(auto &p : freqMap)
            heap.push(p);
        string ans = "";
        do {
            ans = heap.top().first;
            heap.pop();
            
        }while(banSet.count(ans) != 0);
        
        return ans;
    }
};
