#include "json/single_include/nlohmann/json.hpp"
#include <memory>
#include <string>
using json = nlohmann::json;
class output_handler
{
private:
    std::unique_ptr<json> data = std::make_unique<json>();
    auto k_to_f(const std::string &kelvin)
    {
        float K = std::stof(kelvin);
        return std::to_string(((K - 273.15) * (1.8)) + 32.0);
    }

public:
    output_handler()
    {
        std::cout << "parsing json" << std::endl;
    }

    ~output_handler()
    {
        std::cout << "json parsed" << std::endl;
    }

    auto parse(const std::string curl_data)
    {
        auto parser = data->parse(curl_data);

        std::string weather = "The current weather is:" + parser["weather"]["description"].dump() + "\n";
        std::string humidity = "The current humidity is:" + parser["main"]["humidity"].dump() + "\n";
        // std::string feel_like = "Feels Like:" + k_to_f(parser["main"]["feels_like"].dump());
        // std::string degrees = "Actual Temperature:" + k_to_f(parser["wind"]["deg"].dump());
        std::cout << humidity << weather << std::endl;
        return "fadawda";
    }
};
