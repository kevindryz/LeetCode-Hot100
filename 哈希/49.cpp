class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > hash;
//        记得要加&
        for (string& it : strs)
        {
            string pos=it;
            sort(pos.begin(),pos.end());
//            用emplace_back效果与push_back一样，但是push_back还需要拷贝和复制元素，emplace可以直接创建元素
            hash[pos].emplace_back(it);
        }
        vector<vector<string>> ans;
        for (auto it : hash)
        {
            ans.emplace_back(it.second);
        }
        return ans;
    }
};