#include "../common/debugger.h"

class Solution {
public:
    string C(string oo) {
        if(oo =="&quot;")
            return "\"";
        if(oo=="&apos;")
            return "'";
        if(oo=="&amp;")
            return "&";
        if(oo=="&gt;")
            return ">";
        if(oo=="&lt;")
            return "<";
        if(oo=="&frasl;")
            return "\\";
        return oo;
    }
    
    string entityParser(string text) {
        string ret;
        for(int i=0; i<text.size(); ++i) {
            if(text[i] == '&') {
                int j(i+1);
                while(j<i+7 && j<text.size() && text[j] != ';') ++j;
                if(j<i+7 && text[j] == ';') {
                    ret += C(text.substr(i,1+j-i));
                    i=j;
                } else {
                    ret += text[i];
                }
            } else {
                ret += text[i];
            }
        }
        return ret;
        
    }
};

int main() {
    Solution sol;
    cout << sol.entityParser("&amp; is an HTML entity but &ambassador; is not.") << endl;
    cout << sol.entityParser("&frasl;& is an HTML entity but &ambassador; is not.") << endl;
    cout << sol.entityParser("&frasl;&; is an HTML entity but &ambassador; is not.") << endl;
}
