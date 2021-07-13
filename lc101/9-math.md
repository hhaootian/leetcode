
# Chapter 9

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

326. [Power of Three](https://leetcode.com/problems/power-of-three)  

```python
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n == 1:
            return True
        if n == 0:
            return False
        
        return n % 3 == 0 and self.isPowerOfThree(n // 3)
```

384. [Shuffle an Array](https://leetcode.com/problems/shuffle-an-array)  

```python
class Solution:

    def __init__(self, nums: List[int]):
        self.nums = nums


    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.nums


    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        nums = self.nums[:]
        for i in range(len(nums) - 1, 0, -1):
            j = random.randint(0, i)
            nums[i], nums[j] = nums[j], nums[i]
        
        return nums
```

528. [Random Pick with Weight](https://leetcode.com/problems/random-pick-with-weight)  

```python
class Solution:

    def __init__(self, w: List[int]):
        self.nums = [w[0]]
        for i in range(1, len(w)):
            self.nums.append(self.nums[-1] + w[i])

    def pickIndex(self) -> int:
        target = random.randint(1, self.nums[-1])
        left, right = 0, len(self.nums) - 1

        while left < right:
            mid = (left + right) // 2

            if self.nums[mid] < target:
                left = mid + 1
            else:
                right = mid
        
        return right
```

382. [Linked List Random Node](https://leetcode.com/problems/linked-list-random-node)  

```python
class Solution:

    def __init__(self, head: ListNode):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        """
        self.head = head


    def getRandom(self) -> int:
        """
        Returns a random node's value.
        """
        val = None
        prob = self.head
        m = 0
        while prob:
            m += 1
            if random.random() < 1 / m:
                val = prob.val
            prob = prob.next
        
        return val
```

168. [ Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title)  

```python
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:

        ans = ""
        while columnNumber:
            columnNumber -= 1
            num = columnNumber % 26
            ans = chr(ord("A") + num) + ans
            columnNumber //= 26
            
        
        return ans
```

67. [Add Binary](https://leetcode.com/problems/add-binary)  

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # len(a) >= len(b)
        if len(b) > len(a):
            return self.addBinary(b, a)
        
        p1, p2 = len(a) - 1, len(b) - 1
        ans = ""
        carry = 0

        while p2 >= 0:
            val = carry + int(a[p1]) + int(b[p2])
            carry = val // 2
            val = val % 2
            ans = str(val) + ans
            p1 -= 1
            p2 -= 1
        
        while p1 >= 0:
            val = carry + int(a[p1])
            carry = val // 2
            val = val % 2
            ans = str(val) + ans
            p1 -= 1
        
        if carry:
            ans = "1" + ans
        
        return ans
```

