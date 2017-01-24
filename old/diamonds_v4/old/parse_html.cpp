#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

int main ()
{
  int count = 0;
  std::ifstream infile("5_all_html.txt");
  std::ofstream outfile;
  outfile.open("5_rolls.txt");
  std::string line;
  while (std::getline(infile, line))
  {
    if (line.find("<!--") != std::string::npos)
    {
      std::getline(infile, line);
      if (line.find("href") == std::string::npos) 
      {
        line = line.substr(8, 5);
        //std::cout << count << ":" << line << std::endl;
        outfile << line << std::endl;
        count++;
      }
    }
  }
  outfile.close();
  return 0;
}





