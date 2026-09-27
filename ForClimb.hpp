//        .___         .___.__               __             .___                                               _______________   ________  ________
//      __| _/____   __| _/|__| ____ _____ _/  |_  ____   __| _/______ ______________  __ ___________          \_____  \   _  \  \_____  \/  _____/
//     / __ |/ __ \ / __ | |  |/ ___\\__  \\   __\/ __ \ / __ |/  ___// __ \_  __ \  \/ // __ \_  __ \  ______  /  ____/  /_\  \  /  ____/   __  \ 
//    / /_/ \  ___// /_/ | |  \  \___ / __ \|  | \  ___// /_/ |\___ \\  ___/|  | \/\   /\  ___/|  | \/ /_____/ /       \  \_/   \/       \  |__\  \
//    \____ |\___  >____ | |__|\___  >____  /__|  \___  >____ /____  >\___  >__|    \_/  \___  >__|            \_______ \_____  /\_______ \_____  /
//         \/    \/     \/         \/     \/          \/     \/    \/     \/                 \/                        \/     \/         \/     \/ 





#pragma once
#include <limits>
#include <cmath>
#define NOMINMAX
#include <Windows.h>

namespace ForClimb {
	std::vector<__int64> VectorsEntityIdForServers;

	struct SLedgeObjectInfo
	{
		Lineseg_tpl<float> ledge;
		unsigned int entityId;
		float t1;
		float t2;
	};

	struct CSpecialMovementHelpersManager
	{
		std::vector<SLedgeObjectInfo, std::allocator<SLedgeObjectInfo> > m_staticLedgeObjects;
		std::vector<SLedgeObjectInfo, std::allocator<SLedgeObjectInfo> > m_dynamicLedgeObjects;
	};
	enum ELedgeHelperType : __int32
	{
		eLHT_UnknownHelper = 0xFFFFFFFF,
		eLHT_VaultHelper = 0x0,
		eLHT_ClimbHelper = 0x1,
	};

	struct XMVec4
	{

	};
	struct Matrix34_tpl
	{
		float m00;
		float m01;
		float m02;
		float m03;
		float m10;
		float m11;
		float m12;
		float m13;
		float m20;
		float m21;
		float m22;
		float m23;
	};
	struct SLedgeInfo
	{
		ELedgeHelperType type;
		Lineseg_tpl<float> ledge;
		bool switchable;
		IStatObj* pHelperStatObj;
		Matrix34_tpl helperTM;
	};
	struct  __declspec(align(4)) SHelper
	{
		//int BlackMoon;
		Lineseg_tpl<float> edges[4];
		int numEdges;
		bool switchable;
	};
	struct CSpecialMovementSystem_SStatObjCachedInfo
	{
		IStatObj* pStatObj;
		std::vector<SLedgeInfo, std::allocator<SLedgeInfo> > ledges;
		std::vector<SHelper, std::allocator<SHelper> > helpers;
	};

	struct CSpecialMovementSystem {

		CREATE_FUNCTOR(CSpecialMovementHelpersManager, m_helpersManager, 0x40);

		//CSpecialMovementSystem_SStatObjCachedInfo m_statObjCachedInfo;
		//CSpecialMovementHelpersManager m_helpersManager;
	};

	CSpecialMovementHelpersManager m_helpersManagerFull;
	std::vector<Vec3_tpl<float>> m_pHelperPoses;


	typedef void(__fastcall* CLevelSystemClass)(CSpecialMovementSystem* this1,
		void* info,
		void* pLoadContex);
	CLevelSystemClass CLevelSystem_LoadLevel_p = (CLevelSystemClass)0x1403EFAD0;



