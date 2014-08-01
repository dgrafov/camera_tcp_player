#ifndef CONFIG_MANAGER_H_
#define CONFIG_MANAGER_H_

#include <string>

#include "tinyxml2/tinyxml2.h"

class ConfigManager {
public: 
    ConfigManager();
    std::string getHost() const;
    int getPort() const;
    std::string getVideodev() const;
    int getHeight() const;
    int getWidth() const;
    int loadConfig(const std::string & filename);
private:
    std::string host;
    int port;
    std::string videodev;
    int height;
    int width;
};

void printConfig(const ConfigManager &);


#endif
