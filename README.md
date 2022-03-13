# haversine.cpp

Quick code that provides the distance between two GNSS coordinates in kilometers and miles. And because whynot? I added a Python3 version.


```bash
> ./test
Default coords. argc = 1
distance between 22.400000, 113.900002 and 22.400000, 114.000000:
 * 10.280 km
 * 6.390 mi
> ./test 22.2 113.9 22.4 114.1
Custom coords. argc = 5
distance between 22.200001, 113.900002 and 22.400000, 114.099998:
 * 30.300 km
 * 18.830 mi

> python haversine.py                       
Default coords. argc = 1
Distance between 22.4, 113.9 and 22.4, 114.0:
 * 10.28 km
 * 6.39 mi
> python haversine.py 22.2 113.9 -22.4 114.1
Custom coords. argc = 5
Distance between 22.2, 113.9 and -22.4, 114.1:
 * 4959.34 km
 * 3081.59 mi
```
