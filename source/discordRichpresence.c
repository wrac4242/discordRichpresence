#include "discord_game_sdk.h"
#include <stdio.h> 
#include <stdbool.h> 
#include <unistd.h>

typedef void* IDiscordCoreEvents;
void update_presence(struct IDiscordActivityManager* activity_manager);

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
    
    printf("Discord presence app started successfully\n");
    bool running = true;
    
    //creates activity manager
    struct IDiscordActivityManager* activity_manager = app.core -> get_activity_manager(app.core);  

    //setup loop
    while (running == true){ 
        sleep(5);//waits for 5s before updating again
        //update discord, and exit codes
        update_presence(activity_manager);
        enum EDiscordResult result = app.core->run_callbacks(app.core);
        if (result !=DiscordResult_Ok) {  
            printf("error code:%d", result);
            running = false;
        }
    }
    //checks for updates every 0.5s, updates discord side
    //checks if it should exit
    //
    //after loop exits, runs proper exiting code
    //
}

void update_presence(struct IDiscordActivityManager* activity_manager)
{
    //generates richpresents
    //sets it to the values needed
    //updates the presence 
}
