/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

//拓扑排序，记录路径


// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> _graph(numCourses);
        vector<int> path;
        //state:  0:未知   1：visting   2: visited
        vector<int> node_states(numCourses, 0);


        for(auto pair: prerequisites ) {
            _graph[ pair[1]].push_back(pair[0]);
        }

        for(int i = 0; i < numCourses; ++i ) {
            if( dfs(i, _graph, path, node_states) ) { //有环，代表不可能满足先修条件
                return {}; 
            } 
        }
        std::reverse(path.begin(), path.end());
        return path;

    }

    //有环: true, 代表无法修完课
    bool dfs(int class_id, vector<vector<int>>& _graph,  vector<int>& path,  vector<int>& node_states)      {
        if( node_states[class_id] == 1 ) return true;
        if( node_states[class_id] == 2 ) return false;

        node_states[class_id] = 1; //visting
        for(auto neighbor: _graph[class_id]) {
            if (dfs(neighbor, _graph, path, node_states )) {
                return true;
            }
        }
        node_states[class_id] = 2; //visited
        path.push_back( class_id );
        return false; //无环正常
    }

};


// @lc code=end

