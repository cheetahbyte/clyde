#include "clyde.h"
#include <cstdio>
#include <string>
#include <unistd.h>
#include <vector>

std::string exec(const char *cmd) {
  std::vector<char> buffer(128);
  std::string result;
  std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }

  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }

  return result;
}

int main() { Clyde c; }