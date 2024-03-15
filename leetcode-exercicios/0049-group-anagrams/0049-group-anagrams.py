class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        if len(strs) <= 1:
            return [strs]
        anagrams = {}
        for w in strs:
            sorted_w = "".join(sorted(w))
            if sorted_w in anagrams:
                anagrams[sorted_w].append(w)
            else:
                anagrams[sorted_w] = [w]
        return list(anagrams.values())