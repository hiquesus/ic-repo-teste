class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        str = ""
        check = True
        s = len(min(strs, key=len))
        for i in range(s):
            for j in range(len(strs)):
                if strs[0][i] != strs[j][i]:
                    check = False
            if check:
                str += strs[0][i]
        return str