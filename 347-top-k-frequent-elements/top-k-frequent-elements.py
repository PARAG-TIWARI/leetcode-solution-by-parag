class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        f = {}
        for num in nums:
            f[num] = f.get(num, 0) + 1
            
        p = [(freq, num) for num, freq in f.items()]
        p.sort(reverse=True)
        
        res = []
        for i in range(k):
            res.append(p[i][1])
            
        return res