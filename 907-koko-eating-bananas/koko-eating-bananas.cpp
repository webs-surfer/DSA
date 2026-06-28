class Solution {
public:
    long long totalHours(vector<int>& piles, int mid){
        long long int total =0;
        for(int i=0; i<piles.size(); i++){
            total+=(piles[i]+mid-1)/mid;
        }       
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1, e=*max_element(piles.begin(),piles.end()),mid;
        long long int total; 
        int ans=INT_MAX;
        while(s<=e){
            mid=s+(e-s)/2;
            total=totalHours(piles,mid);
            if(total<=h){
                ans=min(mid,ans);
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;

    }
};