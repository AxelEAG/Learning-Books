
"""
# Binary Search

A search algorithm that, given a sorted list and a target value,
returns the index of the target (or `None` if not found).

"""

from random import randint
from typing import Optional

# Iterative implementation of binary search
def binary_search_iter(ls: list, target: int) -> Optional[int]:
    # Define search range
    left, right = 0, len(ls) - 1 

    while left <= right:
        mid = (left + right) // 2 # For languages where overflow can be an issue, can use left + (right - left) // 2
        val = ls[mid]

        # Return midpoint index if it's the target
        if target == val:
            return mid
        
        # Otherwise, adjust search range as needed
        if target < val:
            right = mid - 1  # Don't include mid value as that's already checked
        else:
            left = mid + 1

    return None

# Recursive implementation of binary search
def binary_search_rec(ls: list, target: int) -> Optional[int]:
    def search(left: int, right: int) -> Optional[int]:
        # Base case for when it has looked through the whole range
        if left > right:
            return None
        
        mid = (left + right) // 2
        val = ls[mid]

        # Return midpoint index if it's the target
        if target == val:
            return mid
        
        # Otherwise, recursively search for value in the relevant range
        if target < val:
            idx = search(left, mid - 1)
        else:
            idx = search(mid + 1, right)

        return idx

    return search(0, len(ls) - 1)
    