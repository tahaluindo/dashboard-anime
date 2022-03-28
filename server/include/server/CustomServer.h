#include <WiFi.h>
#include "ESPAsyncWebServer.h"
#include "json/UserSerializer.h"
#include "repository/UserService.h"
#include "log/Log.h"
#include "utils/Utils.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "rfid/RFID.h"
#include "mutex/mutex.h"

#ifndef CUSTOM_SERVER_H
#define CUSTOM_SERVER_H

class CustomServer : public Log {
  public:
    CustomServer(const char *apSsid, const char *apPassword);
    void init();
  private:
    const char *apSsid;
    const char *apPassword;
    IPAddress ip;
    void createAccessPoint();
    void serveStatic();
    void createRoutes();
    void begin();
    void serverLog(std::string method, std::string uri);
    void notFoundHandler(AsyncWebServerRequest *request);
    void createUserHandler(AsyncWebServerRequest *request);
    void getUserHandler(AsyncWebServerRequest *request);
    void updateUserHandler(AsyncWebServerRequest *request);
    void deleteUserHandler(AsyncWebServerRequest *request);
    void optionsHandler(AsyncWebServerRequest *request);
    std::string getPathParam(std::string root, std::string url);
    int hasPathParam(std::string root, std::string url);
};

#endif