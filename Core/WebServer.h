#pragma once

#include <cstddef>
#include <mongoose/mongoose.h>


namespace Monocle
{
    class WebServer
    {
    public:
        WebServer(int port = 8080);
        ~WebServer();
        
    protected:
        mg_context* context;

        
        static void* callback(mg_event event, mg_connection *conn, const mg_request_info* request_info);
    };
}
