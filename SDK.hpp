#include <combaseapi.h>

//        .___         .___.__               __             .___                                               _______________   ________  ________
//      __| _/____   __| _/|__| ____ _____ _/  |_  ____   __| _/______ ______________  __ ___________          \_____  \   _  \  \_____  \/  _____/
//     / __ |/ __ \ / __ | |  |/ ___\\__  \\   __\/ __ \ / __ |/  ___// __ \_  __ \  \/ // __ \_  __ \  ______  /  ____/  /_\  \  /  ____/   __  \ 
//    / /_/ \  ___// /_/ | |  \  \___ / __ \|  | \  ___// /_/ |\___ \\  ___/|  | \/\   /\  ___/|  | \/ /_____/ /       \  \_/   \/       \  |__\  \
//    \____ |\___  >____ | |__|\___  >____  /__|  \___  >____ /____  >\___  >__|    \_/  \___  >__|            \_______ \_____  /\_______ \_____  /
//         \/    \/     \/         \/     \/          \/     \/    \/     \/                 \/                        \/     \/         \/     \/ 









enum EStance {
	STANCE_NULL = -1,
	STANCE_STAND = 0,
	STANCE_CROUCH,
	STANCE_PRONE,
	STANCE_RELAXED,
	STANCE_STEALTH,
	STANCE_LOW_COVER,
	STANCE_ALERTED,
	STANCE_HIGH_COVER,
	STANCE_SWIM,
	STANCE_ZEROG,

	//! This value must be last.
	STANCE_LAST
};
template <typename F> struct Color_tpl
{
public:
	F a, r, g, b;

	Color_tpl() { Color_tpl(0, 0, 0, 0); }
	Color_tpl(int a, int r, int g, int b) { this->a = a; this->r = r; this->g = g; this->b = b; }
	Color_tpl(int r, int g, int b) { this->a = 255; this->r = r; this->g = g; this->b = b; }
	Color_tpl(unsigned long color) { this->b = (color & 0xff); this->g = ((color >> 8) & 0xff); this->r = ((color >> 16) & 0xff); this->a = ((color >> 24) & 0xff); }
	inline float* Base()
	{
		float fColor[3];
		fColor[0] = this->r / 255.0f;
		fColor[1] = this->g / 255.0f;
		fColor[2] = this->b / 255.0f;
		return &fColor[0];
	}

	inline float rBase() const { return this->r / 255.0f; }
	inline float gBase() const { return this->g / 255.0f; }
	inline float bBase() const { return this->b / 255.0f; }
	inline float aBase() const { return this->a / 255.0f; }

	inline operator unsigned long() const { return (a << 24) | (r << 16) | (g << 8) | b; }
};
enum EHARDWAREMOUSEEVENT
{
	HARDWAREMOUSEEVENT_MOVE,
	HARDWAREMOUSEEVENT_LBUTTONDOWN,
	HARDWAREMOUSEEVENT_LBUTTONUP,
	HARDWAREMOUSEEVENT_LBUTTONDOUBLECLICK,
	HARDWAREMOUSEEVENT_RBUTTONDOWN,
	HARDWAREMOUSEEVENT_RBUTTONUP,
	HARDWAREMOUSEEVENT_RBUTTONDOUBLECLICK,
	HARDWAREMOUSEEVENT_MBUTTONDOWN,
	HARDWAREMOUSEEVENT_MBUTTONUP,
	HARDWAREMOUSEEVENT_MBUTTONDOUBLECLICK,
	HARDWAREMOUSEEVENT_WHEEL,
};

