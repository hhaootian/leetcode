
## Chapter 9

204. [Count Primes](https://leetcode.com/problems/count-primes)  

```python
class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        
        isPrime = [True for i in range(n)]

        for i in range(2, n):
            if isPrime[i]:
                for j in range(2 * i, n, i):
                    isPrime[j] = False
        
        return sum(isPrime) - 2
```

504. [Base 7](https://leetcode.com/problems/base-7)  

```python
class Solution:
    def convertToBase7(self, num: int) -> str:
        ans = ""

        neg = False
        if num < 0:
            neg = True
            num = -num
        
        while True:
            ans = str(num % 7) + ans
            num = num // 7

            if num == 0:
                break
        
        return "-" + ans if neg else ans
```
