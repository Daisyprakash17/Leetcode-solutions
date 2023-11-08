class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int first=abs(fy-sy);
        int xm=abs(sx-fx);
        int ma=first+xm;
        if(sx==fx && sy==fy)
        {
            if(t==1)
                return false;
            else
                return true;
        }
        if(xm<=first)
        {
           if(first-1<t && first>0)
           {
             return true;
               
           }
            else
                return false;
        }
            if(fx<=sx)
        {
            sx-=first;
        }
        else
            sx+=first;
        int diff=abs(fx-sx);
        if(first+diff-1<t && (diff+first)>0)
        {
           return true;
             
        }
        else
            return false;
    }
};