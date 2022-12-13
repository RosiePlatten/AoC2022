#pragma once
#include <string>
#include<vector>

class PacketPair {
public:
  PacketPair(std::string left, std::string right);
  bool inOrder() const;

  private:

	  std::vector<std::string> processString(std::string str) const;

	 std::string m_leftString;
	 std::string m_rightString;
};