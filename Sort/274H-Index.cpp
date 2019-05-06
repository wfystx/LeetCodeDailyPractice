/**
 Solution:
 Bucket Sort. So assume n is the total number of papers, if we have n+1 buckets, number from 0 to n, then for any paper with reference corresponding to the index of the bucket, we increment the count for that bucket. The only exception is that for any paper with larger number of reference than n, we put in the n-th bucket.
 Then we iterate from the back to the front of the buckets, whenever the total count exceeds the index of the bucket, meaning that we have the index number of papers that have reference greater than or equal to the index. Which will be our h-index result. The reason to scan from the end of the array is that we are looking for the greatest h-index.
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int n = citations.size();
        vector<int> bucket(n+1,0);
        for(auto c:citations){
            if(c>=n) bucket[n]++;
            else bucket[c]++;
        }
        int count = 0;
        for(int i=n; i>=0; i--){
            count += bucket[i];
            if(count>=i) return i;
        }
        return 0;
    }
};