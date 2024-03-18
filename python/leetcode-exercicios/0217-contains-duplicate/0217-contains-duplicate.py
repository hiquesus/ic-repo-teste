class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        hashset = set()
        for k in nums:
            if k in hashset:
                return True
            else:
                hashset.add(k)
        return False