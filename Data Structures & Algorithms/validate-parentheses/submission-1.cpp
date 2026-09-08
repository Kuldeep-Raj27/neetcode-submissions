class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0){
            return false;
        }

        stack<char> myStack;
        for(auto i : s){
            if((i=='(')||i=='['||i=='{'){
                myStack.push(i);
            }
            else{
                if(myStack.empty()){
                    return false;
                }
                char c = myStack.top();
                myStack.pop();
                if((i==')' && c !='(')||(i==']' && c!='[')||(i=='}'&& c!='{')){
                    return false;
                }
            }
        }
        if(!myStack.empty()){
            return false;
        }
        return true;

    }
};
