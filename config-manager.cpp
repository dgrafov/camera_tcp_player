#include <stdlib.h>

#include "config-manager.h"
#include "debug/debug.h"

using namespace tinyxml2;
using namespace std;

ConfigManager::ConfigManager():
    host("127.0.0.1"),
    port(5000),
    videodev("/dev/video0"),
    height(480),
    width(640)
{}

string  ConfigManager::getHost() const {
    return host;
}
int ConfigManager::getPort() const {
    return port;
}
string ConfigManager::getVideodev() const {
    return videodev;
}
int ConfigManager::getHeight() const {
    return height;
}
int ConfigManager::getWidth() const {
    return width;
}

int ConfigManager::loadConfig(const string & filename) {
    XMLDocument doc;
    doc.LoadFile(filename.c_str());
    if(doc.ErrorID() != 0) {
        DEBUG_PRINT(DL_ERROR, "Can't open file %s. Default config values \
                will be used\n", filename.c_str());
    }
    else {
        XMLElement* elem = doc.FirstChildElement("host");
        if(elem) {
            host = string(elem->GetText());
        }
        else {
            DEBUG_PRINT(DL_ERROR, "No host information in config file %s",
                    filename.c_str());
        }

        elem = doc.FirstChildElement("port");
        if(elem) {
            port = atoi(elem->GetText());
        }
        else {
            DEBUG_PRINT(DL_ERROR, "No port information in config file %s",
                    filename.c_str());
        }
        
        elem = doc.FirstChildElement("videodev");
        if(elem) {
            videodev = string(elem->GetText());
        }
        else {
            DEBUG_PRINT(DL_ERROR, "No videodev information in config \
                    file %s", filename.c_str());
        }

        elem = doc.FirstChildElement("width");
        if(elem) {
            width = atoi(elem->GetText());
        }
        else {
            DEBUG_PRINT(DL_ERROR, "No width information in config file %s",
                    filename.c_str());
        }

        elem = doc.FirstChildElement("height");
        if(elem) {
            height = atoi(elem->GetText());
        }
        else {
            DEBUG_PRINT(DL_ERROR, "No height information in config \
                    file %s", filename.c_str());
        }
    }
    printConfig(*this);
    return doc.ErrorID();
}

void printConfig(const ConfigManager & cm) {
    DEBUG_PRINT(DL_INFO, "Config values:\n");
    DEBUG_PRINT(DL_INFO, "Host: %s:%d\n", cm.getHost().c_str(), cm.getPort());
    DEBUG_PRINT(DL_INFO, "Video device: %s\n", cm.getVideodev().c_str());
    DEBUG_PRINT(DL_INFO, "Resolution: %dx%d\n", cm.getWidth(),
            cm.getHeight());
}

