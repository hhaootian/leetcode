
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

172. [Factorial Trailing Zeroes](https://leetcode.com/problems/factorial-trailing-zeroes)  

```python
class Solution:
    def trailingZeroes(self, n: int) -> int:
        def helper(num):
            count = 0
            while num % 5 == 0:
                count += 1
                num = num // 5
            
            return count
        
        ans = 0
        for i in range(5, n + 1, 5):
            ans += helper(i)
        
        return ans
```

415. [Add Strings](https://leetcode.com/problems/add-strings)  

```python
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        if len(num1) < len(num2):
            return self.addStrings(num2, num1)
        
        # 1 >= 2

        p1, p2 = len(num1) - 1, len(num2) - 1
        carry = 0
        ans = ""

        while p2 >= 0:
            val1 = ord(num1[p1]) - ord("0")
            val2 = ord(num2[p2]) - ord("0")
            val = (val1 + val2 + carry) % 10
            carry = (val1 + val2 + carry) // 10
            ans = str(val) + ans
            p1 -= 1
            p2 -= 1
        
        while p1 >= 0:
            val1 = ord(num1[p1]) - ord("0")
            val = (val1 + carry) % 10
            carry = (val1 + carry) // 10
            ans = str(val) + ans
            p1 -= 1

        if carry:
            ans = "1" + ans
        
        return ans
```
