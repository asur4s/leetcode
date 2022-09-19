from collections import defaultdict
from sortedcontainers import SortedList

class MovieRentingSystem:

    def __init__(self, n: int, entries: List[List[int]]):
        self.movie_to_price_shop = defaultdict(lambda: SortedList())
        self.shop_movie_to_price = {}
        self.report_list = SortedList()
        
        for s, m, p in entries:
            self.movie_to_price_shop[m].add((p, s))
            self.shop_movie_to_price[(s, m)] = p
        

    def search(self, movie: int) -> List[int]:
        return [s for _, s in self.movie_to_price_shop[movie][:5]]
        

    def rent(self, shop: int, movie: int) -> None:
        price = self.shop_movie_to_price[(shop, movie)]
        self.movie_to_price_shop[movie].remove((price, shop))
        self.report_list.add((price, shop, movie))

        
    def drop(self, shop: int, movie: int) -> None:
        price = self.shop_movie_to_price[(shop, movie)]
        self.movie_to_price_shop[movie].add((price, shop))
        self.report_list.remove((price, shop, movie))

    def report(self) -> List[List[int]]:
        return [[s, m] for p, s, m in self.report_list[:5]]
        


# Your MovieRentingSystem object will be instantiated and called as such:
# obj = MovieRentingSystem(n, entries)
# param_1 = obj.search(movie)
# obj.rent(shop,movie)
# obj.drop(shop,movie)
# param_4 = obj.report()