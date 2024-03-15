class Solution:
    def romanToInt(self, s: str) -> int:
        def translate(char):
            if char == "I":
                return 1
            if char == "V":
                return 5
            if char == "X":
                return 10
            if char == "L":
                return 50
            if char == "C":
                return 100
            if char == "D":
                return 500
            if char == "M":
                return 1000
        res = 0
        s = s.replace("IV", "IIII")
        s = s.replace("IX", "VIIII")
        s = s.replace("XL", "XXXX")
        s = s.replace("XC", "LXXXX")
        s = s.replace("CD", "CCCC")
        s = s.replace("CM", "DCCCC")
        for c in s:
            res += translate(c)
        return res