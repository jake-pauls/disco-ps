#include "./api/components/AppComponent.hpp"
#include "./api/controller/AppController.hpp"
#include "./bot/BotClient.hpp"

#include "oatpp/network/Server.hpp"
#include "dotenv.h" 

#include <iostream>
#include <thread>

void serverRun() {
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

void botRun() {
    BotClient client(dotenv::env["BOT_TOKEN"], SleepyDiscord::USER_CONTROLED_THREADS);
    client.setIntents(SleepyDiscord::Intent::SERVER_MESSAGES);
    client.run();
}

int main(int argc, const char * argv[]) {
    dotenv::env.load_dotenv();
    std::cout << "[dotenv] Environment loaded successfully" << std::endl;

    // Initialize and destroy oat environment
    oatpp::base::Environment::init();

    // Run the server and bot on separate threads 
    std::thread server(serverRun);
    std::thread bot(botRun);
    server.join();
    bot.join();

    oatpp::base::Environment::destroy();

    return 0;
}
