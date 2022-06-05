class TextEditor {
public:
    deque<char> left;
    deque<char> right;
    TextEditor() {
    }
    
    void addText(string text) {
        for(char i: text) left.push_back(i);
    }
    int deleteText(int k) {
        if(left.size()<k){
            int sz=left.size();
            while(left.size()>0) left.pop_back();
            return sz;
        }
        for(int i=0;i<k;i++) left.pop_back();
        return k;
    }
    
    string cursorLeft(int k) {
        for(int i=0;i<k;i++){
            if(left.size()==0) break;
            right.push_front(left.back());
            left.pop_back();
        }      
        string curr="";
        int sz=left.size();
        for(int i=0;i<min(sz,10);i++) {
            curr+=left.back();
            left.pop_back();
        }
        reverse(curr.begin(),curr.end());
        //cout<<curr<<endl;
        for(int i=0;i<curr.size();i++) left.push_back(curr[i]);
        return curr;
    }
    
    string cursorRight(int k) {
        for(int i=0;i<k;i++){
            if(right.size()==0) break;
            left.push_back(right.front());
            right.pop_front();
        }      
        string curr="";
        //cout<<left.size()<<" ";
        int sz=left.size();
        for(int i=0;i<min(sz,10);i++) {
            curr+=left.back();
            left.pop_back();
        }
        reverse(curr.begin(),curr.end());
        //cout<<curr<<endl;
        for(int i=0;i<curr.size();i++) left.push_back(curr[i]);
        return curr;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */