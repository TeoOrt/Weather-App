#include <handler.h>
#include <sstream>
#include <weather_man.h>
#include <curlp_pp.h>



Handler::Handler(const std::unique_ptr<Impl>& weather_man, std::string key) {
    const std::string city = weather_man->show_city();
    key_ = key;
    build_api_string(city);
}


Handler::~Handler() {
    delete client;
}

void Handler::build_api_string(const std::string& city) {
    final_string << URL << city << API_KEY << key_;
}

std::string Handler::get_request() {
    client = new CURLplusplus();
    return client->Get(final_string.str());
}

