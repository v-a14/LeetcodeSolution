class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int count = 0;
        int students = 1;
        int n = grades.size();
        while(n>0){
            count++;
            n -= students++;
        }
        if(n<0) return count-1;
        else return count;
    }
};