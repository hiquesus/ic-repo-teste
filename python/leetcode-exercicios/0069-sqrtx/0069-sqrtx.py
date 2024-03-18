class Solution(object):
    def mySqrt(self, x):
        l, r = 0, x
        while l <= r:
            m = (r+l)//2
            if m*m < x:
                l = m + 1
            elif m*m > x:
                r = m - 1
            else:
                return m
        return r