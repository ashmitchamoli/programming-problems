#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(m==0)
            return double (nums1[(n-1/2)] + nums1[(n/2)])/2;
        if(n==0)
            return double (nums2[(m-1/2)] + nums2[(m/2)])/2;

        if((n+m)%2) {
            int k = (n+m)/2;
            
        } 
    }
};