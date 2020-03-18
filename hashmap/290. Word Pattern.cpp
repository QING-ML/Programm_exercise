class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<string, char> word_map;
        char use[128] = {0};
        string word;
        int pos = 0;
        str.push_back(' ');
        for(int i = 0; i  < str.length(); i++){
            if(str[i] == ' '){
                //new word
                if(pos == pattern.length()){
                    return false;
                }
                if(word_map.find(word) == word_map.end()){
                    if(use[pattern[pos]] != 0){
                        return false;
                    }
                    //word_map.insert(make_pair(word, pattern[pos]));
                    word_map[word] = pattern[pos];
                    use[pattern[pos]] = 1;
                }
                else{
                    if(word_map[word] != pattern[pos]){
                        return false;
                    }
                }
                
                word = "";
                pos++;
            }
            else{
                word += str[i];
            }
        }
        if( pos != pattern.length()){
            return false;
        }
        return true;
    }
};