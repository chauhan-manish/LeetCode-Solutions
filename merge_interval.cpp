/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<pair<int,int> >vp;
        int i,j,n=in.size(),z;
        for(i=0;i<n;i++)
        {
            vp.push_back({in[i][0],in[i][1]});
        }
        sort(vp.begin(),vp.end());
       vector<vector<int>> vv;
        for(i=0;i<n;i++)
        {
            j=1;
            z=vp[i].second;
            while(i+j<n&&z>=vp[i+j].first)
            {
                z=max(z,vp[i+j].second);
                j++;
            }
            vector<int> v;
            v.push_back(vp[i].first);
            v.push_back(z);
            vv.push_back(v);
            i+=(j-1);
        }
        return vv;
    }
};
