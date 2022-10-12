class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26,0);
        stack<int> st;
        int n=s.size();
        for(auto ch:s)
            freq[ch-'a']++;
        string answer;
        vector<bool> visited(n,false);
        int index=0;
        for(int c=0;c<26;c++)
        {
            while(!st.empty()&&s[st.top()]<=(c+'a'))
            {   
                int index1=st.top();
                answer.push_back(s[index1]);
                visited[index1]=true;
                st.pop();
            }
            
            if(freq[c]!=0)
            {
                int lastIndex;
                int tempIndex=index;
                while(index<n)
                {
                    if(s[index]==c+'a')
                    {
                        answer.push_back(s[index]);
                        visited[index]=true;
                        lastIndex=index;
                    }
                    index++;
                }
                
                index=lastIndex+1;
                for(int i=tempIndex;i<=lastIndex;i++)
                {
                    if(!visited[i])
                        st.push(i);
                    freq[s[i]-'a']--;
                }
            }
        }
        while(!st.empty())
        {
            answer.push_back(s[st.top()]);
            st.pop();
        }
        return answer;
    }
};