from __future__ import annotations

class Home:
    no_rooms: int
    address: str
    is_north: bool


class Consumer:
    phase: int
    is_demand: bool
    address: str

    def calculate_consumption(self, rate: float, consumer: Consumer):
        return self.phase * 5 + 1000

def calculate_consumption():
    return

class BeautifulHome(Home):
    price: float


mr_rezavanian = Consumer(3, False, "Felan ja")

mr_rezavanian.calculate_consumption()