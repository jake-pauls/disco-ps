#include "./AppComponent.hpp"
#include "./controller/AppController.hpp"

#include "oatpp/network/Server.hpp"

#include <iostream>

void run() {
    AppComponent components;

    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    // Create a controller and append all endpoints
    auto appController = std::make_shared<AppController>();
    appController->addEndpointsToRouter(router); 

    // Inistalize handler and provider
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);
    
    // Launch server
    oatpp::network::Server server(connectionProvider, connectionHandler);
    OATPP_LOGI("DISCO-PS-CORE", "Server running on port %s", connectionProvider->getProperty("port").getData());
    server.run();
}

int main(int argc, const char * argv[]) {
    oatpp::base::Environment::init();

    run(); 

    std::cout << "\nEnvironment:\n" << std::endl;
    std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n" << std::endl;
    std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n" << std::endl;

    oatpp::base::Environment::destroy();

    return 0;
}
