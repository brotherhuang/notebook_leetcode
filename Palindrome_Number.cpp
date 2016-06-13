/* Determine whether an integer is a palindrome. Do this without extra space.*/
class Solution {
public:
    bool check(int x, int &y){
        if (x==0) {return true;}
        if (check(x/10,y)){
            if (x%10==y%10){
                y=y/10;
                return true;
            }
        }
        return false;
    }
    bool isPalindrome(int x) {
        if (x<0){return false;}
        return check(x,x);
    }
};
