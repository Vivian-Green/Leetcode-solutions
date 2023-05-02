problem: EASY - https://leetcode.com/problems/two-sum/

naive solution: https://leetcode.com/problems/two-sum/submissions/943292040/  - runtime beats 33%, memory beats 90%

optimized for better branch prediction (but still naive, using branches): https://leetcode.com/problems/two-sum/submissions/943299826/ - runtime beats 61%, memory beats 63%
  - better branch prediction using continue, init j outside of i loop so it's only defined once


optimized for fewer additions for compare: https://leetcode.com/problems/two-sum/submissions/943337056/ - runtime beats 85%, memory beats 64% 
  - ((numSize-i+1) additions per outer loop reduced to 1 subtraction per outer loop)
  - STILL o(n^2), just fast o(n^2)
