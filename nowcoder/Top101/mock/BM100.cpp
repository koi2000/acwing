//
// Created by DELL on 2023/4/29.
//
#include <list>
#include <unordered_map>

class Solution {
public:
    int capacity;
    unordered_map<int, int> k2v;
    unordered_map<int, int> k2idx;
    list<int> lru;
    int idx = 0;

    Solution(int capacity) {
        // write code here
        this->capacity = capacity;
    }

    int get(int key) {
        // write code here
        if (k2v.count(key)) {
            int id = k2idx[key];
            lru.remove(key);
            lru.push_back(key);
            k2idx[key] = lru.size() - 1;
            return k2v[key];
        } else {
            return -1;
        }
    }

    void set(int key, int value) {
        // write code here
        if (k2v.size() == capacity) {
            int k = *lru.begin();
            lru.pop_front();
            k2idx.erase(k);
            k2v.erase(k);
        }
        if (k2idx.count(key)) {
            int id = k2idx[key];
            lru.remove(key);
            lru.push_back(key);
            k2idx[key] = lru.size() - 1;
        } else {
            lru.push_back(key);
            k2idx[key] = lru.size() - 1;
        }
        k2v[key] = value;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */

#include <unordered_map>

struct Node {
    int key;
    int val;
    Node *pre;
    Node *next;

    Node(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr) {};
};

class Solution {
public:
    int size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
    unordered_map<int, Node *> mp;


    Solution(int capacity) {
        // write code here
        this->size = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
    }

    //获取数据函数
    int get(int key) {
        //找不到返回-1
        int res = -1;
        //哈希表中找到
        if (mp.find(key) != mp.end()) {
            //获取
            res = mp[key]->val;
            //访问过后移到表头
            moveToHead(mp[key]);
        }
        return res;
    }

    void set(int key, int val) {
        //没有见过这个key，新值加入
        if (mp.find(key) == mp.end()) {
            Node *node = new Node(key, val);
            mp[key] = node;
            //超出大小，移除最后一个
            if (size <= 0)
                removeLast();
                //大小还有剩余
            else
                //大小减1
                size--;
            //加到链表头
            insertFirst(node);
        }
            //哈希表中已经有了，即链表里也已经有了
        else {
            mp[key]->val = val;
            //访问过后，移到表头
            moveToHead(mp[key]);
        }
    }

    //移到表头函数
    void moveToHead(Node *node) {
        //已经到了表头
        if (node->pre == head)
            return;
        //将节点断开，取出来
        node->pre->next = node->next;
        node->next->pre = node->pre;
        //插入第一个前面
        insertFirst(node);
    }

    //将节点插入表头函数
    void insertFirst(Node *node) {
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    //删去表尾函数，最近最少使用
    void removeLast() {
        //哈希表去掉key
        mp.erase(tail->pre->key);
        //断连该节点
        tail->pre->pre->next = tail;
        tail->pre = tail->pre->pre;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */
