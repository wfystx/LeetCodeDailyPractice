class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = 0, v2 = 0;
        while(v1<version1.size() && v2<version2.size()){
            int ver1 = 0;
            while(v1<version1.size() && version1[v1]!='.'){
                ver1 = ver1*10 + (version1[v1] - '0');
                v1++;
            }
            int ver2 = 0;
            while(v2<version2.size() && version2[v2]!='.'){
                ver2 = ver2*10 + (version2[v2] - '0');
                v2++;
            }
            if(ver1 > ver2) return 1;
            if(ver1 < ver2) return -1;
            v1++; v2++;
        }
        
        if(v1>=version1.size()){
            for(v2; v2<version2.size(); v2++){
                if(version2[v2]!='.' && version2[v2]-'0'>0) return -1;
            }
        }
        else if(v2>=version2.size()){
            for(v1; v1<version1.size(); v1++){
                if(version1[v1]!='.' && version1[v1]-'0'>0) return 1;
            }
        }
        return 0;
    }
};