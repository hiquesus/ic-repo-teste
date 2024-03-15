class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = {}
        for item in nums:
            if item in freq:
                freq[item] += 1
            else:
                freq[item] = 1
        output = []
        sorted_freq = sorted(freq.items(), key=lambda item: item[1], reverse = True)
        for i in range(k):
            output.append(sorted_freq[i][0])
        return output