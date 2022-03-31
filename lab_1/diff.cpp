
#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

int line = 1;
std::string str1, str2;

int main(int argc, char* argv[])
{
    assert(argc == 3);

    std::ifstream file1(argv[1]);
    std::ifstream file2(argv[2]);

    while (!file1.eof() || !file2.eof())
      {
          getline(file1, str1);
          getline(file2, str2);

          if (str1 != str2)
            {
              int bar = ((std::to_string(line).length()) + strlen(argv[1]) + 4);

              std::cout << argv[1] << ": " << line << ": " << str1 << std::endl;
              std::cout << argv[2] << ": " << line << ": " << str2 << std::endl;

              for (int i = 0; i < bar; ++i)
                  std::cout << " ";


              for (int i = 0; str1[i] == str2[i]; ++i)
                  std::cout << " ";


              std::cout << "^" << std::endl;
          }

          line++;
       }
     return 0;
}
