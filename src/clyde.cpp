#include "clyde.h"
#include <cpptoml.h>
#include <filesystem>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

std::filesystem::path getUserConfigPath() {
  std::string configPath;
  const char *homeDir = getenv("HOME");
  if (homeDir)
    configPath = std::string(homeDir) + "/.config";
  else
    throw std::runtime_error("Unable to get HOME environment");
  return std::filesystem::path(configPath);
}

std::shared_ptr<cpptoml::table> getConfigFileContent() {
  const std::filesystem::path configFilePath =
      getUserConfigPath() / "clyde.toml";
  const auto config = cpptoml::parse_file(configFilePath);
  return config;
}

Clyde::Clyde() {
  const auto config = getConfigFileContent();
  const auto commonpackages =
      config->get_array_of<std::string>("common.packages");
  for (auto &c : commonpackages)
    std::cout << c << std::endl;
}