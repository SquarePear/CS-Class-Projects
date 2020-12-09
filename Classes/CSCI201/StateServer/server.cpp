/*
 *  Program name: State Server
 *  Author: Jeffrey Harmon
 *  Date created: Dec. 3, 2020
 *  Date last updated: Dec. 6, 2020
 *  Purpose: Create a server for a client to request a US state's full name from
 *           the abbreviation
 */

#include "shared.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sys/socket.h>

using namespace std;

response handleRequest(request);
void sendResponse(response);

int main() {
  // Create map of states from file
  map<string, string> states;

  // Open the file stream
  fstream file("states.txt");

  // Add all the states to the map
  while (!file.eof()) {
    string stateabbrv, statelong;

    getline(file, stateabbrv);
    getline(file, statelong);

    states.insert({stateabbrv, statelong});
  }
  /*

  while (true) {
    client c = socket(..., ..., ...);

    // Check for client
    if (!c) continue;

    request req = c.req;

    // Check for request
    if (!req) continue;

    // Generate response
    response res = handleRequest(req, states);

    sendResponse(res, c);

    // Close connection to client
    c.close();
  }

  */
}

response handleRequest(request req, map<string, string> &states) {
  response res;

  auto pos = states.find(req.stateabbrv);

  if (pos == states.end())
    res.failed = true;
  else
    res.statelong = pos->second;

  return res;
}

void sendResponse(response res /* , client &c */) {
  /*

  c.send(client);

  */
}
