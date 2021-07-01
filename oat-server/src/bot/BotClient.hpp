#ifndef BotClient_hpp
#define BotClient_hpp

#include "sleepy_discord/sleepy_discord.h"

#include <iostream>

class BotClient : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
    void onMessage(SleepyDiscord::Message message) override {
        std::cout << "[onMessage]: Triggered Hello WebSocket." << std::endl;
        if (message.startsWith("whcg hello"))
            sendMessage(message.channelID, "Hello " + message.author.username);
    }
}; 

#endif /* BotClient_hpp */