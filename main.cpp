#include <fstream>
#include <iostream>
#include "inc/user_input.h"
#include "inc/parser.h"
#include "inc/services.h"
#include <memory>
using namespace std;
using json = nlohmann::json;
// we are goin to use functional programming with a bit of oop

int main()
{

    string city;

    getline(cin, city);
    shared_ptr<UserInput> input = make_shared<UserInput>(city);

    shared_ptr<Curl_handler> handler = make_shared<Curl_handler>(input);
    shared_ptr<output_handler> output = make_shared<output_handler>();
    try
    {
        cout << output->parse(handler->get_request()) << endl;
    }
    catch (std::runtime_error &e)
    {
        cerr << e.what() << endl;
    }
}
/*
 [√] ask user for city
 [√] validate string from user
 [ ] compact string for sending it over json
 [ ] send json string along with api key to server
 [ ] parse json for result
 [ ] display user the results from the json
*/
