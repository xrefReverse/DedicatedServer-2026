//        .___         .___.__               __             .___                                               _______________   ________  ________
//      __| _/____   __| _/|__| ____ _____ _/  |_  ____   __| _/______ ______________  __ ___________          \_____  \   _  \  \_____  \/  _____/
//     / __ |/ __ \ / __ | |  |/ ___\\__  \\   __\/ __ \ / __ |/  ___// __ \_  __ \  \/ // __ \_  __ \  ______  /  ____/  /_\  \  /  ____/   __  \ 
//    / /_/ \  ___// /_/ | |  \  \___ / __ \|  | \  ___// /_/ |\___ \\  ___/|  | \/\   /\  ___/|  | \/ /_____/ /       \  \_/   \/       \  |__\  \
//    \____ |\___  >____ | |__|\___  >____  /__|  \___  >____ /____  >\___  >__|    \_/  \___  >__|            \_______ \_____  /\_______ \_____  /
//         \/    \/     \/         \/     \/          \/     \/    \/     \/                 \/                        \/     \/         \/     \/ 







#include "SDK.hpp"	
#include <vector>

#define gEnvAddr 0x142A2809E
#define gGameAddr 0x142A935B8
#define m_pPhysicalWorldAddr 0x142DB1800

#define CREATE_FUNCTOR(TYPE, NAME, OFFSET)								\
TYPE NAME##_GET() {														\
return *reinterpret_cast< TYPE* >(this + OFFSET);						\
}																		\
																		\
void NAME##_SET(TYPE VALUE) {											\
*reinterpret_cast< TYPE* >(this + OFFSET) = VALUE;						\
}																		\
																		\
