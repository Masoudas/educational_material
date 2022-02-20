"""
Notice: If you would like to calculate distances between multiple locations across the globe, it is recommended to use Haversine formula to do the calculations. Haversine package in Python provides an easy-to-use function for calculating these based on latitude and longitude values.

Haversine is installed using:
$ pip install haversine

Note that the `Inverse Haversine Formula` calculates a point from a given vector (distance and direction) and start point. Currently explicitly supports both cardinal (north, east, south, west) and intercardinal (northeast, southeast, southwest, northwest) directions. But also allows for explicit angles expressed in Radians.

Me: Compared to google map, it seems to have slight error (600 meter was shown around 630, which does seem to be fine for our purposes.)
"""
from haversine import haversine, Unit

# Babak, Mashhad
latitude_home = 54.573306317730015
longitude_home = 8.450357487910575

latitude_work = 60.1666
longitude_work = 24.9417

distance = haversine(
    (latitude_home, longitude_home), (latitude_work, longitude_work), Unit.KILOMETERS)

print("Distance is:", distance)
