#include <fstream>
#include <map>
#include <string>

class Properties
{
public:
    Properties(const std::string &fileName)
    {
        std::ifstream file(fileName);
        if (file.is_open())
        {
            std::string line;
            while (std::getline(file, line))
            {
                std::size_t delimiterPos = line.find('=');
                if (delimiterPos != std::string::npos)
                {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 1);
                    values[key] = value;
                }
            }
        }
    }

    std::string getValue(const std::string &key) const
    {
        auto it = values.find(key);
        if (it != values.end())
        {
            return it->second;
        }
        return "";
    }

private:
    std::map<std::string, std::string> values;
};