__declspec(property(get = NAME##_GET, put = NAME##_SET)) TYPE NAME		\

#define CREATE_FUNCTOR_STRUCT(TYPE, NAME, OFFSET)						\
TYPE* NAME##_GET() {													\
return &*reinterpret_cast< TYPE* >(this + OFFSET);						\
}																		\
																		\
__declspec(property(get = NAME##_GET)) TYPE* NAME						\

/*
example:
CREATE_FUNCTOR(Type, Name, Offset);
CREATE_FUNCTOR(int, m_predictionHandle, 0x12);

*/

struct SGameContextParams
{
	const char* levelName;
	const char* gameRules;
	const char* demoRecorderFilename;
	const char* demoPlaybackFilename;

	SGameContextParams()
	{

	}
};

struct SGameStartParams
{
	const char* hostname;
	const char* connectionString;
	const SGameContextParams* pContextParams;
	unsigned int flags;
	int maxPlayers;
	unsigned int session;
	unsigned __int16 port;
	const char* nickname;
};



template<typename ClassData>
__forceinline ClassData CallFunction(PVOID64 BaseClass, INT vIndex)
{
	PDWORD64* vPointer = (PDWORD64*)BaseClass;
	PDWORD64 vFunction = *vPointer;
	DWORD64 dwAddress = vFunction[vIndex / 8];
	return (ClassData)(dwAddress);
}
template <typename T> struct CryStringT {
	typedef T					valueFpe;
	typedef const valueFpe* const_str;
	typedef const valueFpe* const_pointer;
	typedef const_pointer		const_iterator;

	struct StrHeader {
		volatile int nRefCount;
		int nLength;
		int nAllocSize;
		valueFpe* GetChars() { return (valueFpe*)(this + 1); }
		void AddRef() { ++nRefCount; };
		int Release() { return --nRefCount; };
	};

	int length() const { return m_header->nLength; }

	const_iterator begin() const { return m_str; };
	const_iterator end() const { return m_str + length(); };

	operator const_str() const { return m_str; }

	const valueFpe* c_str() const { return m_str; }
	const valueFpe* data() const { return m_str; };

	valueFpe* m_str;
	StrHeader* m_header;
};

typedef CryStringT<char>							StringT;

struct AcccountLogin {
public:
	CryStringT< char> authorize; // 0x0000008
	CryStringT< char> authorize1; // 0x0000008
};

class SSystemInitParams {
public:
	char pad_0x0[2891];
	bool m_pDedicatedServer;
	bool bExecuteCommandLine;
	bool bUIFramework;
	bool bSkipFont;
	bool bSkipRenderer;


	//CREATE_FUNCTOR(bool, m_pSkipRenderer, 0xB4F);
};

struct CMissionBackend {
public:

};

struct COnlineAccount {
public:
	char pad_0x0000[0xE8];
	EConnectionState m_state;
};

struct IGameFramework {
public:

};

struct CBackend {
public:

};

struct CAbstractServerInfo {
public:
	char pad_0185[353];
	bool m_telemetrySent;
	using FN_Update = void(__thiscall*)(CAbstractServerInfo*, bool);
	static void Update(CAbstractServerInfo* m_pServerInfo, bool isForceUpdate) {
		FN_Update(0x14059B120)(m_pServerInfo, isForceUpdate);
	}
};

struct CPlayer {
public:
	char p_0x1554[0x1554];
	Vec3 helperClosestPointSM;
	//CREATE_FUNCTOR(Vec3_tpl<float>*, helperClosestPointSM, 0x1554);
};

struct IGameObject{
public:
	IGameObject* ChangedNetworkState(unsigned int a1)
	{
		return CallFunction<IGameObject * (__thiscall*)(PVOID64, unsigned int)>(this, 0x20)(this, a1);
	}
	IGameObject* ChangedNetworkStateW(unsigned int a1)
	{
		return CallFunction<IGameObject * (__thiscall*)(PVOID64, unsigned int)>(this, 0x20)(this, a1);
	}
	IGameObject* SetAspectProfile(__int64 aspect, unsigned __int8 profile, bool fromNetwork)
	{
		return CallFunction<IGameObject * (__thiscall*)(PVOID64, __int64, unsigned __int8, bool)>(this, 0xA8)(this, aspect, profile, fromNetwork);
	}

};
struct IRenderMesh;
struct IFoliage;

enum EStaticSubObjectType : int {
	STATIC_SUB_OBJECT_MESH = 0x0,
	STATIC_SUB_OBJECT_HELPER_MESH = 0x1,
	STATIC_SUB_OBJECT_POINT = 0x2,
	STATIC_SUB_OBJECT_DUMMY = 0x3,
	STATIC_SUB_OBJECT_XREF = 0x4,
	STATIC_SUB_OBJECT_CAMERA = 0x5,
	STATIC_SUB_OBJECT_LIGHT = 0x6,
};

struct IStatObj {
	struct SSubObject {
		EStaticSubObjectType nType;
		StringT name;
		StringT properties;
		int nParent;
		Matrix34_tpl<float> tm;
		Matrix34_tpl<float> localTM;
		IStatObj* pStatObj;
		Vec3_tpl<float> helperSize;
		IRenderMesh* pWeights;
		IFoliage* pFoliage;
		unsigned __int32 bIdentityMatrix : 1;
		unsigned __int32 bHidden : 1;
		unsigned __int32 bShadowProxy : 1;
		unsigned __int32 nBreakerJoints : 8;
	};

	int GetSubObjectCount() {
		return CallFunction<int(__fastcall*)(PVOID)>(this, 448)(this);
	}

	IStatObj::SSubObject* GetSubObject(int nIndex) {
		//typedef IStatObj::SSubObject* (__fastcall* COnlineChannel_Update)(void*, int);
		//return COnlineChannel_Update(0x141D04DC0)(this, nIndex);
		return CallFunction<IStatObj::SSubObject * (__fastcall*)(PVOID, int)>(this, 464)(this, nIndex);
	}
};

struct IEntity {
public:
	IStatObj* GetStatObj(int nSlot) { return CallFunction<IStatObj * (__fastcall*)(PVOID, int)>(this, 0x2B8)(this, nSlot); }// hasGeometry
	const char* GetName() { return CallFunction<const char* (__thiscall*)(PVOID)>(this, 0x68)(this); }
	void SetLocalPos(Vec3& LocalPos) {
		CallFunction<void(__fastcall*)(PVOID64, Vec3&, uint64_t)>(this, 0xE0)(this, LocalPos, 0);
	}
	void SetLocalAngles(Vec3& LocalPos) {
		CallFunction<void(__fastcall*)(PVOID64, Vec3&, uint64_t)>(this, 0xF0)(this, LocalPos, 0);
	}
	Matrix34& GetWorldTM()
	{
		return CallFunction<Matrix34 & (__thiscall*)(PVOID64)>(this, 0xC0)(this);
	}
};

struct CActor {
public:
	CREATE_FUNCTOR(IEntity*, m_pEntity, 0x10);
	CREATE_FUNCTOR(IGameObject*, m_pGameObjcet, 0x18);
};

struct IStreamEngine {
public:

};

struct CGameAI {
public:
	char pad_240[240];
	bool bAI;
	void Func1() {
		CallFunction<void(__fastcall*)(PVOID64) >(this, 952)(this);
	}
	void Func2() {
		CallFunction<void(__fastcall*)(PVOID64) >(this, 960)(this);
	}
};

struct CGame {
public:
	CREATE_FUNCTOR(CBackend*, m_pBackend, 0x1A0);
	CREATE_FUNCTOR(CMissionBackend*, m_pMissionBackend, 0x3D8);
	CREATE_FUNCTOR(CAbstractServerInfo*, m_pServerInfo, 0x1B8);
	CGameAI* GetAI() {
		return CallFunction<CGameAI * (__fastcall*)(PVOID64) >(this, 0x68)(this);
	}
	static CGame* Singlenton() {
		return *(CGame**)gGameAddr;
	}
};

typedef CAbstractServerInfo* (__fastcall* CAbstractServerInfoClass)(CAbstractServerInfo* this1, __int64 compressType);
CAbstractServerInfoClass CAbstractServerInfo_CAbstractServerInfo = (CAbstractServerInfoClass)0x14059B600;

typedef CBackend* (__fastcall* CBackend_CBackendClass)(CBackend* this1, IGameFramework* fw);
CBackend_CBackendClass CBackend_CBackend = (CBackend_CBackendClass)0x14010B850;

struct SSegment
{
	Lineseg_tpl<float> seg;
	float length;
	float velocity;
};

struct CPiecewiseTrajectory
{
	std::vector<SSegment, std::allocator<SSegment> > m_segments;
	float m_totalLength;
	int m_curSegment;
	float m_segmentOffset;
	float m_totalOffset;
	Vec3_tpl<float> m_curPos;
	float m_curVelocity;
};


struct CSM_Climb {
public:
	void* __vftable /*VFT*/;
	void* m_pClass;
	CPlayer* m_pPlayer;
	Lineseg_tpl<float> m_helper;
	CPiecewiseTrajectory m_trajectory;
	void* m_safeCapsule;
	int m_animIndex;
	bool m_animRequested;
	bool m_animStarted;
	bool m_animFinished;
	QuatT_tpl<float> m_animStartPose;
	Vec3_tpl<float> m_helperClosestPoint;
};

typedef IStreamEngine* (__fastcall* CStreamEngine_CStreamEngineClass)(IStreamEngine*);
CStreamEngine_CStreamEngineClass CStreamEngine_CStreamEngine = (CStreamEngine_CStreamEngineClass)0x1414825A0;

typedef CMissionBackend* (__fastcall* CBackend_CMissionBackendClass)(CMissionBackend* this1);
CBackend_CMissionBackendClass CMissionBackend_CMissionBackend = (CBackend_CMissionBackendClass)0x1404AD9B0;


interface ICVar
{
	const char* GetString() {
		return CallFunction<const char* (__thiscall*)(PVOID64)>(this, 40)(this);
	}
};
interface SCVars
{
	CREATE_FUNCTOR(SCVars*, online_dedicated_host_name, 3592);

	CREATE_FUNCTOR(SCVars*, online_dedicated_perf_idx_cpu, 3636);
	CREATE_FUNCTOR(SCVars*, online_dedicated_perf_idx_memory, 3640);
	CREATE_FUNCTOR(SCVars*, online_dedicated_load_average, 3644);
	CREATE_FUNCTOR(SCVars*, online_dedicated_autoshutdown_memory_limit, 3648);
	CREATE_FUNCTOR(SCVars*, online_dedicated_autoshutdown_wait_timeout, 3652);
	CREATE_FUNCTOR(SCVars*, online_dedicated_autoshutdown_data_sent_wait_timeout, 3656);
	CREATE_FUNCTOR(int, e_CullVegActivation, 0xB4);

	static SCVars* Singlenton(){
		return *(SCVars**)0x142A935C8;
	}
};

struct XmlNodeRefV2 {
	void ReadAttribute(const char* attribute, StringT* structured) {
		CallFunction<void(__thiscall*)(PVOID64, const char*, StringT*) >(this, 0xC0)(this, attribute, structured);
	}
};

struct IXmlNode {
public:
	void setAttr(const char* name, const char* attribute) {
		CallFunction<void(__thiscall*)(PVOID64, const char*, const char*) >(this, 0x210)(this, name, attribute);
	}

	XmlNodeRefV2* FindChild(XmlNodeRefV2** result, const char* childing) {
		return CallFunction<XmlNodeRefV2 * (__thiscall*)(PVOID64, XmlNodeRefV2 * *outNode, const char* childName)>(
			this, 0x210
		)(this, result, childing);
	}

};

struct  XmlNodeRef {
public:
	IXmlNode* p;
};

typedef bool(__fastcall* FCAbstractServerInfo_IsOwner)(CAbstractServerInfo*, const char*);
FCAbstractServerInfo_IsOwner CAbstractServerInfo_IsOwner_p = (FCAbstractServerInfo_IsOwner)0x14059B2F0;

bool __fastcall AbstractServerInfo_IsOwner(CAbstractServerInfo* this1, const char* masterserver_resource) {
	return 1;
}


struct SLobbyServerInfo;

struct SLobbyServerInfo
{
	char pad_0000[0x88];
	const char* sMasterServerResource;
};


interface IConsole
{
public:
	SCVars* Register() {

	}

	SCVars* RegisterString(const char* sName, const char* sValue, int nFlags, const char* help, void(__cdecl* pChangeFunc)(SCVars*)) //0x10
	{
		return CallFunction<SCVars * (__thiscall*)(PVOID64, const char*, const char*, int, const char*, void(__cdecl*)(SCVars*))>(this, 0x10)(this, sName, sValue, nFlags, help, pChangeFunc);
	}
	IConsole* RegisterInt(const char* a1, __int64 a2) {
		return CallFunction<IConsole * (__thiscall*)(PVOID64, const char*, __int64) >(this, 0x18)(this, a1, a2);
	}
	SCVars* RegisterInt(const char* sName, int sValue, int nFlags, const char* help, void(__cdecl* pChangeFunc)(SCVars*))
	{
		return CallFunction<SCVars * (__thiscall*)(PVOID64, const char*, int, int, const char*, void(__cdecl*)(SCVars*))>(this, 0x18)(this, sName, sValue, nFlags, help, pChangeFunc);
	}
	IConsole* ExecuteString(const char* a1, bool a2, bool a3) {
		return CallFunction<IConsole * (__thiscall*)(PVOID64, const char*, bool, bool) >(this, 0x118)(this, a1, a2, a3);
	}

	ICVar* GetCVar(const char* pName) { return CallFunction<ICVar * (__thiscall*)(PVOID64, const char*)>(this, 0xB8)(this, pName); }
};
struct   SOBJECTSTATE {
	bool jump;
	bool aimObstructed;
	bool aimTargetIsValid;
	bool forceWeaponAlertness;
	void* fire;
	void* fireSecondary;
	void* fireMelee;
	void* requestedGrenadeType;
	int weaponAccessories;
	int bodystate;
	float lean;
	float peekOver;
	float fHitProbability;
//	Vec3_tpl<float> vShootTargetPos;
//	Vec3_tpl<float> vAimTargetPos;
//	Vec3_tpl<float> vLookTargetPos;
	void* projectileInfo;
	void* eLookStyle;
//	Vec3_tpl<float> vMoveDir;
//	Vec3_tpl<float> vForcedNavigation;
//	Vec3_tpl<float> vBodyTargetDir;
//	Vec3_tpl<float> vDesiredBodyDirectionAtTarget;
	float fForcedNavigationSpeed;
	unsigned int movementContext;
	void* predictedCharacterStates;
//	Vec3_tpl<float> vMoveTarget;
//	Vec3_tpl<float> vInflectionPoint;
	float fMovementUrgency;
	float fDesiredSpeed;
	bool allowStrafing;
	bool allowEntityClampingByAnimation;
	void* remainingPath;
	float fDistanceToPathEnd;
	void* curActorTargetPhase;
//	Vec3_tpl<float> curActorTargetFinishPos;
	void* actorTargetReq;
	bool bCloseContact;
	bool bHurryNow;
	bool bReevaluate;
	bool bTargetEnabled;
	bool bTargetIsGroupTarget;
	bool continuousMotion;
	void* eTargetType;
	void* eTargetContextType;
	void* eTargetThreat;
	unsigned int eTargetID;
	void* ePeakTargetType;
	void* ePeakTargetThreat;
	unsigned int ePeakTargetID;
	void* ePreviousPeakTargetType;
	void* ePreviousPeakTargetThreat;
	unsigned int ePreviousPeakTargetID;
//	Vec3_tpl<float> vTargetPos;
	float fDistanceFromTarget;
	void* eTargetStuntReaction;
	int nTargetType;
	void* Signals;
	int nAuxSignal;
	char* szAuxSignalText;
	float fAuxDelay;
	int nAuxPriority;
	int secondaryIndex;
};


struct AISystemInit {
public:
	void Initialization() {
		CallFunction<void(__fastcall*)(PVOID64)>(this, 8)(this);
	}
	void Reset(int i = 0) {
		CallFunction<void(__fastcall*)(PVOID64, __int64)>(this, 32)(this, i);
	}
};

struct IAISystem {
public:
	char pad_0001[0xB1];
	bool bEnabled;
};

struct AISystem {
public:
	virtual void AISystemW();
	virtual bool InitAI();
};

struct CSystem {
public:
	char pad_0x9A8[3048];
	IStreamEngine* m_pStreamEngine;
	void* InitAI(SOBJECTSTATE* mObjectState) {
		return CallFunction<void* (__fastcall*)(PVOID, SOBJECTSTATE*)>(this, 0x680)(this, mObjectState);
	}
	AISystemInit* Init_V2()
	{
		return CallFunction<AISystemInit * (__thiscall*)(PVOID)>(this, 576)(this);
	}

	int IsSerializingFile() {
		return CallFunction<int (__thiscall*)(PVOID)>(this, 0x100)(this);
		//0x100
	}

};

struct CTimeValue {
public:
	__int64 m_lValue;
};


enum ETimer : __int32
{
	ETIMER_GAME = 0x0,
	ETIMER_UI = 0x1,
	ETIMER_LAST = 0x2,
};

struct ITimer {
public:
	CTimeValue* GetFrameStartTimer(ETimer a1) {
		return CallFunction<CTimeValue * (__thiscall*)(PVOID, ETimer)>(this, 0x20i64)(this, a1);
	}
};

struct IRenderer {
public:
	using FN_DrawLabelExecute = void(__thiscall*)(IRenderer*, double x, double y, float font_size, const float* pfColor, bool bCenter, const char* label_text);
	
	void DrawLabel(double x,double y,float font_size,const float* pfColor,bool bCenter,const char* label_text,...) {
		FN_DrawLabelExecute(0x14035C1B0)(this, x, y, font_size, pfColor, bCenter, label_text);
	}
	static IRenderer* Singlenton() {
		return *(IRenderer**)0x142DB17E8;
	}
};

struct IScrypts {
public:
	bool N00000058; //0x0008
	void* N0000005A; //0x0009
	char pad_0011[65]; //0x0011

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual bool ExecuteBuffer(const char* sBuffer, size_t nSize, const char* sBufferDescription = "", interface IScriptTable* pEnv = 0) = 0;
	bool ExecuteLua(std::string cmd) { return ExecuteBuffer(cmd.c_str(), cmd.size()); }
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void unknown();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
	virtual void Function32();
	virtual void Function33();
	virtual void Function34();
	virtual void Function35();
	virtual void Function36();
	virtual void Function37();
	virtual void Function38();
	virtual void Function39();
	virtual void Function40();
	virtual void Function41();
	virtual void Function42();
	virtual void Function43();
	virtual void Function44();
	virtual void Function45();
	virtual void Function46();
	virtual void Function47();
	virtual void Function48();
	virtual void Function49();
	virtual void Function50();
};

struct IPlayer {
public:
	CREATE_FUNCTOR(unsigned int, holdEntity, 0x14A8);
	CREATE_FUNCTOR(IGameObject*, m_pGameObject, 0x18);
};

struct CPhysStreamer {
public:

};

struct IPhysicalWorld {
public:
	__int64 SetPhysicsStreamer(void** g_pHysStreamer) 
	{
		return CallFunction<__int64 (__fastcall*)(PVOID, void**)>(this, 464i64)(this, g_pHysStreamer);
	}
	static IPhysicalWorld* Singlenton() {
		return *(IPhysicalWorld**)m_pPhysicalWorldAddr;
	}
};

struct IEntityIt{
public:
	IEntity* Next() {
		return CallFunction<IEntity* (__fastcall*)(PVOID)>(this, 48i64)(this);
	}
};

struct IEntitySystem {
public:
	IEntityIt* GetIt() {
		return CallFunction<IEntityIt*(__fastcall*)(PVOID)>(this, 0xA8i64)(this);
	}
};

struct SSystemGlobalEnvironment {
public:
	auto GetCSystem() {
		uintptr_t base = (uintptr_t)this;
		uintptr_t ptr = *(uintptr_t*)(base + 0xA6C78809307C5F8);
		ptr ^= 0xDDBE6106DA0063AFui64;
		return reinterpret_cast<CSystem*>(ptr);
	}
	auto GetIGame() {
		return NULL;
		//uintptr_t base = (uintptr_t)this;
		//uintptr_t ptr = *(uintptr_t*)(base + 0xA6C78809307C5C1i64);
		//ptr -= 0x4855CEEAA9742D05i64;
		//return reinterpret_cast<CGame*>(ptr);
	}
	auto GetIConsole() {
		uintptr_t base = (uintptr_t)this;
		uintptr_t ptr = *(uintptr_t*)(base + 0xA6C78809307C5AFi64);
		ptr += 0x29206D131BC05B14i64;
		return reinterpret_cast<IConsole*>(ptr);
	}


	IAISystem* GetAISystemV2() {
		//0xA6C78809307C623i64
		uintptr_t base = (uintptr_t)this;
		uintptr_t ptr = *(uintptr_t*)(base + 0xA6C78809307C623i64);
		ptr -= 0x46EA9F5B36EEC869i64;
		return reinterpret_cast<IAISystem*>(ptr);
	}

	AISystem* GetAISystem() {
		//0xA6C78809307C623i64
		uintptr_t base = (uintptr_t)this;
		uintptr_t ptr = *(uintptr_t*)(base + 0xA6C78809307C623i64);
		ptr -= 0x46EA9F5B36EEC869i64;
		return reinterpret_cast<AISystem*>(ptr);
	}

	ITimer* GetITimer() {
		uintptr_t base = (uintptr_t)this;
		uintptr_t ptr = *(uintptr_t*)(base + 0xA6C78809307C5A2i64);
		ptr ^= 0xF451830C1D1B5452ui64;
		return reinterpret_cast<ITimer*>(ptr);
	}

	IRenderer* GetIRenderer() {
		uintptr_t base = (uintptr_t)this;
		uintptr_t ptr = *(uintptr_t*)(base + 0xA6C78809307C4BDi64);
		ptr += 0x7A37EB6B98A5CBD8i64;
		return reinterpret_cast<IRenderer*>(ptr);
	}

	IScrypts* GetScrypts() {
		uintptr_t base = (uintptr_t)this;
		uintptr_t ptr = *(uintptr_t*)(base + 0xA6C78809307C4ACi64);
		ptr += 0x535BEBF19D872D66i64;
		return reinterpret_cast<IScrypts*>(ptr);
	}

	IEntitySystem* GetEntitySystem() {
		uintptr_t base = (uintptr_t)this;
		uintptr_t ptr = *(uintptr_t*)(base + 0xA6C78809307C5E0i64);
		ptr -= 0x3F1129737D867504i64;
		return reinterpret_cast<IEntitySystem*>(ptr);
	}

	static SSystemGlobalEnvironment* Singleton() {
		return *(SSystemGlobalEnvironment**)gEnvAddr;
	}
};

#include "ForClimb.hpp"
