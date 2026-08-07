class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int l=0,r=n-1;
        int count = 0;
        while (l<=r){
            if (l==r){
                return count+1;
            }
            if (people[l]+people[r]<=limit){
                count++;
                l++;
                r--;
            }
            else{
                count++;
                r--;
            }

        }
        return count;
    }
};