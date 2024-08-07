#ifndef CLYDE_H
#define CLYDE_H
#include <vector>

struct Config {
public:
  std::vector<std::string> getPackages() { return packages; }

protected:
  std::vector<std::string> packages;
};

struct CommonConfig final : public Config {};

struct ClydeConfig {
private:
  CommonConfig common;
};

class Clyde {
public:
  Clyde();

private:
  ClydeConfig config;
};

#endif