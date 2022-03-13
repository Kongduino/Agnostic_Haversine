Number.prototype.toRad = function() {
   return this * Math.PI / 180;
}

function haversine(lat1, lon1, lat2, lon2, metric=true) {
  var R = 6371; // km
  if(metric!=true) R = 3958.756;
  var x1 = lat2-lat1;
  var dLat = x1.toRad();
  var x2 = lon2-lon1;
  var dLon = x2.toRad();
  var a = Math.sin(dLat/2) * Math.sin(dLat/2) +
    Math.cos(lat1.toRad()) * Math.cos(lat2.toRad()) *
    Math.sin(dLon/2) * Math.sin(dLon/2);
  var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a));
  var d = R * c;
  return Math.round((d + Number.EPSILON) * 100) / 100;
}

print(haversine(22.2, 113.9, -22.4, 114.1)+" km");
print(haversine(22.2, 113.9, -22.4, 114.1, false)+" mi");
