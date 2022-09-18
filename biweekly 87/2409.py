class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        def convert(date):
            month, day = list(map(int, date.split("-")))
            prev = sum(days[:month - 1])
            return prev + day
        
        max_arrive_date = max(convert(arriveAlice), convert(arriveBob))
        min_leave_date = min(convert(leaveAlice), convert(leaveBob))
        ans = min_leave_date - max_arrive_date + 1

        return ans if ans >= 0 else 0
