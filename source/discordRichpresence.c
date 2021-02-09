#include "discord_game_sdk.h"

typedef void* IDiscordCoreEvents;

int main()
{
    struct Application {
        struct IDiscordCore* core;
        struct IDiscordUsers* users;
    };
    
    struct Application app;
    // Don't forget to memset or otherwise initialize your classes!
    memset(&app, 0, sizeof(app));
    
    IDiscordCoreEvents events;
    memset(&events, 0, 8);
    
    struct DiscordCreateParams params;
    DiscordCreateParamsSetDefault(&params);
    params.client_id = 808412626391662592;
    params.flags = DiscordCreateFlags_Default;
    params.events = &events;
    params.event_data = &app;
    
    DiscordCreate(DISCORD_VERSION, &params, &app.core);
    
}
