#include <memory>

#ifndef WEATHER_H
#define WEATHER_H
// Copyright (c) 2024 Mateo Ortega
// SPDX-License-Identifier: MIT
#include <iostream>

#pragma once
enum TemperatureFormat
{
  celcius = 0,
  fahrenheit = 1
};




class Impl
{
private:
  friend class WeatherMan;
  std::string w_city;
  TemperatureFormat temperature{ TemperatureFormat::fahrenheit };
  bool percipitation{ false };
  bool humidity{ false };
  Impl(std::string city) : w_city{ city } {}
public:
  std::string show_city() const {
    return  w_city;
  }
  void select(int)const {}
};




class WeatherMan
{

private:
  std::unique_ptr<Impl> mImpl;

public:


  WeatherMan(std::string city);
  std::unique_ptr<Impl> build();
  WeatherMan& withCelcius();
  WeatherMan& withPrecipitation();
  WeatherMan& withHumidity();

};




#endif // !WEATHER_H
