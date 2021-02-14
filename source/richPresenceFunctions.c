#include <stdio.h>
#include "discord_game_sdk.h"

struct Application {
 struct IDiscordCore* core;
 struct IDiscordUsers* users; 
};


typedef void* IDiscordCoreEvents;
typedef void (*callback)(void* callback_data, enum EDiscordResult result);


void update_presence(struct IDiscordActivityManager* activity_manager, struct Application app, callback callback_presence)
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
    char large_image[] = "weeb_thing";
    char small_text[] = "happy lunar new year"; 
    char small_image[] = "oxething";

    strncpy(activity.state, state, sizeof(activity.state));
    strncpy(activity.details, details, sizeof(activity.details));
    activity.timestamps.start = start; 
    strncpy(activity.assets.large_text, large_text, sizeof(activity.assets.large_text)); 
    strncpy(activity.assets.large_image, large_image, sizeof(activity.assets.large_image));
    strncpy(activity.assets.small_text, small_text, sizeof(activity.assets.small_text)); 
    strncpy(activity.assets.small_image, small_image, sizeof(activity.assets.small_image));

    activity_manager -> update_activity(activity_manager, &activity,app.core,callback_presence);
}


