#include "shared.h"
#include <iostream>
#include <sys/socket.h>

using namespace std;

response sendRequest(request);
void handleResponse(response);

int main() {
  request req;

  // Ask for user input
  cout << "Input a two letter state abbreviation (ex. IN): ";
  cin >> req.stateabbrv;

  /*

  // Create connection to server
  server s = ...;

  // Send request and wait for response
  response res = sendRequest(req, s);

  // Handle the server response
  handleResponse(res);

  */
}

response sendRequest(request req /* , server &s */) {
  response res;

  /*

  res = s.send(req);

  */

  return res;
}

void handleResponse(response res) {
  if (res.failed)
    cout << "Request failed." << endl;
  else
    cout << res.statelong << endl;
}
