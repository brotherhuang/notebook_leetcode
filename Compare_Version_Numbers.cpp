/* Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        int startPos = 0;
        for(int i = 0; i < version1.size(); i++){
            if(version1[i] == '.'){
                int num = stoi(version1.substr(startPos, i - startPos));
                v1.push_back(num);
                startPos = i + 1;
            }
            if(i == version1.size() - 1) {
                int num = stoi(version1.substr(startPos, i - startPos + 1));
                v1.push_back(num);
            }
        }
        startPos = 0;
        for(int i = 0; i < version2.size(); i++){
            if(version2[i] == '.'){
                int num = stoi(version2.substr(startPos, i));
                v2.push_back(num);
                startPos = i + 1;
            }
            if(i == version2.size() - 1) {
                int num = stoi(version2.substr(startPos, i - startPos + 1));
                v2.push_back(num);
            }
        }
        int length = min(v1.size(),v2.size());
        for(int i = 0; i < length; i++){
            if(v1[i] < v2[i]) {return -1;}
            if(v1[i] > v2[i]) {return 1;}
        }
        if(v1.size() > length) {
            for(int i = length; i < v1.size(); i++){
                if(v1[i] != 0) { return 1;}
            }
        }
        if(v2.size() > length) {
            for(int i = length; i < v2.size(); i++){
                if(v2[i] != 0) { return -1;}
            }
        }
        return 0;
    }
};
