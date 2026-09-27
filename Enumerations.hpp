//        .___         .___.__               __             .___                                               _______________   ________  ________
//      __| _/____   __| _/|__| ____ _____ _/  |_  ____   __| _/______ ______________  __ ___________          \_____  \   _  \  \_____  \/  _____/
//     / __ |/ __ \ / __ | |  |/ ___\\__  \\   __\/ __ \ / __ |/  ___// __ \_  __ \  \/ // __ \_  __ \  ______  /  ____/  /_\  \  /  ____/   __  \ 
//    / /_/ \  ___// /_/ | |  \  \___ / __ \|  | \  ___// /_/ |\___ \\  ___/|  | \/\   /\  ___/|  | \/ /_____/ /       \  \_/   \/       \  |__\  \
//    \____ |\___  >____ | |__|\___  >____  /__|  \___  >____ /____  >\___  >__|    \_/  \___  >__|            \_______ \_____  /\_______ \_____  /
//         \/    \/     \/         \/     \/          \/     \/    \/     \/                 \/                        \/     \/         \/     \/ 






#define ENUMERATION enum

ENUMERATION ReasonForCalling : int {
	ATTACH = 1,
	DETACH = 0
};

ENUMERATION EGameStartFlags : __int32
{
	eGSF_NoLevelLoading = 0x1,
	eGSF_Server = 0x2,
	eGSF_Client = 0x4,
	eGSF_NoDelayedStart = 0x8,
	eGSF_BlockingClientConnect = 0x10,
	eGSF_NoGameRules = 0x20,
	eGSF_LocalOnly = 0x40,
	eGSF_NoQueries = 0x80,
	eGSF_NoSpawnPlayer = 0x100,
	eGSF_BlockingMapLoad = 0x200,
	eGSF_DemoRecorder = 0x400,
	eGSF_DemoPlayback = 0x800,
	eGSF_ImmersiveMultiplayer = 0x1000,
	eGSF_RequireController = 0x2000,
	eGSF_RequireKeyboardMouse = 0x4000,
	eGSF_HostMigrated = 0x8000,
	eGSF_NonBlockingConnect = 0x10000,
};

ENUMERATION EActorPhysProfiles
{
    eAPP_NotPhysicalized = 0x0,
    eAPP_Alive = 0x1,
    eAPP_Ragdoll = 0x2,
    eAPP_Spectator = 0x3,
};


ENUMERATION EEntityFlags : __int32
{
    ENTITY_FLAG_CASTSHADOW = 0x2,
    ENTITY_FLAG_UNREMOVABLE = 0x4,
    ENTITY_FLAG_GOOD_OCCLUDER = 0x8,
    ENTITY_FLAG_NO_DECALNODE_DECALS = 0x10,
    ENTITY_FLAG_WRITE_ONLY = 0x20,
    ENTITY_FLAG_NOT_REGISTER_IN_SECTORS = 0x40,
    ENTITY_FLAG_CALC_PHYSICS = 0x80,
    ENTITY_FLAG_CLIENT_ONLY = 0x100,
    ENTITY_FLAG_SERVER_ONLY = 0x200,
    ENTITY_FLAG_CUSTOM_VIEWDIST_RATIO = 0x400,
    ENTITY_FLAG_CALCBBOX_USEALL = 0x800,
    ENTITY_FLAG_VOLUME_SOUND = 0x1000,
    ENTITY_FLAG_HAS_AI = 0x2000,
    ENTITY_FLAG_TRIGGER_AREAS = 0x4000,
    ENTITY_FLAG_NO_SAVE = 0x8000,
    ENTITY_FLAG_CAMERA_SOURCE = 0x10000,
    ENTITY_FLAG_CLIENTSIDE_STATE = 0x20000,
    ENTITY_FLAG_SEND_RENDER_EVENT = 0x40000,
    ENTITY_FLAG_NO_PROXIMITY = 0x80000,
    ENTITY_FLAG_ON_RADAR = 0x100000,
    ENTITY_FLAG_UPDATE_HIDDEN = 0x200000,
    ENTITY_FLAG_NEVER_NETWORK_STATIC = 0x400000,
    ENTITY_FLAG_IGNORE_PHYSICS_UPDATE = 0x800000,
    ENTITY_FLAG_SPAWNED = 0x1000000,
    ENTITY_FLAG_SLOTS_CHANGED = 0x2000000,
    ENTITY_FLAG_MODIFIED_BY_PHYSICS = 0x4000000,
    ENTITY_FLAG_OUTDOORONLY = 0x8000000,
    ENTITY_FLAG_SEND_NOT_SEEN_TIMEOUT = 0x10000000,
    ENTITY_FLAG_RECVWIND = 0x20000000,
    ENTITY_FLAG_LOCAL_PLAYER = 0x40000000,
    ENTITY_FLAG_AI_HIDEABLE = 0x80000000,
};


ENUMERATION EConnectionState : __int32
{
	ECS_Disconnected = 0x0,
	ECS_WaitingForCredentials = 0x1,
	ECS_WaitingForConnection = 0x2,
	ECS_WaitingForDisconnect = 0x3,
	ECS_Connected = 0x4,
};

void WriteMemory(void* adress, LPCVOID lpBuffer, int len) {
	DWORD oldProtect = 0;

	VirtualProtect(adress, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(GetCurrentProcess(), adress, lpBuffer, len, NULL);
	VirtualProtect(adress, len, oldProtect, NULL);
}