enum EUIDRAWHORIZONTAL {
	UIDRAWHORIZONTAL_LEFT,
	UIDRAWHORIZONTAL_CENTER,
	UIDRAWHORIZONTAL_RIGHT
};
enum EUIDRAWVERTICAL {
	UIDRAWVERTICAL_TOP,
	UIDRAWVERTICAL_CENTER,
	UIDRAWVERTICAL_BOTTOM
};
enum class eVictoryCondition : int
{
	eVC_Lobby = 0,
	eVC_Deathmatch,
	eVC_Occupation,
	eVC_PVE,
	eVC_Undermining,
	eVC_Storm,
	eVC_Chopper,
	eVC_Destruction,
	eVC_Domination,
	eVC_Survival
};
class CryCRT
{
public:
	static float sqrt(float number);
	static float isqrt_safe_tpl(float op);
	//	static PVOID memcpy(PVOID dest, const PVOID src, uint64 count);
	//	static PVOID memset(PVOID src, int val, uint64 count);
	static char strstr(char _Str, char _SubStr);
	static int strcmp(char cs, char ct);
	static PVOID RtlSecureZeroMemory(PVOID  ptr, SIZE_T cnt);
};

enum class EWeaponStates
{
	eWS_Disabled,
	eWS_Idle,
	eWS_IdleZoomed,
	eWS_Fire,
	eWS_IdleUnderBarrel,
	eWS_HoldFireUnderBarrel,
	eWS_FireUnderBarrel,
	eWS_ReloadUnderBarrel,
	eWS_HolsterInDisabled,
	eWS_HolsterInUnderBarrel,
	eWS_HolsteredUnderBarrel,
	eWS_MeleeUnderBarrel,
	eWS_ThrowingFire,
	eWS_ThrowingFireActivate,
	eWS_ZoomedFire,
	eWS_ZoomInFire,
	eWS_ZoomOutFire,
	eWS_Reload,
	eWS_ReloadBarrel,
	eWS_BoltAction,
	eWS_ZoomedBoltAction,
	eWS_ZoomIn,
	eWS_ZoomOut,
	eWS_ZoomOutReloadAuto,
	eWS_ZoomOutReloadManual,
	eWS_ZoomOutQSA,
	eWS_ZoomOutMelee,
	eWS_ZoomOutBoltAction,
	eWS_ZoomOutCustomize,
	eWS_Throwing,
	eWS_Toss,
	eWS_Melee,
	eWS_Select,
	eWS_Deselect,
	eWS_Holding,
	eWS_Activate,
	eWS_Customize,
	eWS_CustomizeIn,
	eWS_CustomizeOut,
	eWS_HolsterIn,
	eWS_Holstered,
	eWS_StartRestoreSelf,
	eWS_StartRestoreTeamMate,
	eWS_CancelRestore,
	eWS_RestoreSelf,
	eWS_RestoreTeamMate,
	eWS_TryingRestoreSelf,
	eWS_TryingRestoreTeamMate,
	eWS_DropAmmoPack,
	eWS_Resurrect,
	eWS_ResetClipAmmo,
	eWS_Last,
	eWS_Num = eWS_Last
};

enum type_zero { ZERO };
enum type_min { VMIN };
enum type_max { VMAX };
enum type_identity { IDENTITY };


enum EDeviceId
{
	eDI_Keyboard = 0x0,
	eDI_Mouse = 0x1,
	eDI_XI = 0x2,
	eDI_Orbis = 0x3,
	eDI_Unknown = 0xFF,
};

enum EInputState
{
	eIS_Unknown = 0x0,
	eIS_Pressed = 0x1,
	eIS_Released = 0x2,
	eIS_Down = 0x4,
	eIS_Changed = 0x8,
	eIS_UI = 0x10
};




#define pLine __forceinline



__forceinline  float __sqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;
	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	return 1 / y;
}


template <typename F> struct Vec2_tpl {
	F x, y;
	Vec2_tpl(type_zero) : x(0), y(0) {}
	Vec2_tpl(type_min) {};
	Vec2_tpl(type_max) {};
	explicit  Vec2_tpl(F f) : x(f), y(f) {}
	Vec2_tpl() {
		Vec2_tpl(0, 0);
	}
	Vec2_tpl(F xt, F yt) {
		x = xt;
		y = yt;
	}
};

