class Solution {
public:
    int minFlips(int a, int b, int c) {
        int answer=0;
        int maxi=max({a,b,c});
        while(maxi!=0)
        {
            if(c&1)
            {
                if(!((a&1)||(b&1)))
                {
                    // cout<<"HEY"<<endl;
                    answer++;
                }
            }
            else
            {
                if((a&1)&&(b&1))
                {
                    answer+=2;
                }
                else if((a&1)||(b&1)){
                    answer+=1;
                }
            }
            c=c>>1;
            a=a>>1;
            b=b>>1;
            maxi=maxi>>1;
        }
        return answer;
    }
};

