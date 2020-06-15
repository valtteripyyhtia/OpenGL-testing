#ifndef APP_CONFIGURATION_H_
#define APP_CONFIGURATION_H_

#include <spdlog/spdlog.h>

#include <boost/property_tree/json_parser.hpp>
#include <string>

typedef struct {
    std::string name;
    uint width = 800;
    uint height = 600;
} configuration;

class AppConfiguration {
   private:
    configuration conf;
    void resolveWindowConfig(boost::property_tree::ptree json);
    void resolveName(boost::property_tree::ptree json);

   public:
    void loadConfiguration(std::string configFile);
    const configuration getConfig();
};

#endif