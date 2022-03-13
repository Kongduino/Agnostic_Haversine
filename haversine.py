import sys, math

def toRad(x):
  return x * 3.141592653 / 180

def haversine(lat1, lon1, lat2, lon2, metric = True):
  R = 6371.0
  if (metric != True):
    R = 3958.756
  x1 = lat2-lat1
  dLat = toRad(x1)
  x2 = lon2-lon1
  dLon = toRad(x2)
  a = math.sin(dLat/2) * math.sin(dLat/2) + math.cos(toRad(lat1)) * math.cos(toRad(lat2)) * math.sin(dLon/2) * math.sin(dLon/2)
  c = 2 * math.atan2(math.sqrt(a), math.sqrt(1-a))
  d = R * c
  return round((d + 2.220446049250313e-16) * 100) / 100

if __name__ == "__main__":
  argc = len(sys.argv)
  if argc<5:
    print(f"Default coords. argc = {argc}")
    lat0 = 22.4
    lat1 = 22.4
    long0 = 113.9
    long1 = 114.0
  else:
    print(f"Custom coords. argc = {argc}")
    lat0 = float(sys.argv[1])
    long0 = float(sys.argv[2])
    lat1 = float(sys.argv[3])
    long1 = float(sys.argv[4])
  km = haversine(lat0, long0, lat1, long1)
  mi = haversine(lat0, long0, lat1, long1, False)
  print(f"Distance between {lat0}, {long0} and {lat1}, {long1}:")
  print(f" * {km} km")
  print(f" * {mi} mi")
