class Solution {
public:

    bool solved(vector<int> &cards){

        double a = cards[0],b = cards[1],c = cards[2],d = cards[3];

        if(helper1(a+b,c,d) || helper1(a*b,c,d) || helper1(a-b,c,d) || helper1(a/b,c,d)) return true;
        if(helper1(a,b,c+d) || helper1(a,b,c*d) || helper1(a,b,c-d) || helper1(a,b,c/d)) return true;
        if(helper1(a,b+c,d) || helper1(a,b-c,d) || helper1(a,b*c,d) || helper1(a,b/c,d)) return true;
        return false;

    }

    bool helper1(double a,double b,double c){

        if(helper2(a+b,c) || helper2(a-b,c) || helper2(a/b,c) || helper2(a*b,c)) return true;
        if(helper2(a,b+c) || helper2(a,b-c) || helper2(a,b/c) || helper2(a,b*c)) return true;
        return false;
    }

    bool helper2(double a,double b){
        if (abs(a+b-24.0) < 0.0001 || abs(a-b-24.0) < 0.0001 || abs(a*b-24.0) < 0.0001 || b&&abs(a/b-24.0) < 0.0001) 
            return true;
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        
        sort(cards.begin(),cards.end());

        do{
            if(solved(cards)) return true;
        }while(next_permutation(cards.begin(),cards.end()));

        return false;
    }
};