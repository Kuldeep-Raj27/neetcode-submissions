class Solution {
public:
    bool isAnagram(string s, string t) {
        
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

// no need of this. as exact same char should be there inn anagram.
    // // removng duplicate by moving duplicates to end and then erase them..
    // auto new_end1 = unique(s.begin(), s.end());
    // auto new_end2 = unique(t.begin(), t.end());

    // // 3. Erase the remaining duplicate tail
    // s.erase(new_end1, s.end());
    // t.erase(new_end2, t.end());

    if(s==t){
        return true;
    }
    else{
        return false;
    }
    }
};
