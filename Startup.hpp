//ñäåëàé êàê ó òàí÷èêîâ
//        .___         .___.__               __             .___                                               _______________   ________  ________
//      __| _/____   __| _/|__| ____ _____ _/  |_  ____   __| _/______ ______________  __ ___________          \_____  \   _  \  \_____  \/  _____/
//     / __ |/ __ \ / __ | |  |/ ___\\__  \\   __\/ __ \ / __ |/  ___// __ \_  __ \  \/ // __ \_  __ \  ______  /  ____/  /_\  \  /  ____/   __  \ 
//    / /_/ \  ___// /_/ | |  \  \___ / __ \|  | \  ___// /_/ |\___ \\  ___/|  | \/\   /\  ___/|  | \/ /_____/ /       \  \_/   \/       \  |__\  \
//    \____ |\___  >____ | |__|\___  >____  /__|  \___  >____ /____  >\___  >__|    \_/  \___  >__|            \_______ \_____  /\_______ \_____  /
//         \/    \/     \/         \/     \/          \/     \/    \/     \/                 \/                        \/     \/         \/     \/ 







#define _CRT_SECURE_NO_WARNINGS

#include <set>
#include <random>
#include <map>

typedef char(__fastcall* Cert)();
Cert CCertificateValidator__Query_p = (Cert)0x1417E7290;

__int64 __fastcall CCertificateValidator__Query(void* this1, void* remoteCert)
{
	return 1;
}

bool IsGame, IsPreMatch = false;

bool m_pSessionRewards = false;

typedef void* (__fastcall* operator_newClass)(size_t Size);
operator_newClass operator_new = (operator_newClass)0x140079FF0;

typedef __int64(__fastcall* fixSub_0x)(/* args null nothing */);
fixSub_0x fixSub_p;
typedef __int64(__fastcall* fixMetrics_0x)(/* args null nothing */);
fixMetrics_0x fixMetrics_p;
typedef __int64(__fastcall* fixMetrics_0x2)(/* args null nothing */);
fixMetrics_0x2 fixMetrics2_p;

typedef void*(__fastcall* CGameStartupClass)(void* this1, void* a2, SSystemInitParams* startupParams);
CGameStartupClass CGameStartup_Init_p = (CGameStartupClass)0x1400BD530;

void on_terminate() {
    std::cerr << "std::terminate called\n";
    if (auto ep = std::current_exception()) {
        try {
            std::rethrow_exception(ep);
        }
        catch (const std::exception& e) {
            std::cerr << "Unhandled exception: " << e.what() << "\n";
        }
        catch (...) {
            std::cerr << "Unhandled non-std exception\n";
        }
    }
    std::abort();
}

void* __fastcall CGameStartup_InitMethod(void* this1, void* a2, SSystemInitParams* startupParams)
{
    //startupParams->bSkipRenderer = TRUE;
    startupParams->m_pDedicatedServer = TRUE;
   // startupParams->bUIFramework = FALSE;
    //startupParams->bSkipRenderer = TRUE;

	return CGameStartup_Init_p(this1, a2, startupParams);
}

__int64 __fastcall fixMetrics() {
    return 0;
}

char __fastcall sub_1414E0B70()
{
    /*  v1 = (*(__int64 (__fastcall **)(_QWORD, __int64, _QWORD))(**(_QWORD **)qword_142B48ED0 + 80i64))(
         *(_QWORD *)qword_142B48ED0,
         56i64,
         0i64);
  v2 = v1;
  */
    return 1;// *(__int64*)0x142AE1AB8;
}

namespace Console {
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <set>
#include <random>
#include <map>
    using namespace std;
    void CreateConsole() {
        int hConHandle = 0;
        HANDLE lStdHandle = 0;
        FILE* fp = 0;
        AllocConsole();
        freopen("CON", "w", stdout);
        SetConsoleTitle("DedicatedServer");
        lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
        fp = _fdopen(hConHandle, "w");
        *stdout = *fp;
        setvbuf(stdout, NULL, _IONBF, 0);
    }
}

typedef __int64(__fastcall* ResourceParticleParamsClass)(void* a1, __int64 a2);
ResourceParticleParamsClass ResourceParticleParams__LoadResources_p = (ResourceParticleParamsClass)0x141B95E70;

void __fastcall FlareItem(void* a1, __int64 a2)
{


    return; /*ResourceParticleParams__LoadResources_p(a1, a2)*/
}

void PrepareMetrics() {
    WriteMemory((void*)0x14087E87D, "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90",10);
}

void InitPatches() {
    WriteMemory((void*)0x000000014143C789, "\x0F\x85", 2); // GameCvars->SysRenderer
    WriteMemory((void*)0x14143CD24, "\x0F\x85", 2); // CryInput.DLL -> Not Found
    WriteMemory((void*)0x00000001400A754F, "\x90\x90\x90", 3); // CGameOptions::CGameOptions(init)
    WriteMemory((void*)0x140654450, "\xEB", 1); // ui_precache_textures
    WriteMemory((void*)0x1406546AC, "\x90\x90\x90", 3); // ui_select_resolutionCVar
    WriteMemory((void*)0x1400A7631, "\xEB", 1); // CFlowChartManager::CFlowChartManager
    WriteMemory((void*)0x1400A7651, "\xEB", 1); // CFlowChartManager::CFlowChartManager
    WriteMemory((void*)0x1400A7664, "\x90\x90\x90\x90\x90", 5); // CFlowChartManager::Init
    WriteMemory((void*)0x1400A7674, "\x90\x90\x90\x90\x90", 5); // CFlowChartManager::Register
    //WriteMemory((void*)0x1404DEB28, "\xEB", 1); // Metrics (Danger!)
    //WriteMemory((void*)0x1404DEB3C, "\x90\x90\x90\x90\x90", 5); // Metrics
      //  WriteMemory((void*)0x1404DEB6B, "\x90\x90\x90\x90\x90", 5); // Metrics
    WriteMemory((void*)0x14141F4D9, "\xEB", 1); // UpdatePhysicalizedAttachment
    //WriteMemory((void*)0x140545608, "\xEB", 1); // SendClientInfoStats
    WriteMemory((void*)0x14054841B, "\x90\x90\x90\x90\x90\x90", 6); // SendClientInfoStats gEnv->pRenderer
    WriteMemory((void*)0x0000000141A542A9, "\xB1\x00", 2); // ParticleEffect
    WriteMemory((void*)0x0000000141498F39, "\xEB", 1); // CRenderer->FullDisableRender
    
    PrepareMetrics();
    
    


}

typedef char (__fastcall* CGameInitClass)(CGame* this1, IGameFramework* pFramework);
CGameInitClass CGame_Init_p = (CGameInitClass)0x1400A6940;

//typedef CBackend* (__fastcall* CBackend_CBackendClass)(CBackend* this1, IGameFramework* fw);
//CBackend_CBackendClass CBackend_CBackend = (CBackend_CBackendClass)0x14010B850;

typedef void(__fastcall* FSLobbyServerInfo_SerializeAllToXml_p)(SLobbyServerInfo*, XmlNodeRef*);
FSLobbyServerInfo_SerializeAllToXml_p SLobbyServerInfo_SerializeAllToXml_p = (FSLobbyServerInfo_SerializeAllToXml_p)0x140952510;

void __fastcall SLobbyServerInfo_SerializeAllToXml(SLobbyServerInfo* this1, XmlNodeRef* outNode) {
    outNode->p->setAttr("forward_receiver_id", SSystemGlobalEnvironment::Singleton()->GetIConsole()->GetCVar("forward_receiver_id")->GetString());
    return SLobbyServerInfo_SerializeAllToXml_p(this1, outNode);
}



int InitializationCVarsPort() {
    const int minValue = 55520;
    const int maxValue = 65500;



    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);


    std::set<int> generatedNumbers;


    for (int i = 0; i < 10; ++i) {
        int randomNum;
        do {
            randomNum = dis(gen);
        } while (generatedNumbers.count(randomNum));

        generatedNumbers.insert(randomNum);
        return randomNum;
    }
    return 0;
}


