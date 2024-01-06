// Copyright (c) 2024 Mateo Ortega
// SPDX-License-Identifier: MIT
#include <memory>
#include <weather_man.h>

//  std::string city;
// float temperature;
//  float percipitation;
// float humidity;

WeatherMan::WeatherMan(std::string city) : mImpl{ new Impl{city} } {
  std::cout << "Checking Weather in city ........ \n";

}

std::unique_ptr<Impl> WeatherMan::build() {
  return std::move(mImpl);
}

WeatherMan& WeatherMan::withCelcius() {
  mImpl->temperature = TemperatureFormat::celcius;
  return *this;
}


WeatherMan& WeatherMan::withHumidity() {
  mImpl->humidity = true;
  return *this;
}

WeatherMan& WeatherMan::withPrecipitation() {
  mImpl->percipitation = true;
  return *this;
}

