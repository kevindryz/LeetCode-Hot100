class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
//    	也可以用unordered_map做hash容器，用count判断是否存在，insert插入
        unordered_map<int,int> hash;
        for (int & it : nums) hash[it]=1;
        int len=1,now,cnt;
        if (nums.size() == 0) len=0;
        for (int & it : nums)
        {
            now=it;
            cnt=1;
            if (hash[now-1]) continue;
            while (hash[now+1])
            {
                now++;
                cnt++;
            }
            len=max(len,cnt);
        }
        return len;
    }
};