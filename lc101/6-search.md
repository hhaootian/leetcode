
## Chapter 6

695. [Max Area of Island](https://leetcode.com/problems/max-area-of-island)  

```python
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxArea = 0
        row, col = len(grid), len(grid[0])
        visited = [[False for i in range(col)] for j in range(row)]
        direction = [[0, -1], [0, 1], [-1, 0], [1, 0]]

        def dfs(i, j):
            if visited[i][j]:
                return 0
            visited[i][j] = True
            currentArea = 1
            for direc in direction:
                newI, newJ = i + direc[0], j + direc[1]
                if newI >= 0 and newI <= row - 1 and newJ >= 0 and newJ <= col - 1 and grid[newI][newJ] == 1:
                    currentArea += dfs(newI, newJ)
            return currentArea
        
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 1:
                    area = dfs(i, j)
                    maxArea = max(maxArea, area)
        
        return maxArea
```

547. [ Number of Provinces](https://leetcode.com/problems/number-of-provinces)  

```python
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        visited = [False for i in range(n)]
        ans = 0

        def dfs(i):
            if visited[i]:
                return
            
            visited[i] = True
            for j in range(n):
                if j != i and M[i][j] == 1:
                    dfs(j)
        
        for i in range(n):
            if not visited[i]:
                ans += 1
                dfs(i)
        
        return ans
```

417. [ Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow)  

```python
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return []
        
        row, col = len(matrix), len(matrix[0])
        pacific = set()
        atlantic = set()
        directions = [[0, 1], [0, -1], [-1, 0], [1, 0]]

        def dfs(visited, i, j):
            visited.add((i, j))
            for direc in directions:
                newI, newJ = i + direc[0], j + direc[1]
                if 0 <= newI < row and 0 <= newJ < col and (newI, newJ) not in visited and matrix[newI][newJ] >= matrix[i][j]:
                    dfs(visited, newI, newJ)
        
        for i in range(row):
            dfs(pacific, i, 0)
            dfs(atlantic, i, col - 1)
        
        for i in range(col):
            dfs(pacific, 0, i)
            dfs(atlantic, row - 1, i)
    
        return list(pacific.intersection(atlantic))
```

46. [ Permutations](https://leetcode.com/problems/permutations)  

```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.ans = []

        def backtrack(cur, rest):
            if not rest:
                self.ans.append(cur[:])
            
            for i in range(len(rest)):
                cur.append(rest[i])
                backtrack(cur, rest[:i] + rest[i+1:])
                cur.pop(-1)

        backtrack([], nums)

        return self.ans
```

77. [Combinations](https://leetcode.com/problems/combinations)  

```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.ans = []

        def backtrack(cur, start):
            if len(cur) == k:
                self.ans.append(cur[:])
                return
            
            for number in range(start, n + 1):
                cur.append(number)
                backtrack(cur, number + 1)
                cur.pop(-1)
        
        backtrack([], 1)
        return self.ans
```

79. [ Word Search](https://leetcode.com/problems/word-search)  

```python
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.ans = False
        row, col = len(board), len(board[0])
        visited = [[False for i in range(col)] for j in range(row)]

        def dfs(cur_index, x, y, visited):
            if self.ans:
                return 

            if cur_index >= len(word):
                self.ans = True
                return

            if x < 0 or x >= row or y < 0 or y >= col:
                return
            
            if board[x][y] != word[cur_index] or visited[x][y]:
                return
            
            visited[x][y] = True

            dfs(cur_index + 1, x + 1, y, visited)
            dfs(cur_index + 1, x - 1, y, visited)
            dfs(cur_index + 1, x, y + 1, visited)
            dfs(cur_index + 1, x, y - 1, visited)

            visited[x][y] = False

        for i in range(row):
            for j in range(col):
                dfs(0, i, j, visited)
                if self.ans:
                    return True

        return self.ans
```

51. [N-Queens](https://leetcode.com/problems/n-queens)  

```python
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        board = [["." for i in range(n)] for j in range(n)]

        def backtrack(board, row):
            if row == n:
                ans.append(["".join(line) for line in board])
            
            for col in range(0, n):
                if valid(board, row, col):
                    # do
                    board[row][col] = "Q"
                    backtrack(board, row + 1)
                    # undo
                    board[row][col] = "."

        def valid(board, row, col):
            for i in range(0, row):
                if board[i][col] == "Q":
                    return False
            
            i, j = row - 1, col + 1
            while i >= 0 and j < n:
                if board[i][j] == "Q":
                    return False
                i -= 1
                j += 1
            
            i, j = row - 1, col - 1
            while i >= 0 and j >= 0:
                if board[i][j] == "Q":
                    return False
                i -= 1
                j -= 1
            
            return True
        
        backtrack(board, 0)
        return ans
```

934. [Shortest Bridge](https://leetcode.com/problems/shortest-bridge)  

```python
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        row, col = len(A), len(A[0])
        direction = [[-1, 0], [1, 0], [0, 1], [0, -1]]
        visited = [[False for i in range(col)] for j in range(row)]
        points = []

        def dfs(i, j):
            if i < 0 or i >= row or j < 0 or j >= col or A[i][j] != 1 or visited[i][j]:
                return
            
            visited[i][j] = True
            points.append([i, j])

            for direc in direction:
                dfs(i + direc[0], j + direc[1])
        
        # find 1st island
        found = False
        for i in range(row):
            if found:
                break
            for j in range(col):
                if A[i][j] == 1:
                    dfs(i, j)
                    found = True
                    break
        
        step = 0
        while points:
            size = len(points)
            for _ in range(size):
                # current i, j
                pos = points.pop(0)
                for direc in direction:
                    i, j = pos[0] + direc[0], pos[1] + direc[1]
                    if i < 0 or i >= row or j < 0 or j >= col:
                        continue
                    if A[i][j] == 0 and not visited[i][j]:
                        points.append([i, j])
                        visited[i][j] = True
                    #if A[i][j] == 1 and visited[i][j] == True:
                    #    continue
                    # found island 2
                    if A[i][j] == 1 and not visited[i][j]:
                        return step

            step += 1

        return -1
```

126. [Word Ladder II](https://leetcode.com/problems/word-ladder-ii)  

```python
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList:
            return []
        
        wordList = set(wordList)
        current = {}
        # key: target; value: path
        current[beginWord] = [[beginWord]]

        while current:
            nxt = collections.defaultdict(list)
            for word in current:
                if word == endWord:
                    return current[word]
                
                for i in range(len(word)):
                    for char in range(ord('a'), ord('z') + 1):
                        new = word[:i] + chr(char) + word[i+1:]
                        if new in wordList:
                            nxt[new] += [path + [new] for path in current[word]]

            # delete loop
            wordList -= set(nxt.keys())
            current = nxt
        
        return []
```

130. [Surrounded Regions](https://leetcode.com/problems/surrounded-regions)  

```python
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row, col =  len(board), len(board[0])
        direction = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        visited = [[False for i in range(col)] for j in range(row)]

        def dfs(i, j):
            if i < 0 or i >= row or j < 0 or j >= col:
                return
            
            if visited[i][j] or board[i][j] != "O":
                return
            
            visited[i][j] = True
            for direc in direction:
                x, y = i + direc[0], j + direc[1]
                dfs(x, y)
        
        for i in range(row):
            dfs(i, 0)
            dfs(i, col - 1)
        
        for j in range(col):
            dfs(0, j)
            dfs(row - 1, j)
        
        for i in range(row):
            for j in range(col):
                if not visited[i][j]:
                    board[i][j] = "X"
```

257. [Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths)  

```python
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        ans = []
        if not root:
            return ans
        
        paths = [str(root.val)]
        # node
        layer = [root]

        while layer:
            size = len(layer)
            for i in range(size):
                node = layer.pop(0)
                path = paths.pop(0)
                if node.left:
                    layer.append(node.left)
                    paths.append(path + "->" + str(node.left.val))
                if node.right:
                    layer.append(node.right)
                    paths.append(path + "->" + str(node.right.val))
                if not node.right and not node.left:
                    ans.append(path[:])
        
        return ans
```

47. [ Permutations II](https://leetcode.com/problems/permutations-ii)  

```python
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        visited = [False for i in range(len(nums))]
        ans = []

        def backtrack(cur, visited):
            if len(cur) == len(nums):
                ans.append(cur[:])
                return
            
            for i in range(len(nums)):
                if visited[i] or (i >= 1 and nums[i-1] == nums[i] and not visited[i-1]):
                    continue
                
                # mark, do
                visited[i] = True
                cur.append(nums[i])
                backtrack(cur, visited)
                # unmark, undo
                visited[i] = False
                cur.pop(-1)

        backtrack([], visited)
        return ans
```

40. [Combination Sum II](https://leetcode.com/problems/combination-sum-ii)  

```python
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates = sorted(candidates)
        ans = []
        
        def dfs(left, path, start):
            if left < 0:
                return
            if left == 0: # sum(path) == target
                ans.append(path[:])
                return
            
            for i in range(start, len(candidates)):
                if i > start and candidates[i-1] == candidates[i]:
                    continue
                
                dfs(left - candidates[i], path + [candidates[i]], i + 1)
        
        dfs(target, [], 0)
        return ans
```

37. [Sudoku Solver](https://leetcode.com/problems/sudoku-solver)  

```python
class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        return self.backtrack(board, 0, 0)

    def backtrack(self, board, i, j):
        m, n = 9, 9
        if j == n:
            return self.backtrack(board, i + 1, 0)
        
        if i == m:
            return True
        
        if board[i][j] != ".":
            return self.backtrack(board, i, j + 1)
        
        for number in range(1, 10):
            if not self.valid(board, i, j, number):
                continue
            
            board[i][j] = str(number)
            if self.backtrack(board, i, j + 1):
                return True
            board[i][j] = "."

    
    def valid(self, board, i, j, number):
        for p in range(9):
            if board[p][j] == str(number):
                return False
            if board[i][p] == str(number):
                return False
            row = (i // 3) * 3 + p // 3
            col = (j // 3) * 3 + p % 3
            if board[row][col] == str(number):
                return False
        return True
```

310. [Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees)  

```python
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]
        
        degree = [0 for i in range(n)]
        dic = collections.defaultdict(list)
        for edge in edges:
            node1, node2 = edge
            degree[node1] += 1
            degree[node2] += 1
            dic[node1].append(node2)
            dic[node2].append(node1)
        
        # degree = 1
        queue = []
        for i in range(n):
            if degree[i] == 1:
                queue.append(i)
        
        while queue:
            size = len(queue)
            res = []

            for i in range(size):
                node = queue.pop(0)
                res.append(node)

                adjacent = dic[node]
                for adj in adjacent:
                    degree[adj] -= 1
                    if degree[adj] == 1:
                        queue.append(adj)
        
        return res
```
