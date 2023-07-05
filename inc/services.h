#include "curlp_pp.h"
#include <memory>
class Curl_handler
{

private:
    std::shared_ptr<UserInput> user_input;
    const std::string URL = "http://api.openweathermap.org/data/2.5/weather?q=";
    const std::string API_KEY = "&appid=";
    const std::string KEY = "372502867223ae6258cd8efd9c3d2602";
    std::string final;
    std::unique_ptr<CURLplusplus> client = std::make_unique<CURLplusplus>();
    auto build_api_string()
    {
        final = URL + user_input->get_input() + API_KEY + KEY;
    };

public:
    Curl_handler(std::shared_ptr<UserInput> &user_input) : user_input(user_input)
    {

        std::cout << "Searching for weather in the area asked for ..." << std::endl;
        // start building the string
        build_api_string();
    };

    ~Curl_handler()
    {
        std::cout << "Finished the searches" << std::endl;
    };

    auto get_request()
    {

        return client->Get(final);
    }
};
