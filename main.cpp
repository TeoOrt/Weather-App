// Copyright (c) 2024 Mateo Ortega
// SPDX-License-Identifier: MIT

#include <boost/program_options.hpp>
#include <handler.h>
#include <iostream>
#include <iterator>
#include <memory>
#include <weather_man.h>

namespace po = boost::program_options;

typedef std::string string;

static const string CITY = "city";
static const string HELP = "help";
static const string TEMPERATURE = "temperature";

void check_args(po::variables_map vm) {}

int main(int argc, char *argv[]) {
  string weather_city;
  try {
    po::options_description desc("Allowed options");
    desc.add_options()("help", "produce help message")(
        "city", po::value<string>(),
        "specify the city for weather information")(
        "celcius",
        "display temperature in celcius")("less", "only shows the temperature");
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count(HELP)) {
      std::cout << desc << std::endl;
    }

    if (!vm.count(CITY)) {
      std::cerr << desc << std::endl;
    }

    const string city = vm[CITY].as<string>();
    weather_city = city;
  } catch (const std::exception &e) {
    std::cerr << "Missing City\n";
    exit(0);
    return 1;
  }
  const std::unique_ptr<Impl> weather =
      WeatherMan{weather_city}.withCelcius().withDescription().build();

  Handler *testet = new Handler(weather, "372502867223ae6258cd8efd9c3d2602");
  std::cout << testet->get_request() << "\n";
  weather->toString();

  return 0;
}