template <typename F>
struct Vec3_tpl
{
	F x, y, z;

	// --- constructors ---
	Vec3_tpl() : x(0), y(0), z(0) {}
	explicit Vec3_tpl(F f) : x(f), y(f), z(f) {}
	Vec3_tpl(F xt, F yt, F zt) : x(xt), y(yt), z(zt) {}

	// --- math ---
	F Dot(const Vec3_tpl& r) const
	{
		return x * r.x + y * r.y + z * r.z;
	}

	Vec3_tpl Cross(const Vec3_tpl& r) const
	{
		return Vec3_tpl(
			y * r.z - z * r.y,
			z * r.x - x * r.z,
			x * r.y - y * r.x
		);
	}

	F LenSq() const
	{
		return Dot(*this);
	}

	F Len() const
	{
		return std::sqrt(LenSq());
	}

	void Normalize()
	{
		F len = Len();
		if (len > F(0))
		{
			F inv = F(1) / len;
			x *= inv;
			y *= inv;
			z *= inv;
		}
	}

	// --- operators ---
	F& operator[](int i) { return ((F*)this)[i]; }
	F  operator[](int i) const { return ((F*)this)[i]; }

	Vec3_tpl operator+(const Vec3_tpl& v) const
	{
		return Vec3_tpl(x + v.x, y + v.y, z + v.z);
	}

	Vec3_tpl operator-(const Vec3_tpl& v) const
	{
		return Vec3_tpl(x - v.x, y - v.y, z - v.z);
	}

	Vec3_tpl operator*(F k) const
	{
		return Vec3_tpl(x * k, y * k, z * k);
	}

	Vec3_tpl operator/(F k) const
	{
		return Vec3_tpl(x / k, y / k, z / k);
	}

	Vec3_tpl& operator+=(const Vec3_tpl& v)
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}

	Vec3_tpl& operator-=(const Vec3_tpl& v)
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}

	Vec3_tpl& operator*=(F k)
	{
		x *= k; y *= k; z *= k;
		return *this;
	}

	Vec3_tpl& operator/=(F k)
	{
		x /= k; y /= k; z /= k;
		return *this;
	}

	bool operator==(const Vec3_tpl& v) const
	{
		return x == v.x && y == v.y && z == v.z;
	}

	// --- ÂÀÆÍÎ: float * Vec3 ---
	friend Vec3_tpl operator*(F k, const Vec3_tpl& v)
	{
		return Vec3_tpl(v.x * k, v.y * k, v.z * k);
	}
};

template <typename F> struct Quat_tpl {
	Vec3_tpl<F> v;
	F w;
	Quat_tpl() {}
	Quat_tpl(F angle, const Vec3_tpl<F>& axis) : w(angle), v(axis) {};
	Quat_tpl(type_identity) : w(1), v(0, 0, 0) {}

	Quat_tpl& operator=(const Quat_tpl* rhs)
	{
		if (!rhs) { v = Vec3_tpl<F>(0, 0, 0); w = 1; return *this; }
		v = rhs->v;
		w = rhs->w;
		return *this;
	}

	Vec3_tpl<F> operator*(const Vec3_tpl<F>& p) const
	{
		const Vec3_tpl<F>& u = v;
		const F s = w;

		return u * (F(2) * u.Dot(p))
			+ p * (s * s - u.Dot(u))
			+ u.Cross(p) * (F(2) * s);
	}

};

template <typename F> struct QuatT_tpl {
	Quat_tpl<F>   q;
	Vec3_tpl<F> t;
	QuatT_tpl() {};
	QuatT_tpl(const Vec3_tpl<F>& _t, const Quat_tpl<F>& _q) { q = _q; t = _t; }
	QuatT_tpl(type_identity) { q.w = 1; q.v.x = 0; q.v.y = 0; q.v.z = 0; t.x = 0; t.y = 0; t.z = 0; }

};

