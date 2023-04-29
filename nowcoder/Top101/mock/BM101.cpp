
#include <list>
#include <set>
#include <unordered_map>
#include <vector>
class Solution {
public:
    /**
     * lfu design
     * @param operators int整型vector<vector<>> ops
     * @param k int整型 the k
     * @return int整型vector
     */
    // 以频率作为key，存储一系列的数据
    unordered_map<int, list<vector<int>>> freq_mp;
    // key到节点的映射
    unordered_map<int, list<vector<int>>::iterator> mp;
    int min_freq = 0;
    int size = 0;

    vector<int> LFU(vector<vector<int> >& operators, int k) {
        // write code here
        vector<int> res;
        size = k;
        for (int i=0; i<operators.size(); i++) {
            auto op = operators[i];
            if (op[0]==1) {
                set(op[1],op[2]);
            }else{
                res.push_back(get(op[1]));
            }
        }
        return res;
    }

    void set(int key,int value){
        auto it = mp.find(key);
        if (it!=mp.end()) {
            update(it->second, key, value);
        }else{
            if (size==0) {
                // 如果已满，则取频率最低且最早的删掉
                int oldkey = freq_mp[min_freq].back()[1];
                freq_mp[min_freq].pop_back();
                if (freq_mp[min_freq].empty()) {
                    freq_mp.erase(min_freq);
                }
                mp.erase(oldkey);
            }else{
                size--;
            }
            min_freq = 1;
            freq_mp[1].push_front({1,key,value});
            mp[key] = freq_mp[1].begin();
        }
    }

    int get(int key){
        int res = -1;
        auto it = mp.find(key);
        if(it!=mp.end()){
            auto iter = it->second;
            res = (*iter)[2];
            update(iter, key, res);
        }
        return res;
    }

    void update(list<vector<int>>::iterator iter, int key,int value) {
        // 得到原来的频率是多少
        int freq = (*iter)[0];
        freq_mp[freq].erase(iter);
        if(freq_mp[freq].empty()){
            freq_mp.erase(freq);
            //若当前频率为最小，最小频率加1
            if(min_freq == freq)
                min_freq++;
        }
        freq_mp[freq+1].push_front({freq+1,key,value});
        mp[key] = freq_mp[freq+1].begin();
    }
};