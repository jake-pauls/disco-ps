#include "./api/components/AppComponent.hpp"
#include "./api/controller/AppController.hpp"
#include "./bot/BotClient.hpp"

#include "oatpp/network/Server.hpp"
#include "dotenv.h" 

#include <iostream>
#include <thread>

void loadEnvFile() {
    dotenv::env.load_dotenv();
    std::cout << "[dotenv] Environment loaded successfully" << std::endl;
}

void serverRun() {
    // Create scoped environment components
    AppComponent components;

    // Create a controller and append all endpoints
    auto router = components.httpRouter.getObject();
    auto appController = AppController::createShared();
    appController->addEndpointsToRouter(router); 

    // Initialize handler and provider
    auto connectionProvider = components.serverConnectionProvider.getObject();
    auto connectionHandler = components.serverConnectionHandler.getObject();
    oatpp::network::Server server(connectionProvider, connectionHandler); 

    OATPP_LOGI("DISCO-PS-CORE", " Server running on port %s ", connectionProvider->getProperty("port").getData());
    server.run();
}

void botRun() {
    BotClient client(dotenv::env["BOT_TOKEN"], SleepyDiscord::USER_CONTROLED_THREADS);
    client.setIntents(SleepyDiscord::Intent::SERVER_MESSAGES);
    client.run();
}

int main(int argc, const char * argv[]) {
    loadEnvFile();

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
