// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left justified and no extra space is inserted between words.

// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.

// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int curLen = 0;
        int start = 0, end = 0;
        for(int i = 0; i < words.size(); ++i) {
            if(curLen + (end-start) + words[i].length() > L) {
                res.push_back(genString(words,L,curLen,start,end,false));
                start = end = i;
                curLen = 0;
                --i;
            } else {
                curLen += words[i].length();
                ++end;
            }
        }
        res.push_back(genString(words,L,curLen,start,end,true));
        return res;
    }
    
    string genString(vector<string> &words, int L, int curLen, int start, int end, bool isLeftJust) {
        string res("");
        int numSpaces = L-curLen;
        for(int i = 0; i < end-start; ++i) {
            res += words[start+i];
            res += addSpaces(numSpaces, end-start-1, i, isLeftJust);
        }
        if(res.size() < L) res.append(L-res.size(), ' ');
        return res;
    }
    
    string addSpaces(int numSpaces, int numPos, int idx, bool isLeftJust) {
        if(idx >= numPos) return "";
        if(isLeftJust) return " ";
        int avg = numSpaces/numPos;
        int extraIdx = numSpaces%numPos;
        return idx < extraIdx ? string(avg+1,' ') : string(avg, ' ');
    }
};
