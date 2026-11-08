class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char first=x>=y?'a':'b',second=x>=y?'b':'a';int answer=0;for(int pass=0;pass<2;pass++){char a=pass==0?first:second,b=pass==0?second:first;int score=pass==0?max(x,y):min(x,y);string stack;for(char ch:s){if(!stack.empty()&&stack.back()==a&&ch==b){stack.pop_back();answer+=score;}else stack.push_back(ch);}s=move(stack);}return answer;
    }
};
