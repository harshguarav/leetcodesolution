class Solution {
public:
    string sortVowels(string s) {
        string t="";
        string vowel="";
        string con="";

        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
            s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') vowel+=s[i];
            else con+=s[i];

        }
        sort(vowel.begin(),vowel.end());
        int l=0;
        int r=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
            s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
                 t+=vowel[l];
                 l++;
            }
            else{
                t+=con[r];
                r++;
            }

        }
        return t;
        
    }
};