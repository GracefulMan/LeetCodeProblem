class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int nums1[26] = {0};
        int nums2[26] = {0};
        for(int i=0;i<magazine.length();i++){
            nums2[magazine[i] - 'a'] ++;
        }
        for(int i=0;i<ransomNote.length();i++){
            nums1[ransomNote[i] - 'a'] ++;
        }
        for(int i=0;i<26;i++)
            if(nums1[i]> nums2[i]) return false;
        return true;
    }
};