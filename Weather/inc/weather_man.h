#include <memory>
#include <sstream>

#ifndef WEATHER_H
#define WEATHER_H
// Copyright (c) 2024 Mateo Ortega
// SPDX-License-Identifier: MIT
#include <iostream>

#pragma once
enum TemperatureFormat { celcius = 0, fahrenheit = 1 };

class Impl {
private:
  friend class WeatherMan;
  std::string w_city;
  TemperatureFormat temperature{TemperatureFormat::fahrenheit};
  bool description{false};
  bool humidity{false};
  Impl(std::string city) : w_city{city} {}
  std::string get_format(float);
  std::string get_description(std::string );
  std::string get_humidity(float );
public:
  std::string show_city() const { return w_city; }
  void select(int) const {}
  void toString();
};

class WeatherMan {

private:
  std::unique_ptr<Impl> mImpl;

public:
  WeatherMan(std::string city);
  std::unique_ptr<Impl> build();
  WeatherMan &withCelcius();
  WeatherMan &withDescription();
  WeatherMan &withHumidity();
};

#endif // !WEATHER_H