template <typename F> struct Matrix33_tpl {
	F m00, m01, m02;
	F m10, m11, m12;
	F m20, m21, m22;
	Matrix33_tpl() {};
	explicit  Matrix33_tpl<F>(const Quat_tpl<F>& q) {
		Vec3_tpl<F> v2 = q.v + q.v;
		F xx = 1 - v2.x * q.v.x;
		F yy = v2.y * q.v.y;
		F xw = v2.x * q.w;
		F xy = v2.y * q.v.x;
		F yz = v2.z * q.v.y;
		F yw = v2.y * q.w;
		F xz = v2.z * q.v.x;
		F zz = v2.z * q.v.z;
		F zw = v2.z * q.w;
		m00 = 1 - yy - zz;
		m01 = xy - zw;
		m02 = xz + yw;
		m10 = xy + zw;
		m11 = xx - zz;
		m12 = yz - xw;
		m20 = xz - yw;
		m21 = yz + xw;
		m22 = xx - yy;
	}
	template<typename F1>   Matrix33_tpl(const Matrix33_tpl<F1>& m) {
		m00 = F(m.m00);	m01 = F(m.m01);	m02 = F(m.m02);
		m10 = F(m.m10);	m11 = F(m.m11);	m12 = F(m.m12);
		m20 = F(m.m20);	m21 = F(m.m21);	m22 = F(m.m22);
	}
	Matrix33_tpl& operator = (const Matrix33_tpl<F>& m) {
		m00 = m.m00;	m01 = m.m01;	m02 = m.m02;
		m10 = m.m10;	m11 = m.m11;	m12 = m.m12;
		m20 = m.m20;	m21 = m.m21;	m22 = m.m22;
		return *this;
	}
};

template <typename F> struct Matrix34_tpl {
	F m00, m01, m02, m03;
	F m10, m11, m12, m13;
	F m20, m21, m22, m23;

	Matrix34_tpl() {};
	template<class F1> explicit Matrix34_tpl(const QuatT_tpl<F1>& q) {
		Vec3_tpl<F1> v2 = q.q.v + q.q.v;
		F1 xx = 1 - v2.x * q.q.v.x;		F1 yy = v2.y * q.q.v.y;		F1 xw = v2.x * q.q.w;
		F1 xy = v2.y * q.q.v.x;			F1 yz = v2.z * q.q.v.y;		F1 yw = v2.y * q.q.w;
		F1 xz = v2.z * q.q.v.x;			F1 zz = v2.z * q.q.v.z;		F1 zw = v2.z * q.q.w;
		m00 = F(1 - yy - zz);			m01 = F(xy - zw);			m02 = F(xz + yw);			m03 = F(q.t.x);
		m10 = F(xy + zw);				m11 = F(xx - zz);			m12 = F(yz - xw);			m13 = F(q.t.y);
		m20 = F(xz - yw);				m21 = F(yz + xw);			m22 = F(xx - yy);			m23 = F(q.t.z);
	}
	Vec3_tpl <F>GetTranslation() const { return Vec3_tpl <F>(m03, m13, m23); }

	Matrix34_tpl <F>SetTranslation(Vec3_tpl<F>vPos) {
		m03 = F(vPos.x);
		m13 = F(vPos.y);
		m23 = F(vPos.z);
		return *this;
	}
};




template <class F> Vec3_tpl<F> operator*(const Matrix34_tpl<F>& m, const Vec3_tpl<F>& p) {
	Vec3_tpl<F> tp;
	tp.x = m.m00 * p.x + m.m01 * p.y + m.m02 * p.z + m.m03;
	tp.y = m.m10 * p.x + m.m11 * p.y + m.m12 * p.z + m.m13;
	tp.z = m.m20 * p.x + m.m21 * p.y + m.m22 * p.z + m.m23;
	return tp;
}

