

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>
#include <parser.h>



Parser::Parser(std::stringstream data)
{
  root = new pt::ptree();
  pt::ptree read_json(data,root)
  delete root;

}

