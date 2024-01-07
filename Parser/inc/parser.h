
#ifndef PARSER_H
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>
namespace pt = boost::property_tree;

class Parser
{
  private:
  pt::ptree *root;

  public:
  Parser(std::stringstream);

};

#endif // !v
