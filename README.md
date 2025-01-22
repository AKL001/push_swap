# Push_swap 🔄

A sorting algorithm implementation using specific push and swap operations with double linked lists. Let's make sorting fun! 🎮

## Project Overview 🎯

This project implements a sorting algorithm using a restricted set of operations (push, swap, rotate) on two stacks. The main challenge? Getting creative with these limited moves to sort numbers efficiently! 

## Technical Implementation 🛠️

### Data Structure 📚
- Uses double linked lists for both stacks ➡️
- Makes implementing operations (sa, ra, etc.) straightforward 🔧
- Helped me dive deeper into linked list manipulation 🤓

### The "RANGE" Algorithm 🔍

For the algorithm, I like to call it the RANGE Algorithm (you can call it whatever you prefer 😉).

It's pretty straightforward but tricky to optimize for good benchmarks. Here's how it works:

#### Special Cases ⚡
- For **len = 3**: Special algorithm (max 3 moves required)
- For **len = 5**: Different approach (max 12 moves required)

#### Main Algorithm (for n > 5) 🎯

1. **Sort the stack** 🧮
   - Convert stack to array and sort it
   - Example: Stack = `[9, 8, 7, 2, 1, 0]` → Array = `[0, 1, 2, 7, 8, 9]`

2. **Chunk the sorted array** 📏
    - Define ranges based on array length using this formula:
   ```c
   if (!size)
       return (0);
   if (size <= 6)
       range = 2;
   if (size <= 16)
       range = 3;
   else if (size <= 100)
       range = 13;
   else if (size <= 500)
       range = 30;
   else
       range = 45;
   ```
   - These range values were carefully chosen for optimal performance 🎯
   - For example:
     * Arrays ≤ 6 elements: chunk size = 2
     * Arrays ≤ 16 elements: chunk size = 3
     * Arrays ≤ 100 elements: chunk size = 13
     * Arrays ≤ 500 elements: chunk size = 30
     * Larger arrays: chunk size = 45
   - Push matching numbers to Stack B
   - Increment range window (`[0,7]` → `[1,8]` → etc.)
   - Keep going until we've processed all chunks!

3. **Stack B management** 🧳
   - When Stack B has ≥ 2 elements:
   - If top element < next element: swap Stack B
   - Condition: `(*b)->value < (*b)->next->value`
   - This keeps larger numbers at top and bottom
   - Trust me, it works! (I was surprised too) 😄

4. **Handling out-of-range numbers** 🔄
   - When number < range start:
   - Push to Stack B
   - Rotate B
   - It's like magic - don't ask me why it works so well 

5. **Current State** 📊
   - Big numbers: chilling at top and bottom of Stack B
   - Small numbers: hanging out in the middle
   - Looking good so far! 👍

6. **The Return Journey** 🔙
   - "I'll leave it up to you..."
   - Just kidding! Keep reading 

7. **Stack A Revival** 💫
   - Find the largest number in Stack B
   - Push it to Stack A
   - Repeat until done
   - Simple but effective! 🎯

8. **Optimization Trick** ⚡
   - Check position of largest number
   - If position < stack_len/2: use `ra`
   - If position > stack_len/2: use `rra`
   - Work smarter, not harder! 😎

9. **Edge Case Alert** ⚠️
   - Watch out for reverse-sorted arrays!
   - I'll let you figure this one out (consider it a challenge 😉)

## Important Notes 📝

- Don't forget memory leak checks 🧹
- Handle error cases properly 🛡️
- Test thoroughly with different input sizes 🧪

## Benchmarks 📊
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations
- 100 numbers: ≤ 600 operations
- 500 numbers: ≤ 5000 operations

## Final Words 🎉
Remember: Sometimes the simplest solutions are the most elegant. This might not be the most sophisticated algorithm out there, but it gets the job done efficiently and meets the project requirements. Keep practicing and experimenting to optimize it even further. Happy sorting! 🚀

### Good luck with your implementation! 🙌
