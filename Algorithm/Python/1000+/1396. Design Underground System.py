class UndergroundSystem:

    def __init__(self):
        self.travelTime = collections.defaultdict(lambda: collections.defaultdict(lambda: []))
        self.idRecord = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        # Record id
        recordItem = {
            "station_name": stationName,
            "start_time": t
        }
        self.idRecord[id] = recordItem

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        # Get startStation and endStation
        startStation = self.idRecord[id]["station_name"]
        endStation = stationName
        startTime = self.idRecord[id]["start_time"]
        endTime = t
        spendTime = endTime - startTime
        
        # Get time list && Update time list
        if endStation in self.travelTime[startStation].keys():
            self.travelTime[startStation][endStation].append(spendTime)
        else:
            self.travelTime[startStation][endStation] = [spendTime]

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        # Caculate average time
        timeList = self.travelTime[startStation][endStation]
        return float(sum(timeList)) / len(timeList)
        
