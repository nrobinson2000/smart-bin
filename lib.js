var device = "https://api.particle.io/v1/devices/48ff6b065067555032091787/";
var token = "0101e75a4acb0c906e1d8f4956f9cd032163db43";

function httpGet(theUrl)
{
  var xmlHttp = new XMLHttpRequest();
  xmlHttp.open( "GET", theUrl, false );
  xmlHttp.send( null );
  return xmlHttp.responseText;
}

function getVariable(variable)
{
  var response = httpGet(device + variable + "?access_token=" + token);
  obj = JSON.parse(response);
  return obj.result;
}
