class Solution:
    def matchPlayersAndTrainers(self, players: List[int], trainers: List[int]) -> int:
        ans = 0
        players = sorted(players)
        trainers = sorted(trainers)
        
        while players and trainers:
            while players and players[-1] > trainers[-1]:
                players.pop()
            
            if players and trainers:
                players.pop()
                trainers.pop()
                ans += 1
            
            
        return ans