char __fastcall CGame_Init(CGame* this1, IGameFramework* pFramework) {
    char result = CGame_Init_p(this1, pFramework);
    auto gEnv = SSystemGlobalEnvironment::Singleton();
    auto pCvars = SCVars::Singlenton();
    auto pSystem = gEnv->GetCSystem();

    if (strstr(GetCommandLineA(), "-dedicated"))
    {
        if (gEnv) {
            auto pConsole = gEnv->GetIConsole();
            pCvars->online_dedicated_host_name = pConsole->RegisterString("online_dedicated_host_name", "26.158.115.175", 1, "", 0);
            pCvars->online_dedicated_perf_idx_cpu = pConsole->RegisterString("online_dedicated_host_name", "25.0", 1, "", 0);
            pCvars->online_dedicated_perf_idx_memory = pConsole->RegisterString("online_dedicated_perf_idx_memory", "55.0", 1, "", 0);
            pCvars->online_dedicated_load_average = pConsole->RegisterString("online_dedicated_load_average", "35.0", 1, "", 0);
            pCvars->online_dedicated_autoshutdown_memory_limit = pConsole->RegisterString("online_dedicated_autoshutdown_memory_limit", "75.0", 1, "", 0);
            pCvars->online_dedicated_autoshutdown_wait_timeout = pConsole->RegisterString("online_dedicated_autoshutdown_wait_timeout", "20.0", 1, "", 0);
            pCvars->online_dedicated_autoshutdown_data_sent_wait_timeout = pConsole->RegisterString("online_dedicated_autoshutdown_data_sent_wait_timeout", "20.0", 1, "", 0);

            pCvars->e_CullVegActivation = 0;
                
            pConsole->ExecuteString("e_CullVegActivation 0", false, false);

            
            



           // pConsole->RegisterString("online_telemetry_streaming", "1", 0, "Init telemetry stream", 0);
           // pConsole->ExecuteString("online_telemetry_streaming 1", 0, 0);
            pConsole->RegisterString("forward_receiver_id", "main_pvp_pro_001", 0, "Custom line for initializing the setserver channel", 0);
            pConsole->ExecuteString("sv_cvars_hash_enable 0", false, false);
            pConsole->ExecuteString("g_cache_actorcc 0", false, false);
            pConsole->ExecuteString("g_metrics_enabled 0", false, false);
            pConsole->ExecuteString("g_character_manager_early_preload 0", false, false);
            pConsole->ExecuteString("g_enable_flashbang_mechanic 1", false, false);
            pConsole->ExecuteString("g_material_effects_early_preload 0", false, false);
            pConsole->ExecuteString("g_serverDfConeAngle 70", false, false);
            pConsole->ExecuteString("i_offset_front -0.01", false, false);
            pConsole->ExecuteString("i_offset_nearFOV 60", false, false);
            pConsole->ExecuteString("i_offset_up -0.01", false, false);
            pConsole->ExecuteString("pl_lerp_depth 0.084", false, false);
            pConsole->ExecuteString("g_wait_all_loaded_timeout 1", false, false);
            pConsole->ExecuteString("hud_invulnerability_vignette_alpha_step 2", false, false);
            pConsole->ExecuteString("g_coinInvulnerabilityTime 3", false, false);
            pConsole->ExecuteString("g_invulnerabilityTime 5", false, false);
            pConsole->ExecuteString("g_visualize_invulnerability 0", false, false);
            pConsole->ExecuteString("g_invulnerability_premature_interrupt_allow 0", false, false);
            pConsole->RegisterInt("net_mitigator_enabled", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("online_mitigator_enabled", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_pings_enabled", 1, 1, "Custom line for initializing the setserver channel", 0);



            pConsole->RegisterInt("cl_packetRate", 1, 1, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("sv_packetRate", 1, 1, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("net_packetsendrate", 1, 1, "Custom line for initializing the setserver channel", 0);

            pConsole->ExecuteString("pl_new_movement 1", false, false);
            pConsole->ExecuteString("online_mitigator_enabled 0", false, false);
            pConsole->ExecuteString("net_mitigator_enabled 0", false, false);
            pConsole->ExecuteString("g_anti_wallhack_pve_enabled 1", false, false);
            pConsole->ExecuteString("g_pings_enabled 1", false, false);
            pConsole->ExecuteString("g_ingame_metrics_cl_ping 1", false, false);
            pConsole->ExecuteString("g_ingame_ping_indicator_show_threshold 200", false, false);


            pConsole->RegisterInt("g_zoom_speed_multiplier", 1, 0, "Custom line for initializing the setserver channel", 0);

            pConsole->ExecuteString("g_zoom_speed_multiplier 0.9", false, false);
            pConsole->ExecuteString("g_bomb_drop_enabled 1", false, false);

            pConsole->ExecuteString("cl_packetRate 60", 0, 0);
            pConsole->ExecuteString("sv_packetRate 60", 0, 0);
            pConsole->ExecuteString("net_packetsendrate 60", 0, 0);

            ICVar* m_pCVar = pConsole->GetCVar("sv_packetRate");
            printf("m_pCVAR: %p\n", m_pCVar);


            pConsole->ExecuteString("g_watchdogEnabled 0", false, false);
            pConsole->ExecuteString("g_visibilityTimeout 0", false, false);
            pConsole->ExecuteString("g_visibilityTimeoutTime 30", false, false);
            pConsole->ExecuteString("es_UsePhysVisibilityChecks 20", false, false);
            pConsole->ExecuteString("ai_CoverSystem 1", false, false);
            pConsole->ExecuteString("cl_AISystem 1", false, false);
            pConsole->ExecuteString("sys_ai 1", false, false);
            pConsole->ExecuteString("ai_DrawFireEffectEnabled 1", false, false);
            pConsole->ExecuteString("ai_UseSmartPathFollower 1", false, false);
            pConsole->ExecuteString("ai_EnableGroupTargets 1", false, false);
            pConsole->ExecuteString("ai_TargetTracking 1", false, false);
            pConsole->ExecuteString("ai_CoverSystem 1", false, false);

            pConsole->ExecuteString("sv_cvars_hash_enable 0", false, false);
            pConsole->ExecuteString("g_cache_actorcc 0", false, false);
            pConsole->ExecuteString("g_metrics_enabled 0", false, false);
            pConsole->ExecuteString("g_character_manager_early_preload 0", false, false);
            pConsole->ExecuteString("g_enable_flashbang_mechanic 1", false, false);
            pConsole->ExecuteString("g_material_effects_early_preload 0", false, false);
            pConsole->ExecuteString("g_serverDfConeAngle 70", false, false);

            pConsole->ExecuteString("i_offset_front -0.01", false, false);
            pConsole->ExecuteString("i_offset_nearFOV 60", false, false);
            pConsole->ExecuteString("i_offset_up -0.01", false, false);
            pConsole->ExecuteString("pl_lerp_depth 0.084", false, false);
            pConsole->ExecuteString("g_wait_all_loaded_timeout 1", false, false);
            pConsole->ExecuteString("hud_invulnerability_vignette_alpha_step 2", false, false);
            pConsole->ExecuteString("g_coinInvulnerabilityTime 3", false, false);
            pConsole->ExecuteString("g_invulnerabilityTime 5", false, false);
            pConsole->ExecuteString("g_visualize_invulnerability 0", false, false);
            pConsole->ExecuteString("g_invulnerability_premature_interrupt_allow 0", false, false);

            pConsole->ExecuteString("ui_new_damage_report 0", false, false);
            //pConsole->ExecuteString("hud_new_design_enabled 1", false, false);
            pConsole->ExecuteString("hud_show_invulnerability_vignette 0", false, false);
            pConsole->ExecuteString("g_bomb_drop_enabled 1", false, false);
            pConsole->ExecuteString("net_timer_min_wait_time 1.0", false, false);



            pConsole->RegisterInt("g_weapon_resistance_enabled", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_hide_locked_attachments", 0, 0, "Custom line for initializing the setserver channel", 0);


            pConsole->RegisterInt("g_send_inventory_before_revive", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_weapon_resistance_enabled", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_hide_locked_attachments", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODAliveTime", 10, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODMoveInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODStanceInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODDirInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODAmbientFireInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODKillZoneInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODReactionTime", 10, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODReactionDistInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODReactionLeanInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODReactionDirInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_AmbientFireEnable", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODCoverFireTimeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODKillRangeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODCombatRangeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_AmbientFireUpdateInterval", 9999, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_AmbientFireQuota", 9999, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODLowHealthMercyTime", 10, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_playerLowHealthThreshold", 40, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_UseAlternativeReadability", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_friendlyfireratio", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_reaction_audio_range_aggressive", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_enable_occlusion_trigger", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_reaction_audio_range_threatening", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_reaction_audio_range_interesting", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_reaction_audio_time_aggressive", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_reaction_audio_time_threatening", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_reaction_audio_time_interesting", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_reaction_visual_time_near_react", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_reaction_visual_time_aggressive", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_reaction_visual_time_threatening", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_reaction_visual_time_interesting", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODMoveInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODStanceInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODDirInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODAmbientFireInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODKillZoneInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODReactionDistInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODReactionDirInc", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_AmbientFireEnable", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODCoverFireTimeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODKillRangeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODCombatRangeMod", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_AmbientFireUpdateInterval", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_AmbientFireQuota", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_RODLowHealthMercyTime", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_UseAlternativeReadability", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_death_cam_fadeout_time", 0.2, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_death_cam_switch_time", 1.5, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_death_cam_time", 4, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_dynamic_spawn_dangerous_mode", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_dynamic_spawn_dangerous_radius", 15, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_dynamic_spawn_dangerous_time", 20, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_dynamic_spawn_enemy_inner_radius", 5, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_dynamic_spawn_enemy_outer_radius", 15, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_honest_death_cam", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_locked_spectator_camera", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("g_sudden_death_rounds_enabled", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ui_new_radar", 1, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("sv_fix_explode_bomb", 1, 0, "Custom line for initializing the setserver channel", 0);
            std::string ports = "sv_port " + std::to_string(InitializationCVarsPort());
            pConsole->ExecuteString(ports.c_str(), false, false);

            pConsole->RegisterInt("cl_AISystem", 0, 0, "Custom line for initializing the setserver channel", 0);
            pConsole->RegisterInt("ai_CoverSystem", 0, 0, "Custom line for initializing the setserver channel", 0);

            pConsole->ExecuteString("cl_AISystem 1", 0, 0);
            pConsole->ExecuteString("ai_CoverSystem 1", 0, 0);
        }
    }

    //CBackend* pBackend = (CBackend*)operator_new(20000);
    //CBackend* mBackend = CBackend_CBackend(pBackend, pFramework);
    //this1->m_pBackend = mBackend;

    if (strstr(GetCommandLineA(), "-dedicated"))
    {

        CBackend* pBackend = (CBackend*)operator_new(20000);
        CBackend* mBackend = CBackend_CBackend(pBackend, pFramework);
        this1->m_pBackend = mBackend;
        CMissionBackend* pMissionBackend = (CMissionBackend*)operator_new(20000);
        CMissionBackend* mMissionBackend = CMissionBackend_CMissionBackend(pMissionBackend);
        this1->m_pMissionBackend = mMissionBackend;
        CAbstractServerInfo* pAbstractServerInfo = (CAbstractServerInfo*)operator_new(20000);
        CAbstractServerInfo* mAbstractServerInfo = CAbstractServerInfo_CAbstractServerInfo(pAbstractServerInfo, 0);
        this1->m_pServerInfo = mAbstractServerInfo;
                //IStreamEngine* m_pStreamEngine = (IStreamEngine*)operator_new(20000);
                //IStreamEngine* pStreamEngine = CStreamEngine_CStreamEngine(m_pStreamEngine);
                //pSystem->m_pStreamEngine = pStreamEngine;
    }

                 gEnv->GetAISystem()->InitAI();
                 gEnv->GetAISystemV2()->bEnabled = true;
                
                 auto pc = pSystem->Init_V2();
                 pc->Initialization();
                 auto pc2 = pSystem->Init_V2();
                 pc2->Reset(4);
                 auto pgame1 = this1->GetAI();
                 pgame1->Func1();
                 auto pgame2 = this1->GetAI();
                 pgame2->Func2();


    return result;
}

typedef bool(__fastcall* CFlowChartManager_IsStateClass)();
CFlowChartManager_IsStateClass CFlowChartManager_IsState_p = (CFlowChartManager_IsStateClass)0x140490990;

typedef __int64(__fastcall* cFlowChartManagerstate)(/* args null nothing */);
cFlowChartManagerstate CFlowchartManager_GetCurrentState_p;

__int64 __fastcall CFlowchartManager_GetCurrentState()
{
    return 0; // íåò ñìûñëà ò.ê ëèáî true ëèáî false
}

bool __fastcall CFlowChartManager_IsState(void* pointer, int state)
{
    return state == 0; 
    // ò.ê ìû âûðåçàëè ýòó ñòðóêòóðó, òî this1 - íóëåâûé ïîèíòåð, ìû ðåàëèçóåì òîæå ñàìîå. Èáî this->m_currentState òîò æå ñàìûé int state. Int state == 0;
}

struct SInstantAwardDesc {

};


struct CInstantAwardConfig {
public:
    std::vector<SInstantAwardDesc, std::allocator<SInstantAwardDesc> > m_achDescs;
};

struct CInstantAwardSystem {
public:
    void* __vftable /*VFT*/;
    std::auto_ptr<CInstantAwardConfig> m_pInstantAwardConfig;
    void* m_pInstantAwardTracker;
    //char pad_0x0000[0x10];
    //void* m_pAwardTracker;
};

struct CMissionDailyAccessTracker {
public:

};

struct CFeedbackSystem {
public:

};

typedef CFeedbackSystem* (__fastcall* CFeedbackSystemClass)(CFeedbackSystem* this1);
CFeedbackSystemClass CFeedbackSystem_CFeedbackSystem = (CFeedbackSystemClass)0x14041EDA0;

typedef CMissionDailyAccessTracker* (__fastcall* CMissionDailyAccessTrackerClass)(CMissionDailyAccessTracker* this1);
CMissionDailyAccessTrackerClass CMissionDailyAccessTracker_CMissionDailyAccessTracker = (CMissionDailyAccessTrackerClass)0x1408FCAC0;

struct IGameRules {
public:
    CREATE_FUNCTOR(CInstantAwardSystem*, m_pAwardSystem, 1048);
    CREATE_FUNCTOR(CMissionDailyAccessTracker*, m_missionDailyAccessTracker, 1000);
    CREATE_FUNCTOR(CFeedbackSystem*, m_pFeedbackSystem, 784);
    CREATE_FUNCTOR(int, m_softCollisionState, 1440);
};

typedef void(__fastcall* CGameRules_UpdateClass)(IGameRules* this1, void* ctx, int updateSlot);
CGameRules_UpdateClass CGameRules_Update = (CGameRules_UpdateClass)0x140534F10;

void __fastcall CGameRules_UpdateHook(IGameRules* this1, void* ctx, int updateSlot)
{
    typedef bool(__fastcall* InGame)(IGameRules*);
    bool InGameA = InGame((InGame)0x14054CA40)(this1);

    if (InGameA) {
        IsPreMatch = true;
    }

    //Modifications::TeleportToLook(this1);


    IsGame = InGameA;

    CGameRules_Update(this1, ctx, updateSlot);

    
}

typedef void(__fastcall* COnlineAccountUpdateClass)(COnlineAccount* this1);
COnlineAccountUpdateClass COnlineAccount__Update_p = (COnlineAccountUpdateClass)0x14044B100;

int iLastState = -1;


void __fastcall COnlineAccount__Update(COnlineAccount* this1)
{
    //sub_14044B350 - login
    void* pGame = CGame::Singlenton();
    typedef void(__cdecl* pGame_OnlineTick)(void*);
    CallFunction<pGame_OnlineTick>(pGame, 0xD0)(pGame);
    typedef void(__cdecl* COnlineChannel_Update)(void*);
    COnlineChannel_Update(0x140520030)(*(void**)((DWORD64)this1 + 0x100));

    if (this1->m_state == ECS_Disconnected) {
        if (iLastState != this1->m_state)
        {
            typedef void(__cdecl* COnlineAccount__Connect)(void*, bool);
            COnlineAccount__Connect(0x1404310E0)(this1, FALSE);
        }
    }
    if (this1->m_state == ECS_WaitingForCredentials) {
        if (iLastState != this1->m_state)
        {
            typedef void(__cdecl* COnlineAccount_Login)(void* this1, const char* a2, AcccountLogin* a3);
            AcccountLogin login;
            //memset(&login, 0, sizeof(AcccountLogin*));
            login.authorize.m_header = new CryStringT<char>::StrHeader();

            login.authorize.m_header->nRefCount = 1;
            login.authorize.m_header->nLength = 9;
            login.authorize.m_header->nAllocSize = 10;
            login.authorize.m_str = new char[login.authorize.m_header->nAllocSize];
            const char* login_ = "dedicated";
            strcpy(login.authorize.m_str, login_);
            COnlineAccount_Login(0x140431440)(this1, "dedicated", &login);
        }
    }
    if (this1->m_state == ECS_WaitingForConnection) {
        //....
    }
    if (this1->m_state == ECS_WaitingForDisconnect) {
        //...
    }
    if (this1->m_state == ECS_Connected) {
        //...
    }
    iLastState = this1->m_state;


    //switch (this1->m_state) { // íå áóèò ðàáîòàòü ò.ê îíî ïîýòàïíî èäåò
    //    case ECS_WaitingForConnection: this1->m_state = ECS_WaitingForDisconnect; break;
    //    case ECS_WaitingForDisconnect: this1->m_state = ECS_Connected; break;
    //    case ECS_Connected: break;
    //    case ECS_WaitingForCredentials:
    //        printf("Waiting for credits.\n");
    //        typedef void(__cdecl* COnlineAccount_Login)(void* this1, const char* a2, AcccountLogin* a3);
    //        AcccountLogin login;
    //        //memset(&login, 0, sizeof(AcccountLogin*));
    //        login.authorize.m_header = new CryString::StrHeader();
    //        login.authorize.m_header->nRefCount = 1;
    //        login.authorize.m_header->nLength = 9;
    //        login.authorize.m_header->nAllocSize = 10;
    //        login.authorize.m_str = new char[login.authorize.m_header->nAllocSize];
    //        const char* login_ = "dedicated";
    //        strcpy(login.authorize.m_str, login_);
    //        COnlineAccount_Login(0x14044B350)(this1, login_, &login);
    //        this1->m_state = ECS_WaitingForConnection;
    //        break;
    //    //case ECS_WaitingForConnection: this1->m_state = ECS_WaitingForDisconnect; break;
    //    //case ECS_WaitingForDisconnect: this1->m_state = ECS_Connected; break;
    //    //case ECS_Connected: break;
    //}


    COnlineAccount__Update_p(this1);
}

typedef bool(__fastcall* nsub_140DD6400)(__int64 a1);
nsub_140DD6400 sub_140DD6400_p = (nsub_140DD6400)0x141523CD0;

typedef bool(__cdecl* nZipDir__CacheFactory__ReadHeaderData)(void* this1, void* pDest, unsigned int nSize);
nZipDir__CacheFactory__ReadHeaderData mZipDir__CacheFactory__ReadHeaderData = (nZipDir__CacheFactory__ReadHeaderData)0x141525090;


bool __cdecl ZipDir__CacheFactory__ReadHeaderData(void* this1, void* pDest, unsigned int nSize) {
    bool ret = false;
    if (*(bool*)((DWORD64)this1 + 0xBB)) ret = mZipDir__CacheFactory__ReadHeaderData(this1, pDest, nSize);
    else
    {
        typedef __int64(__cdecl* ZipDir__FRead)(void* file, void* data, unsigned __int64 elementSize, unsigned __int64 count, void* pInternalFile);
        ret = ZipDir__FRead(0x14151E9F0)(&*(void**)((DWORD64)this1 + 0x10), pDest, nSize, 1u, NULL) == 1;
    }
    return ret;
}


typedef uint8_t(__fastcall* sub_1412FF510_t)();
typedef uint8_t(__fastcall* sub_1412F9E00_t)(__int64, uint32_t, uint64_t, uint64_t);
typedef void(__fastcall* sub_141300440_t)(__int64, __int64, uint64_t);
typedef void(__fastcall* sub_141300550_t)(__int64);
typedef uint8_t(__fastcall* sub_1412FF770_t)(__int64);

sub_1412FF510_t sub_1412FF510 = (sub_1412FF510_t)0x141524110;
sub_1412F9E00_t sub_1412F9E00 = (sub_1412F9E00_t)0x14151E950;
sub_141300440_t sub_141300440 = (sub_141300440_t)0x141525040;
sub_141300550_t sub_141300550 = (sub_141300550_t)0x141525150;
sub_1412FF770_t sub_1412FF770 = (sub_1412FF770_t)0x141524370;

char __fastcall sub_140DD6400(__int64 a1) {
    uint16_t v2;
    int16_t v3;
    int16_t v4;
    uint32_t v5;
    uint32_t v6;
    uint32_t v7;

    sub_1412FF510();

    v2 = *reinterpret_cast<uint16_t*>(a1 + 68);
    v3 = v2 >> 15;
    v4 = v2 & 0x7FFF;
    *reinterpret_cast<uint8_t*>(a1 + 187) = static_cast<uint8_t>(v3);
    *reinterpret_cast<uint16_t*>(a1 + 68) = v4;

    if (*reinterpret_cast<uint16_t*>(a1 + 70))
        return 0;
    if (*reinterpret_cast<uint16_t*>(a1 + 72) != *reinterpret_cast<uint16_t*>(a1 + 74))
        return 0;
    v5 = *reinterpret_cast<uint32_t*>(a1 + 80);
    v6 = *reinterpret_cast<uint32_t*>(a1 + 112);
    if (v5 > v6)
        return 0;
    v7 = *reinterpret_cast<uint32_t*>(a1 + 76);
    if (v7 > v6 || v7 + v5 > v6)
        return 0;

    sub_1412F9E00(a1 + 16, v7 + v5 + 22, 0, 0);
    if (*reinterpret_cast<uint16_t*>(a1 + 84) >= 8) {
        sub_141300440(a1, a1 + 2548, 8);
        if (*reinterpret_cast<uint32_t*>(a1 + 2548) != 8)
            return 0;
        *reinterpret_cast<uint32_t*>(a1 + 188) = *reinterpret_cast<uint32_t*>(a1 + 2552);
        if (*reinterpret_cast<uint16_t*>(a1 + 84) >= 0x93C) {
            sub_141300440(a1, a1 + 192, 2356);
            if (*reinterpret_cast<uint32_t*>(a1 + 192) != 2356)
                return 0;
            sub_141300550(a1);
        }
    }

    if (sub_1412FF770(a1))
        return 1;

    return 0;
}

typedef void(__fastcall* StarforceClass)();
StarforceClass FunctionWithStarforce_Fix_p = (StarforceClass)0x141B948B0;

//FunctionWithStarforce_Fix_p
void __fastcall FunctionWithStarforce_Fix() {
    return;
}

typedef void(__fastcall* FD1SF)(/* args null nothing */);
FD1SF CAbstractServerInfo__OnGameStarted_p;


typedef void(__fastcall* _3CAbstractServerInfoClass)(/* args null nothing */);
_3CAbstractServerInfoClass CAbstractServerInfo__OnGameStarted_p3;
typedef void(__fastcall* _3CAbstractServerInfoClass4)(/* args null nothing */);
_3CAbstractServerInfoClass4 CAbstractServerInfo__OnGameStarted_p4;




struct fMetricsStruct {
public:
    fMetricsStruct* __vtablePointer8() {
        return CallFunction<fMetricsStruct * (__thiscall*)(PVOID64, const char*, __int64, __int64) >(this, 8)(this, "g_none", 0, 0);
    }
    void Init(void* p, const char* text, void* p1, __int64 = -1) {
        CallFunction<void* (__thiscall*)(PVOID64, const char*, void*, __int64) >(this, 8)(p, text, p1, -1);
    }
};

double __fastcall fMetrics(__int64 a1, __int64 a2) {
    printf("g_ingame_metrics_cl_packetlossrate initialization\n");
    __int64 v40 = *(__int64*)((DWORD64)a1 + 8);
    if (!v40) {
        printf("g_ingame_metrics_cl_packetlossrate Failure\n");
        return 1i64;
    }
    //fMetricsStruct* pointerV40 = v40->__vtablePointer8();
    //
    //
    //void* v44;
    //void* v43 = operator_new(0x3337);
    //if (v43) {
    //    typedef void* (__fastcall* fTest)(void* a1, int a2, int a3, const char* a4);
    //    v44 = fTest(0x140880E30)(v43, 6i64, 0i64, "Packet loss");
    //}
    //else v44 = 0;
    //
    //pointerV40->Init(v40, "g_ingame_metrics_cl_packetlossrate", v44, -1);
    return 0i64;

}


__int64 __fastcall CAbstractServerInfo__OnGameStarted() {
    return 0;
}

void __fastcall sub_1405008D0(void* a1, __int64 a2) // abort function
{
    return;
}

char __fastcall sub_14083A610(void* a1, __int64 a2)
{
    return 1;
}

typedef bool(__cdecl* nCCryAction_StartGameContext)(void* this1, SGameStartParams* pGameStartParams);
nCCryAction_StartGameContext CCryAction_StartGameContext_p = (nCCryAction_StartGameContext)0x140F53A10;

bool __cdecl CCryAction_StartGameContext(void* this1, SGameStartParams* pGameStartParams)
{
    pGameStartParams->flags = eGSF_ImmersiveMultiplayer | eGSF_Server | eGSF_BlockingMapLoad | eGSF_BlockingClientConnect;
    pGameStartParams->maxPlayers = 32;

    return CCryAction_StartGameContext_p(this1, pGameStartParams);
}

enum ERequestSendType
{
    eRST_Regular = 0x0,
    eRST_Immediate = 0x1,
};

enum EGameEndReason : __int32
{
    eGER_Unknown = 0x0,
    eGER_Completed = 0x1,
    eGER_Failed = 0x2,
    eGER_Timelimit = 0x3,
    eGER_NotEnoughPlayers = 0x4,
    eGER_NoPlayers = 0x5,
    eGER_ModeratorStopSession = 0x6,
};

void FixNops_ClientTokenIsMissmatch() {
    WriteMemory((void*)0x00000001420B701F, "\x0F\x85", 2);
    WriteMemory((void*)0x000000014107C702, "\x0F\x85", 2);
}
typedef CAbstractServerInfo* (__fastcall* FN_CGame__GetServerInfo_p)(CGame*);
FN_CGame__GetServerInfo_p CGame_GetServerInfo_p = (FN_CGame__GetServerInfo_p)0x1400AA990;
CAbstractServerInfo* __fastcall Game_GetServerInfo(CGame* a1) {
    CGame* m_pGame = CGame::Singlenton();
    if (!m_pGame)
        return CGame_GetServerInfo_p(a1);
    return m_pGame->m_pServerInfo;
}

struct SPlayerScoresInfo {};
struct SPlayerPerformanceInfo {};

typedef bool(__fastcall* FCGame_Update)(CGame*, bool, unsigned int);
FCGame_Update CGame_Update_p = (FCGame_Update)0x1400A8610;

struct SSessionRewardsInfo {
    std::map<int, std::vector<SPlayerScoresInfo, std::allocator<SPlayerScoresInfo> >, std::less<int>, std::allocator<std::pair<int const, std::vector<SPlayerScoresInfo, std::allocator<SPlayerScoresInfo> > > > > teamRewards;
    std::vector<SPlayerPerformanceInfo, std::allocator<SPlayerPerformanceInfo> > playersPerformances;
    CryStringT<char> missionId;
    bool incompleteSession;
    float sessionTime;
    unsigned int sessionKillCount;
    int winningTeamId;
    int maxSessionScore;
    int passedSublevelsCount;
    int passedCheckpointsCount;
    int totalPerformance;
    int totalPerformanceNotMultiplied;
    unsigned __int8 secondaryObjectivesCompleted;
    //public:
    //    using FN_SessionRewardsInfo = void(__thiscall*)(SSessionRewardsInfo**);
    //    static void SessionRewardsInfo(SSessionRewardsInfo** this1) {
    //        FN_SessionRewardsInfo(0x14149CDA0)(this1);
    //    }
};

class CScoringConfig {
public:
    char pad_0x10[0x10];
    void* m_setRewardsInfoBinder;

    using FN_GetSessionRewardsInfo = void(__thiscall*)(CScoringConfig*, EGameEndReason, int, SSessionRewardsInfo*);
    static void GetSessionRewardsInfo(CScoringConfig* this1, EGameEndReason gameEndReason, int winningTeamId, SSessionRewardsInfo* result) {
        FN_GetSessionRewardsInfo(0x140759030)(this1, gameEndReason, winningTeamId, result);
    }
};

struct CGameRulesEnd {
    char pad_0x18[0x518];
    CScoringConfig* m_pScoringConfig;
};

SSessionRewardsInfo* new_m_pSessionRewardsInfo = nullptr;

typedef void(__cdecl* SendSSessionRewardsInfo)(void*, SSessionRewardsInfo*, ERequestSendType);




typedef void(__cdecl* CGameRules_ReportGameEndClass)(CGameRulesEnd* this1, EGameEndReason gameEndReason, int winningTeamId, SSessionRewardsInfo* m_pSessionRewardsInfo);
CGameRules_ReportGameEndClass CGameRules_ReportGameEnd_p = (CGameRules_ReportGameEndClass)0x1405499E0;

struct IFunctionHandler {};
struct CScriptBind_GameRules {};

typedef __int64(__fastcall* FN_CScriptBind_GameRules_DisconnectToLobby)(CScriptBind_GameRules*, IFunctionHandler*);
FN_CScriptBind_GameRules_DisconnectToLobby CScriptBind_GameRules_DisconnectToLobby_p = (FN_CScriptBind_GameRules_DisconnectToLobby)0x1403CA6A0;

__int64 __fastcall ScriptBind_GameRules_DisconnectToLobby(CScriptBind_GameRules* this1, IFunctionHandler* pH) {
    CGame::Singlenton()->m_pServerInfo->m_telemetrySent = true;
    return CScriptBind_GameRules_DisconnectToLobby_p(this1, pH);
}

void __fastcall GameRules_ReportGameEnd(CGameRulesEnd* this1, EGameEndReason gameEndReason, int winningTeamId, SSessionRewardsInfo* m_pSessionRewardsInfo) {
    new_m_pSessionRewardsInfo = m_pSessionRewardsInfo;
    CScoringConfig* Myptr = this1->m_pScoringConfig;
    if (Myptr)
    {
        CScoringConfig::GetSessionRewardsInfo(Myptr, gameEndReason, winningTeamId, m_pSessionRewardsInfo);
        SendSSessionRewardsInfo((SendSSessionRewardsInfo)0x14075BB30)(&Myptr->m_setRewardsInfoBinder, new_m_pSessionRewardsInfo, ERequestSendType::eRST_Regular);
    }
    CGameRules_ReportGameEnd_p(this1, gameEndReason, winningTeamId, m_pSessionRewardsInfo);
}

typedef void(__fastcall* CSSetRewardsInfoSerializer_OnRequest)(void*, XmlNodeRef* request, SSessionRewardsInfo* rewardsInfo);
CSSetRewardsInfoSerializer_OnRequest SSetRewardsInfoSerializer_OnRequest_p = (CSSetRewardsInfoSerializer_OnRequest)0x140757140;

void __fastcall SetRewardsInfoSerializer_OnRequest(void* SSetRewardsInfoSerializer, XmlNodeRef* request, SSessionRewardsInfo* rewardsInfo) {
    rewardsInfo = new_m_pSessionRewardsInfo;

   //Modifications::HighJump = false;
   //Modifications::Teleport = false;
   //Modifications::OnlyHead = false;

    //auto gEnv = SSystemGlobalEnvironment::Singleton();
    //if (gEnv && gEnv->GetCSystem()) {
    //    auto pc2 = gEnv->GetCSystem()->Init_V2();
    //    pc2->Reset(5); // RESET_UNLOAD_LEVEL
    //}

    IsPreMatch = false;
    IsGame = false;

    SSetRewardsInfoSerializer_OnRequest_p(SSetRewardsInfoSerializer, request, rewardsInfo);

}

bool __fastcall Game_Update(CGame* this1, bool haveFocus, unsigned int updateFlags) {
    bool result = CGame_Update_p(this1, haveFocus, updateFlags);
    //CGame* this_ = CGame::Signlenton();

   // printf("%s\n", SSystemGlobalEnvironment::Singleton()->GetIConsole()->GetCVar("sv_packetRate")->GetString());

    if (this1->m_pServerInfo) {
        this1->m_pServerInfo->Update(this1->m_pServerInfo, 0);
    }
    return result;
}
typedef void(__fastcall* nAddRegisterSoundListener)(void* pEst, int state);
nAddRegisterSoundListener mAddRegisterSoundListener = (nAddRegisterSoundListener)0x14109B340;

typedef void(__fastcall* nCrash)(void* pEst, int state);
nCrash mCrashInCGame;

void __fastcall AddRegisterSoundListener(void* pEst, int state)
{
    return;
}

void FixQuerySend() {
    //OnlineBalancer >= 3 -> >= 0;

    WriteMemory((void*)0x00000001400CB851, "\x83\xB8\xE8\x01\x00\x00\x00", 7);

}
struct SEntityLoadParams {};
struct CEntityLoadManager {};

typedef int(__thiscall* Extract_FFFF)(CEntityLoadManager* this1, XmlNodeRef* entityNode, SEntityLoadParams* outLoadParams);
Extract_FFFF CEntityLoadManager_ExtractEntityLoadParams_p = (Extract_FFFF)0x141FDEA60;

int __fastcall CEntityLoadManager_ExtractEntityLoadParams(CEntityLoadManager* this1, XmlNodeRef* entityNode, SEntityLoadParams* outLoadParam)
{
    int ret = CEntityLoadManager_ExtractEntityLoadParams_p(this1, entityNode, outLoadParam);
    if (*(int*)((DWORD64)outLoadParam + 0x98) > 0 || *(int*)((DWORD64)outLoadParam + 0x9C) > 0) { // minSpec & maxSpec
        //printf("CEntityLoadManager_ExtractEntityLoadParams\n");
        *(int*)((DWORD64)outLoadParam + 0x40) |= ENTITY_FLAG_CLIENT_ONLY;
    }
    return ret;

}

typedef HANDLE(__stdcall* nCreateMutexA)(LPSECURITY_ATTRIBUTES, BOOL, LPCSTR);
nCreateMutexA mCreateMutexA;

typedef char(__thiscall* PtrFunc_CSystem_IntializeEngineModule)(void* this1, const char* dllName, DWORD64* moduleClassName, const char*, bool bQuitIfNotFound);
PtrFunc_CSystem_IntializeEngineModule pfnCSystem_IntializeEngineModule = (PtrFunc_CSystem_IntializeEngineModule)0x14143D780;


char __fastcall Hook_CSystem_IntializeEngineModule(void* this1, const char* dllName, DWORD64* a3, const char* initParams, bool bQuitIfNotFound)
{
    //   printf("dllName: %s\n", dllName);
    if (strstr(dllName, "CryAnimation")) {
        SSystemGlobalEnvironment::Singleton()->GetCSystem()->InitAI(0);
    }

    return pfnCSystem_IntializeEngineModule(this1, dllName, a3, initParams, bQuitIfNotFound);
}


void* __fastcall sub_140912DF0(void* a1)
{
    return *(void**)0x142A935C8;
}
typedef char(__fastcall* CActor_SetPhysicalizationProfileClass)(CActor* a1, EActorPhysProfiles a2);
CActor_SetPhysicalizationProfileClass CActor_SetPhysicalizationProfile = (CActor_SetPhysicalizationProfileClass)0x140397900;
char __fastcall CActor_SetPhysicalizationProfileHook(CActor* a1, EActorPhysProfiles a2)
{
    char result = CActor_SetPhysicalizationProfile(a1, a2);
    unsigned int aspect = 0x2000000i64;
    a1->m_pGameObjcet->ChangedNetworkState(aspect);


    return result;
}

typedef bool(__cdecl* CPlayer_CreateInputClassByTypeClass)(CPlayer* this1, int nPlayerInputType);
CPlayer_CreateInputClassByTypeClass CPlayer_CreateInputClassByType_p = (CPlayer_CreateInputClassByTypeClass)0x140585450;


bool __fastcall CPlayer_CreateInputClassByType(CPlayer* this1, int nPlayerInputType) {

    if (nPlayerInputType == 3) {
        return CPlayer_CreateInputClassByType_p(this1, 2);
    }
    else {
        return CPlayer_CreateInputClassByType_p(this1, nPlayerInputType);
    }
}

typedef __int64(__fastcall* CPhysCallbacks_OnFoliageClass)(void*);
CPhysCallbacks_OnFoliageClass CPhysCallbacks_OnFoliageTouched_p = (CPhysCallbacks_OnFoliageClass)0x141B89DF0;



__int64 __fastcall CPhysCallbacks_OnFoliageTouched(void* pEvent)
{
    auto m_pPhysicalWorld = IPhysicalWorld::Singlenton();

    //void* pPhysStreamer = off_142A676D0;
    return m_pPhysicalWorld->SetPhysicsStreamer((void**)0x142A676D0);
}

HANDLE __stdcall CreateMutexAHook(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
    
    if (lpName != NULL) {
        printf("CreateMutexAHook\n");
        if (strstr(lpName, "CrytekApplication")) {
            printf("CreateMutexAHook\n");

            MhCreateAndEnableHook(*pfnCSystem_IntializeEngineModule, Hook_CSystem_IntializeEngineModule, (LPVOID*)&pfnCSystem_IntializeEngineModule);
           

            if (strstr(GetCommandLineA(), "-dedicated"))
            {
                MhCreateAndEnableHook(*CEntityLoadManager_ExtractEntityLoadParams_p, CEntityLoadManager_ExtractEntityLoadParams, (LPVOID*)&CEntityLoadManager_ExtractEntityLoadParams_p);
            }
         
            return INVALID_HANDLE_VALUE;
        }
    }
    return mCreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
}



void FixUpdateAchievements() {
    WriteMemory((void*)0x0000000140533415, "\x75", 1); // jz gEnv->bClient
    WriteMemory((void*)0x1408F078A, "\x90\x90", 2); // !IsPVE
    WriteMemory((void*)0x00000001408F0802, "\xEB", 1); // !IsPVE

}



void AIInit() {
    WriteMemory((void*)0x14143FC39, "\xEB", 1);
    WriteMemory((void*)0x000000014143D405, "\xEB", 1);
    WriteMemory((void*)0x0000000141C5C34D, "\xEB", 1);
    WriteMemory((void*)0x0000000141001FA3, "\x75", 1); // danger
    WriteMemory((void*)0x0000000141001F85, "\xEB", 1); // danger
    WriteMemory((void*)0x000000014073910D, "\x90\x90\x90\x90", 4);
    WriteMemory((void*)0x0000000141B8C237, "\xEB", 1);
    WriteMemory((void*)0x000000014125481F, "\x90\x90\x90\x90\x90", 5);
}

void SvRequestHitFix() {
    BYTE* pCall = (BYTE*)0x00000001406725E2;
    while (true) {
        if (*pCall == 0xE8) {
            break;
        }
        Sleep(1);
    }
    DWORD* pServerHit = (DWORD*)0x00000001406725E3;
    DWORD old;
    VirtualProtect((LPDWORD)pServerHit, 4, PAGE_READWRITE, &old);
    *pServerHit = 0 - ((DWORD)pServerHit - ((DWORD)0x1405A0970 - 4));
    VirtualProtect((LPDWORD)pServerHit, 4, old, &old);
}

typedef char(__fastcall* SADSDFSDFSDFSDF15)(__int64, __int64);
SADSDFSDFSDFSDF15 SADSDFSDFSDFSDF15_p;
char __fastcall SSADSDFSDFSDFSDF15(__int64 a1, __int64 a2) {
    printf("status a2: %i\n", a2);
    auto pp = SSystemGlobalEnvironment::Singleton();
    auto ppp = pp->GetAISystemV2();
    if (ppp) {
        printf("%p", ppp);

        

        //if (a2 != 5 && a2 != 2)
        //    ppp->bEnabled = true;
        //if (a2 == 5) {
        //    ppp->bEnabled = false;
        //    auto pc2 = pp->GetCSystem()->Init_V2();
        //    pc2->Reset(5);
        //}
    }
    return SADSDFSDFSDFSDF15_p(a1, a2);
}
typedef void(__fastcall* SADSDFSDFSDFSDF5)(__int64, __int64);
SADSDFSDFSDFSDF5 SADSDFSDFSDFSDF5_p;
__int64 __fastcall sub_1400AA610(__int64 a1, __int64 a2)
{
    if (!IsPreMatch)
        return 1;
    
    if (!IsGame) return 0;

    return 1;
}
typedef void(__fastcall* SADSDFSDFSDFSDF12)(__int64, __int64);
SADSDFSDFSDFSDF12 SADSDFSDFSDFSDF12_p;
__int64 __fastcall sub_1404BBA10(void* a1)
{
    return 1;
}

struct SMessage {
    void* ptr;
    int type;
    int msgType;
    __int64 serverTime;
    int opcode;
    char instant;
};

struct SM_Network__SCoopAssistMessage : SMessage {
    int animIndex;
    bool singleClimb;
    Vec3_tpl<float> animStartPos;
    Vec3_tpl<float> helperClosestPoint;
    unsigned int climber;
    Lineseg_tpl<float> edge;
    __int64 ServerStartFrame;
};

enum ECoopAssistState : __int32
{
    eCAS_EnteringAssistPose = 0x0,
    eCAS_Waiting = 0x1,
    eCAS_Assisting = 0x2,
};

typedef void(__fastcall* SendMessageFromServer_0)(CActor*, SM_Network__SCoopAssistMessage*);

typedef void(__cdecl* CSM_CoopAssistClass)(void* this1);
CSM_CoopAssistClass CSM_CoopAssist__Finish_p = (CSM_CoopAssistClass)0x140712E50;

struct CEidSerializer
{
    unsigned int m_id;
    bool m_valid;
};

struct SKnockBackMessage : SMessage {
    Quat_tpl<float> animStartLocalRot;
    Vec3_tpl<float> startPos;
    CEidSerializer standingOn;
};



struct CSM_HoldEntityStruct {
public:
    char pad_0x0000[0x10];
    IPlayer* pPlayer;
};

struct SM_Network_SHoldEntityMessage : SMessage
{
    unsigned int entityId;
    unsigned int playerId;
    CryStringT<char> itemName;
};

typedef void(__fastcall* CSM_HoldEntity)(CSM_HoldEntityStruct* this1, __int64 a2, bool a3);
CSM_HoldEntity CSM_HoldEntityFinish_p;


typedef void(__fastcall* SendMessageFromServer_Knockback)(CActor*, SKnockBackMessage*);
typedef void(__cdecl* CSM_CoopClimbClass)(void* this1);
CSM_CoopClimbClass mCSM_CoopClimb__Finish = (CSM_CoopClimbClass)0x14070E320;
void __fastcall CSM_CoopClimb__Finish(void* this1)
{
    mCSM_CoopClimb__Finish(this1);





    CActor* m_pPlayer = *(CActor**)((DWORD64)this1 + 16);

    Vec3 myLastPosition = m_pPlayer->m_pEntity->GetWorldTM().GetTranslation();

    CGame* pGame = CGame::Singlenton();

    Vec3 v;

    SKnockBackMessage msg;
    memset(&msg, 0, sizeof(SKnockBackMessage));
    {
        msg.type = 3;
        msg.msgType = 0;
        msg.startPos = myLastPosition;
    }
    SendMessageFromServer_Knockback((SendMessageFromServer_Knockback)0x1407078E0)(m_pPlayer, &msg);

    SKnockBackMessage msg1;
    memset(&msg1, 0, sizeof(SKnockBackMessage));
    {
        msg1.type = 3;
        msg1.msgType = 1;
        msg1.startPos = myLastPosition;
    }
    SendMessageFromServer_Knockback((SendMessageFromServer_Knockback)0x1407078E0)(m_pPlayer, &msg1);
}



void __fastcall CSM_HoldEntity_Finish(CSM_HoldEntityStruct* this1, __int64 a2, bool a3)
{
    CSM_HoldEntityFinish_p(this1, a2, a3);
    SM_Network_SHoldEntityMessage msg;
    memset(&msg, 0, sizeof(SM_Network_SHoldEntityMessage));
    {
        msg.type = 0xA;
        msg.msgType = 1;
        *&msg.entityId = 0;
        msg.instant = 0;
        msg.opcode = -1;
        msg.serverTime = SSystemGlobalEnvironment::Singleton()->GetITimer()->GetFrameStartTimer(ETIMER_GAME)->m_lValue;
        msg.entityId = this1->pPlayer->holdEntity;

        CryStringT<char>::StrHeader hdr;
        hdr.nRefCount = 1;
        hdr.nLength = 0;


        char Buf2;

        msg.itemName = { &Buf2, &hdr };
        //msg.itemName.m_str = &Buf2;



        
    }
    typedef void(__fastcall* SendMessage_FromClient)(IGameObject*, void*, void*, SM_Network_SHoldEntityMessage* msg);
    SendMessage_FromClient((SendMessage_FromClient)0x140A72260)(this1->pPlayer->m_pGameObject, *(void**)0x142AAC628, *(void**)0x142AAC620, &msg);
}


void __cdecl CSM_CoopAssist__Finish(void* this1)
{
    CSM_CoopAssist__Finish_p(this1);

    SM_Network__SCoopAssistMessage pSM_Network__SCoopAssistMessage;
    RtlSecureZeroMemory(&pSM_Network__SCoopAssistMessage, sizeof(SM_Network__SCoopAssistMessage));
    pSM_Network__SCoopAssistMessage.ptr = (void*)0;
    pSM_Network__SCoopAssistMessage.type = 8;
    pSM_Network__SCoopAssistMessage.msgType = 1;
    pSM_Network__SCoopAssistMessage.opcode = -1;
    pSM_Network__SCoopAssistMessage.instant = 1;
    pSM_Network__SCoopAssistMessage.animIndex = -1;

    if (*(ECoopAssistState*)((DWORD64)this1 + 0xB0) != eCAS_Assisting)
    {
        CActor* m_pPlayer = *(CActor**)((DWORD64)this1 + 16);
        if (m_pPlayer)
            SendMessageFromServer_0((SendMessageFromServer_0)0x140715BA0)(m_pPlayer, &pSM_Network__SCoopAssistMessage);
    }
    else {
        CActor* m_pPlayer = *(CActor**)((DWORD64)this1 + 16);
        if (m_pPlayer)
        {
            Vec3 endPoint;
            typedef Vec3* (__fastcall* CPiecewiseTrajectory__GetEndPoint)(void*, Vec3*);
            CPiecewiseTrajectory__GetEndPoint((CPiecewiseTrajectory__GetEndPoint)0x1406FB4D0)((void*)((DWORD64)this1 + 0x38), &endPoint);

            pSM_Network__SCoopAssistMessage.helperClosestPoint = endPoint;
            pSM_Network__SCoopAssistMessage.serverTime = SSystemGlobalEnvironment::Singleton()->GetITimer()->GetFrameStartTimer(ETIMER_GAME)->m_lValue;

            m_pPlayer->m_pEntity->SetLocalPos(endPoint);

            SendMessageFromServer_0((SendMessageFromServer_0)0x140715BA0)(m_pPlayer, &pSM_Network__SCoopAssistMessage);
        }
    }
}

#include <stdio.h>
#include <time.h>
#include <chrono>

static int a1 = 0;
typedef bool(__cdecl* CSystem_UpdateClass)(void* this1, int updateFlags, int nPauseMode);
CSystem_UpdateClass CSystem_Update_p = (CSystem_UpdateClass)0x141423A10;

int get_mam() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto currentTimeMs = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return currentTimeMs;
}

long long accumulator = 0;
long long lastFrameTime = get_mam();

static bool isDev = false;
static bool isDevConsole = false;

bool __fastcall CSystem_Update(void* this1, int updateFlags, int nPauseMode)
{
   long long currentTime = get_mam();
   accumulator += currentTime - lastFrameTime;
   lastFrameTime = currentTime;
   
   while (accumulator >= 1000 / 60)
   {
       accumulator -= 1000 / 60;
   }
   if (accumulator < 1000 / 60)
       Sleep(1000 / 60 - accumulator);

    //else {
    //    if (GetAsyncKeyState(VK_F1) & 1)
    //        isDev = !isDev;
    //    if (GetAsyncKeyState(VK_F2) & 1)
    //        isDevConsole = !isDevConsole;
    //    IRenderer* m_pRenderer = SSystemGlobalEnvironment::Singleton()->GetIRenderer();
    //    Vec3 pos = Vec3(1, 1, 1);
    //    //const float color = 255.0f;
    //    float pfColor[4]; // [rsp+A8h] [rbp-29h] BYREF
    //
    //    pfColor[3] = 1.0;
    //    pfColor[2] = 1.0;
    //    pfColor[1] = 1.0;
    //    pfColor[0] = 1.0;
    //
    //    
    //
    //    if (m_pRenderer && isDev)
    //    {
    //        m_pRenderer->DrawLabel(2042, 2042, 2.0f, pfColor, false, "CamPos=102.13 224.69 7.49 Angl= 0 0 0 90 IN=0.15 ZF=1000 FC=5.93 VS=1.00 1.00 Zoom=0.60 Speed=0.0\nDX11 Profile 64Bit HighSpec MT PT HDR SGHR Gl DevMode bw_hideout_scandic_xmas (18.35995)\nDP: 116 (120) ShadowGen: 0 (  0)\n");
    //        m_pRenderer->DrawLabel(2032, 2032, 2.0f, pfColor, false, "Streaming IO: ACT: 180088sec: Jobs: 0\n");
    //        m_pRenderer->DrawLabel(2018, 2018, 2.0f, pfColor, false, "Mem=2048 Peak=1798 Dlights=(1/1/1/12)\n");
    //        pfColor[3] = 255.0;
    //        pfColor[2] = 255.0;
    //        pfColor[1] = 255.0;
    //        pfColor[0] = 255.0;
    //
    //        m_pRenderer->DrawLabel(2000, 2000, 2.0f, pfColor, false, "CamPos=102.13 224.69 7.49 Angl= 0 0 0 90 IN=0.15 ZF=1000 FC=5.93 VS=1.00 1.00 Zoom=0.60 Speed=0.0\nDX11 Profile 64Bit HighSpec MT PT HDR SGHR Gl DevMode bw_hideout_scandic_xmas (18.35995)\nDP: 116 (120) ShadowGen: 0 (  0)\nStreaming IO: ACT: 180088sec: Jobs: 0\nMem=2048 Peak=1798 Dlights=(1/1/1/12)\n");
    //    }
    //        auto m_pSSGE = SSystemGlobalEnvironment::Singleton();
    //        auto m_pScrypts = m_pSSGE->GetScrypts();
    //        if (m_pScrypts && isDevConsole) {
    //            m_pScrypts->ExecuteLua("System.ShowConsole(1);");
    //        }
    //        else if (!isDevConsole) {
    //            m_pScrypts->ExecuteLua("System.ShowConsole(0);");
    //        }
    //        else {
    //            //todo nothing.
    //        }
    //    
    //
    //}

    return CSystem_Update_p(this1, updateFlags, nPauseMode);
}


typedef char(__thiscall* ControllerPPPP)(void* a1, const char* a2, DWORD64* a3);
ControllerPPPP CStaticAIMovementController_Update_p = (ControllerPPPP)0x1403A3CF0;

char __fastcall CStaticAIMovementController_Update(void* a1, const char* a2, DWORD64* a3)
{
    char ret = CStaticAIMovementController_Update_p(a1, a2, a3);
    if (a2 && strstr(a2, "eiActorMovementController") && a3)
    {
        //printf("CStaticAIMovementController_Update: %u (ptr=%p)\n", (unsigned)*a3, (void*)a3);

        if (*a3 == 3)
        {
            *a3 = 2;
        }
        // printf("CStaticAIMovementController_Update_NEW: %u (ptr=%p)\n", (unsigned)*a3, (void*)a3);
    }

    return ret;
}

typedef __int64(__thiscall* sub_140927500Class)(__int64 a1, __int64 a2);
sub_140927500Class sub_140927500_p = (sub_140927500Class)0x140927500;

__int64 __fastcall sub_140927500(__int64 a1, __int64 a2)
{
    __int64 result = sub_140927500_p(a1, a2);

    typedef void(__cdecl* mFollowRotateAndPos)(__int64 a1);
    mFollowRotateAndPos((mFollowRotateAndPos)0x140947F70)(a1);

    return result;
}

bool __fastcall CSystem_IsDevMode(BYTE* a1)
{
    return TRUE;
}

__int64 __fastcall Crash_InCGame(__int64 a1, void* a2)
{
    if ((DWORD64)a2 + 0xC) {
        __int64 result = *(__int64*)((DWORD64)a2 + 0xC);
        return result;
    }
    return NULL;
}

typedef void(__fastcall* nCGameRules_BalancePlayers)(void* pEst, int state);
nCGameRules_BalancePlayers mnCGameRules_BalancePlayers_p;

void __fastcall CGameRules_BalancePlayers(void* this1, bool reset)
{
    return; /* íàõóé îí íóæåí âàùå? ÿ íå ïîíèìàþ */
}


//__int64 __fastcall sub_140942660(__int64 a1) - CStaticAIMovement_Reset

typedef void(__fastcall* CStaticAIMovementC)(void* this1, CActor* pPlayer);
CStaticAIMovementC CStaticAIMovementController_CStaticAIMovementController_p;

void __fastcall CStaticAIMovementController_CStaticAIMovementController(void* this1,CActor* pPlayer)
{



    if (strstr(pPlayer->m_pEntity->GetName(), "TurretWall") || 
        strstr(pPlayer->m_pEntity->GetName(), "Wall") ||
        strstr(pPlayer->m_pEntity->GetName(), "Robot") ||
        strstr(pPlayer->m_pEntity->GetName(), "Nakai"))
    {
        return;
    }


    CStaticAIMovementController_CStaticAIMovementController_p(this1, pPlayer);
}

typedef void(__fastcall* sub_1408C8650Class)(void* a1, __int64 a2, unsigned __int64 a3);
sub_1408C8650Class sub_1408C8650_p;

typedef void(__fastcall* sub_1408C8650Class12)(void* a1, __int64 a2, unsigned __int64 a3);
sub_1408C8650Class12 sub_1408C8650_p1;

void __fastcall sub_1408C8650(void* a1, __int64 a2, unsigned __int64 a3)
{
    /*
    
    v4 = (__int64 *)(16
                 * ((0x100000001B3i64
                   * (HIBYTE(a3) ^ (0x100000001B3i64
                                  * (BYTE6(a3) ^ (0x100000001B3i64
                                                * (BYTE5(a3) ^ (0x100000001B3i64
                                                              * (BYTE4(a3) ^ (0x100000001B3i64
                                                                            * (BYTE3(a3) ^ (0x100000001B3i64
                                                                                          * (BYTE2(a3) ^ (0x100000001B3i64 * (BYTE1(a3) ^ (0x100000001B3i64 * ((unsigned __int8)a3 ^ 0xCBF29CE484222325ui64)))))))))))))))) & a1[6])
                 + a1[3]);
    
    */

    return;
}

typedef void(__fastcall* sub_1408C8650Class32)(void* a1, __int64 a2, unsigned __int64 a3);
sub_1408C8650Class32 sub_1408C86501_p1;

__int64 __fastcall sub_1408C86501(void* a1, __int64 a2, unsigned __int64 a3)
{
    return 0i64;
}

typedef bool(__fastcall* CGameRules_InitClass)(IGameRules* this1, IGameObject* pGameObject);
CGameRules_InitClass CGameRules_Init_p = (CGameRules_InitClass)0x140532D20;



bool __fastcall CGameRules_Init(IGameRules* this1, IGameObject* pGameObject)
{
    CMissionDailyAccessTracker* pBackend = (CMissionDailyAccessTracker*)operator_new(20000);
    CMissionDailyAccessTracker* mBackend = CMissionDailyAccessTracker_CMissionDailyAccessTracker(pBackend);
    this1->m_missionDailyAccessTracker = mBackend;

    this1->m_softCollisionState = 0;

    //CFeedbackSystem* pBackend2 = (CFeedbackSystem*)operator_new(20000);
    //CFeedbackSystem* mBackend2 = CFeedbackSystem_CFeedbackSystem(pBackend2);
    //this1->m_pFeedbackSystem = mBackend2;



    return CGameRules_Init_p(this1, pGameObject);
}

void __fastcall KillPhysicsThread(void* a1)
{
    //if (1 == 1)
    return;
}

void FixKillPhyicsThread() {
    WriteMemory((void*)0x1414243AF, "\x90\x90\x90\x90\x90\x90\x90\x90\x90", 9);

    //TODO: òóò ìû ïîñòàâèëè !a1->bDedicatedServer íà a1->bDedicatedServer ïîòîìó ÷òà åáëàíû çàáûëè òî øî ýòà íàäî äëÿ äåäèêà
    //TODO: jnz -> jz
    //TODO: StreamEngine initializing....

    WriteMemory((void*)0x14143C220, "\x74", 1);


}

typedef __int64(__fastcall* CPhysicalWorld_Ge)(void*);
CPhysicalWorld_Ge CPhysicalWorld_GetEntitiesAround_p = (CPhysicalWorld_Ge)0x142164450;

__int64 __fastcall CPhysicalWorld_GetEntitiesAround(
    void* this1,
    Vec3_tpl<float>* ptmin,
    Vec3_tpl<float>* ptmax,
    void*** pList,
    unsigned int objtypes,
    void* pPetitioner,
    int szListPrealloc,
    int iCaller)
{
    return 0i64;
}

DWORD StartDedicated(LPVOID param) 
{

	if (MH_Initialize() != MH_OK) {
		return 1;
	}
   
    //MhCreateAndEnableHook(*CStaticAIMovementController_Update_p, CStaticAIMovementController_Update, (LPVOID*)&CStaticAIMovementController_Update_p);
    MhCreateAndEnableHook(*mZipDir__CacheFactory__ReadHeaderData, ZipDir__CacheFactory__ReadHeaderData, (LPVOID*)&mZipDir__CacheFactory__ReadHeaderData);
    WriteMemory((void*)0x0000000141523D7B, "\x0F\x84", 2);
    //  MhCreateAndEnableHook(*sub_140DD6400_p, sub_140DD6400, (LPVOID*)&sub_140DD6400_p);
	MhCreateAndEnableHook(*CCertificateValidator__Query_p, CCertificateValidator__Query, (LPVOID*)&CCertificateValidator__Query_p);
	//MhCreateAndEnableHook((void*)0x140942410, CStaticAIMovementController_CStaticAIMovementController, (LPVOID*)&CStaticAIMovementController_CStaticAIMovementController_p);
	//MhCreateAndEnableHook(*CStaticAIMovementController_Update_p, CStaticAIMovementController_Update, (LPVOID*)&CStaticAIMovementController_Update_p);
	//MhCreateAndEnableHook(*sub_140927500_p, sub_140927500, (LPVOID*)&sub_140927500_p);
    //WriteMemory((void*)0x140946AC4, "\x90\x90", 2);

    //AI:
    MhCreateAndEnableHook(*CSystem_Update_p, CSystem_Update, (LPVOID*)&CSystem_Update_p);
    
    if (!strstr(GetCommandLineA(), "-dedicated"))
    {
       // MhCreateAndEnableHook((void*)0x14142CBE0, CSystem_IsDevMode, (LPVOID*)&CFlowchartManager_GetCurrentState_p);
    }
   


    if(strstr(GetCommandLineA(), "-dedicated")) {
        Console::CreateConsole();
        //std::set_terminate(on_terminate);
        
        
        //WriteMemory((void*)0x00000001405332C8, "\x0F\x85", 2); // metrics_feedbackSystem
        //WriteMemory((void*)0x140533612, "\x0F\x85", 2); 

        /*
        if ( qword_142A935B8
    && (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)qword_142A935B8 + 240i64))(qword_142A935B8) )
  {
    v85 = sub_140079FF0(64i64);
    if ( v85 )
      v86 = sub_1408C85C0(v85);
    else
      v86 = 0i64;
    v87 = *(_QWORD *)(a1 + 1008);
    *(_QWORD *)(a1 + 1008) = v86;
    if ( v87 )
    {
      sub_1408C8640(v87);
      sub_14007A070(v87);
    }
    v88 = sub_140079FF0(16i64);
    if ( v88 )
      v89 = sub_1408FCAC0(v88);
    else
      v89 = 0i64;
    v90 = *(_QWORD *)(a1 + 1000);
    *(_QWORD *)(a1 + 1000) = v89;
    if ( v90 )
    {
      sub_1408FCB00(v90);
      sub_14007A070(v90);
    }
  }
  void __fastcall CPassedCheckpointsTracker::CPassedCheckpointsTracker(CPassedCheckpointsTracker *this)
        
        
        */
        
        //MhCreateAndEnableHook((void*)0x0000000140500A80, sub_1408C8650, (LPVOID*)&sub_1408C8650_p); //ABORT_FIX
        //WriteMemory((void*)0x0000000140501284, "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90", 25);
        //MhCreateAndEnableHook((void*)0x0000000140500940, sub_1408C8650, (LPVOID*)&sub_1408C8650_p1);//ABORT_FIX
       //MhCreateAndEnableHook((void*)0x14011BE70, sub_1408C86501, (LPVOID*)&sub_1408C86501_p1);


       // MhCreateAndEnableHook(*CGameRules_KillPlayer_p, CGameRules_KillPlayer, (LPVOID*)&CGameRules_KillPlayer_p);



        MhCreateAndEnableHook(*CGameRules_Init_p, CGameRules_Init, (LPVOID*)&CGameRules_Init_p);
        MhCreateAndEnableHook((void*)0x140540480, CGameRules_BalancePlayers, (LPVOID*)&mnCGameRules_BalancePlayers_p);
        MhCreateAndEnableHook((void*)0x141BC2760, Crash_InCGame, (LPVOID*)&mCrashInCGame);
        MhCreateAndEnableHook(*mAddRegisterSoundListener, AddRegisterSoundListener, (LPVOID*)&mAddRegisterSoundListener);
        MhCreateAndEnableHook(*CGame_GetServerInfo_p, Game_GetServerInfo, (LPVOID*)&CGame_GetServerInfo_p);
       // MhCreateAndEnableHook(*CGame_Update_p, Game_Update, (LPVOID*)&CGame_Update_p);
        MhCreateAndEnableHook(*CGameStartup_Init_p, CGameStartup_InitMethod, (LPVOID*)&CGameStartup_Init_p);
        
        MhCreateAndEnableHook(*ResourceParticleParams__LoadResources_p, FlareItem, (LPVOID*)&ResourceParticleParams__LoadResources_p);
        MhCreateAndEnableHook((void*)0x1414C3180, sub_1414E0B70, (LPVOID*)&fixSub_p);
        MhCreateAndEnableHook((void*)0x140B59530, fixMetrics, (LPVOID*)&fixMetrics_p);
        //MhCreateAndEnableHook((void*)0x1404DECB0, fixMetrics, (LPVOID*)&fixMetrics2_p);
        MhCreateAndEnableHook(*CFlowChartManager_IsState_p, CFlowChartManager_IsState, (LPVOID*)&CFlowChartManager_IsState_p);
       MhCreateAndEnableHook((void*)0x1404909E0, CFlowchartManager_GetCurrentState, (LPVOID*)&CFlowchartManager_GetCurrentState_p);
        MhCreateAndEnableHook((void*)0x1404311F0, COnlineAccount__Update, (LPVOID*)&COnlineAccount__Update_p);
        MhCreateAndEnableHook(*SLobbyServerInfo_SerializeAllToXml_p, SLobbyServerInfo_SerializeAllToXml, (LPVOID*)&SLobbyServerInfo_SerializeAllToXml_p);
        MhCreateAndEnableHook(*CAbstractServerInfo_IsOwner_p, AbstractServerInfo_IsOwner, (LPVOID*)&CAbstractServerInfo_IsOwner_p);
        MhCreateAndEnableHook(*CCryAction_StartGameContext_p, CCryAction_StartGameContext, (LPVOID*)&CCryAction_StartGameContext_p);
        MhCreateAndEnableHook((void*)0x14059B3A0, CAbstractServerInfo__OnGameStarted, (LPVOID*)&CAbstractServerInfo__OnGameStarted_p);
        //MhCreateAndEnableHook((void*)0x1404DECB0, fMetrics, (LPVOID*)&CAbstractServerInfo__OnGameStarted_p3);
        MhCreateAndEnableHook((void*)0x140912DF0, sub_140912DF0, (LPVOID*)&CAbstractServerInfo__OnGameStarted_p3);
        MhCreateAndEnableHook(*CPlayer_CreateInputClassByType_p, CPlayer_CreateInputClassByType, (LPVOID*)&CPlayer_CreateInputClassByType_p);
        MhCreateAndEnableHook(*CActor_SetPhysicalizationProfile, CActor_SetPhysicalizationProfileHook, (LPVOID*)&CActor_SetPhysicalizationProfile);
        InitPatches();
        FixNops_ClientTokenIsMissmatch();
        FixQuerySend();
        AIInit();
        FixKillPhyicsThread();
        MhCreateAndEnableHook(*CGame_Init_p, CGame_Init, (LPVOID*)&CGame_Init_p);
                    //MhCreateAndEnableHook((void*)0x141C5AB80, SSADSDFSDFSDFSDF15èì
                    // , (LPVOID*)&SADSDFSDFSDFSDF15_p);


        SvRequestHitFix();
        FixUpdateAchievements();
        
                    MhCreateAndEnableHook(*CGameRules_Update, CGameRules_UpdateHook, (LPVOID*)&CGameRules_Update);
            MhCreateAndEnableHook((void*)0x1400AA610, sub_1400AA610, (LPVOID*)&SADSDFSDFSDFSDF5_p);
            MhCreateAndEnableHook((void*)0x1404BBA10, sub_1404BBA10, (LPVOID*)&SADSDFSDFSDFSDF12_p);
                MhCreateAndEnableHook((void*)CSM_CoopAssist__Finish_p, CSM_CoopAssist__Finish, (LPVOID*)&CSM_CoopAssist__Finish_p);
                MhCreateAndEnableHook((void*)mCSM_CoopClimb__Finish, CSM_CoopClimb__Finish, (LPVOID*)&mCSM_CoopClimb__Finish);
                 MhCreateAndEnableHook(*CGameRules_ReportGameEnd_p, GameRules_ReportGameEnd, (LPVOID*)&CGameRules_ReportGameEnd_p);
        
                MhCreateAndEnableHook(*SSetRewardsInfoSerializer_OnRequest_p, SetRewardsInfoSerializer_OnRequest, (LPVOID*)&SSetRewardsInfoSerializer_OnRequest_p);
        MhCreateAndEnableHook(*CScriptBind_GameRules_DisconnectToLobby_p, ScriptBind_GameRules_DisconnectToLobby, (LPVOID*)&CScriptBind_GameRules_DisconnectToLobby_p);

        //TODO: ôèêñ âîñõîä

        //MhCreateAndEnableHook((void*)0x141B89F90, sub_14083A610, (LPVOID*)&CAbstractServerInfo__OnGameStarted_p3);
        //MhCreateAndEnableHook((void*)0x140A712C0, CSM_HoldEntity_Finish, (LPVOID*)&CSM_HoldEntityFinish_p);
        //MhCreateAndEnableHook((void*)0x1414271C0, KillPhysicsThread, (LPVOID*)&CAbstractServerInfo__OnGameStarted_p4);
        bool IsCMASet = false;
        while (!IsCMASet) {
            if (DWORD64 NCreateMutexAAdr = (DWORD64)GetProcAddress(GetModuleHandle("KERNEL32"), "CreateMutexA")) {
                if (MH_CreateHook((void*)NCreateMutexAAdr, CreateMutexAHook, (LPVOID*)&mCreateMutexA) == MH_OK) {
                    MH_EnableHook((void*)NCreateMutexAAdr);
                    IsCMASet = true;
                }
            }
            Sleep(100);
        }
        ForClimb::Init();
        //MhCreateAndEnableHook(*CPhysicalWorld_GetEntitiesAround_p, CPhysicalWorld_GetEntitiesAround, (LPVOID*)&CPhysCallbacks_OnFoliageTouched_p);
        MhCreateAndEnableHook(*CPhysCallbacks_OnFoliageTouched_p, CPhysCallbacks_OnFoliageTouched, (LPVOID*)&CPhysCallbacks_OnFoliageTouched_p);
    }
    
	return 0;
}



