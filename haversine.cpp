#include <stdio.h> /* printf, fgets */
#include <stdlib.h> /* atof */
#include <math.h> /* sin */
#include <stdint.h>

float toRad(float x) {
  return x * 3.141592653 / 180;
}

float haversine(float lat1, float lon1, float lat2, float lon2, bool metric) {
  float R;
  if (metric) R = 6371; // km
  else R = 3958.756; // mi
  float x1 = lat2 - lat1;
  float dLat = toRad(x1);
  float x2 = lon2 - lon1;
  float dLon = toRad(x2);
  float a =
    sin(dLat / 2) * sin(dLat / 2) +
    cos(toRad(lat1)) * cos(toRad(lat2)) *
    sin(dLon / 2) * sin(dLon / 2);
  float c = 2 * atan2(sqrt(a), sqrt(1 - a));
  float d = R * c;
  return round(d * 100.0) / 100;
}

int main(int argc, char **argv) {
  float lat0, lat1, long0, long1;
  if (argc<5) {
    printf("Default coords. argc = %d\n", argc);
    lat0 = 22.4;
    lat1 = 22.4;
    long0 = 113.9;
    long1 = 114.0;
  } else {
    printf("Custom coords. argc = %d\n", argc);
    lat0 = atof(argv[1]);
    long0 = atof(argv[2]);
    lat1 = atof(argv[3]);
    long1 = atof(argv[4]);
  }
  float km = haversine(lat0, long0, lat1, long1, true);
  float mi = haversine(lat0, long0, lat1, long1, false);
  printf("distance between %.6f, %.6f and %.6f, %.6f:\n * %.3f km\n * %.3f mi\n", lat0, long0, lat1, long1, km, mi);
  return 0;
}
