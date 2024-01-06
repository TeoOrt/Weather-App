#ifndef HANDLER_H
#define HANDLER_H

#include <sstream>
#include <weather_man.h>
#include <curlp_pp.h>

class Handler {


private:
  const std::string URL = "http://api.openweathermap.org/data/2.5/weather?q=";
  const std::string API_KEY = "&appid=";
  std::string key_;//get it from the env
  std::stringstream final_string;
  CURLplusplus* client;
  void build_api_string(const std::string&);
public:
  Handler(const std::unique_ptr<Impl>&, std::string);
  std::string get_request();
  ~Handler();

};

#endif // !HANDLER_H
