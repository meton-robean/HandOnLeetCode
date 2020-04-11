/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

//使用map+list的组合可以达到get查询O（1）, 并且put插入o（1）的速度.
//使用STL提供的数据结构，不用造轮子.
//参考: https://www.bilibili.com/video/BV19b411c7ue?from=search&seid=8150904456314140577
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto m_it = map_.find(key);
        if (m_it == map_.end()) {
            return -1;
        }
        //将cahce被查到的那个元素拼接移动到cache最前面
        cache_.splice(cache_.begin(), cache_, m_it->second );
        return m_it->second->second; //value
    }
    
    void put(int key, int value) {
        auto m_it = map_.find( key);
        //key存在，更新value即可，并将这个元素移动到cache_ list的最前端
        if (m_it != map_.end()){
            m_it->second->second = value;
            cache_.splice(cache_.begin(), cache_, m_it->second);
            return;
        }
        
        //若cache_满了，删除cahce_最后一个元素，记得在map_中删除对应的那个索引
        if( capacity_ == map_.size()){
            auto& c_it = cache_.back();
            map_.erase( c_it.first );
            cache_.pop_back();
        }
        //在cache_前端插入新的(key,value) pair
        cache_.push_front(make_pair(key, value));
        //记得在map_添加对应的索引.
        map_[key] = cache_.begin();
    }

private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> map_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

