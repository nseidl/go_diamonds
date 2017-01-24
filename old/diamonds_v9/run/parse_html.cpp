#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

int main (int argc, char *argv[])
{
  std::string seed_num = argv[1];
  int count = 0;
  std::ifstream infile("../data/html/" + seed_num + "_all_html.txt");
  std::ofstream outfile;
  outfile.open("../data/rolls/" + seed_num + "_rolls.txt");
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





