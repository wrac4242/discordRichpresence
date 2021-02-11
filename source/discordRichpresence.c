#include "discord_game_sdk.h"
#include <stdio.h> 
#include <stdbool.h> 
#include <unistd.h>
#include <string.h> 

typedef void* IDiscordCoreEvents;
typedef void (*callback)(void* callback_data, enum EDiscordResult result);
struct Application {
    struct IDiscordCore* core;
    struct IDiscordUsers* users; 
};

void update_presence(struct IDiscordActivityManager* activity_manager, struct Application app);
void callback_func(void* callback_data, enum EDiscordResult result);

int status = 0;

int main()
{
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
    if (activity_manager == NULL){
        printf("activity manager not properly initialized\n");
        return 1;
    }
    //setup loop
    while (running == true){ 
        sleep(5);//waits for 5s before updating again
        //update discord, and exit codes
        printf("Updating presence\n");

        update_presence(activity_manager,app);
        enum EDiscordResult result = app.core->run_callbacks(app.core);
        if (result !=DiscordResult_Ok) {  
            printf("error code:%d", result);
            running = false;
        }
        if (status !=0){
            printf("error, status:%d", status);
            running = false; 
        }
    }
    //checks for updates every 0.5s, updates discord side
    //checks if it should exit
    //
    //after loop exits, runs proper exiting code
    //
}

void update_presence(struct IDiscordActivityManager* activity_manager, struct Application app)
{
    //generates richpresents
    //sets it to the values needed
    //updates the presence
    struct DiscordActivity activity;
    memset(&activity, 0, sizeof(activity));

    char state[] = "How to exit vim";
    char details[] = "big potato man"; 
    DiscordTimestamp start = 666;
    char large_text[] = "fishes";
    
    strncpy(activity.state, state, sizeof(activity.state));
    strncpy(activity.details, details, sizeof(activity.details));
    activity.timestamps.start = start; 
    strncpy(activity.assets.large_text, large_text, sizeof(activity.assets.large_text)); 

    callback callback_presence = &callback_func;
    activity_manager -> update_activity(activity_manager, &activity,app.core,callback_presence);
}

void callback_func(void* callback_data, enum EDiscordResult result)
{
    if (result != DiscordResult_Ok){
        printf("error code:%d", result);
        status = 1;
    }
}
