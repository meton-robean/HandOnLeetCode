/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
//拓扑排序，只不过这里不用给出排序序列，只要判断是否满足先修情况.
//参考:https://www.bilibili.com/video/BV1Ut411a74a?from=search&seid=11929718426466640870
class Solution {
private:
    vector<vector<int>> graph_;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph_ = vector<vector<int>>(numCourses);
        //build graph
        for(auto t : prerequisites){
            graph_[t[1]].push_back( t[0] );//t[1] --> t[0]
        }
        //节点状态 0 unkown; 1 vistting; 2 visited 
        vector<int> node_status( numCourses, 0);
        for( int i = 0; i < numCourses; i++){
            if (dfs(i, node_status)) return false; //有环， 说明无法满足先修条件
        }
        return true;
    }

    bool dfs(int cur_node, vector<int> & node_status){
        if(node_status[cur_node] == 1) return true; //出现环，说明无法满足先修条件
        if(node_status[cur_node] == 2) return false; //该节点已经visied了，直接结束dfs

        node_status[cur_node] = 1; //status: visiting
        //遍历当前节点的邻居
        for(const auto neigbor: graph_[cur_node]){
            if (dfs(neigbor, node_status)) {//环
                return true;
            }
        }
        //若该节点无邻居或者所有邻居访问结束，标记为visited
        node_status[cur_node] = 2; //visited
        return false;

    }

};
// @lc code=end

