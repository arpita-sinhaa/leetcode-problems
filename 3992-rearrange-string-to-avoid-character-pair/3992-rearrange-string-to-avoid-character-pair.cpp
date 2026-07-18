class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string X="";
        string Y="";
        string rest="";

        for(int i=0; i<s.size(); i++){
            if(s[i]==y) Y+=s[i];
            else if(s[i]==x) X+=s[i];
            else rest+=s[i];
        }
        return Y+X+rest;
    }
};