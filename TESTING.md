# Push_swap Test Cases 🧪

A comprehensive guide to test cases for the push_swap project. Use these to validate your implementation! 

## Basic Error Handling 🚫

### Empty Arguments
```bash
# Empty quotes
./push_swap "       " 1 2 3 
# Expected: Error

# Multiple spaces between numbers
./push_swap "  1   2  " 3
# Expected: Should work! (Bonus handling)
```

### Invalid Input
```bash
# Non-numeric input
./push_swap "Gg 1 2 3" 
# Expected: Error

# No arguments
./push_swap
# Expected: No output

# Duplicate numbers
./push_swap 1 1 2 3
# Expected: Error
```

## Sorting Tests 📊

### Already Sorted Array
```bash
./push_swap 1 2 3 4 5 6
# Expected: No actions (0 operations)
```

### Small Sets
```bash
# 3 Numbers
./push_swap 0 2 1 
# Expected: ≤ 3 actions
# If you get 2 actions, you're killing it! 🔥

# 5 Numbers
./push_swap 0 5 2 3 1
# Expected: ≤ 12 actions
# < 8 actions: You're a sorting wizard! 🧙‍♂️
# > 12 actions: Back to the drawing board 😅
```

### Large Sets
```bash
# 100 Numbers
./push_swap <100 random numbers>
# Expected: ≤ 700 actions
# Tip: Use Python to generate random numbers!

# 500 Numbers
./push_swap <500 random numbers>
# Expected: ≤ 5500 actions
```

### Bonus Handling 🎯
```bash
# Mixed quotes (not required but nice to handle)
./push_swap "  1 2 " 3 "4"
# Expected: Should work!
```

## Memory Testing 🧹

Always test for memory leaks using Valgrind:
```bash
# Test each case with Valgrind
valgrind --leak-check=full ./push_swap <your test case>

# Example
valgrind --leak-check=full ./push_swap 1 2 3
valgrind --leak-check=full ./push_swap "1 2" 3
```

## Python Script for Random Number Testing 🐍
```python
import random
import subprocess

# Generate 100 random numbers
numbers = list(range(1, 101))
random.shuffle(numbers)
test = " ".join(map(str, numbers))

# Run push_swap
command = f"./push_swap {test}"
result = subprocess.run(command, shell=True, capture_output=True, text=True)

# Count operations
operation_count = len(result.stdout.splitlines())
print(f"Operation count: {operation_count}")
```

## Checklist ✅

- [ ] All error cases handled
- [ ] No memory leaks in any test case
- [ ] 3 numbers sorted in ≤ 3 moves
- [ ] 5 numbers sorted in ≤ 12 moves
- [ ] 100 numbers sorted in ≤ 700 moves
- [ ] 500 numbers sorted in ≤ 5500 moves
- [ ] Program handles quoted arguments correctly
- [ ] No crashes on any input

## Pro Tips 💡

1. Always test edge cases first
2. Use shell scripts to automate testing
3. Test with Valgrind frequently
4. Keep track of your operation counts
5. Test with both ascending and descending orders

Good luck with testing! Remember: thorough testing is what separates a good project from a great one! 🚀
