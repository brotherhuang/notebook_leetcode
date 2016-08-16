"""
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37 """
class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        vNum1 = version1.split('.')
        vNum2 = version2.split('.')
        for i in range(min(len(vNum1), len(vNum2))):
            if int(vNum1[i]) < int(vNum2[i]) : return -1
            elif int(vNum1[i]) > int(vNum2[i]) : return 1
            else : continue
        if len(vNum2) > len(vNum1):
            for i in range(len(vNum1), len(vNum2)):
                if int(vNum2[i]) > 0 : return -1
        if len(vNum1) > len(vNum2):
            for i in range(len(vNum2), len(vNum1)):
                if int(vNum1[i]) > 0 : return 1
        return 0
