bool compare(pair<int,int>& p1,pair<int,int>& p2)
{
    return p1.first<p2.first;
}
class MyCalendarTwo {
public:
    vector<pair<int,int>> intervals;
    MyCalendarTwo() {
        
    }
    bool isOverlapping(vector<pair<int,int>>& helper)
    {
        int n=helper.size();
        if(n<2)
            return false;
        sort(helper.begin(),helper.end(),compare);
        int start=helper[0].first,end=helper[0].second;
        for(int index=1;index<n;index++)
        {
            int s=helper[index].first,e=helper[index].second;
            if(s>=end||e<=start)
            {
                start=s;end=e;
            }
            else
                return true;
        }
        return false;
    }
    bool book(int start, int end) {
        vector<pair<int,int>> helper;
        for(auto interval:intervals)
        {
            int s=interval.first,e=interval.second;
            if(start>=e||end<=s)
                continue;
            else
                helper.push_back({s,e});
        }
        if(isOverlapping(helper))
            return false;
        intervals.push_back({start,end});
        return true;
    }
};