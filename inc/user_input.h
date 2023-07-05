#include <string>
#include <stdexcept>

#include <algorithm>
// get user input
// first step lets get a string from user,
// parse the string and ID a city
//
// Feed it back to api

class UserInput
{

private:
	std::string city;

public:
	UserInput(const std::string &city)
	{
		set_input(city);
	};

	~UserInput()
	{
		std::cout << "User Input destroyed" << std::endl;
	};

	void set_input(const std::string &city_input)
	{
		if (city_input.length() < 3)
		{
			throw std::length_error("City name is too small try again \n");
		}
		city = city_input;
	};

	// preparing for we coding
	auto encode_city()
	{

		std::replace(city.begin(), city.end(), ' ', '+');
	}
	// turn this into a json string, and make it easy to parse
	auto get_input()
	{
		encode_city();
		return city;
	};
};