typedef Vec2_tpl<float>						Vec2;
typedef Vec3_tpl<float>						Vec3;
typedef Quat_tpl<float>						Quat;
typedef QuatT_tpl<float>					QuatT;
typedef Matrix33_tpl<float>					Matrix33;
typedef Matrix34_tpl<float>					Matrix34;


template <class TVarType, typename TMaskType, TMaskType TMaxMaskValue = 0x7FFFFFFF>
class CMaskedVarT {
public:
	CMaskedVarT() : m_mask(0) {}
	CMaskedVarT(const TVarType v) { Set(v); }

	operator TVarType () const { return this->Get(); }

	CMaskedVarT& operator += (const TVarType rhs) {
		TVarType  v = this->Get();
		v += rhs;
		this->Set(v);
		return (*this);
	}

	CMaskedVarT& operator -= (const TVarType rhs)
	{
		TVarType  v = this->Get();
		v -= rhs;
		this->Set(v);
		return (*this);
	}

	CMaskedVarT& operator *= (const TVarType rhs)
	{
		TVarType  v = this->Get();
		v *= rhs;
		this->Set(v);
		return (*this);
	}

	CMaskedVarT& operator /= (const TVarType rhs) {

		TVarType  v = this->Get();
		v /= rhs;
		this->Set(v);
		return (*this);
	}

	CMaskedVarT& operator = (const TVarType rhs) {
		Set(rhs);
		return (*this);
	}

private:

	void Set(const TVarType v) {

		UVal		w;
		w.asVarType = v;
		m_val.asMaskType = (w.asMaskType ^ m_mask);
	}

	TVarType Get() const
	{
		UVal  w;
		w.asMaskType = 0;
		if (m_mask > 0) w.asMaskType = (m_val.asMaskType ^ m_mask);
		return w.asVarType;
	}

	union UVal {
		TVarType asVarType;
		TMaskType asMaskType;
	};

	UVal m_val;
	TMaskType m_mask;
};

interface TKeyName
{
	const char* key;
	TKeyName() { key = ""; }
	TKeyName(const char* _key) { key = _key; };
	operator const char* () const { return key; };
	const char* c_str() const { return key; }
};

interface SInputSymbol
{
	enum EType
	{
		Button,
		Toggle,
		RawAxis,
		Axis,
		Trigger,
	};
	bool GetKeyState(bool async = true)
	{
		if (state == eIS_Down)
		{
			if (async) state = eIS_Changed;
			return true;
		}
		return false;
	}
	TKeyName		name;
	unsigned int	devSpecId;
	EInputState		state;
	const EType		type;
	float			value;
	unsigned int	user;
	EDeviceId		deviceId;
	unsigned char	deviceIndex;
};

interface ITimers
{
public:
	void Hz(float hz) { DeadS = 1.f / hz; }
	void Upd(float t) { cLeft += t; }
	bool Hav() { return cLeft >= DeadS; }
	void Res() { cLeft = 0.f; }

private:
	float DeadS, cLeft;
}; ITimers Timer;


template <typename F> struct Lineseg_tpl {

	Vec3 start;
	Vec3 end;

	//default Lineseg constructor (without initialisation)
	inline Lineseg_tpl(void) {}
	inline Lineseg_tpl(const Vec3& s, const Vec3& e) { start = s; end = e; }
	inline void operator () (const Vec3& s, const Vec3& e) { start = s; end = e; }

	Vec3 GetPoint(F t) const { return t * end + (F(1.0) - t) * start; }

	~Lineseg_tpl(void) {};
};

typedef Lineseg_tpl<float> Lineseg;

interface AABB
{
	Vec3 min, max;
	Vec3 GetCenter() { return (min + max) * 0.5f; }
	bool IsReset() { return min.x > max.x; }
	void Reset() {
		min = Vec3(1e15f); max = Vec3(-1e15f);
	}
};
