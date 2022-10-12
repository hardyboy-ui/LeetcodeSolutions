class Solution {
public:
    int findTotalXor(int n)
    {
        int answer=0;
        for(int i=1;i<=n;i++)
        {
            answer=answer^i;
        }
        return answer;
    }
    vector<int> decode(vector<int>& encoded) 
    {
        int n=encoded.size();
        int totalXor=findTotalXor(n+1);
        int val=0;
        for(int index=0;index<n;index+=2)
        {
            val=val^encoded[index];
        }
        vector<int> answer(n+1);
        answer[n]=totalXor^val;
        for(int index=n-1;index>=0;index--)
        {
            answer[index]=answer[index+1]^encoded[index];
        }
        return answer;
    }
};