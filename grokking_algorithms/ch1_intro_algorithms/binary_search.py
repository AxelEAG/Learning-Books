
"""
# Binary Search

A search algorithm that, given a sorted list and a target value,
returns the index of the target (or `None` if not found).

## Use Case
Binary search is used when you need to efficiently find an element in a **sorted** list or array.
It’s ideal for large datasets where a linear scan would be too slow, as it reduces the search space by half each step.

## Algorithm Steps
    1. Define the search range (`left` to `right`).
    2. Compute the midpoint of the range.
    3. Compare the midpoint value with the target.
        - If target == midpoint → return the index.
        - If target < midpoint  → search the left half.
        - If target > midpoint  → search the right half.
    4. Repeat (steps 2-3) until the range is 1 element / it's not found.

## Complexity
    - Time:  O(log n)
        For a given list of size n, every iteration reduces the search range in half. 
        This gives the algorithm at most log_2(n) (or log n) iterations.
        Each of these iterations has a constant amound of operations x, totaling (log n) * x
        operations - or just log n for big-O notation.
    - Space: O(1)
        No data structures dependant on size were used so space is just constant
"""

from random import randint
from typing import Optional
	
def binary_search(ls: list, target: int) -> Optional[int]:
    # Define search range
    left, right = 0, len(ls) - 1 

    while left <= right:
        mid = (left + right) // 2 # For languages where overflow can be an issue, can use left + (right - left) // 2
        mid_val = ls[mid]

        # Compare midpoint with target value and adjust range as needed
        if target == mid_val:
            return mid
        elif target < mid_val:
            right = mid - 1  # Don't include mid value as that's already checked
        else:
            left = mid + 1

    return None

# Example of running the function
if __name__ == "__main__":
    nums = sorted([randint(0, 1000) for _ in range(99)])    # Generate list of 100 random numbers 
    target = nums[randint(0,99)]                            # Pick a random target that's found on list
    idx = binary_search(nums, target)
    if idx is not None:
        print(f'Target {target} found at index {idx}: nums[{idx}] = {nums[idx]}')
    else:
        print(f'Target {target} is not on the given list.')
    