class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        int x11=rec1[0],x12=rec1[2],y11=rec1[1],y12=rec1[3];
        int x21=rec2[0],x22=rec2[2],y21=rec2[1],y22=rec2[3];
        
        if(min(x21,x22)>=max(x11,x12) || max(x21,x22)<=min(x11,x12))return false;
        if(min(y21,y22)>=max(y11,y12) || max(y21,y22)<=min(y11,y12))return false;
        
        return true;
    }
};