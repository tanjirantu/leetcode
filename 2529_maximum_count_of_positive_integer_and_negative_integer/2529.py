class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        arrLen = len(nums)
        if arrLen == 1 and nums[0] == 0:
            return 0
        if arrLen == 1: return 1
        if nums[arrLen - 1] == 0 and nums[0] == 0:
            return 0
        if nums[0] > 0:
            return arrLen
        if nums[0] < 0 and nums[arrLen -1] < 0: return arrLen

        lo = 0
        hi = arrLen

        if nums[0] == 0:
            while lo == 0:
                mid = int(lo + ((hi - lo) / 2))
                if nums[mid] > 0:
                    lo = mid
            return lo
        else:
            while lo < hi:
                mid = int(lo + ((hi - lo) / 2))
                if nums[mid] >= 0:
                    hi = mid - 1
                if nums[mid] < 0:
                    lo = mid + 1

        if nums[0] < 0:
            while nums[lo] >= 0:
                lo = lo - 1

        lo = lo + 1
        lastIndex = lo
        posInt = arrLen - lo

        if nums[lastIndex] == 0 and nums[arrLen - 1] == 0:
            return lo

        while nums[lastIndex] == 0:
            lastIndex = lastIndex + 1
            posInt = posInt - 1

        return lo if posInt < lo else posInt