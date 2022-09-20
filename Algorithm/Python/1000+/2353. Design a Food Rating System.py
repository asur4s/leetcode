# Method 1: TLE
from sortedcontainers import SortedList
from collections import defaultdict

class FoodRatings(object):

    def __init__(self, foods, cuisines, ratings):
        """
        :type foods: List[str]
        :type cuisines: List[str]
        :type ratings: List[int]
        """
        self.foodDict = {}
        self.ratedDict = defaultdict(lambda: SortedList())
        
        for i,food in enumerate(foods):
            self.foodDict[food] = (cuisines[i], ratings[i])
            self.ratedDict[cuisines[i]].add((-ratings[i], foods[i]))

    def changeRating(self, food, newRating):
        """
        :type food: str
        :type newRating: int
        :rtype: None
        """
        cuisine, rating = self.foodDict[food]
        self.ratedDict[cuisine].remove((-rating, food))
        
        self.foodDict[food] = (cuisine, newRating)
        self.ratedDict[cuisine].add((-newRating, food))
        

    def highestRated(self, cuisine):
        """
        :type cuisine: str
        :rtype: str
        """
        return self.ratedDict[cuisine][0][1] # return the latest food name
        
# Method 2: 
