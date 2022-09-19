import collections

class TopVotedCandidate:
    winner = []
    times = []

    def __init__(self, persons: List[int], times: List[int]):
        vote_count = {}
        winner = []
        max_vote = 0
        max_vote_person = -1
        vote_count = collections.defaultdict(lambda: 0)
        
        for p, t in zip(persons, times):
            
            vote_count[p] += 1
            if vote_count[p] >= max_vote:
                max_vote = vote_count[p]
                max_vote_person = p
            winner.append(max_vote_person)
            
        self.times = times
        self.winner = winner 
        
    def q(self, t: int) -> int:
        winner = self.winner
        times = self.times
        
        i = bisect.bisect_left(times, t)
        if i != len(times) and times[i] == t:
            return winner[i]
        
        return winner[i-1]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)