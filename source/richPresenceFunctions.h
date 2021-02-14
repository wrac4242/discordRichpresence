struct Application {
 struct IDiscordCore* core;
 struct IDiscordUsers* users; 
};

typedef void* IDiscordCoreEvents;
typedef void (*callback)(void* callback_data, enum EDiscordResult result);

void update_presence(struct IDiscordActivityManager* activity_manager, struct Application app, callback callback_presence);
