#include "WebServer.h"

#include <vector>
#include <string>
#include <sstream>


namespace Monocle
{
    WebServer::WebServer(int port)
    {
        // Build options array to start webserver
        std::vector<std::string> options;
        std::stringstream str;
        options.push_back("listening_ports");
        str << port;
        options.push_back(str.str());
        
        const char** optionsArray = new const char*[options.size() + 1];
        int i;
        for (i = 0; i < options.size(); i++)
            optionsArray[i] = options[i].c_str();
        optionsArray[i] = NULL;
        
        // Start webserver
        context = mg_start(&callback, NULL, optionsArray);
    }


    WebServer::~WebServer()
    {
        mg_stop(context);
    }


    void* WebServer::callback(mg_event event, mg_connection *conn, const mg_request_info* request_info)
    {
        if (event == MG_NEW_REQUEST)
        {
            // Echo requested URI back to the client
            mg_printf(conn, "HTTP/1.1 200 OK\r\n"
                      "Content-Type: text/plain\r\n\r\n"
                      "%s", request_info->uri);
            return const_cast<char*>("");
        }
        return NULL;
    }
}
