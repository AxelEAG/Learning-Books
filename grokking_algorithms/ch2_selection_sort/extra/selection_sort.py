
"""
# Selection sort

A sorting algorithm that repeatedly finds the smallest element in the unsorted portion,
and swaps it into the sorted portion.

"""

from typing import List


def selection_sort(nums: List[int]) -> List[int]:
    L = len(nums)
    for i in range(L): # nums[:i] is the sorted 
        # Search for next smallest
        min_idx = i
        for j in range(i + 1, L): #  nums[i+1:] is the unsorted
            if nums[j] < nums[min_idx]:
                min_idx = j
        
        # Swipe current with next smallest
        nums[i], nums[min_idx] = nums[min_idx], nums[i]
    return nums
