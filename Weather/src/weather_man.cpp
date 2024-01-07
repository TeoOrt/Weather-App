// Copyright (c) 2024 Mateo Ortega
// SPDX-License-Identifier: MIT
#include <memory>
#include <sstream>
#include <weather_man.h>

//  std::string city;
// float temperature;
//  float percipitation;
// float humidity;

WeatherMan::WeatherMan(std::string city) : mImpl{new Impl{city}} {
  std::cout << "Checking Weather in " << mImpl->w_city << "........ \n";
}

std::unique_ptr<Impl> WeatherMan::build() { return std::move(mImpl); }

WeatherMan &WeatherMan::withCelcius() {
  mImpl->temperature = TemperatureFormat::celcius;
  return *this;
}

WeatherMan &WeatherMan::withHumidity() {
  mImpl->humidity = true;
  return *this;
}

WeatherMan &WeatherMan::withDescription() {
  mImpl->description = true;
  return *this;
}

std::string Impl::get_format(float temp) {
  std::string format = "Your current temperature is: ";
  switch (temperature) {
  case TemperatureFormat::fahrenheit:
    format += std::to_string(temp);
    format += " F";
    break;
  case TemperatureFormat::celcius:
    float c = (temp - 32.0) * (5.0 / 9.0);
    format += std::to_string(c);
    format += " C";
    break;
  }
  return format;
}

std::string Impl::get_description(std::string data) {
  std::stringstream perci;
  if (!description)
    return "\b";
  perci << "Description of weather is: " << data << "\n";
  return perci.str();
}

std::string Impl::get_humidity(float data){
  std::stringstream humid;
  if(!humidity) return "\b";
  humid <<"Humidity Today is: " << data << "%\n";
  return humid.str();
}


void Impl::toString() {

  std::stringstream result;
  result << "Found the weather!\n" << get_format(90.0);
  result << get_description("cloudy");
  result << get_humidity(99.9);

  std::cout << result.str();
}