	void __fastcall RegisterLedgeObject(CSpecialMovementSystem* this1,void* info,void* pLoadContext)
	{
		CLevelSystem_LoadLevel_p(this1, info, pLoadContext);

		printf("m_dynamicLedgeObjects: %i\n", this1->m_helpersManager.m_dynamicLedgeObjects.size());
		printf("m_staticLedgeObjects: %i\n", this1->m_helpersManager.m_staticLedgeObjects.size());
		m_helpersManagerFull = this1->m_helpersManager;
	}
	typedef void(__fastcall* RegisterLedgeObjectsClass)(CSpecialMovementSystem* this1, void* objectsNode, void* pLoadContext);
	RegisterLedgeObjectsClass RegisterLedgeObjects_p = (RegisterLedgeObjectsClass)0x1403EF830;
	void __fastcall RegisterLedgeObjects(CSpecialMovementSystem* this1,void* objectsNode,void* pLoadContext)
	{
		RegisterLedgeObjects_p(this1, objectsNode, pLoadContext);
		m_pHelperPoses.clear();

		for (auto& obj : m_helpersManagerFull.m_dynamicLedgeObjects)
		{
			for (float t = 0.0f; t <= 1.0f; t += 0.25f)
			{
				m_pHelperPoses.push_back(obj.ledge.GetPoint(t));
			}
		}

		for (auto& obj : m_helpersManagerFull.m_staticLedgeObjects)
		{
			for (float t = 0.0f; t <= 1.0f; t += 0.25f)
			{
				m_pHelperPoses.push_back(obj.ledge.GetPoint(t));
			}
		}

		for (auto& m_helperPos : m_pHelperPoses) {
			printf("founded blackmoon pos: { %f, %f, %f }\n", m_helperPos.x, m_helperPos.y, m_helperPos.z);
		}



	}
	typedef bool(__fastcall* IsPathBlockedClass)(void* this1, CActor* pPlayer, const Vec3_tpl<float>* checkPos, CPlayer* pAssister);
	IsPathBlockedClass IsPathBlocked_p = (IsPathBlockedClass)0x1403EA660;
	
	float DistXY(const Vec3_tpl<float>& a, const Vec3_tpl<float>& b)
	{
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		return std::sqrt(dx * dx + dy * dy);
	}

	float DistanceSq(const Vec3& a, const Vec3& b)
	{
		float dx = a.x - b.x;
		float dy = a.y - b.y;
		float dz = a.z - b.z;
		return dx * dx + dy * dy + dz * dz;
	}

	bool __fastcall IsPathBlocked(void* this1, CActor* pPlayer, const Vec3_tpl<float>* checkPos, CPlayer* pAssister)
	{
		if (m_pHelperPoses.empty())
			return FALSE;

		Vec3 playerPos =
		{
			pPlayer->m_pEntity->GetWorldTM().GetTranslation().x,
			pPlayer->m_pEntity->GetWorldTM().GetTranslation().y,
			pPlayer->m_pEntity->GetWorldTM().GetTranslation().z
		};

		float bestDist = 1e30f;
		Vec3 bestPoint{};
		bool found = false; // <-- добавляем флаг

		for (const auto& pt : m_pHelperPoses)
		{
			float dz = fabsf(playerPos.z - pt.z);
			if (dz > 4.0f)
				continue;

			float dx = playerPos.x - pt.x;
			float dy = playerPos.y - pt.y;
			float dist = dx * dx + dy * dy;

			if (dist < bestDist)
			{
				bestDist = dist;
				bestPoint = pt;
				found = true; // нашли подходящую точку
			}
		}

		if (!found)
		{
			printf("BLOCKED! No suitable helper points found\n");
			return true;
		}

		// радиус 6 метров
		const float maxDist = 6.0f;
		const float maxDistSq = maxDist * maxDist;

		if (bestDist > maxDistSq)
		{
			printf("BLOCKED!\n");
			printf("DistanceXY: %.2f\n", sqrtf(bestDist));
			printf("Player: {%f %f %f}\n", playerPos.x, playerPos.y, playerPos.z);
			printf("Point:  {%f %f %f}\n", bestPoint.x, bestPoint.y, bestPoint.z);
			return true;
		}

		printf("OK (distXY=%.2f)\n", sqrtf(bestDist));
		return IsPathBlocked_p(this1, pPlayer, checkPos, pAssister);
		
	}



	//void __fastcall CSMClimb__Finish(CSM_Climb* this1) {
	//	CSMClimb__Finish_p(this1);
	//
	//	printf("Vector for m_helper (start) {%i, %i, %i}\n", this1->m_helper.start.x, this1->m_helper.start.y, this1->m_helper.start.z);
	//	printf("Vector for m_helper (end) {%i, %i, %i}\n", this1->m_helper.end.x, this1->m_helper.end.y, this1->m_helper.end.z);
	//	printf("Vector for m_helperClosestPoint {%i, %i, %i}\n", this1->m_helperClosestPoint.x, this1->m_helperClosestPoint.y, this1->m_helperClosestPoint.z);
	//
	//}

	void Init() {
		//printf("CryAntiCheat.dll has loaded.\n");
		//MhCreateAndEnableHook(*CLevelSystem_LoadLevel_p, RegisterLedgeObject, (LPVOID*)&CLevelSystem_LoadLevel_p);
		//MhCreateAndEnableHook(*RegisterLedgeObjects_p, RegisterLedgeObjects, (LPVOID*)&RegisterLedgeObjects_p);
		//MhCreateAndEnableHook(*IsPathBlocked_p, IsPathBlocked, (LPVOID*)&IsPathBlocked_p);
	}
}
