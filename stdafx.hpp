#pragma once

//        .___         .___.__               __             .___                                               _______________   ________  ________
//      __| _/____   __| _/|__| ____ _____ _/  |_  ____   __| _/______ ______________  __ ___________          \_____  \   _  \  \_____  \/  _____/
//     / __ |/ __ \ / __ | |  |/ ___\\__  \\   __\/ __ \ / __ |/  ___// __ \_  __ \  \/ // __ \_  __ \  ______  /  ____/  /_\  \  /  ____/   __  \ 
//    / /_/ \  ___// /_/ | |  \  \___ / __ \|  | \  ___// /_/ |\___ \\  ___/|  | \/\   /\  ___/|  | \/ /_____/ /       \  \_/   \/       \  |__\  \
//    \____ |\___  >____ | |__|\___  >____  /__|  \___  >____ /____  >\___  >__|    \_/  \___  >__|            \_______ \_____  /\_______ \_____  /
//         \/    \/     \/         \/     \/          \/     \/    \/     \/                 \/                        \/     \/         \/     \/ 






#include "MH/MinHook.h"
void MhCreateAndEnableHook(LPVOID pTarget, LPVOID pDetour, LPVOID* ppOriginal) {

    bool F1Set = false;

    while (!F1Set)
    {
        if (MH_CreateHook(pTarget, pDetour, ppOriginal) == MH_OK)
        {
            MH_EnableHook(pTarget);
            //  Data::hooks++;
            F1Set = true;
        }

        Sleep(1);
    }

}
#include <iostream>
#include <string>
#include <stdio.h>
#include "Enumerations.hpp"
#include "Classess.hpp"
#include "Startup.hpp"
