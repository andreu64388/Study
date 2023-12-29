#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct InvokerActionInvoker1
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1)
	{
		void* params[1] = { &p1 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2)
	{
		void* params[2] = { p1, &p2 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};

// System.Collections.Generic.List`1<UnityEngine.CanvasGroup>
struct List_1_t2CDCA768E7F493F5EDEBC75AEB200FD621354E35;
// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween>
struct TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// UnityEngine.UI.Selectable[]
struct SelectableU5BU5D_t4160E135F02A40F75A63F787D36F31FEC6FE91A9;
// UnityEngine.UIVertex[]
struct UIVertexU5BU5D_tBC532486B45D071A520751A90E819C77BA4E3D2F;
// UnityEngine.Vector2[]
struct Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA;
// UnityEngine.Vector3[]
struct Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C;
// AmpMeterScript
struct AmpMeterScript_tE85F2D1AB3341B20C602472492B9304889A702DD;
// Anim1
struct Anim1_t152A00E9FA8808492109790385A79D68AA368219;
// AnimBlock
struct AnimBlock_t4FB9E140C9C2CDAB65219E978EADE516FB440F39;
// AnimButton
struct AnimButton_t1B46D0AD1647580EAFCF01F920BFAA05254E80BC;
// UnityEngine.Animation
struct Animation_t6593B06C39E3B139808B19F2C719C860F3F61040;
// UnityEngine.UI.AnimationTriggers
struct AnimationTriggers_tA0DC06F89C5280C6DD972F6F4C8A56D7F4F79074;
// UnityEngine.Animator
struct Animator_t8A52E42AE54F76681838FE9E632683EF3952E883;
// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
// Camera
struct Camera_t9FA9D68A2946676AA0E9C404046C831F5535DB24;
// UnityEngine.Camera
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184;
// UnityEngine.Canvas
struct Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26;
// UnityEngine.CanvasRenderer
struct CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860;
// ChangeColor
struct ChangeColor_t70B53D9F65E73F39B15A13EDB83B60E1C29BB9C1;
// ChangeText1
struct ChangeText1_tDD565E7D40765D3469FFC7098E3425E9CAD8F3CE;
// ChangeText10
struct ChangeText10_tEEB05929B5A0B99B29162C0F24F44C2DEF220974;
// ChangeText11
struct ChangeText11_tE2176BD24191962309985F26D85506A5D4D9F3B1;
// ChangeText12
struct ChangeText12_t817B7DC1E62D271BBEB3F13FE53E8B947C979A86;
// ChangeText13
struct ChangeText13_t43C2E47AF1257F49E4309202F052D13EDDD61560;
// ChangeText14
struct ChangeText14_tAA556CC6633063BD1D85621B203B6119C381C240;
// ChangeText15
struct ChangeText15_tF47BF5B2635C1557942793C52E96947674332A4F;
// ChangeText16
struct ChangeText16_t3B6E07E6C7890D4163472544AE5FBF6E1F964434;
// ChangeText2
struct ChangeText2_t66CA80084DC5D32919692C6D40BEA1321A96BCE4;
// ChangeText3
struct ChangeText3_t0F74CBD51AB6C9AE379D6C6B72937A66C6D81B19;
// ChangeText4
struct ChangeText4_t9131E982E802BAA38DB2438DD54313985A44F84C;
// ChangeText5
struct ChangeText5_tB143BE03DA2DF2D6F5DC2AB8D78925F3AFC08907;
// ChangeText6
struct ChangeText6_t48F992915F56F9296E34DC38A3CE36ACEAE7BF22;
// ChangeText7
struct ChangeText7_tDB92093D4D186F59BCC8539C17FB183FEE977780;
// ChangeText8
struct ChangeText8_tAD6D121FBC92DE4396AD3B01F83395FE5B5F7AE1;
// ChangeText9
struct ChangeText9_tA70CB19E32A836A3CBFFD1EC25F831C48FC985FC;
// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
// UnityEngine.Coroutine
struct Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B;
// CupControl
struct CupControl_tA04B1EB807F79800176E939A70AA4B94EA5CB61D;
// System.Delegate
struct Delegate_t;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// UnityEngine.Event
struct Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB;
// UnityEngine.UI.FontData
struct FontData_tB8E562846C6CB59C43260F69AE346B9BF3157224;
// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
// UnityEngine.UI.Graphic
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931;
// System.IAsyncResult
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
// UnityEngine.UI.InputField
struct InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140;
// UnityEngine.Material
struct Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3;
// UnityEngine.Mesh
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
// MoveCam
struct MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A;
// MoveObjectWithMouse
struct MoveObjectWithMouse_tFEBCCC731305AB9831C1038E010BA3E5E999DFD0;
// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
// OutputInfo
struct OutputInfo_tAC08BE0EC12F767A093907FF0347268ABA8E6BBB;
// UnityEngine.UI.RectMask2D
struct RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670;
// UnityEngine.RectTransform
struct RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5;
// UnityEngine.Renderer
struct Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF;
// RotMouse
struct RotMouse_tB15C38E97A03A7782CB6BBC472FCA7E80721D844;
// RotPir
struct RotPir_t568F2AB4F3F42493F526733A25173694B1D591AB;
// RunTest
struct RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A;
// Script
struct Script_t16820696475B1CE5329D1A278120D55D1EAB0117;
// UnityEngine.UI.Selectable
struct Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712;
// UnityEngine.Sprite
struct Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99;
// System.String
struct String_t;
// UnityEngine.UI.Text
struct Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62;
// UnityEngine.TextGenerator
struct TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC;
// UnityEngine.Texture2D
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4;
// UnityEngine.TouchScreenKeyboard
struct TouchScreenKeyboard_tE87B78A3DAED69816B44C99270A734682E093E7A;
// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1;
// Trigger_Anim
struct Trigger_Anim_tF3C781751DD09B03E8AC9509860F8F3FC1242BF6;
// Tumbler
struct Tumbler_t625725C532E9AF9C93E4B2B40A7A812C2E4DD6AC;
// Tumbler1
struct Tumbler1_t5F8D47869C2459B4D767E01867D9865281754ACC;
// UnityEngine.Events.UnityAction
struct UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7;
// UnityEngine.UI.VertexHelper
struct VertexHelper_tB905FCB02AE67CBEE5F265FE37A5938FC5D136FE;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// VoltMeterScript
struct VoltMeterScript_t076A2E0A790F6C3C209A171F75B922CC27838586;
// UnityEngine.WaitForSecondsRealtime
struct WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01;
// Window_up2
struct Window_up2_tA58A67A9C61588E05FE1156060249039DF64E1BE;
// Windows_up
struct Windows_up_t369E4FBE2D3DF45BFBEE7FE0EC42B546BEC651A4;
// UnityEngine.Camera/CameraCallback
struct CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD;
// UnityEngine.UI.InputField/EndEditEvent
struct EndEditEvent_t946A962BA13CF60BB0BE7AD091DA041FD788E655;
// UnityEngine.UI.InputField/OnChangeEvent
struct OnChangeEvent_tE4829F88300B0E0E0D1B78B453AF25FC1AA55E2F;
// UnityEngine.UI.InputField/OnValidateInput
struct OnValidateInput_t48916A4E9C9FD6204401FF0808C2B7A93D73418B;
// UnityEngine.UI.InputField/SubmitEvent
struct SubmitEvent_t1E0F5A2AB28D0DB55AE18E8DA99147D86492DD5D;
// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent
struct CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8;
// RunTest/PlayInstChanged
struct PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91;

IL2CPP_EXTERN_C RuntimeClass* Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral0068482617098B0041B46A581D3FD79189050B55;
IL2CPP_EXTERN_C String_t* _stringLiteral008B35E247C06DE8267E2688661ED79A44F96CAA;
IL2CPP_EXTERN_C String_t* _stringLiteral0459945BB841C0193561201BBC1332C36EB10ADB;
IL2CPP_EXTERN_C String_t* _stringLiteral0622AE9DF118BA2589680D980FEC763981B180F9;
IL2CPP_EXTERN_C String_t* _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C;
IL2CPP_EXTERN_C String_t* _stringLiteral0B0FD00CCE723A953C3ADBBAD1430C433014C703;
IL2CPP_EXTERN_C String_t* _stringLiteral15BC706EA79F9CBF31BF02F9C40C739F58EB15C8;
IL2CPP_EXTERN_C String_t* _stringLiteral1AB42754C0B85DC778ADC812754A92A13BDE19BB;
IL2CPP_EXTERN_C String_t* _stringLiteral1D23B502661278913DD0A7A4A532F50A722A865A;
IL2CPP_EXTERN_C String_t* _stringLiteral2294A02B5DEA3B4E9CBE1471D959E98EC86EC6EC;
IL2CPP_EXTERN_C String_t* _stringLiteral22BCB08134DF4129F83330A14F3760EEE62D8858;
IL2CPP_EXTERN_C String_t* _stringLiteral24A09BD802A5C9BAB9BE373BD8E026B5619DA3B9;
IL2CPP_EXTERN_C String_t* _stringLiteral25C688CE13B144B3D43B765FF26D95F688FEF5BC;
IL2CPP_EXTERN_C String_t* _stringLiteral2891C1EE6C522F08A3F752A34DB4E31A09508606;
IL2CPP_EXTERN_C String_t* _stringLiteral2A1197F53A255F57930E97CAA10DF6FABF13C3E1;
IL2CPP_EXTERN_C String_t* _stringLiteral2E324792FFF44EE03ABDDD74FD2C335DE15005FF;
IL2CPP_EXTERN_C String_t* _stringLiteral3A5D56B26B1A9CEDE88C8DBEC1D7FF8296992654;
IL2CPP_EXTERN_C String_t* _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0;
IL2CPP_EXTERN_C String_t* _stringLiteral4CCB470730A3A7B6552F44D8F3BD5316F1655B9B;
IL2CPP_EXTERN_C String_t* _stringLiteral6069A933D1289F5E11D63BF4FBF355117226CFEC;
IL2CPP_EXTERN_C String_t* _stringLiteral616FA8FACA4BD63856D14D13CE36C30A22C4AE73;
IL2CPP_EXTERN_C String_t* _stringLiteral64B966C17214F45051BA3BBE40EFFF89A6C36424;
IL2CPP_EXTERN_C String_t* _stringLiteral68378C2D44F794C11BED470E3321C6DDC5D031CA;
IL2CPP_EXTERN_C String_t* _stringLiteral6F0E8A61331AF136E15EED133A124EE9B7364FF3;
IL2CPP_EXTERN_C String_t* _stringLiteral6F976EEE995FFC1EB2410801332E7AB5163E99F7;
IL2CPP_EXTERN_C String_t* _stringLiteral7210E18A0DD65B9C3AAB6EA77FA82782BB517411;
IL2CPP_EXTERN_C String_t* _stringLiteral727D72616EA1401037226B5080FD7EEA1AA8D852;
IL2CPP_EXTERN_C String_t* _stringLiteral78F151921B7FFAFB3E6DA87AD9FCCAC6A03D1404;
IL2CPP_EXTERN_C String_t* _stringLiteral7DB229E4B4513366157C0D536C533A2B6C5F7AA5;
IL2CPP_EXTERN_C String_t* _stringLiteral7EB32EA6F51D894751240E37BA59E639B290E918;
IL2CPP_EXTERN_C String_t* _stringLiteral7F8C014BD4810CC276D0F9F81A1E759C7B098B1E;
IL2CPP_EXTERN_C String_t* _stringLiteral88BEE283254D7094E258B3A88730F4CC4F1E4AC7;
IL2CPP_EXTERN_C String_t* _stringLiteral8A4A08A86ACABFB2E8022BB44D6B1525830196B3;
IL2CPP_EXTERN_C String_t* _stringLiteral9CEB4D81FE1382FF120AEE05E403D6F7BCE690D2;
IL2CPP_EXTERN_C String_t* _stringLiteral9F24FB9F6B79BD601755A6710686857F7B86347B;
IL2CPP_EXTERN_C String_t* _stringLiteralAA088AB23998B170C1E74EA50752653670EE33C4;
IL2CPP_EXTERN_C String_t* _stringLiteralAFEAA8D70AE913BC8FD03E90D55C692F73D7282D;
IL2CPP_EXTERN_C String_t* _stringLiteralB2DD8390EDD462B3183E90D041F1BA75121138B5;
IL2CPP_EXTERN_C String_t* _stringLiteralB889CCEBAD3C5A0EA57CBF1E1EC93237C8BAD9B6;
IL2CPP_EXTERN_C String_t* _stringLiteralBA69D7E125E0D005D67F802926FF010F322A4A25;
IL2CPP_EXTERN_C String_t* _stringLiteralBDAE78F75C6624B36EA14F930D41E236387AF3B9;
IL2CPP_EXTERN_C String_t* _stringLiteralC71913A9C8423A634306B793FD996AD5C940C9E1;
IL2CPP_EXTERN_C String_t* _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709;
IL2CPP_EXTERN_C String_t* _stringLiteralDAB77A744DC77C5B9134A776467542BEC9E7F959;
IL2CPP_EXTERN_C String_t* _stringLiteralDBAEBBE394D4B81FC4A2E94EA1078E305D3DCDF4;
IL2CPP_EXTERN_C String_t* _stringLiteralE1CE3848CAF32FEBFB723A7A9B05198BEEB5C8EA;
IL2CPP_EXTERN_C String_t* _stringLiteralE94F8E7EE311280D32FA4CB842D2C6C91C18F201;
IL2CPP_EXTERN_C String_t* _stringLiteralEF10CCBD3D333B3F2DC25CC04DB2BCF475074D67;
IL2CPP_EXTERN_C String_t* _stringLiteralFC6687DC37346CD2569888E29764F727FAF530E0;
IL2CPP_EXTERN_C String_t* _stringLiteralFE1B726DA152A7DE337C661475E95B6E311B9860;
IL2CPP_EXTERN_C String_t* _stringLiteralFF007DCBAADA2014554528E5BEAADE4DFC5E217E;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* RotMouse_HandlePlayInstChanged_m08198C416FA37E07ACD3A36DD92FA32A32B8AE5F_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;

struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// <Module>
struct U3CModuleU3E_tBB65183F1134474D09FF49B95625D25472B9BA8B 
{
};

// GlobalGonfig
struct GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01  : public RuntimeObject
{
};

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
};

// System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

// UnityEngine.Color
struct Color_tD001788D726C3A7F1379BEED0260B9591F440C1F 
{
	// System.Single UnityEngine.Color::r
	float ___r_0;
	// System.Single UnityEngine.Color::g
	float ___g_1;
	// System.Single UnityEngine.Color::b
	float ___b_2;
	// System.Single UnityEngine.Color::a
	float ___a_3;
};

// System.Double
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	// System.Double System.Double::m_value
	double ___m_value_0;
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.IntPtr
struct IntPtr_t 
{
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;
};

// UnityEngine.UI.Navigation
struct Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C 
{
	// UnityEngine.UI.Navigation/Mode UnityEngine.UI.Navigation::m_Mode
	int32_t ___m_Mode_0;
	// System.Boolean UnityEngine.UI.Navigation::m_WrapAround
	bool ___m_WrapAround_1;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnUp
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnUp_2;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnDown
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnDown_3;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnLeft
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnLeft_4;
	// UnityEngine.UI.Selectable UnityEngine.UI.Navigation::m_SelectOnRight
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnRight_5;
};
// Native definition for P/Invoke marshalling of UnityEngine.UI.Navigation
struct Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C_marshaled_pinvoke
{
	int32_t ___m_Mode_0;
	int32_t ___m_WrapAround_1;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnUp_2;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnDown_3;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnLeft_4;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnRight_5;
};
// Native definition for COM marshalling of UnityEngine.UI.Navigation
struct Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C_marshaled_com
{
	int32_t ___m_Mode_0;
	int32_t ___m_WrapAround_1;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnUp_2;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnDown_3;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnLeft_4;
	Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712* ___m_SelectOnRight_5;
};

// UnityEngine.Quaternion
struct Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 
{
	// System.Single UnityEngine.Quaternion::x
	float ___x_0;
	// System.Single UnityEngine.Quaternion::y
	float ___y_1;
	// System.Single UnityEngine.Quaternion::z
	float ___z_2;
	// System.Single UnityEngine.Quaternion::w
	float ___w_3;
};

// System.Single
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	// System.Single System.Single::m_value
	float ___m_value_0;
};

// UnityEngine.UI.SpriteState
struct SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD 
{
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_HighlightedSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_HighlightedSprite_0;
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_PressedSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_PressedSprite_1;
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_SelectedSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_SelectedSprite_2;
	// UnityEngine.Sprite UnityEngine.UI.SpriteState::m_DisabledSprite
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_DisabledSprite_3;
};
// Native definition for P/Invoke marshalling of UnityEngine.UI.SpriteState
struct SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD_marshaled_pinvoke
{
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_HighlightedSprite_0;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_PressedSprite_1;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_SelectedSprite_2;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_DisabledSprite_3;
};
// Native definition for COM marshalling of UnityEngine.UI.SpriteState
struct SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD_marshaled_com
{
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_HighlightedSprite_0;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_PressedSprite_1;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_SelectedSprite_2;
	Sprite_tAFF74BC83CD68037494CB0B4F28CBDF8971CAB99* ___m_DisabledSprite_3;
};

// UnityEngine.Vector2
struct Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 
{
	// System.Single UnityEngine.Vector2::x
	float ___x_0;
	// System.Single UnityEngine.Vector2::y
	float ___y_1;
};

// UnityEngine.Vector3
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 
{
	// System.Single UnityEngine.Vector3::x
	float ___x_2;
	// System.Single UnityEngine.Vector3::y
	float ___y_3;
	// System.Single UnityEngine.Vector3::z
	float ___z_4;
};

// UnityEngine.Vector4
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 
{
	// System.Single UnityEngine.Vector4::x
	float ___x_1;
	// System.Single UnityEngine.Vector4::y
	float ___y_2;
	// System.Single UnityEngine.Vector4::z
	float ___z_3;
	// System.Single UnityEngine.Vector4::w
	float ___w_4;
};

// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

// UnityEngine.UI.ColorBlock
struct ColorBlock_tDD7C62E7AFE442652FC98F8D058CE8AE6BFD7C11 
{
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_NormalColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_NormalColor_0;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_HighlightedColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_HighlightedColor_1;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_PressedColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_PressedColor_2;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_SelectedColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_SelectedColor_3;
	// UnityEngine.Color UnityEngine.UI.ColorBlock::m_DisabledColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_DisabledColor_4;
	// System.Single UnityEngine.UI.ColorBlock::m_ColorMultiplier
	float ___m_ColorMultiplier_5;
	// System.Single UnityEngine.UI.ColorBlock::m_FadeDuration
	float ___m_FadeDuration_6;
};

// System.Delegate
struct Delegate_t  : public RuntimeObject
{
	// System.IntPtr System.Delegate::method_ptr
	Il2CppMethodPointer ___method_ptr_0;
	// System.IntPtr System.Delegate::invoke_impl
	intptr_t ___invoke_impl_1;
	// System.Object System.Delegate::m_target
	RuntimeObject* ___m_target_2;
	// System.IntPtr System.Delegate::method
	intptr_t ___method_3;
	// System.IntPtr System.Delegate::delegate_trampoline
	intptr_t ___delegate_trampoline_4;
	// System.IntPtr System.Delegate::extra_arg
	intptr_t ___extra_arg_5;
	// System.IntPtr System.Delegate::method_code
	intptr_t ___method_code_6;
	// System.IntPtr System.Delegate::interp_method
	intptr_t ___interp_method_7;
	// System.IntPtr System.Delegate::interp_invoke_impl
	intptr_t ___interp_invoke_impl_8;
	// System.Reflection.MethodInfo System.Delegate::method_info
	MethodInfo_t* ___method_info_9;
	// System.Reflection.MethodInfo System.Delegate::original_method_info
	MethodInfo_t* ___original_method_info_10;
	// System.DelegateData System.Delegate::data
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	// System.Boolean System.Delegate::method_is_virtual
	bool ___method_is_virtual_12;
};
// Native definition for P/Invoke marshalling of System.Delegate
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};
// Native definition for COM marshalling of System.Delegate
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Object::m_CachedPtr
	intptr_t ___m_CachedPtr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr_0;
};
// Native definition for COM marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr_0;
};

// UnityEngine.Ray
struct Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 
{
	// UnityEngine.Vector3 UnityEngine.Ray::m_Origin
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Origin_0;
	// UnityEngine.Vector3 UnityEngine.Ray::m_Direction
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Direction_1;
};

// UnityEngine.RaycastHit
struct RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 
{
	// UnityEngine.Vector3 UnityEngine.RaycastHit::m_Point
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Point_0;
	// UnityEngine.Vector3 UnityEngine.RaycastHit::m_Normal
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___m_Normal_1;
	// System.UInt32 UnityEngine.RaycastHit::m_FaceID
	uint32_t ___m_FaceID_2;
	// System.Single UnityEngine.RaycastHit::m_Distance
	float ___m_Distance_3;
	// UnityEngine.Vector2 UnityEngine.RaycastHit::m_UV
	Vector2_t1FD6F485C871E832B347AB2DC8CBA08B739D8DF7 ___m_UV_4;
	// System.Int32 UnityEngine.RaycastHit::m_Collider
	int32_t ___m_Collider_5;
};

// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// UnityEngine.Material
struct Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// System.MulticastDelegate
struct MulticastDelegate_t  : public Delegate_t
{
	// System.Delegate[] System.MulticastDelegate::delegates
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates_13;
};
// Native definition for P/Invoke marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates_13;
};
// Native definition for COM marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates_13;
};

// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C  : public MulticastDelegate_t
{
};

// UnityEngine.Behaviour
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.Renderer
struct Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.Transform
struct Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// RunTest/PlayInstChanged
struct PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91  : public MulticastDelegate_t
{
};

// UnityEngine.Animation
struct Animation_t6593B06C39E3B139808B19F2C719C860F3F61040  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.Animator
struct Animator_t8A52E42AE54F76681838FE9E632683EF3952E883  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.Camera
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// AmpMeterScript
struct AmpMeterScript_tE85F2D1AB3341B20C602472492B9304889A702DD  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Single AmpMeterScript::amplitude
	float ___amplitude_4;
	// System.Single AmpMeterScript::frequency
	float ___frequency_5;
	// System.Single AmpMeterScript::rotationSpeed
	float ___rotationSpeed_6;
	// System.Single AmpMeterScript::timeCounter
	float ___timeCounter_7;
	// System.Single AmpMeterScript::minYRotation
	float ___minYRotation_8;
	// System.Single AmpMeterScript::maxYRotation
	float ___maxYRotation_9;
};

// Anim1
struct Anim1_t152A00E9FA8808492109790385A79D68AA368219  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};

// AnimBlock
struct AnimBlock_t4FB9E140C9C2CDAB65219E978EADE516FB440F39  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Animator AnimBlock::anim
	Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* ___anim_4;
};

// AnimButton
struct AnimButton_t1B46D0AD1647580EAFCF01F920BFAA05254E80BC  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Animator AnimButton::anim
	Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* ___anim_4;
};

// Camera
struct Camera_t9FA9D68A2946676AA0E9C404046C831F5535DB24  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Transform Camera::targetPos
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___targetPos_4;
	// System.Int32 Camera::sensitivity
	int32_t ___sensitivity_5;
	// System.Single Camera::scrollSpeed
	float ___scrollSpeed_6;
	// System.Int32 Camera::maxDistance
	int32_t ___maxDistance_7;
	// System.Int32 Camera::minDistance
	int32_t ___minDistance_8;
};

// ChangeColor
struct ChangeColor_t70B53D9F65E73F39B15A13EDB83B60E1C29BB9C1  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Color ChangeColor::currentColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___currentColor_4;
};

// ChangeText1
struct ChangeText1_tDD565E7D40765D3469FFC7098E3425E9CAD8F3CE  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText1::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText10
struct ChangeText10_tEEB05929B5A0B99B29162C0F24F44C2DEF220974  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText10::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText11
struct ChangeText11_tE2176BD24191962309985F26D85506A5D4D9F3B1  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText11::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText12
struct ChangeText12_t817B7DC1E62D271BBEB3F13FE53E8B947C979A86  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText12::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText13
struct ChangeText13_t43C2E47AF1257F49E4309202F052D13EDDD61560  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText13::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText14
struct ChangeText14_tAA556CC6633063BD1D85621B203B6119C381C240  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText14::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText15
struct ChangeText15_tF47BF5B2635C1557942793C52E96947674332A4F  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText15::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText16
struct ChangeText16_t3B6E07E6C7890D4163472544AE5FBF6E1F964434  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText16::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText2
struct ChangeText2_t66CA80084DC5D32919692C6D40BEA1321A96BCE4  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText2::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText3
struct ChangeText3_t0F74CBD51AB6C9AE379D6C6B72937A66C6D81B19  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText3::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText4
struct ChangeText4_t9131E982E802BAA38DB2438DD54313985A44F84C  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText4::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText5
struct ChangeText5_tB143BE03DA2DF2D6F5DC2AB8D78925F3AFC08907  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText5::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText6
struct ChangeText6_t48F992915F56F9296E34DC38A3CE36ACEAE7BF22  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText6::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText7
struct ChangeText7_tDB92093D4D186F59BCC8539C17FB183FEE977780  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText7::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText8
struct ChangeText8_tAD6D121FBC92DE4396AD3B01F83395FE5B5F7AE1  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText8::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// ChangeText9
struct ChangeText9_tA70CB19E32A836A3CBFFD1EC25F831C48FC985FC  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text ChangeText9::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// CupControl
struct CupControl_tA04B1EB807F79800176E939A70AA4B94EA5CB61D  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Animator CupControl::cup
	Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* ___cup_4;
};

// MoveCam
struct MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Boolean MoveCam::move
	bool ___move_4;
	// System.Single MoveCam::speed
	float ___speed_5;
	// System.Single MoveCam::offset
	float ___offset_6;
	// UnityEngine.Vector3 MoveCam::startPosition
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___startPosition_7;
	// UnityEngine.Vector3 MoveCam::needPosition
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___needPosition_8;
	// UnityEngine.Quaternion MoveCam::startRotation
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___startRotation_9;
	// UnityEngine.Quaternion MoveCam::needRotaton
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___needRotaton_10;
};

// MoveObjectWithMouse
struct MoveObjectWithMouse_tFEBCCC731305AB9831C1038E010BA3E5E999DFD0  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Boolean MoveObjectWithMouse::isMoving
	bool ___isMoving_4;
	// UnityEngine.Vector3 MoveObjectWithMouse::previousMousePosition
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___previousMousePosition_5;
	// System.Single MoveObjectWithMouse::objectPositionY
	float ___objectPositionY_6;
};

// OutputInfo
struct OutputInfo_tAC08BE0EC12F767A093907FF0347268ABA8E6BBB  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Single OutputInfo::l
	float ___l_4;
	// System.Single OutputInfo::s
	float ___s_5;
	// UnityEngine.UI.InputField OutputInfo::textInput
	InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* ___textInput_6;
	// UnityEngine.UI.Text OutputInfo::_1
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____1_7;
	// UnityEngine.UI.Text OutputInfo::_2
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____2_8;
	// UnityEngine.UI.Text OutputInfo::_3
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____3_9;
	// UnityEngine.UI.Text OutputInfo::_4
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____4_10;
	// UnityEngine.UI.Text OutputInfo::_5
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____5_11;
	// UnityEngine.UI.Text OutputInfo::_6
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____6_12;
	// UnityEngine.UI.Text OutputInfo::_7
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____7_13;
	// UnityEngine.UI.Text OutputInfo::_8
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____8_14;
	// UnityEngine.UI.Text OutputInfo::_9
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____9_15;
	// UnityEngine.UI.Text OutputInfo::_10
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____10_16;
	// UnityEngine.UI.Text OutputInfo::_11
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____11_17;
	// UnityEngine.UI.Text OutputInfo::_12
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____12_18;
	// UnityEngine.UI.Text OutputInfo::_13
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____13_19;
	// UnityEngine.UI.Text OutputInfo::_14
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____14_20;
	// UnityEngine.UI.Text OutputInfo::_15
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____15_21;
	// UnityEngine.UI.Text OutputInfo::_16
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____16_22;
	// UnityEngine.UI.Text OutputInfo::_17
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____17_23;
	// UnityEngine.UI.Text OutputInfo::_18
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____18_24;
	// UnityEngine.UI.Text OutputInfo::_19
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____19_25;
	// UnityEngine.UI.Text OutputInfo::_20
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____20_26;
	// UnityEngine.UI.Text OutputInfo::_21
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____21_27;
	// UnityEngine.UI.Text OutputInfo::_22
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____22_28;
	// UnityEngine.UI.Text OutputInfo::_23
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____23_29;
	// UnityEngine.UI.Text OutputInfo::_24
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ____24_30;
	// UnityEngine.UI.Text OutputInfo::R1
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___R1_31;
	// UnityEngine.UI.Text OutputInfo::R2
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___R2_32;
	// UnityEngine.UI.Text OutputInfo::R3
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___R3_33;
	// UnityEngine.UI.Text OutputInfo::R1Result
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___R1Result_34;
	// UnityEngine.UI.Text OutputInfo::R4
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___R4_35;
	// UnityEngine.UI.Text OutputInfo::R5
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___R5_36;
	// UnityEngine.UI.Text OutputInfo::R6
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___R6_37;
	// UnityEngine.UI.Text OutputInfo::R2Result
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___R2Result_38;
	// UnityEngine.UI.Text OutputInfo::Z1
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___Z1_39;
	// UnityEngine.UI.Text OutputInfo::Z2
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___Z2_40;
	// UnityEngine.UI.Text OutputInfo::Z3
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___Z3_41;
	// UnityEngine.UI.Text OutputInfo::Z1Result
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___Z1Result_42;
	// UnityEngine.UI.Text OutputInfo::Z4
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___Z4_43;
	// UnityEngine.UI.Text OutputInfo::Z5
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___Z5_44;
	// UnityEngine.UI.Text OutputInfo::Z6
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___Z6_45;
	// UnityEngine.UI.Text OutputInfo::Z2Result
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___Z2Result_46;
	// UnityEngine.UI.Text OutputInfo::L1Result
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___L1Result_47;
	// UnityEngine.UI.Text OutputInfo::L2Result
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___L2Result_48;
};

// RotMouse
struct RotMouse_tB15C38E97A03A7782CB6BBC472FCA7E80721D844  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Boolean RotMouse::isRotating
	bool ___isRotating_4;
	// UnityEngine.Vector3 RotMouse::previousMousePosition
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___previousMousePosition_5;
	// System.Single RotMouse::rotationSpeed
	float ___rotationSpeed_6;
	// UnityEngine.GameObject RotMouse::Amp
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___Amp_7;
	// UnityEngine.GameObject RotMouse::Volt
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___Volt_8;
	// System.Boolean RotMouse::Play
	bool ___Play_9;
	// System.Single RotMouse::minZ
	float ___minZ_10;
	// System.Single RotMouse::maxZ
	float ___maxZ_11;
	// RunTest RotMouse::RunTest
	RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A* ___RunTest_12;
	// System.Single RotMouse::digitValue
	float ___digitValue_13;
};

// RotPir
struct RotPir_t568F2AB4F3F42493F526733A25173694B1D591AB  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Single RotPir::rotationSpeed
	float ___rotationSpeed_4;
	// UnityEngine.GameObject RotPir::Line
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___Line_5;
	// UnityEngine.GameObject RotPir::Pir
	GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___Pir_6;
	// Camera RotPir::mainCamera
	Camera_t9FA9D68A2946676AA0E9C404046C831F5535DB24* ___mainCamera_7;
	// System.Boolean RotPir::isRotating
	bool ___isRotating_8;
	// UnityEngine.Vector3 RotPir::previousMousePosition
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___previousMousePosition_9;
};

// RunTest
struct RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Animator RunTest::anim
	Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* ___anim_4;
};

// Script
struct Script_t16820696475B1CE5329D1A278120D55D1EAB0117  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Transform Script::targetPos
	Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* ___targetPos_4;
	// System.Int32 Script::sensitivity
	int32_t ___sensitivity_5;
	// System.Single Script::scrollSpeed
	float ___scrollSpeed_6;
	// System.Int32 Script::maxDistance
	int32_t ___maxDistance_7;
	// System.Int32 Script::minDistance
	int32_t ___minDistance_8;
};

// Trigger_Anim
struct Trigger_Anim_tF3C781751DD09B03E8AC9509860F8F3FC1242BF6  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text Trigger_Anim::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
	// UnityEngine.Animator Trigger_Anim::anim
	Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* ___anim_5;
};

// Tumbler
struct Tumbler_t625725C532E9AF9C93E4B2B40A7A812C2E4DD6AC  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Animator Tumbler::anim
	Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* ___anim_4;
	// UnityEngine.UI.Text Tumbler::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_5;
};

// Tumbler1
struct Tumbler1_t5F8D47869C2459B4D767E01867D9865281754ACC  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.Animator Tumbler1::anim
	Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* ___anim_4;
};

// UnityEngine.EventSystems.UIBehaviour
struct UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};

// VoltMeterScript
struct VoltMeterScript_t076A2E0A790F6C3C209A171F75B922CC27838586  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Single VoltMeterScript::amplitude
	float ___amplitude_4;
	// System.Single VoltMeterScript::frequency
	float ___frequency_5;
	// System.Single VoltMeterScript::rotationSpeed
	float ___rotationSpeed_6;
	// System.Single VoltMeterScript::timeCounter
	float ___timeCounter_7;
	// System.Single VoltMeterScript::minYRotation
	float ___minYRotation_8;
	// System.Single VoltMeterScript::maxYRotation
	float ___maxYRotation_9;
};

// Window_up2
struct Window_up2_tA58A67A9C61588E05FE1156060249039DF64E1BE  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// System.Boolean Window_up2::isClose
	bool ___isClose_4;
};

// Windows_up
struct Windows_up_t369E4FBE2D3DF45BFBEE7FE0EC42B546BEC651A4  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// UnityEngine.UI.Text Windows_up::message
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___message_4;
};

// UnityEngine.UI.Graphic
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// UnityEngine.Material UnityEngine.UI.Graphic::m_Material
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_Material_6;
	// UnityEngine.Color UnityEngine.UI.Graphic::m_Color
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_Color_7;
	// System.Boolean UnityEngine.UI.Graphic::m_SkipLayoutUpdate
	bool ___m_SkipLayoutUpdate_8;
	// System.Boolean UnityEngine.UI.Graphic::m_SkipMaterialUpdate
	bool ___m_SkipMaterialUpdate_9;
	// System.Boolean UnityEngine.UI.Graphic::m_RaycastTarget
	bool ___m_RaycastTarget_10;
	// System.Boolean UnityEngine.UI.Graphic::m_RaycastTargetCache
	bool ___m_RaycastTargetCache_11;
	// UnityEngine.Vector4 UnityEngine.UI.Graphic::m_RaycastPadding
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___m_RaycastPadding_12;
	// UnityEngine.RectTransform UnityEngine.UI.Graphic::m_RectTransform
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_RectTransform_13;
	// UnityEngine.CanvasRenderer UnityEngine.UI.Graphic::m_CanvasRenderer
	CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860* ___m_CanvasRenderer_14;
	// UnityEngine.Canvas UnityEngine.UI.Graphic::m_Canvas
	Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* ___m_Canvas_15;
	// System.Boolean UnityEngine.UI.Graphic::m_VertsDirty
	bool ___m_VertsDirty_16;
	// System.Boolean UnityEngine.UI.Graphic::m_MaterialDirty
	bool ___m_MaterialDirty_17;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyLayoutCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyLayoutCallback_18;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyVertsCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyVertsCallback_19;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyMaterialCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyMaterialCallback_20;
	// UnityEngine.Mesh UnityEngine.UI.Graphic::m_CachedMesh
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___m_CachedMesh_23;
	// UnityEngine.Vector2[] UnityEngine.UI.Graphic::m_CachedUvs
	Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA* ___m_CachedUvs_24;
	// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween> UnityEngine.UI.Graphic::m_ColorTweenRunner
	TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4* ___m_ColorTweenRunner_25;
	// System.Boolean UnityEngine.UI.Graphic::<useLegacyMeshGeneration>k__BackingField
	bool ___U3CuseLegacyMeshGenerationU3Ek__BackingField_26;
};

// UnityEngine.UI.Selectable
struct Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// System.Boolean UnityEngine.UI.Selectable::m_EnableCalled
	bool ___m_EnableCalled_6;
	// UnityEngine.UI.Navigation UnityEngine.UI.Selectable::m_Navigation
	Navigation_t4D2E201D65749CF4E104E8AC1232CF1D6F14795C ___m_Navigation_7;
	// UnityEngine.UI.Selectable/Transition UnityEngine.UI.Selectable::m_Transition
	int32_t ___m_Transition_8;
	// UnityEngine.UI.ColorBlock UnityEngine.UI.Selectable::m_Colors
	ColorBlock_tDD7C62E7AFE442652FC98F8D058CE8AE6BFD7C11 ___m_Colors_9;
	// UnityEngine.UI.SpriteState UnityEngine.UI.Selectable::m_SpriteState
	SpriteState_tC8199570BE6337FB5C49347C97892B4222E5AACD ___m_SpriteState_10;
	// UnityEngine.UI.AnimationTriggers UnityEngine.UI.Selectable::m_AnimationTriggers
	AnimationTriggers_tA0DC06F89C5280C6DD972F6F4C8A56D7F4F79074* ___m_AnimationTriggers_11;
	// System.Boolean UnityEngine.UI.Selectable::m_Interactable
	bool ___m_Interactable_12;
	// UnityEngine.UI.Graphic UnityEngine.UI.Selectable::m_TargetGraphic
	Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931* ___m_TargetGraphic_13;
	// System.Boolean UnityEngine.UI.Selectable::m_GroupsAllowInteraction
	bool ___m_GroupsAllowInteraction_14;
	// System.Int32 UnityEngine.UI.Selectable::m_CurrentIndex
	int32_t ___m_CurrentIndex_15;
	// System.Boolean UnityEngine.UI.Selectable::<isPointerInside>k__BackingField
	bool ___U3CisPointerInsideU3Ek__BackingField_16;
	// System.Boolean UnityEngine.UI.Selectable::<isPointerDown>k__BackingField
	bool ___U3CisPointerDownU3Ek__BackingField_17;
	// System.Boolean UnityEngine.UI.Selectable::<hasSelection>k__BackingField
	bool ___U3ChasSelectionU3Ek__BackingField_18;
	// System.Collections.Generic.List`1<UnityEngine.CanvasGroup> UnityEngine.UI.Selectable::m_CanvasGroupCache
	List_1_t2CDCA768E7F493F5EDEBC75AEB200FD621354E35* ___m_CanvasGroupCache_19;
};

// UnityEngine.UI.InputField
struct InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140  : public Selectable_t3251808068A17B8E92FB33590A4C2FA66D456712
{
	// UnityEngine.TouchScreenKeyboard UnityEngine.UI.InputField::m_Keyboard
	TouchScreenKeyboard_tE87B78A3DAED69816B44C99270A734682E093E7A* ___m_Keyboard_20;
	// UnityEngine.UI.Text UnityEngine.UI.InputField::m_TextComponent
	Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* ___m_TextComponent_23;
	// UnityEngine.UI.Graphic UnityEngine.UI.InputField::m_Placeholder
	Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931* ___m_Placeholder_24;
	// UnityEngine.UI.InputField/ContentType UnityEngine.UI.InputField::m_ContentType
	int32_t ___m_ContentType_25;
	// UnityEngine.UI.InputField/InputType UnityEngine.UI.InputField::m_InputType
	int32_t ___m_InputType_26;
	// System.Char UnityEngine.UI.InputField::m_AsteriskChar
	Il2CppChar ___m_AsteriskChar_27;
	// UnityEngine.TouchScreenKeyboardType UnityEngine.UI.InputField::m_KeyboardType
	int32_t ___m_KeyboardType_28;
	// UnityEngine.UI.InputField/LineType UnityEngine.UI.InputField::m_LineType
	int32_t ___m_LineType_29;
	// System.Boolean UnityEngine.UI.InputField::m_HideMobileInput
	bool ___m_HideMobileInput_30;
	// UnityEngine.UI.InputField/CharacterValidation UnityEngine.UI.InputField::m_CharacterValidation
	int32_t ___m_CharacterValidation_31;
	// System.Int32 UnityEngine.UI.InputField::m_CharacterLimit
	int32_t ___m_CharacterLimit_32;
	// UnityEngine.UI.InputField/SubmitEvent UnityEngine.UI.InputField::m_OnSubmit
	SubmitEvent_t1E0F5A2AB28D0DB55AE18E8DA99147D86492DD5D* ___m_OnSubmit_33;
	// UnityEngine.UI.InputField/EndEditEvent UnityEngine.UI.InputField::m_OnDidEndEdit
	EndEditEvent_t946A962BA13CF60BB0BE7AD091DA041FD788E655* ___m_OnDidEndEdit_34;
	// UnityEngine.UI.InputField/OnChangeEvent UnityEngine.UI.InputField::m_OnValueChanged
	OnChangeEvent_tE4829F88300B0E0E0D1B78B453AF25FC1AA55E2F* ___m_OnValueChanged_35;
	// UnityEngine.UI.InputField/OnValidateInput UnityEngine.UI.InputField::m_OnValidateInput
	OnValidateInput_t48916A4E9C9FD6204401FF0808C2B7A93D73418B* ___m_OnValidateInput_36;
	// UnityEngine.Color UnityEngine.UI.InputField::m_CaretColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_CaretColor_37;
	// System.Boolean UnityEngine.UI.InputField::m_CustomCaretColor
	bool ___m_CustomCaretColor_38;
	// UnityEngine.Color UnityEngine.UI.InputField::m_SelectionColor
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_SelectionColor_39;
	// System.String UnityEngine.UI.InputField::m_Text
	String_t* ___m_Text_40;
	// System.Single UnityEngine.UI.InputField::m_CaretBlinkRate
	float ___m_CaretBlinkRate_41;
	// System.Int32 UnityEngine.UI.InputField::m_CaretWidth
	int32_t ___m_CaretWidth_42;
	// System.Boolean UnityEngine.UI.InputField::m_ReadOnly
	bool ___m_ReadOnly_43;
	// System.Boolean UnityEngine.UI.InputField::m_ShouldActivateOnSelect
	bool ___m_ShouldActivateOnSelect_44;
	// System.Int32 UnityEngine.UI.InputField::m_CaretPosition
	int32_t ___m_CaretPosition_45;
	// System.Int32 UnityEngine.UI.InputField::m_CaretSelectPosition
	int32_t ___m_CaretSelectPosition_46;
	// UnityEngine.RectTransform UnityEngine.UI.InputField::caretRectTrans
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___caretRectTrans_47;
	// UnityEngine.UIVertex[] UnityEngine.UI.InputField::m_CursorVerts
	UIVertexU5BU5D_tBC532486B45D071A520751A90E819C77BA4E3D2F* ___m_CursorVerts_48;
	// UnityEngine.TextGenerator UnityEngine.UI.InputField::m_InputTextCache
	TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC* ___m_InputTextCache_49;
	// UnityEngine.CanvasRenderer UnityEngine.UI.InputField::m_CachedInputRenderer
	CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860* ___m_CachedInputRenderer_50;
	// System.Boolean UnityEngine.UI.InputField::m_PreventFontCallback
	bool ___m_PreventFontCallback_51;
	// UnityEngine.Mesh UnityEngine.UI.InputField::m_Mesh
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___m_Mesh_52;
	// System.Boolean UnityEngine.UI.InputField::m_AllowInput
	bool ___m_AllowInput_53;
	// System.Boolean UnityEngine.UI.InputField::m_ShouldActivateNextUpdate
	bool ___m_ShouldActivateNextUpdate_54;
	// System.Boolean UnityEngine.UI.InputField::m_UpdateDrag
	bool ___m_UpdateDrag_55;
	// System.Boolean UnityEngine.UI.InputField::m_DragPositionOutOfBounds
	bool ___m_DragPositionOutOfBounds_56;
	// System.Boolean UnityEngine.UI.InputField::m_CaretVisible
	bool ___m_CaretVisible_59;
	// UnityEngine.Coroutine UnityEngine.UI.InputField::m_BlinkCoroutine
	Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* ___m_BlinkCoroutine_60;
	// System.Single UnityEngine.UI.InputField::m_BlinkStartTime
	float ___m_BlinkStartTime_61;
	// System.Int32 UnityEngine.UI.InputField::m_DrawStart
	int32_t ___m_DrawStart_62;
	// System.Int32 UnityEngine.UI.InputField::m_DrawEnd
	int32_t ___m_DrawEnd_63;
	// UnityEngine.Coroutine UnityEngine.UI.InputField::m_DragCoroutine
	Coroutine_t85EA685566A254C23F3FD77AB5BDFFFF8799596B* ___m_DragCoroutine_64;
	// System.String UnityEngine.UI.InputField::m_OriginalText
	String_t* ___m_OriginalText_65;
	// System.Boolean UnityEngine.UI.InputField::m_WasCanceled
	bool ___m_WasCanceled_66;
	// System.Boolean UnityEngine.UI.InputField::m_HasDoneFocusTransition
	bool ___m_HasDoneFocusTransition_67;
	// UnityEngine.WaitForSecondsRealtime UnityEngine.UI.InputField::m_WaitForSecondsRealtime
	WaitForSecondsRealtime_tA8CE0AAB4B0C872B843E7973637037D17682BA01* ___m_WaitForSecondsRealtime_68;
	// System.Boolean UnityEngine.UI.InputField::m_TouchKeyboardAllowsInPlaceEditing
	bool ___m_TouchKeyboardAllowsInPlaceEditing_69;
	// System.Boolean UnityEngine.UI.InputField::m_IsCompositionActive
	bool ___m_IsCompositionActive_70;
	// UnityEngine.Event UnityEngine.UI.InputField::m_ProcessingEvent
	Event_tEBC6F24B56CE22B9C9AD1AC6C24A6B83BC3860CB* ___m_ProcessingEvent_73;
};

// UnityEngine.UI.MaskableGraphic
struct MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E  : public Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931
{
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_ShouldRecalculateStencil
	bool ___m_ShouldRecalculateStencil_27;
	// UnityEngine.Material UnityEngine.UI.MaskableGraphic::m_MaskMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_MaskMaterial_28;
	// UnityEngine.UI.RectMask2D UnityEngine.UI.MaskableGraphic::m_ParentMask
	RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670* ___m_ParentMask_29;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_Maskable
	bool ___m_Maskable_30;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_IsMaskingGraphic
	bool ___m_IsMaskingGraphic_31;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_IncludeForMasking
	bool ___m_IncludeForMasking_32;
	// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent UnityEngine.UI.MaskableGraphic::m_OnCullStateChanged
	CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8* ___m_OnCullStateChanged_33;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_ShouldRecalculate
	bool ___m_ShouldRecalculate_34;
	// System.Int32 UnityEngine.UI.MaskableGraphic::m_StencilValue
	int32_t ___m_StencilValue_35;
	// UnityEngine.Vector3[] UnityEngine.UI.MaskableGraphic::m_Corners
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___m_Corners_36;
};

// UnityEngine.UI.Text
struct Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62  : public MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E
{
	// UnityEngine.UI.FontData UnityEngine.UI.Text::m_FontData
	FontData_tB8E562846C6CB59C43260F69AE346B9BF3157224* ___m_FontData_37;
	// System.String UnityEngine.UI.Text::m_Text
	String_t* ___m_Text_38;
	// UnityEngine.TextGenerator UnityEngine.UI.Text::m_TextCache
	TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC* ___m_TextCache_39;
	// UnityEngine.TextGenerator UnityEngine.UI.Text::m_TextCacheForLayout
	TextGenerator_t85D00417640A53953556C01F9D4E7DDE1ABD8FEC* ___m_TextCacheForLayout_40;
	// System.Boolean UnityEngine.UI.Text::m_DisableFontTextureRebuiltCallback
	bool ___m_DisableFontTextureRebuiltCallback_42;
	// UnityEngine.UIVertex[] UnityEngine.UI.Text::m_TempVerts
	UIVertexU5BU5D_tBC532486B45D071A520751A90E819C77BA4E3D2F* ___m_TempVerts_43;
};

// <Module>

// <Module>

// GlobalGonfig
struct GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields
{
	// System.Boolean GlobalGonfig::<isConstTok>k__BackingField
	bool ___U3CisConstTokU3Ek__BackingField_0;
	// System.Boolean GlobalGonfig::<isHeart>k__BackingField
	bool ___U3CisHeartU3Ek__BackingField_1;
	// System.Boolean GlobalGonfig::<isSocket>k__BackingField
	bool ___U3CisSocketU3Ek__BackingField_2;
	// System.Int32 GlobalGonfig::<Step>k__BackingField
	int32_t ___U3CStepU3Ek__BackingField_3;
};

// GlobalGonfig

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Boolean

// UnityEngine.Color

// UnityEngine.Color

// System.Double

// System.Double

// System.Int32

// System.Int32

// System.IntPtr
struct IntPtr_t_StaticFields
{
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;
};

// System.IntPtr

// UnityEngine.Quaternion
struct Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974_StaticFields
{
	// UnityEngine.Quaternion UnityEngine.Quaternion::identityQuaternion
	Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___identityQuaternion_4;
};

// UnityEngine.Quaternion

// System.Single

// System.Single

// UnityEngine.Vector3
struct Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields
{
	// UnityEngine.Vector3 UnityEngine.Vector3::zeroVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___zeroVector_5;
	// UnityEngine.Vector3 UnityEngine.Vector3::oneVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___oneVector_6;
	// UnityEngine.Vector3 UnityEngine.Vector3::upVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___upVector_7;
	// UnityEngine.Vector3 UnityEngine.Vector3::downVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___downVector_8;
	// UnityEngine.Vector3 UnityEngine.Vector3::leftVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___leftVector_9;
	// UnityEngine.Vector3 UnityEngine.Vector3::rightVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___rightVector_10;
	// UnityEngine.Vector3 UnityEngine.Vector3::forwardVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___forwardVector_11;
	// UnityEngine.Vector3 UnityEngine.Vector3::backVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___backVector_12;
	// UnityEngine.Vector3 UnityEngine.Vector3::positiveInfinityVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___positiveInfinityVector_13;
	// UnityEngine.Vector3 UnityEngine.Vector3::negativeInfinityVector
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___negativeInfinityVector_14;
};

// UnityEngine.Vector3

// System.Void

// System.Void

// System.Delegate

// System.Delegate

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	// System.Int32 UnityEngine.Object::OffsetOfInstanceIDInCPlusPlusObject
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject_1;
};

// UnityEngine.Object

// UnityEngine.Ray

// UnityEngine.Ray

// UnityEngine.RaycastHit

// UnityEngine.RaycastHit

// UnityEngine.Component

// UnityEngine.Component

// UnityEngine.GameObject

// UnityEngine.GameObject

// UnityEngine.Material

// UnityEngine.Material

// System.AsyncCallback

// System.AsyncCallback

// UnityEngine.Renderer

// UnityEngine.Renderer

// UnityEngine.Transform

// UnityEngine.Transform

// RunTest/PlayInstChanged

// RunTest/PlayInstChanged

// UnityEngine.Animation

// UnityEngine.Animation

// UnityEngine.Animator

// UnityEngine.Animator

// UnityEngine.Camera
struct Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184_StaticFields
{
	// UnityEngine.Camera/CameraCallback UnityEngine.Camera::onPreCull
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPreCull_4;
	// UnityEngine.Camera/CameraCallback UnityEngine.Camera::onPreRender
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPreRender_5;
	// UnityEngine.Camera/CameraCallback UnityEngine.Camera::onPostRender
	CameraCallback_t844E527BFE37BC0495E7F67993E43C07642DA9DD* ___onPostRender_6;
};

// UnityEngine.Camera

// UnityEngine.MonoBehaviour

// UnityEngine.MonoBehaviour

// AmpMeterScript

// AmpMeterScript

// Anim1

// Anim1

// AnimBlock

// AnimBlock

// AnimButton

// AnimButton

// Camera

// Camera

// ChangeColor

// ChangeColor

// ChangeText1

// ChangeText1

// ChangeText10

// ChangeText10

// ChangeText11

// ChangeText11

// ChangeText12

// ChangeText12

// ChangeText13

// ChangeText13

// ChangeText14

// ChangeText14

// ChangeText15

// ChangeText15

// ChangeText16

// ChangeText16

// ChangeText2

// ChangeText2

// ChangeText3

// ChangeText3

// ChangeText4

// ChangeText4

// ChangeText5

// ChangeText5

// ChangeText6

// ChangeText6

// ChangeText7

// ChangeText7

// ChangeText8

// ChangeText8

// ChangeText9

// ChangeText9

// CupControl

// CupControl

// MoveCam

// MoveCam

// MoveObjectWithMouse

// MoveObjectWithMouse

// OutputInfo

// OutputInfo

// RotMouse

// RotMouse

// RotPir

// RotPir

// RunTest
struct RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_StaticFields
{
	// RunTest/PlayInstChanged RunTest::OnPlayInstChanged
	PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* ___OnPlayInstChanged_5;
};

// RunTest

// Script

// Script

// Trigger_Anim

// Trigger_Anim

// Tumbler

// Tumbler

// Tumbler1

// Tumbler1

// VoltMeterScript

// VoltMeterScript

// Window_up2

// Window_up2

// Windows_up

// Windows_up

// UnityEngine.UI.InputField
struct InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140_StaticFields
{
	// System.Char[] UnityEngine.UI.InputField::kSeparators
	CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___kSeparators_21;
	// System.Boolean UnityEngine.UI.InputField::s_IsQuestDevice
	bool ___s_IsQuestDevice_22;
};

// UnityEngine.UI.InputField

// UnityEngine.UI.Text
struct Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62_StaticFields
{
	// UnityEngine.Material UnityEngine.UI.Text::s_DefaultText
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___s_DefaultText_41;
};

// UnityEngine.UI.Text
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771  : public RuntimeArray
{
	ALIGN_FIELD (8) Delegate_t* m_Items[1];

	inline Delegate_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Delegate_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Delegate_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Delegate_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


// T UnityEngine.Component::GetComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;

// System.Boolean GlobalGonfig::get_isSocket()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GlobalGonfig_get_isSocket_m57DAE1FBAE65E6AC8FADDED4F56EEEB136152844_inline (const RuntimeMethod* method) ;
// System.Boolean GlobalGonfig::get_isConstTok()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GlobalGonfig_get_isConstTok_mB62CCC94C131692862AB730ED6980A2E68C320C2_inline (const RuntimeMethod* method) ;
// UnityEngine.Transform UnityEngine.Component::get_transform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::get_right()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_right_mFF573AFBBB2186E7AFA1BA7CA271A78DF67E4EA0_inline (const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::op_UnaryNegation(UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_UnaryNegation_m5450829F333BD2A88AF9A592C4EE331661225915_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, const RuntimeMethod* method) ;
// System.Single UnityEngine.Time::get_deltaTime()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865 (const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::Rotate(UnityEngine.Vector3,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_axis, float ___1_angle, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<UnityEngine.Animation>()
inline Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared)(__this, method);
}
// System.Boolean UnityEngine.Animation::Play(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5 (Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* __this, String_t* ___0_animation, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<UnityEngine.Animator>()
inline Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared)(__this, method);
}
// System.Boolean UnityEngine.Input::GetKeyDown(UnityEngine.KeyCode)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Input_GetKeyDown_mB237DEA6244132670D38990BAB77D813FBB028D2 (int32_t ___0_key, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Animator::GetBool(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Animator_GetBool_mBC4D952885FF7504963E5923C29481A891028FD8 (Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* __this, String_t* ___0_name, const RuntimeMethod* method) ;
// System.Void UnityEngine.Animator::SetBool(System.String,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Animator_SetBool_m6F8D4FAF0770CD4EC1F54406249785DE7391E42B (Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* __this, String_t* ___0_name, bool ___1_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.Animator::Play(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Animator_Play_m0F6A9F84B2E256E644D56C34A7A9BD622CB00FF9 (Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* __this, String_t* ___0_stateName, const RuntimeMethod* method) ;
// System.Void GlobalGonfig::set_isConstTok(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GlobalGonfig_set_isConstTok_m829451F001136839108CCAF669A96DA63F266A7D_inline (bool ___0_value, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Input::GetMouseButton(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Input_GetMouseButton_m4995DD4A2D4F916565C1B1B5AAF7DF17C126B3EA (int32_t ___0_button, const RuntimeMethod* method) ;
// System.Single UnityEngine.Input::GetAxis(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Input_GetAxis_m10372E6C5FF591668D2DC5F58C58D213CC598A62 (String_t* ___0_axisName, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Transform::get_position()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::get_up()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline (const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::RotateAround(UnityEngine.Vector3,UnityEngine.Vector3,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_RotateAround_m489C5BE8B8B15D0A5F4863DE6D23FF2CC8FA76C6 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_point, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_axis, float ___2_angle, const RuntimeMethod* method) ;
// System.Void UnityEngine.Vector3::.ctor(System.Single,System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Transform::TransformDirection(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Transform_TransformDirection_m9BE1261DF2D48B7A4A27D31EE24D2D97F89E7757 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_direction, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::op_Addition(UnityEngine.Vector3,UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_Addition_m78C0EC70CB66E8DCAC225743D82B268DAEE92067_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_b, const RuntimeMethod* method) ;
// System.Single UnityEngine.Vector3::Distance(UnityEngine.Vector3,UnityEngine.Vector3)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector3_Distance_m2314DB9B8BD01157E013DF87BEA557375C7F9FF9_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_b, const RuntimeMethod* method) ;
// System.Boolean Camera::ControlDistance(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Camera_ControlDistance_m64478A576A3EB5A8B8DC52E027CE2F3AD34B8010 (Camera_t9FA9D68A2946676AA0E9C404046C831F5535DB24* __this, float ___0_distance, const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::set_position(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_value, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::get_forward()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline (const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::op_Multiply(UnityEngine.Vector3,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, float ___1_d, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<UnityEngine.Renderer>()
inline Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared)(__this, method);
}
// System.Boolean UnityEngine.Object::op_Inequality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
// UnityEngine.Material UnityEngine.Renderer::get_material()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* Renderer_get_material_m5BA2A00816C4CC66580D4B2E409CF10718C15656 (Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* __this, const RuntimeMethod* method) ;
// UnityEngine.Color UnityEngine.Material::get_color()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Color_tD001788D726C3A7F1379BEED0260B9591F440C1F Material_get_color_mA4B7D4B96200D9D8B4F36BF19957E9DA81071DBB (Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Color::.ctor(System.Single,System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Color__ctor_mCD6889CDE39F18704CD6EA8E2EFBFA48BA3E13B0_inline (Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* __this, float ___0_r, float ___1_g, float ___2_b, const RuntimeMethod* method) ;
// System.Void UnityEngine.Material::set_color(UnityEngine.Color)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Material_set_color_m5C32DEBB215FF9EE35E7B575297D8C2F29CC2A2D (Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* __this, Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.Animator::SetTrigger(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Animator_SetTrigger_mC9CD54D627C8843EF6E159E167449D216EF6EB30 (Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* __this, String_t* ___0_name, const RuntimeMethod* method) ;
// UnityEngine.Quaternion UnityEngine.Transform::get_rotation()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, const RuntimeMethod* method) ;
// UnityEngine.Quaternion UnityEngine.Quaternion::AngleAxis(System.Single,UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 Quaternion_AngleAxis_mF37022977B297E63AA70D69EA1C4C922FF22CC80 (float ___0_angle, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_axis, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Vector3::Lerp(UnityEngine.Vector3,UnityEngine.Vector3,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_Lerp_m3A906D0530A94FAABB94F0F905E84D99BE85C3F8_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_b, float ___2_t, const RuntimeMethod* method) ;
// UnityEngine.Quaternion UnityEngine.Quaternion::Slerp(UnityEngine.Quaternion,UnityEngine.Quaternion,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 Quaternion_Slerp_m0A9969F500E7716EA4F6BC4E7D5464372D8E9E15 (Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___0_a, Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___1_b, float ___2_t, const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::set_rotation(UnityEngine.Quaternion)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_set_rotation_m61340DE74726CF0F9946743A727C4D444397331D (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 ___0_value, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Input::GetMouseButtonDown(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Input_GetMouseButtonDown_m8DFC792D15FFF15D311614D5CC6C5D055E5A1DE3 (int32_t ___0_button, const RuntimeMethod* method) ;
// UnityEngine.Camera UnityEngine.Camera::get_main()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* Camera_get_main_m52C992F18E05355ABB9EEB64A4BF2215E12762DF (const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Input::get_mousePosition()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Input_get_mousePosition_mFF21FBD2647DAE2A23BD4C45571CA95D05A0A42C (const RuntimeMethod* method) ;
// UnityEngine.Ray UnityEngine.Camera::ScreenPointToRay(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 Camera_ScreenPointToRay_m2887B9A49880B7AB670C57D66B67D6A6689FE315 (Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_pos, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Physics::Raycast(UnityEngine.Ray,UnityEngine.RaycastHit&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Physics_Raycast_mCAC9F02A1AAB49E16B384EBC8318E2DF30F4B0E5 (Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_ray, RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5* ___1_hitInfo, const RuntimeMethod* method) ;
// UnityEngine.Transform UnityEngine.RaycastHit::get_transform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* RaycastHit_get_transform_m89DB7FCFC50E0213A37CBE089400064B8FA19155 (RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Equality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Input::GetMouseButtonUp(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Input_GetMouseButtonUp_mBE89CC9C69BBEA9A863819E77EA54411B0476ED6 (int32_t ___0_button, const RuntimeMethod* method) ;
// System.String UnityEngine.UI.InputField::get_text()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704 (InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* __this, const RuntimeMethod* method) ;
// System.Int32 System.String::get_Length()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) ;
// System.Boolean System.String::op_Equality(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1 (String_t* ___0_a, String_t* ___1_b, const RuntimeMethod* method) ;
// System.Single System.Single::Parse(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8 (String_t* ___0_s, const RuntimeMethod* method) ;
// System.Double System.Math::Round(System.Double,System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline (double ___0_value, int32_t ___1_digits, const RuntimeMethod* method) ;
// System.String System.Double::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339 (double* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.UI.InputField::set_text(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InputField_set_text_m28B1C806BBCAC44F3ACCDC3B550509CA0C7D257F (InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Void RunTest/PlayInstChanged::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayInstChanged__ctor_m9DBD9E676393AE119505B981B6015C0F8913612C (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void RunTest::add_OnPlayInstChanged(RunTest/PlayInstChanged)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RunTest_add_OnPlayInstChanged_m357E7B4B9A256F93E8326F26F5F106EF02489719 (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* ___0_value, const RuntimeMethod* method) ;
// System.Void RunTest::remove_OnPlayInstChanged(RunTest/PlayInstChanged)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RunTest_remove_OnPlayInstChanged_mE8E5B1AA4ED0FF64C9C6013FCFB987799824E2F3 (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* ___0_value, const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::Translate(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_Translate_m018D015E89C8CB743C54A21B4A1C5202EBF6297A (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_translation, const RuntimeMethod* method) ;
// System.Single UnityEngine.Mathf::Clamp(System.Single,System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Clamp_mEB9AEA827D27D20FCC787F7375156AF46BB12BBF_inline (float ___0_value, float ___1_min, float ___2_max, const RuntimeMethod* method) ;
// System.Boolean GlobalGonfig::get_isHeart()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GlobalGonfig_get_isHeart_m14A72AC416E63D6C1A5F8C371A85FE17667A0EF6_inline (const RuntimeMethod* method) ;
// UnityEngine.Transform UnityEngine.GameObject::get_transform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Physics::Raycast(UnityEngine.Ray,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Physics_Raycast_m7A0FEA813B93A82713C06D8466F0A21325743488 (Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 ___0_ray, float ___1_maxDistance, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::print(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour_print_m9E6FF71C673B651F35DD418C293CFC50C46803B6 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// UnityEngine.Vector3 UnityEngine.Transform::get_eulerAngles()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Transform_get_eulerAngles_mCAAF48EFCF628F1ED91C2FFE75A4FD19C039DD6A (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Transform::set_eulerAngles(UnityEngine.Vector3)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Transform_set_eulerAngles_m9F0BC484A7915A51FAB87230644229B75BACA004 (Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* __this, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_value, const RuntimeMethod* method) ;
// System.Delegate System.Delegate::Combine(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00 (Delegate_t* ___0_a, Delegate_t* ___1_b, const RuntimeMethod* method) ;
// System.Delegate System.Delegate::Remove(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3 (Delegate_t* ___0_source, Delegate_t* ___1_value, const RuntimeMethod* method) ;
// System.Void GlobalGonfig::set_isSocket(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GlobalGonfig_set_isSocket_m89642441CD2C0F5112EA12496F732EA889B224CC_inline (bool ___0_value, const RuntimeMethod* method) ;
// System.Void GlobalGonfig::set_Step(System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GlobalGonfig_set_Step_m07F0DC514B18F632AA191958E08758F26EB1192A_inline (int32_t ___0_value, const RuntimeMethod* method) ;
// System.Void RunTest/PlayInstChanged::Invoke(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_inline (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, bool ___0_newValue, const RuntimeMethod* method) ;
// System.Boolean Script::ControlDistance(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Script_ControlDistance_m2DA061CADBB51303DF37021DD0DC0BBD27BFE62B (Script_t16820696475B1CE5329D1A278120D55D1EAB0117* __this, float ___0_distance, const RuntimeMethod* method) ;
// System.Int32 GlobalGonfig::get_Step()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GlobalGonfig_get_Step_m486B62F18526F24C79F59C02E034D73902EACD16_inline (const RuntimeMethod* method) ;
// System.Void GlobalGonfig::set_isHeart(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GlobalGonfig_set_isHeart_m989E0D619D6EA32F6836D4F97269A4AF84416BA2_inline (bool ___0_value, const RuntimeMethod* method) ;
// System.Void Window_up2::Close()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Window_up2_Close_m313A6EB20E46707A6073BBF6C5CF1573C6EBEBD0 (Window_up2_tA58A67A9C61588E05FE1156060249039DF64E1BE* __this, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.Component::get_gameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.GameObject::SetActive(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, bool ___0_value, const RuntimeMethod* method) ;
// System.Single UnityEngine.Mathf::Clamp01(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Clamp01_mA7E048DBDA832D399A581BE4D6DED9FA44CE0F14_inline (float ___0_value, const RuntimeMethod* method) ;
// System.Double System.Math::Round(System.Double,System.Int32,System.MidpointRounding)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double Math_Round_m8DB2F61CB73B9E71E54149290ABD5DC8A68890D1 (double ___0_value, int32_t ___1_digits, int32_t ___2_mode, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void AmpMeterScript::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AmpMeterScript_Update_m179C15DD624F43E4A97C7F9A611B3B7F15FFAC9D (AmpMeterScript_tE85F2D1AB3341B20C602472492B9304889A702DD* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	float V_2 = 0.0f;
	{
		// if (!GlobalGonfig.isSocket) return;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0;
		L_0 = GlobalGonfig_get_isSocket_m57DAE1FBAE65E6AC8FADDED4F56EEEB136152844_inline(NULL);
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_000f;
		}
	}
	{
		// if (!GlobalGonfig.isSocket) return;
		goto IL_0073;
	}

IL_000f:
	{
		// if (!GlobalGonfig.isConstTok)
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = GlobalGonfig_get_isConstTok_mB62CCC94C131692862AB730ED6980A2E68C320C2_inline(NULL);
		V_1 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0073;
		}
	}
	{
		// float deltaY = amplitude * Mathf.Sin(2 * Mathf.PI * frequency * timeCounter);
		float L_4 = __this->___amplitude_4;
		float L_5 = __this->___frequency_5;
		float L_6 = __this->___timeCounter_7;
		float L_7;
		L_7 = sinf(((float)il2cpp_codegen_multiply(((float)il2cpp_codegen_multiply((6.28318548f), L_5)), L_6)));
		V_2 = ((float)il2cpp_codegen_multiply(L_4, L_7));
		// transform.Rotate(-Vector3.right, deltaY * rotationSpeed * Time.deltaTime);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_8;
		L_8 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9;
		L_9 = Vector3_get_right_mFF573AFBBB2186E7AFA1BA7CA271A78DF67E4EA0_inline(NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10;
		L_10 = Vector3_op_UnaryNegation_m5450829F333BD2A88AF9A592C4EE331661225915_inline(L_9, NULL);
		float L_11 = V_2;
		float L_12 = __this->___rotationSpeed_6;
		float L_13;
		L_13 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_8, L_10, ((float)il2cpp_codegen_multiply(((float)il2cpp_codegen_multiply(L_11, L_12)), L_13)), NULL);
		// timeCounter += Time.deltaTime;
		float L_14 = __this->___timeCounter_7;
		float L_15;
		L_15 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		__this->___timeCounter_7 = ((float)il2cpp_codegen_add(L_14, L_15));
	}

IL_0073:
	{
		// }
		return;
	}
}
// System.Void AmpMeterScript::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AmpMeterScript__ctor_mD5B97D2FE5C9BC46D3CE5524015B1E412886076D (AmpMeterScript_tE85F2D1AB3341B20C602472492B9304889A702DD* __this, const RuntimeMethod* method) 
{
	{
		// public float amplitude = 0.01f;
		__this->___amplitude_4 = (0.00999999978f);
		// public float frequency = 0.01f;
		__this->___frequency_5 = (0.00999999978f);
		// public float rotationSpeed = 150f;
		__this->___rotationSpeed_6 = (150.0f);
		// private float timeCounter = 0f;
		__this->___timeCounter_7 = (0.0f);
		// public float minYRotation = -180f;
		__this->___minYRotation_8 = (-180.0f);
		// public float maxYRotation = 180.25f;
		__this->___maxYRotation_9 = (180.25f);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Anim1::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_Start_m13E577B0D7D02D247854F1182EC134653BE13E18 (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void Anim1::anim1()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim1_m5C5BB3C66FC80C17647F52189F0489E5432BAB55 (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral24A09BD802A5C9BAB9BE373BD8E026B5619DA3B9);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim1");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteral24A09BD802A5C9BAB9BE373BD8E026B5619DA3B9, NULL);
		// }
		return;
	}
}
// System.Void Anim1::anim2()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim2_m55099E8F1EC8DAB808B917F641BC5704EB9F47C4 (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6F0E8A61331AF136E15EED133A124EE9B7364FF3);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim2");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteral6F0E8A61331AF136E15EED133A124EE9B7364FF3, NULL);
		// }
		return;
	}
}
// System.Void Anim1::anim3()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim3_m1B9A41CE9905AA95DA2548BC777D3FF7BD012937 (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralAFEAA8D70AE913BC8FD03E90D55C692F73D7282D);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim3");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteralAFEAA8D70AE913BC8FD03E90D55C692F73D7282D, NULL);
		// }
		return;
	}
}
// System.Void Anim1::anim4()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim4_m45D35DF46044DB95E8DD20A39E151E0348AA6A4A (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE1CE3848CAF32FEBFB723A7A9B05198BEEB5C8EA);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim4");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteralE1CE3848CAF32FEBFB723A7A9B05198BEEB5C8EA, NULL);
		// }
		return;
	}
}
// System.Void Anim1::anim5()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim5_m4B1C183E17C645A1BAF32B0A0975EC7ACABE341C (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral25C688CE13B144B3D43B765FF26D95F688FEF5BC);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim5");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteral25C688CE13B144B3D43B765FF26D95F688FEF5BC, NULL);
		// }
		return;
	}
}
// System.Void Anim1::anim6()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim6_m6884AA3B07CE4379A8356B1958BA68650FA538CA (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2E324792FFF44EE03ABDDD74FD2C335DE15005FF);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim6");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteral2E324792FFF44EE03ABDDD74FD2C335DE15005FF, NULL);
		// }
		return;
	}
}
// System.Void Anim1::anim7()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim7_m09448686353BC566AF0525B38EEC062A43536BC5 (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral68378C2D44F794C11BED470E3321C6DDC5D031CA);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim7");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteral68378C2D44F794C11BED470E3321C6DDC5D031CA, NULL);
		// }
		return;
	}
}
// System.Void Anim1::anim8()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim8_m9A7F893892CC07328A985018EDD8556FF2B7CA77 (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1D23B502661278913DD0A7A4A532F50A722A865A);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim8");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteral1D23B502661278913DD0A7A4A532F50A722A865A, NULL);
		// }
		return;
	}
}
// System.Void Anim1::anim9()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim9_m0D23FE7275735EDE95EA74A6F07122E7539591D7 (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7210E18A0DD65B9C3AAB6EA77FA82782BB517411);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim9");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteral7210E18A0DD65B9C3AAB6EA77FA82782BB517411, NULL);
		// }
		return;
	}
}
// System.Void Anim1::anim10()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim10_m879279DBCAFE58098D17A0866002D3551AC7CF4A (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralEF10CCBD3D333B3F2DC25CC04DB2BCF475074D67);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim10");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteralEF10CCBD3D333B3F2DC25CC04DB2BCF475074D67, NULL);
		// }
		return;
	}
}
// System.Void Anim1::anim11()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1_anim11_m10810FF776F43C1E1A6706E87452B6AD12138EE5 (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7EB32EA6F51D894751240E37BA59E639B290E918);
		s_Il2CppMethodInitialized = true;
	}
	{
		// GetComponent<Animation>().Play("anim11");
		Animation_t6593B06C39E3B139808B19F2C719C860F3F61040* L_0;
		L_0 = Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290(__this, Component_GetComponent_TisAnimation_t6593B06C39E3B139808B19F2C719C860F3F61040_mC2FF017155293B66CD07DC5916A37D54F3DCC290_RuntimeMethod_var);
		bool L_1;
		L_1 = Animation_Play_m95CC43633DC2B587AB3A0D1FF5F93B863A5440D5(L_0, _stringLiteral7EB32EA6F51D894751240E37BA59E639B290E918, NULL);
		// }
		return;
	}
}
// System.Void Anim1::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Anim1__ctor_mADF7D3E0DD8C3F35D3C8DFD2BB72CAE00AA69214 (Anim1_t152A00E9FA8808492109790385A79D68AA368219* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void AnimButton::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimButton_Start_mB7F6D024720BF86D4108D1A06963044069BA6E42 (AnimButton_t1B46D0AD1647580EAFCF01F920BFAA05254E80BC* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// anim = GetComponent<Animator>();
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_0;
		L_0 = Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE(__this, Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		__this->___anim_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___anim_4), (void*)L_0);
		// }
		return;
	}
}
// System.Void AnimButton::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimButton_Update_m369111D3D06059E621DC456AB7351B268177FFF6 (AnimButton_t1B46D0AD1647580EAFCF01F920BFAA05254E80BC* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3A5D56B26B1A9CEDE88C8DBEC1D7FF8296992654);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral616FA8FACA4BD63856D14D13CE36C30A22C4AE73);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7DB229E4B4513366157C0D536C533A2B6C5F7AA5);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	{
		// if (!GlobalGonfig.isSocket) return;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0;
		L_0 = GlobalGonfig_get_isSocket_m57DAE1FBAE65E6AC8FADDED4F56EEEB136152844_inline(NULL);
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_000f;
		}
	}
	{
		// if (!GlobalGonfig.isSocket) return;
		goto IL_007e;
	}

IL_000f:
	{
		// if (Input.GetKeyDown(KeyCode.E))
		bool L_2;
		L_2 = Input_GetKeyDown_mB237DEA6244132670D38990BAB77D813FBB028D2(((int32_t)101), NULL);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_007e;
		}
	}
	{
		// var prev = anim.GetBool("button");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_4 = __this->___anim_4;
		bool L_5;
		L_5 = Animator_GetBool_mBC4D952885FF7504963E5923C29481A891028FD8(L_4, _stringLiteral3A5D56B26B1A9CEDE88C8DBEC1D7FF8296992654, NULL);
		V_2 = L_5;
		// anim.SetBool("button", !prev);
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_6 = __this->___anim_4;
		bool L_7 = V_2;
		Animator_SetBool_m6F8D4FAF0770CD4EC1F54406249785DE7391E42B(L_6, _stringLiteral3A5D56B26B1A9CEDE88C8DBEC1D7FF8296992654, (bool)((((int32_t)L_7) == ((int32_t)0))? 1 : 0), NULL);
		// if (anim.GetBool("button"))
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_8 = __this->___anim_4;
		bool L_9;
		L_9 = Animator_GetBool_mBC4D952885FF7504963E5923C29481A891028FD8(L_8, _stringLiteral3A5D56B26B1A9CEDE88C8DBEC1D7FF8296992654, NULL);
		V_3 = L_9;
		bool L_10 = V_3;
		if (!L_10)
		{
			goto IL_006a;
		}
	}
	{
		// anim.Play("On");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_11 = __this->___anim_4;
		Animator_Play_m0F6A9F84B2E256E644D56C34A7A9BD622CB00FF9(L_11, _stringLiteral616FA8FACA4BD63856D14D13CE36C30A22C4AE73, NULL);
		goto IL_007d;
	}

IL_006a:
	{
		// anim.Play("Off");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_12 = __this->___anim_4;
		Animator_Play_m0F6A9F84B2E256E644D56C34A7A9BD622CB00FF9(L_12, _stringLiteral7DB229E4B4513366157C0D536C533A2B6C5F7AA5, NULL);
	}

IL_007d:
	{
	}

IL_007e:
	{
		// }
		return;
	}
}
// System.Void AnimButton::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimButton__ctor_mDE43253BC25E7666CC44A10624BB59E4E26EEF19 (AnimButton_t1B46D0AD1647580EAFCF01F920BFAA05254E80BC* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void AnimBlock::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimBlock_Start_m5C448F59AFD275BEC90BE4F886C763E25C5DF81A (AnimBlock_t4FB9E140C9C2CDAB65219E978EADE516FB440F39* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// anim = GetComponent<Animator>();
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_0;
		L_0 = Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE(__this, Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		__this->___anim_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___anim_4), (void*)L_0);
		// }
		return;
	}
}
// System.Void AnimBlock::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimBlock_Update_mBD3D33344F145DE09629D62F9492DEF4FF8506F9 (AnimBlock_t4FB9E140C9C2CDAB65219E978EADE516FB440F39* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral78F151921B7FFAFB3E6DA87AD9FCCAC6A03D1404);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral8A4A08A86ACABFB2E8022BB44D6B1525830196B3);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDAB77A744DC77C5B9134A776467542BEC9E7F959);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	{
		// if (!GlobalGonfig.isSocket) return;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0;
		L_0 = GlobalGonfig_get_isSocket_m57DAE1FBAE65E6AC8FADDED4F56EEEB136152844_inline(NULL);
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_000f;
		}
	}
	{
		// if (!GlobalGonfig.isSocket) return;
		goto IL_008c;
	}

IL_000f:
	{
		// if (Input.GetKeyDown(KeyCode.P))
		bool L_2;
		L_2 = Input_GetKeyDown_mB237DEA6244132670D38990BAB77D813FBB028D2(((int32_t)112), NULL);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_008c;
		}
	}
	{
		// var prev = anim.GetBool("block");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_4 = __this->___anim_4;
		bool L_5;
		L_5 = Animator_GetBool_mBC4D952885FF7504963E5923C29481A891028FD8(L_4, _stringLiteralDAB77A744DC77C5B9134A776467542BEC9E7F959, NULL);
		V_2 = L_5;
		// anim.SetBool("block", !prev);
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_6 = __this->___anim_4;
		bool L_7 = V_2;
		Animator_SetBool_m6F8D4FAF0770CD4EC1F54406249785DE7391E42B(L_6, _stringLiteralDAB77A744DC77C5B9134A776467542BEC9E7F959, (bool)((((int32_t)L_7) == ((int32_t)0))? 1 : 0), NULL);
		// if (anim.GetBool("block"))
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_8 = __this->___anim_4;
		bool L_9;
		L_9 = Animator_GetBool_mBC4D952885FF7504963E5923C29481A891028FD8(L_8, _stringLiteralDAB77A744DC77C5B9134A776467542BEC9E7F959, NULL);
		V_3 = L_9;
		bool L_10 = V_3;
		if (!L_10)
		{
			goto IL_0071;
		}
	}
	{
		// GlobalGonfig.isConstTok = false;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		GlobalGonfig_set_isConstTok_m829451F001136839108CCAF669A96DA63F266A7D_inline((bool)0, NULL);
		// anim.Play("onBlock");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_11 = __this->___anim_4;
		Animator_Play_m0F6A9F84B2E256E644D56C34A7A9BD622CB00FF9(L_11, _stringLiteral78F151921B7FFAFB3E6DA87AD9FCCAC6A03D1404, NULL);
		goto IL_008b;
	}

IL_0071:
	{
		// GlobalGonfig.isConstTok = true;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		GlobalGonfig_set_isConstTok_m829451F001136839108CCAF669A96DA63F266A7D_inline((bool)1, NULL);
		// anim.Play("OffBlock");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_12 = __this->___anim_4;
		Animator_Play_m0F6A9F84B2E256E644D56C34A7A9BD622CB00FF9(L_12, _stringLiteral8A4A08A86ACABFB2E8022BB44D6B1525830196B3, NULL);
	}

IL_008b:
	{
	}

IL_008c:
	{
		// }
		return;
	}
}
// System.Void AnimBlock::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimBlock__ctor_m3B16483BC923F946B932EB9538336499A81CE4A8 (AnimBlock_t4FB9E140C9C2CDAB65219E978EADE516FB440F39* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Camera::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Camera_Start_m48167220F68C499CA52D515C89D271BB2201233D (Camera_t9FA9D68A2946676AA0E9C404046C831F5535DB24* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void Camera::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Camera_Update_m60638BE66FB3F1B5A163454A4BABAA692DE45B5F (Camera_t9FA9D68A2946676AA0E9C404046C831F5535DB24* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7F8C014BD4810CC276D0F9F81A1E759C7B098B1E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral88BEE283254D7094E258B3A88730F4CC4F1E4AC7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFC6687DC37346CD2569888E29764F727FAF530E0);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	float V_1 = 0.0f;
	bool V_2 = false;
	float V_3 = 0.0f;
	bool V_4 = false;
	bool V_5 = false;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_6;
	memset((&V_6), 0, sizeof(V_6));
	bool V_7 = false;
	bool V_8 = false;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_9;
	memset((&V_9), 0, sizeof(V_9));
	bool V_10 = false;
	{
		// if (Input.GetMouseButton(1))
		bool L_0;
		L_0 = Input_GetMouseButton_m4995DD4A2D4F916565C1B1B5AAF7DF17C126B3EA(1, NULL);
		V_2 = L_0;
		bool L_1 = V_2;
		if (!L_1)
		{
			goto IL_0050;
		}
	}
	{
		// float y = Input.GetAxis("Mouse X") * sensitivity;
		float L_2;
		L_2 = Input_GetAxis_m10372E6C5FF591668D2DC5F58C58D213CC598A62(_stringLiteral88BEE283254D7094E258B3A88730F4CC4F1E4AC7, NULL);
		int32_t L_3 = __this->___sensitivity_5;
		V_3 = ((float)il2cpp_codegen_multiply(L_2, ((float)L_3)));
		// if (y != 0)
		float L_4 = V_3;
		V_4 = (bool)((((int32_t)((((float)L_4) == ((float)(0.0f)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_5 = V_4;
		if (!L_5)
		{
			goto IL_004f;
		}
	}
	{
		// transform.RotateAround(targetPos.position, Vector3.up, y);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_6;
		L_6 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_7 = __this->___targetPos_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8;
		L_8 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_7, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9;
		L_9 = Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline(NULL);
		float L_10 = V_3;
		Transform_RotateAround_m489C5BE8B8B15D0A5F4863DE6D23FF2CC8FA76C6(L_6, L_8, L_9, L_10, NULL);
	}

IL_004f:
	{
	}

IL_0050:
	{
		// float x = Input.GetAxis("Horizontal") / sensitivity; // ??????? A, D
		float L_11;
		L_11 = Input_GetAxis_m10372E6C5FF591668D2DC5F58C58D213CC598A62(_stringLiteral7F8C014BD4810CC276D0F9F81A1E759C7B098B1E, NULL);
		int32_t L_12 = __this->___sensitivity_5;
		V_0 = ((float)(L_11/((float)L_12)));
		// if (x != 0)
		float L_13 = V_0;
		V_5 = (bool)((((int32_t)((((float)L_13) == ((float)(0.0f)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_14 = V_5;
		if (!L_14)
		{
			goto IL_00d1;
		}
	}
	{
		// Vector3 newpos = transform.position + transform.TransformDirection(new Vector3(x, 0, 0));
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_15;
		L_15 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_16;
		L_16 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_15, NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_17;
		L_17 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		float L_18 = V_0;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_19;
		memset((&L_19), 0, sizeof(L_19));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_19), L_18, (0.0f), (0.0f), /*hidden argument*/NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_20;
		L_20 = Transform_TransformDirection_m9BE1261DF2D48B7A4A27D31EE24D2D97F89E7757(L_17, L_19, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_21;
		L_21 = Vector3_op_Addition_m78C0EC70CB66E8DCAC225743D82B268DAEE92067_inline(L_16, L_20, NULL);
		V_6 = L_21;
		// if (ControlDistance(Vector3.Distance(newpos, targetPos.position)))
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_22 = V_6;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_23 = __this->___targetPos_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_24;
		L_24 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_23, NULL);
		float L_25;
		L_25 = Vector3_Distance_m2314DB9B8BD01157E013DF87BEA557375C7F9FF9_inline(L_22, L_24, NULL);
		bool L_26;
		L_26 = Camera_ControlDistance_m64478A576A3EB5A8B8DC52E027CE2F3AD34B8010(__this, L_25, NULL);
		V_7 = L_26;
		bool L_27 = V_7;
		if (!L_27)
		{
			goto IL_00d0;
		}
	}
	{
		// transform.position = newpos;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_28;
		L_28 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_29 = V_6;
		Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156(L_28, L_29, NULL);
	}

IL_00d0:
	{
	}

IL_00d1:
	{
		// float z = Input.GetAxis("Mouse ScrollWheel") * scrollSpeed;
		float L_30;
		L_30 = Input_GetAxis_m10372E6C5FF591668D2DC5F58C58D213CC598A62(_stringLiteralFC6687DC37346CD2569888E29764F727FAF530E0, NULL);
		float L_31 = __this->___scrollSpeed_6;
		V_1 = ((float)il2cpp_codegen_multiply(L_30, L_31));
		// if (z != 0)
		float L_32 = V_1;
		V_8 = (bool)((((int32_t)((((float)L_32) == ((float)(0.0f)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_33 = V_8;
		if (!L_33)
		{
			goto IL_014c;
		}
	}
	{
		// Vector3 newpos = transform.position + transform.TransformDirection(Vector3.forward * z);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_34;
		L_34 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_35;
		L_35 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_34, NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_36;
		L_36 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_37;
		L_37 = Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline(NULL);
		float L_38 = V_1;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_39;
		L_39 = Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline(L_37, L_38, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_40;
		L_40 = Transform_TransformDirection_m9BE1261DF2D48B7A4A27D31EE24D2D97F89E7757(L_36, L_39, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_41;
		L_41 = Vector3_op_Addition_m78C0EC70CB66E8DCAC225743D82B268DAEE92067_inline(L_35, L_40, NULL);
		V_9 = L_41;
		// if (ControlDistance(Vector3.Distance(newpos, targetPos.position)))
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_42 = V_9;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_43 = __this->___targetPos_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_44;
		L_44 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_43, NULL);
		float L_45;
		L_45 = Vector3_Distance_m2314DB9B8BD01157E013DF87BEA557375C7F9FF9_inline(L_42, L_44, NULL);
		bool L_46;
		L_46 = Camera_ControlDistance_m64478A576A3EB5A8B8DC52E027CE2F3AD34B8010(__this, L_45, NULL);
		V_10 = L_46;
		bool L_47 = V_10;
		if (!L_47)
		{
			goto IL_014b;
		}
	}
	{
		// transform.position = newpos;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_48;
		L_48 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_49 = V_9;
		Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156(L_48, L_49, NULL);
	}

IL_014b:
	{
	}

IL_014c:
	{
		// }
		return;
	}
}
// System.Boolean Camera::ControlDistance(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Camera_ControlDistance_m64478A576A3EB5A8B8DC52E027CE2F3AD34B8010 (Camera_t9FA9D68A2946676AA0E9C404046C831F5535DB24* __this, float ___0_distance, const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	int32_t G_B3_0 = 0;
	{
		// if (distance > minDistance && distance < maxDistance) return true;
		float L_0 = ___0_distance;
		int32_t L_1 = __this->___minDistance_8;
		if ((!(((float)L_0) > ((float)((float)L_1)))))
		{
			goto IL_0017;
		}
	}
	{
		float L_2 = ___0_distance;
		int32_t L_3 = __this->___maxDistance_7;
		G_B3_0 = ((((float)L_2) < ((float)((float)L_3)))? 1 : 0);
		goto IL_0018;
	}

IL_0017:
	{
		G_B3_0 = 0;
	}

IL_0018:
	{
		V_0 = (bool)G_B3_0;
		bool L_4 = V_0;
		if (!L_4)
		{
			goto IL_0020;
		}
	}
	{
		// if (distance > minDistance && distance < maxDistance) return true;
		V_1 = (bool)1;
		goto IL_0024;
	}

IL_0020:
	{
		// return false;
		V_1 = (bool)0;
		goto IL_0024;
	}

IL_0024:
	{
		// }
		bool L_5 = V_1;
		return L_5;
	}
}
// System.Void Camera::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Camera__ctor_m25E6BFC52C3B33D00EB7D3809145AB3A385B3EFC (Camera_t9FA9D68A2946676AA0E9C404046C831F5535DB24* __this, const RuntimeMethod* method) 
{
	{
		// int sensitivity = 3;
		__this->___sensitivity_5 = 3;
		// float scrollSpeed = 10f;
		__this->___scrollSpeed_6 = (10.0f);
		// int maxDistance = 100;
		__this->___maxDistance_7 = ((int32_t)100);
		// int minDistance = 1;
		__this->___minDistance_8 = 1;
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeColor::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeColor_Start_mFFF9A8BFA333CC0E38A78786ED5BF7602EF3D3EB (ChangeColor_t70B53D9F65E73F39B15A13EDB83B60E1C29BB9C1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* V_0 = NULL;
	bool V_1 = false;
	{
		// Renderer renderer = GetComponent<Renderer>();
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_0;
		L_0 = Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8(__this, Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		V_0 = L_0;
		// if (renderer != null)
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_1 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_002b;
		}
	}
	{
		// currentColor = GetComponent<Renderer>().material.color;
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_4;
		L_4 = Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8(__this, Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* L_5;
		L_5 = Renderer_get_material_m5BA2A00816C4CC66580D4B2E409CF10718C15656(L_4, NULL);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_6;
		L_6 = Material_get_color_mA4B7D4B96200D9D8B4F36BF19957E9DA81071DBB(L_5, NULL);
		__this->___currentColor_4 = L_6;
	}

IL_002b:
	{
		// }
		return;
	}
}
// System.Void ChangeColor::ChangeCol()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeColor_ChangeCol_m554E9213F68ABAF6D5405A7F4FDED7E0E84F3878 (ChangeColor_t70B53D9F65E73F39B15A13EDB83B60E1C29BB9C1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* V_0 = NULL;
	bool V_1 = false;
	{
		// Renderer renderer = GetComponent<Renderer>();
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_0;
		L_0 = Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8(__this, Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		V_0 = L_0;
		// if (renderer != null)
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_1 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_003a;
		}
	}
	{
		// GetComponent<Renderer>().material.color = new Color(1, 1, 0);
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_4;
		L_4 = Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8(__this, Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* L_5;
		L_5 = Renderer_get_material_m5BA2A00816C4CC66580D4B2E409CF10718C15656(L_4, NULL);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_6;
		memset((&L_6), 0, sizeof(L_6));
		Color__ctor_mCD6889CDE39F18704CD6EA8E2EFBFA48BA3E13B0_inline((&L_6), (1.0f), (1.0f), (0.0f), /*hidden argument*/NULL);
		Material_set_color_m5C32DEBB215FF9EE35E7B575297D8C2F29CC2A2D(L_5, L_6, NULL);
	}

IL_003a:
	{
		// }
		return;
	}
}
// System.Void ChangeColor::ChangeCol1()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeColor_ChangeCol1_mB87B4E501868FD7A5ED56BB5D034A1FCEABB76E5 (ChangeColor_t70B53D9F65E73F39B15A13EDB83B60E1C29BB9C1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* V_0 = NULL;
	bool V_1 = false;
	{
		// Renderer renderer = GetComponent<Renderer>();
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_0;
		L_0 = Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8(__this, Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		V_0 = L_0;
		// if (renderer != null)
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_1 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_002c;
		}
	}
	{
		// GetComponent<Renderer>().material.color = currentColor;
		Renderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF* L_4;
		L_4 = Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8(__this, Component_GetComponent_TisRenderer_t320575F223BCB177A982E5DDB5DB19FAA89E7FBF_mC91ACC92AD57CA6CA00991DAF1DB3830BCE07AF8_RuntimeMethod_var);
		Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* L_5;
		L_5 = Renderer_get_material_m5BA2A00816C4CC66580D4B2E409CF10718C15656(L_4, NULL);
		Color_tD001788D726C3A7F1379BEED0260B9591F440C1F L_6 = __this->___currentColor_4;
		Material_set_color_m5C32DEBB215FF9EE35E7B575297D8C2F29CC2A2D(L_5, L_6, NULL);
	}

IL_002c:
	{
		// }
		return;
	}
}
// System.Void ChangeColor::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeColor__ctor_m8BB1B19B1A2961B218222DF5C104ECAE825C8EA1 (ChangeColor_t70B53D9F65E73F39B15A13EDB83B60E1C29BB9C1* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText1::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText1_OnSettings_mD65DF6F89764A1BA84192A0E2663B0093D53885A (ChangeText1_tDD565E7D40765D3469FFC7098E3425E9CAD8F3CE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral15BC706EA79F9CBF31BF02F9C40C739F58EB15C8);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????????? - ??? ????????????? ??????????, ??????? ???????????? ??? ???????? ????????????? ??????? ????? ????? ??? ????? ????????.";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral15BC706EA79F9CBF31BF02F9C40C739F58EB15C8);
		// }
		return;
	}
}
// System.Void ChangeText1::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText1_OnExit_mA921697C73E18B3F4D20E0DC2E0CAC1BAC2CE5A8 (ChangeText1_tDD565E7D40765D3469FFC7098E3425E9CAD8F3CE* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText1::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText1__ctor_m91F70C59EE8E0CFB00CDFA20EF874FF4949A4F9F (ChangeText1_tDD565E7D40765D3469FFC7098E3425E9CAD8F3CE* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText10::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText10_OnSettings_m9AF3BBBCDF9B8A3027B992930AC353BE425604EB (ChangeText10_tEEB05929B5A0B99B29162C0F24F44C2DEF220974* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFE1B726DA152A7DE337C661475E95B6E311B9860);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "2. ???????? ???????? ???????/????????? ";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteralFE1B726DA152A7DE337C661475E95B6E311B9860);
		// }
		return;
	}
}
// System.Void ChangeText10::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText10_OnExit_m966679D6F86649D6ABE42A5DE0EA936250B52D5C (ChangeText10_tEEB05929B5A0B99B29162C0F24F44C2DEF220974* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText10::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText10__ctor_m9F13754031ECE61D10C6444DFFB26E0EAB532AFA (ChangeText10_tEEB05929B5A0B99B29162C0F24F44C2DEF220974* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText11::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText11_OnSettings_m294921135E4B4AE6D191487982324A97675C7257 (ChangeText11_tE2176BD24191962309985F26D85506A5D4D9F3B1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBDAE78F75C6624B36EA14F930D41E236387AF3B9);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "3. ???????? ????????????? ????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteralBDAE78F75C6624B36EA14F930D41E236387AF3B9);
		// }
		return;
	}
}
// System.Void ChangeText11::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText11_OnExit_m2B772351A00D288A7D16C2A865DEED08F3189976 (ChangeText11_tE2176BD24191962309985F26D85506A5D4D9F3B1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText11::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText11__ctor_mBBC996A73DA9FF3030AAF73436F7E2F33E713F60 (ChangeText11_tE2176BD24191962309985F26D85506A5D4D9F3B1* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText12::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText12_OnSettings_mF1A6BA489AAF9707FDACCAB20EE4A096869E1F00 (ChangeText12_t817B7DC1E62D271BBEB3F13FE53E8B947C979A86* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralAA088AB23998B170C1E74EA50752653670EE33C4);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "3. ?? ???????? ??????? ?????????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteralAA088AB23998B170C1E74EA50752653670EE33C4);
		// }
		return;
	}
}
// System.Void ChangeText12::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText12_OnExit_m179D2829B5073B80CBFD8DB44E89CD52D40D0FE5 (ChangeText12_t817B7DC1E62D271BBEB3F13FE53E8B947C979A86* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText12::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText12__ctor_m937D67D0BF77D8FC177444B57A11DACCCC2495E0 (ChangeText12_t817B7DC1E62D271BBEB3F13FE53E8B947C979A86* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText13::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText13_OnSettings_m11E971673B8DB01C3D07B121A93CAC75C0D31693 (ChangeText13_t43C2E47AF1257F49E4309202F052D13EDDD61560* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2294A02B5DEA3B4E9CBE1471D959E98EC86EC6EC);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "4. ?????????? ?????? ?? ??????? ";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral2294A02B5DEA3B4E9CBE1471D959E98EC86EC6EC);
		// }
		return;
	}
}
// System.Void ChangeText13::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText13_OnExit_mA69F95A2AFCE9370DA7A42FB7B33A538977023C2 (ChangeText13_t43C2E47AF1257F49E4309202F052D13EDDD61560* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText13::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText13__ctor_m3F709EFEC3690D47FA0474A10576A8441744C0F4 (ChangeText13_t43C2E47AF1257F49E4309202F052D13EDDD61560* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText14::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText14_OnSettings_m49B006C5E570F551837B9971D5DA16A26ED2ABAA (ChangeText14_tAA556CC6633063BD1D85621B203B6119C381C240* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral64B966C17214F45051BA3BBE40EFFF89A6C36424);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "??? 1: ???????? ? ??????? ????? ??????? C. ????? ???????? ??????? ?? ????????? ???????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral64B966C17214F45051BA3BBE40EFFF89A6C36424);
		// }
		return;
	}
}
// System.Void ChangeText14::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText14_OnExit_mE193C5CE2238C72E42445EDDFCE9CEDBB71575E0 (ChangeText14_tAA556CC6633063BD1D85621B203B6119C381C240* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText14::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText14__ctor_m2D4E8C242921C7A290D2AF3EFC784878947EDA62 (ChangeText14_tAA556CC6633063BD1D85621B203B6119C381C240* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText15::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText15_OnSettings_m1A18ADC12690557896E39AA73E54ED81870B6F09 (ChangeText15_tF47BF5B2635C1557942793C52E96947674332A4F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral727D72616EA1401037226B5080FD7EEA1AA8D852);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "??? 23232";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral727D72616EA1401037226B5080FD7EEA1AA8D852);
		// }
		return;
	}
}
// System.Void ChangeText15::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText15_OnExit_m80B55F149F0648568B1F074EBD1C339048A63F18 (ChangeText15_tF47BF5B2635C1557942793C52E96947674332A4F* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText15::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText15__ctor_m87856D788E405180B4AF7DD7635F82D9600C4DDC (ChangeText15_tF47BF5B2635C1557942793C52E96947674332A4F* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText16::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText16_OnSettings_mF00B989CACFFB29FD8C1A9B9743E69A1485ED5F2 (ChangeText16_t3B6E07E6C7890D4163472544AE5FBF6E1F964434* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6F976EEE995FFC1EB2410801332E7AB5163E99F7);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "???????? ??????? - ??? ?????????? ??? ???????, ??????????????? ??? ??????????? ????????????? ???????? ?????? ????????? ??? ??????. ";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral6F976EEE995FFC1EB2410801332E7AB5163E99F7);
		// }
		return;
	}
}
// System.Void ChangeText16::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText16_OnExit_m6CDC32BA5E79F2A2A7703CAE08F1C0BC470CD272 (ChangeText16_t3B6E07E6C7890D4163472544AE5FBF6E1F964434* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText16::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText16__ctor_m6F1C833047C2248BF796556A10B2439A6D8475CA (ChangeText16_t3B6E07E6C7890D4163472544AE5FBF6E1F964434* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText2::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText2_OnSettings_m82C4636E78E90E8E7E0B6A8CE91EEECDC7F1D075 (ChangeText2_t66CA80084DC5D32919692C6D40BEA1321A96BCE4* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2891C1EE6C522F08A3F752A34DB4E31A09508606);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????????? - ??? ????????????? ??????????, ??????????????? ??? ?????????? ??? ???????????? ????????????? ?????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral2891C1EE6C522F08A3F752A34DB4E31A09508606);
		// }
		return;
	}
}
// System.Void ChangeText2::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText2_OnExit_mE9A164BF81AECF8A4928AD33B0094155E847B493 (ChangeText2_t66CA80084DC5D32919692C6D40BEA1321A96BCE4* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText2::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText2__ctor_mEFA02D1FA7938D96649455E49F017ECC11B8F17A (ChangeText2_t66CA80084DC5D32919692C6D40BEA1321A96BCE4* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText3::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText3_OnSettings_m1C04DB24A05293008FD20EB3AF7B567248F2C072 (ChangeText3_t0F74CBD51AB6C9AE379D6C6B72937A66C6D81B19* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6F976EEE995FFC1EB2410801332E7AB5163E99F7);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "???????? ??????? - ??? ?????????? ??? ???????, ??????????????? ??? ??????????? ????????????? ???????? ?????? ????????? ??? ??????. ";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral6F976EEE995FFC1EB2410801332E7AB5163E99F7);
		// }
		return;
	}
}
// System.Void ChangeText3::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText3_OnExit_m4B7813F696B89F05ABC75427A7FE69403FD1E140 (ChangeText3_t0F74CBD51AB6C9AE379D6C6B72937A66C6D81B19* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText3::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText3__ctor_m7888B899B074E803282C6F4399C5373712CCB03A (ChangeText3_t0F74CBD51AB6C9AE379D6C6B72937A66C6D81B19* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText4::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText4_OnSettings_m01089500167F0A0623A7278D68AE65B557FAAA44 (ChangeText4_t9131E982E802BAA38DB2438DD54313985A44F84C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0068482617098B0041B46A581D3FD79189050B55);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "?????????????? - ??? ????????????? ??????, ???????????? ??? ????????? ?????????????? ????, ??????????? ? ???????????? (??). ";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral0068482617098B0041B46A581D3FD79189050B55);
		// }
		return;
	}
}
// System.Void ChangeText4::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText4_OnExit_mFBC6236770CC7B4FD79B7AF3ECB7702BCD4107AB (ChangeText4_t9131E982E802BAA38DB2438DD54313985A44F84C* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText4::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText4__ctor_m0CF4B7866688EECA9469674C6887DD44FD487357 (ChangeText4_t9131E982E802BAA38DB2438DD54313985A44F84C* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText5::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText5_OnSettings_mB1DCAE7FF2384FB699636FF83995A6A723525DFF (ChangeText5_tB143BE03DA2DF2D6F5DC2AB8D78925F3AFC08907* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0622AE9DF118BA2589680D980FEC763981B180F9);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "??????? ????????????? - ??? ????????????? ??????????, ??????? ??????? ??????????? ????????????? ? ????????????? ????. ";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral0622AE9DF118BA2589680D980FEC763981B180F9);
		// }
		return;
	}
}
// System.Void ChangeText5::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText5_OnExit_m8B53AEC95FD8D13EA17CB8616EF8254CE40F653A (ChangeText5_tB143BE03DA2DF2D6F5DC2AB8D78925F3AFC08907* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText5::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText5__ctor_m759081D73CD7C07543D4DEEBD991A8F9EF3E5ED1 (ChangeText5_tB143BE03DA2DF2D6F5DC2AB8D78925F3AFC08907* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText6::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText6_OnSettings_mDA5F71A5C1EA7256DAFDB78E6B4218051770ED0A (ChangeText6_t48F992915F56F9296E34DC38A3CE36ACEAE7BF22* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral1AB42754C0B85DC778ADC812754A92A13BDE19BB);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "??????? - ??? ?????????? ????????????? ??????????, ???????????? ??? ????????? ????????????? ? ????????????? ????.";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral1AB42754C0B85DC778ADC812754A92A13BDE19BB);
		// }
		return;
	}
}
// System.Void ChangeText6::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText6_OnExit_mF9DF66BBF91387CAE5065F736AE9DF83AB0EE7F4 (ChangeText6_t48F992915F56F9296E34DC38A3CE36ACEAE7BF22* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText6::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText6__ctor_m33B0D92B5BCC67E88F9D89191017FC96813E654B (ChangeText6_t48F992915F56F9296E34DC38A3CE36ACEAE7BF22* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText7::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText7_OnSettings_m50CF6B04445DA8A360466B1F24B04C2685E44136 (ChangeText7_tDB92093D4D186F59BCC8539C17FB183FEE977780* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2A1197F53A255F57930E97CAA10DF6FABF13C3E1);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "??????? - ??? ??? ????????????? ??? ???????????, ??????? ???????????? ??? ?????????? ?????????????? ??????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral2A1197F53A255F57930E97CAA10DF6FABF13C3E1);
		// }
		return;
	}
}
// System.Void ChangeText7::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText7_OnExit_mDF9F7B52C3D426B0B389E996321E420F59D03023 (ChangeText7_tDB92093D4D186F59BCC8539C17FB183FEE977780* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText7::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText7__ctor_m8B8DE08E38BB1A5BB6E85F84619573109FB55CCF (ChangeText7_tDB92093D4D186F59BCC8539C17FB183FEE977780* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText8::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText8_OnSettings_m8590540FA01A73EAB11DE3605C1CFFED2AA5D5D9 (ChangeText8_tAD6D121FBC92DE4396AD3B01F83395FE5B5F7AE1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE94F8E7EE311280D32FA4CB842D2C6C91C18F201);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????? - ??? ????????????? ??????, ??????????????? ??? ????????? ?????????? ? ????????????? ?????. ";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteralE94F8E7EE311280D32FA4CB842D2C6C91C18F201);
		// }
		return;
	}
}
// System.Void ChangeText8::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText8_OnExit_m290E41F4FED26F7C4AEDE6D0761F872A7BD4917B (ChangeText8_tAD6D121FBC92DE4396AD3B01F83395FE5B5F7AE1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText8::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText8__ctor_mC81EB04B8A866620E627338F73067D6A6E8932E1 (ChangeText8_tAD6D121FBC92DE4396AD3B01F83395FE5B5F7AE1* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void ChangeText9::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText9_OnSettings_m0514FEA5148DD07AD9583B6AB0186726B1A21FD0 (ChangeText9_tA70CB19E32A836A3CBFFD1EC25F831C48FC985FC* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral008B35E247C06DE8267E2688661ED79A44F96CAA);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "1. ???????? ? ??????? ???????? ????????? ? ???????? ???????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral008B35E247C06DE8267E2688661ED79A44F96CAA);
		// }
		return;
	}
}
// System.Void ChangeText9::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText9_OnExit_m5D1E540012F42959E09A75399E47AB8C45BB3FE8 (ChangeText9_tA70CB19E32A836A3CBFFD1EC25F831C48FC985FC* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "????????";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral09FEFD4C446CB9644CFC99EEC4A84F0C3D47739C);
		// }
		return;
	}
}
// System.Void ChangeText9::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ChangeText9__ctor_m96D151A44F92AC8A6EDAE3A5880AEE96AA34F87A (ChangeText9_tA70CB19E32A836A3CBFFD1EC25F831C48FC985FC* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void CupControl::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CupControl_Start_m46A7E32DCD90DFD6AD01336105A71D2BF3EF1908 (CupControl_tA04B1EB807F79800176E939A70AA4B94EA5CB61D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// cup = GetComponent<Animator>();
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_0;
		L_0 = Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE(__this, Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		__this->___cup_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___cup_4), (void*)L_0);
		// }
		return;
	}
}
// System.Void CupControl::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CupControl_Update_m64D610E327AD6EB30D2E3D5B62EF23E3D860DA68 (CupControl_tA04B1EB807F79800176E939A70AA4B94EA5CB61D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9CEB4D81FE1382FF120AEE05E403D6F7BCE690D2);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		// if (Input.GetKeyDown(KeyCode.T)) { cup.SetTrigger("hit"); }
		bool L_0;
		L_0 = Input_GetKeyDown_mB237DEA6244132670D38990BAB77D813FBB028D2(((int32_t)116), NULL);
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_001f;
		}
	}
	{
		// if (Input.GetKeyDown(KeyCode.T)) { cup.SetTrigger("hit"); }
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_2 = __this->___cup_4;
		Animator_SetTrigger_mC9CD54D627C8843EF6E159E167449D216EF6EB30(L_2, _stringLiteral9CEB4D81FE1382FF120AEE05E403D6F7BCE690D2, NULL);
	}

IL_001f:
	{
		// }
		return;
	}
}
// System.Void CupControl::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void CupControl__ctor_mCA63BDF454CF2AE0C1CB234F73C55089B36AB5F3 (CupControl_tA04B1EB807F79800176E939A70AA4B94EA5CB61D* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Boolean GlobalGonfig::get_isConstTok()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool GlobalGonfig_get_isConstTok_mB62CCC94C131692862AB730ED6980A2E68C320C2 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isConstTok { get; set; } = true;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0 = ((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisConstTokU3Ek__BackingField_0;
		return L_0;
	}
}
// System.Void GlobalGonfig::set_isConstTok(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GlobalGonfig_set_isConstTok_m829451F001136839108CCAF669A96DA63F266A7D (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isConstTok { get; set; } = true;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisConstTokU3Ek__BackingField_0 = L_0;
		return;
	}
}
// System.Boolean GlobalGonfig::get_isHeart()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool GlobalGonfig_get_isHeart_m14A72AC416E63D6C1A5F8C371A85FE17667A0EF6 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isHeart { get; set; } = false;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0 = ((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisHeartU3Ek__BackingField_1;
		return L_0;
	}
}
// System.Void GlobalGonfig::set_isHeart(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GlobalGonfig_set_isHeart_m989E0D619D6EA32F6836D4F97269A4AF84416BA2 (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isHeart { get; set; } = false;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisHeartU3Ek__BackingField_1 = L_0;
		return;
	}
}
// System.Boolean GlobalGonfig::get_isSocket()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool GlobalGonfig_get_isSocket_m57DAE1FBAE65E6AC8FADDED4F56EEEB136152844 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isSocket { get; set; } = false;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0 = ((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisSocketU3Ek__BackingField_2;
		return L_0;
	}
}
// System.Void GlobalGonfig::set_isSocket(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GlobalGonfig_set_isSocket_m89642441CD2C0F5112EA12496F732EA889B224CC (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isSocket { get; set; } = false;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisSocketU3Ek__BackingField_2 = L_0;
		return;
	}
}
// System.Int32 GlobalGonfig::get_Step()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t GlobalGonfig_get_Step_m486B62F18526F24C79F59C02E034D73902EACD16 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static int Step { get; set; } = 0;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		int32_t L_0 = ((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CStepU3Ek__BackingField_3;
		return L_0;
	}
}
// System.Void GlobalGonfig::set_Step(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GlobalGonfig_set_Step_m07F0DC514B18F632AA191958E08758F26EB1192A (int32_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static int Step { get; set; } = 0;
		int32_t L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CStepU3Ek__BackingField_3 = L_0;
		return;
	}
}
// System.Void GlobalGonfig::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GlobalGonfig__cctor_mAD7A77298293F5267DA58B699AA7317B40EECEFF (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isConstTok { get; set; } = true;
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisConstTokU3Ek__BackingField_0 = (bool)1;
		// public static bool isHeart { get; set; } = false;
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisHeartU3Ek__BackingField_1 = (bool)0;
		// public static bool isSocket { get; set; } = false;
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisSocketU3Ek__BackingField_2 = (bool)0;
		// public static int Step { get; set; } = 0;
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CStepU3Ek__BackingField_3 = 0;
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MoveCam::Move0()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam_Move0_m796485A2DDAEDF94630879DC25F3BF47F083548E (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	{
		// move = true;
		__this->___move_4 = (bool)1;
		// startPosition = transform.position;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0;
		L_0 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_0, NULL);
		__this->___startPosition_7 = L_1;
		// startRotation = transform.rotation;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_3;
		L_3 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_2, NULL);
		__this->___startRotation_9 = L_3;
		// needPosition = new Vector3(46.7f, 124f, 830.4f);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), (46.7000008f), (124.0f), (830.400024f), /*hidden argument*/NULL);
		__this->___needPosition_8 = L_4;
		// needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		memset((&L_5), 0, sizeof(L_5));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_5), (1.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6;
		L_6 = Quaternion_AngleAxis_mF37022977B297E63AA70D69EA1C4C922FF22CC80((23.1259995f), L_5, NULL);
		__this->___needRotaton_10 = L_6;
		// }
		return;
	}
}
// System.Void MoveCam::Move1()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam_Move1_m808861FCC44E1AF2FDB79F90898398FE09516724 (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	{
		// move = true;
		__this->___move_4 = (bool)1;
		// startPosition = transform.position;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0;
		L_0 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_0, NULL);
		__this->___startPosition_7 = L_1;
		// startRotation = transform.rotation;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_3;
		L_3 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_2, NULL);
		__this->___startRotation_9 = L_3;
		// needPosition = new Vector3(63.4347f, 102.7913f, 890.0599f);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), (63.4347f), (102.791298f), (890.059875f), /*hidden argument*/NULL);
		__this->___needPosition_8 = L_4;
		// needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		memset((&L_5), 0, sizeof(L_5));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_5), (1.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6;
		L_6 = Quaternion_AngleAxis_mF37022977B297E63AA70D69EA1C4C922FF22CC80((23.1259995f), L_5, NULL);
		__this->___needRotaton_10 = L_6;
		// }
		return;
	}
}
// System.Void MoveCam::Move2()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam_Move2_m0C26B8C7832CB2504E62DD4D49231A35A4D9EB51 (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	{
		// move = true;
		__this->___move_4 = (bool)1;
		// startPosition = transform.position;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0;
		L_0 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_0, NULL);
		__this->___startPosition_7 = L_1;
		// startRotation = transform.rotation;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_3;
		L_3 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_2, NULL);
		__this->___startRotation_9 = L_3;
		// needPosition = new Vector3(61.32006f, 103.1837f, 880.1401f);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), (61.3200607f), (103.183701f), (880.140076f), /*hidden argument*/NULL);
		__this->___needPosition_8 = L_4;
		// needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		memset((&L_5), 0, sizeof(L_5));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_5), (1.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6;
		L_6 = Quaternion_AngleAxis_mF37022977B297E63AA70D69EA1C4C922FF22CC80((23.1259995f), L_5, NULL);
		__this->___needRotaton_10 = L_6;
		// }
		return;
	}
}
// System.Void MoveCam::Move3()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam_Move3_mB993423907FBFF200A439BD490310C8213575899 (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	{
		// move = true;
		__this->___move_4 = (bool)1;
		// startPosition = transform.position;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0;
		L_0 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_0, NULL);
		__this->___startPosition_7 = L_1;
		// startRotation = transform.rotation;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_3;
		L_3 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_2, NULL);
		__this->___startRotation_9 = L_3;
		// needPosition = new Vector3(87.41313f, 102.3982f, 880.9795f);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), (87.4131317f), (102.398201f), (880.979492f), /*hidden argument*/NULL);
		__this->___needPosition_8 = L_4;
		// needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		memset((&L_5), 0, sizeof(L_5));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_5), (1.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6;
		L_6 = Quaternion_AngleAxis_mF37022977B297E63AA70D69EA1C4C922FF22CC80((23.1259995f), L_5, NULL);
		__this->___needRotaton_10 = L_6;
		// }
		return;
	}
}
// System.Void MoveCam::Move4()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam_Move4_mD5299154E68AA229EC0891F30ECDC0ABF2300D5C (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	{
		// move = true;
		__this->___move_4 = (bool)1;
		// startPosition = transform.position;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0;
		L_0 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_0, NULL);
		__this->___startPosition_7 = L_1;
		// startRotation = transform.rotation;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_3;
		L_3 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_2, NULL);
		__this->___startRotation_9 = L_3;
		// needPosition = new Vector3(48.11927f, 103.1837f, 879.1404f);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), (48.1192703f), (103.183701f), (879.140381f), /*hidden argument*/NULL);
		__this->___needPosition_8 = L_4;
		// needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		memset((&L_5), 0, sizeof(L_5));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_5), (1.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6;
		L_6 = Quaternion_AngleAxis_mF37022977B297E63AA70D69EA1C4C922FF22CC80((23.1259995f), L_5, NULL);
		__this->___needRotaton_10 = L_6;
		// }
		return;
	}
}
// System.Void MoveCam::Move5()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam_Move5_mF51615195A356F30BA9376BE09DC0FD2BE3752F9 (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	{
		// move = true;
		__this->___move_4 = (bool)1;
		// startPosition = transform.position;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0;
		L_0 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_0, NULL);
		__this->___startPosition_7 = L_1;
		// startRotation = transform.rotation;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_3;
		L_3 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_2, NULL);
		__this->___startRotation_9 = L_3;
		// needPosition = new Vector3(31.34561f, 101.2199f, 883.7385f);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), (31.3456097f), (101.219902f), (883.738525f), /*hidden argument*/NULL);
		__this->___needPosition_8 = L_4;
		// needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		memset((&L_5), 0, sizeof(L_5));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_5), (1.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6;
		L_6 = Quaternion_AngleAxis_mF37022977B297E63AA70D69EA1C4C922FF22CC80((23.1259995f), L_5, NULL);
		__this->___needRotaton_10 = L_6;
		// }
		return;
	}
}
// System.Void MoveCam::Move6()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam_Move6_m33BC02AD2021D4D83B7562C822A5323693A4F978 (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	{
		// move = true;
		__this->___move_4 = (bool)1;
		// startPosition = transform.position;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0;
		L_0 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_0, NULL);
		__this->___startPosition_7 = L_1;
		// startRotation = transform.rotation;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_3;
		L_3 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_2, NULL);
		__this->___startRotation_9 = L_3;
		// needPosition = new Vector3(73.09177f, 101.2199f, 883.7385f);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), (73.0917664f), (101.219902f), (883.738525f), /*hidden argument*/NULL);
		__this->___needPosition_8 = L_4;
		// needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		memset((&L_5), 0, sizeof(L_5));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_5), (1.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6;
		L_6 = Quaternion_AngleAxis_mF37022977B297E63AA70D69EA1C4C922FF22CC80((23.1259995f), L_5, NULL);
		__this->___needRotaton_10 = L_6;
		// }
		return;
	}
}
// System.Void MoveCam::Move7()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam_Move7_m682D3F3D5B918BF311F196CD4445FCBA8A9CAAEB (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	{
		// move = true;
		__this->___move_4 = (bool)1;
		// startPosition = transform.position;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0;
		L_0 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_0, NULL);
		__this->___startPosition_7 = L_1;
		// startRotation = transform.rotation;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_3;
		L_3 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_2, NULL);
		__this->___startRotation_9 = L_3;
		// needPosition = new Vector3(40.74721f, 102.791f, 880.0601f);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), (40.7472115f), (102.791f), (880.06012f), /*hidden argument*/NULL);
		__this->___needPosition_8 = L_4;
		// needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		memset((&L_5), 0, sizeof(L_5));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_5), (1.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6;
		L_6 = Quaternion_AngleAxis_mF37022977B297E63AA70D69EA1C4C922FF22CC80((23.1259995f), L_5, NULL);
		__this->___needRotaton_10 = L_6;
		// }
		return;
	}
}
// System.Void MoveCam::Move8()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam_Move8_mCB1C1717CA1F033A1C0B0A4DE4533D9A0116A1BE (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	{
		// move = true;
		__this->___move_4 = (bool)1;
		// startPosition = transform.position;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_0;
		L_0 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1;
		L_1 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_0, NULL);
		__this->___startPosition_7 = L_1;
		// startRotation = transform.rotation;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_2;
		L_2 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_3;
		L_3 = Transform_get_rotation_m32AF40CA0D50C797DA639A696F8EAEC7524C179C(L_2, NULL);
		__this->___startRotation_9 = L_3;
		// needPosition = new Vector3(15.36858f, 94.15027f, 900.2919f);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4;
		memset((&L_4), 0, sizeof(L_4));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_4), (15.3685799f), (94.1502686f), (900.29187f), /*hidden argument*/NULL);
		__this->___needPosition_8 = L_4;
		// needRotaton = Quaternion.AngleAxis(23.126f, new Vector3(1, 0, 0));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		memset((&L_5), 0, sizeof(L_5));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_5), (1.0f), (0.0f), (0.0f), /*hidden argument*/NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_6;
		L_6 = Quaternion_AngleAxis_mF37022977B297E63AA70D69EA1C4C922FF22CC80((23.1259995f), L_5, NULL);
		__this->___needRotaton_10 = L_6;
		// }
		return;
	}
}
// System.Void MoveCam::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam_Update_m8444DCC1A6A5C7FC2C10C2D39B60709BB0EF1034 (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	{
		// if (move)
		bool L_0 = __this->___move_4;
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0091;
		}
	}
	{
		// offset += speed;
		float L_2 = __this->___offset_6;
		float L_3 = __this->___speed_5;
		__this->___offset_6 = ((float)il2cpp_codegen_add(L_2, L_3));
		// transform.position = Vector3.Lerp(startPosition, needPosition, offset);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_4;
		L_4 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5 = __this->___startPosition_7;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = __this->___needPosition_8;
		float L_7 = __this->___offset_6;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8;
		L_8 = Vector3_Lerp_m3A906D0530A94FAABB94F0F905E84D99BE85C3F8_inline(L_5, L_6, L_7, NULL);
		Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156(L_4, L_8, NULL);
		// transform.rotation = Quaternion.Slerp(startRotation, needRotaton, offset);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_9;
		L_9 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_10 = __this->___startRotation_9;
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_11 = __this->___needRotaton_10;
		float L_12 = __this->___offset_6;
		Quaternion_tDA59F214EF07D7700B26E40E562F267AF7306974 L_13;
		L_13 = Quaternion_Slerp_m0A9969F500E7716EA4F6BC4E7D5464372D8E9E15(L_10, L_11, L_12, NULL);
		Transform_set_rotation_m61340DE74726CF0F9946743A727C4D444397331D(L_9, L_13, NULL);
		// if (offset >= 1)
		float L_14 = __this->___offset_6;
		V_1 = (bool)((((int32_t)((!(((float)L_14) >= ((float)(1.0f))))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_15 = V_1;
		if (!L_15)
		{
			goto IL_0090;
		}
	}
	{
		// move = false;
		__this->___move_4 = (bool)0;
		// offset = 0;
		__this->___offset_6 = (0.0f);
	}

IL_0090:
	{
	}

IL_0091:
	{
		// }
		return;
	}
}
// System.Void MoveCam::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveCam__ctor_m18E21EA8FFD9EF4CDD29A4DC2FD21046AF62307F (MoveCam_tB7AAC3D6A6A2CC582700E8564092DDD34EBF468A* __this, const RuntimeMethod* method) 
{
	{
		// bool move = false;
		__this->___move_4 = (bool)0;
		// float speed = 0.01f;
		__this->___speed_5 = (0.00999999978f);
		// float offset = 0;
		__this->___offset_6 = (0.0f);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void MoveObjectWithMouse::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveObjectWithMouse_Update_mFFA2BACB925A7FF7E04F6ECC5B9885416970FC39 (MoveObjectWithMouse_tFEBCCC731305AB9831C1038E010BA3E5E999DFD0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 V_1;
	memset((&V_1), 0, sizeof(V_1));
	RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 V_2;
	memset((&V_2), 0, sizeof(V_2));
	bool V_3 = false;
	bool V_4 = false;
	bool V_5 = false;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_6;
	memset((&V_6), 0, sizeof(V_6));
	float V_7 = 0.0f;
	int32_t G_B4_0 = 0;
	{
		// if (Input.GetMouseButtonDown(0))
		bool L_0;
		L_0 = Input_GetMouseButtonDown_m8DFC792D15FFF15D311614D5CC6C5D055E5A1DE3(0, NULL);
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0054;
		}
	}
	{
		// Ray ray = UnityEngine.Camera.main.ScreenPointToRay(Input.mousePosition);
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_2;
		L_2 = Camera_get_main_m52C992F18E05355ABB9EEB64A4BF2215E12762DF(NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_3;
		L_3 = Input_get_mousePosition_mFF21FBD2647DAE2A23BD4C45571CA95D05A0A42C(NULL);
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_4;
		L_4 = Camera_ScreenPointToRay_m2887B9A49880B7AB670C57D66B67D6A6689FE315(L_2, L_3, NULL);
		V_1 = L_4;
		// if (Physics.Raycast(ray, out hit) && hit.transform == transform)
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_5 = V_1;
		bool L_6;
		L_6 = Physics_Raycast_mCAC9F02A1AAB49E16B384EBC8318E2DF30F4B0E5(L_5, (&V_2), NULL);
		if (!L_6)
		{
			goto IL_003a;
		}
	}
	{
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_7;
		L_7 = RaycastHit_get_transform_m89DB7FCFC50E0213A37CBE089400064B8FA19155((&V_2), NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_8;
		L_8 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_9;
		L_9 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_7, L_8, NULL);
		G_B4_0 = ((int32_t)(L_9));
		goto IL_003b;
	}

IL_003a:
	{
		G_B4_0 = 0;
	}

IL_003b:
	{
		V_3 = (bool)G_B4_0;
		bool L_10 = V_3;
		if (!L_10)
		{
			goto IL_0053;
		}
	}
	{
		// isMoving = true;
		__this->___isMoving_4 = (bool)1;
		// previousMousePosition = Input.mousePosition;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_11;
		L_11 = Input_get_mousePosition_mFF21FBD2647DAE2A23BD4C45571CA95D05A0A42C(NULL);
		__this->___previousMousePosition_5 = L_11;
	}

IL_0053:
	{
	}

IL_0054:
	{
		// if (Input.GetMouseButtonUp(0))
		bool L_12;
		L_12 = Input_GetMouseButtonUp_mBE89CC9C69BBEA9A863819E77EA54411B0476ED6(0, NULL);
		V_4 = L_12;
		bool L_13 = V_4;
		if (!L_13)
		{
			goto IL_0069;
		}
	}
	{
		// isMoving = false;
		__this->___isMoving_4 = (bool)0;
	}

IL_0069:
	{
		// if (isMoving)
		bool L_14 = __this->___isMoving_4;
		V_5 = L_14;
		bool L_15 = V_5;
		if (!L_15)
		{
			goto IL_00d2;
		}
	}
	{
		// Vector3 currentMousePosition = Input.mousePosition;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_16;
		L_16 = Input_get_mousePosition_mFF21FBD2647DAE2A23BD4C45571CA95D05A0A42C(NULL);
		V_6 = L_16;
		// float deltaY = currentMousePosition.y - previousMousePosition.y;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_17 = V_6;
		float L_18 = L_17.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* L_19 = (&__this->___previousMousePosition_5);
		float L_20 = L_19->___y_3;
		V_7 = ((float)il2cpp_codegen_subtract(L_18, L_20));
		// transform.position = new Vector3(transform.position.x, objectPositionY, transform.position.z);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_21;
		L_21 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_22;
		L_22 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_23;
		L_23 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_22, NULL);
		float L_24 = L_23.___x_2;
		float L_25 = __this->___objectPositionY_6;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_26;
		L_26 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_27;
		L_27 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_26, NULL);
		float L_28 = L_27.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_29;
		memset((&L_29), 0, sizeof(L_29));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_29), L_24, L_25, L_28, /*hidden argument*/NULL);
		Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156(L_21, L_29, NULL);
		// previousMousePosition = currentMousePosition;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_30 = V_6;
		__this->___previousMousePosition_5 = L_30;
	}

IL_00d2:
	{
		// }
		return;
	}
}
// System.Void MoveObjectWithMouse::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MoveObjectWithMouse__ctor_mB00A0FE38B546DD93CD9E5AC881B18047056CD55 (MoveObjectWithMouse_tFEBCCC731305AB9831C1038E010BA3E5E999DFD0* __this, const RuntimeMethod* method) 
{
	{
		// bool isMoving = false;
		__this->___isMoving_4 = (bool)0;
		// float objectPositionY = 0;
		__this->___objectPositionY_6 = (0.0f);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void OutputInfo::OnButtonClicked()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OutputInfo_OnButtonClicked_m6D5E31BB4CF9703A94D8D59F0E719A8A3942CD8D (OutputInfo_tAC08BE0EC12F767A093907FF0347268ABA8E6BBB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	double V_3 = 0.0;
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	bool V_7 = false;
	bool V_8 = false;
	bool V_9 = false;
	bool V_10 = false;
	bool V_11 = false;
	bool V_12 = false;
	bool V_13 = false;
	bool V_14 = false;
	bool V_15 = false;
	bool V_16 = false;
	bool V_17 = false;
	bool V_18 = false;
	bool V_19 = false;
	bool V_20 = false;
	bool V_21 = false;
	bool V_22 = false;
	bool V_23 = false;
	bool V_24 = false;
	bool V_25 = false;
	{
		// if (textInput.text.Length == 0) return;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_0 = __this->___textInput_6;
		String_t* L_1;
		L_1 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_0, NULL);
		int32_t L_2;
		L_2 = String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline(L_1, NULL);
		V_0 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
		bool L_3 = V_0;
		if (!L_3)
		{
			goto IL_001d;
		}
	}
	{
		// if (textInput.text.Length == 0) return;
		goto IL_0a80;
	}

IL_001d:
	{
		// if (_1.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_4 = __this->____1_7;
		String_t* L_5;
		L_5 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_4);
		bool L_6;
		L_6 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_5, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_1 = L_6;
		bool L_7 = V_1;
		if (!L_7)
		{
			goto IL_0057;
		}
	}
	{
		// _1.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_8 = __this->____1_7;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_9 = __this->___textInput_6;
		String_t* L_10;
		L_10 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_9, NULL);
		String_t* L_11;
		L_11 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_10);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_8, L_11);
		goto IL_0a6f;
	}

IL_0057:
	{
		// else if (_2.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_12 = __this->____2_8;
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_12);
		bool L_14;
		L_14 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_13, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_2 = L_14;
		bool L_15 = V_2;
		if (!L_15)
		{
			goto IL_00cf;
		}
	}
	{
		// _2.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_16 = __this->____2_8;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_17 = __this->___textInput_6;
		String_t* L_18;
		L_18 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_17, NULL);
		String_t* L_19;
		L_19 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_18);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_16, L_19);
		// R1.text = Math.Round(float.Parse(_1.text) / float.Parse(_2.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_20 = __this->___R1_31;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_21 = __this->____1_7;
		String_t* L_22;
		L_22 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_21);
		float L_23;
		L_23 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_22, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_24 = __this->____2_8;
		String_t* L_25;
		L_25 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_24);
		float L_26;
		L_26 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_25, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_27;
		L_27 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_23/L_26))), 2, NULL);
		V_3 = L_27;
		String_t* L_28;
		L_28 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_20, L_28);
		goto IL_0a6f;
	}

IL_00cf:
	{
		// else if (_3.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_29 = __this->____3_9;
		String_t* L_30;
		L_30 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_29);
		bool L_31;
		L_31 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_30, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_4 = L_31;
		bool L_32 = V_4;
		if (!L_32)
		{
			goto IL_010d;
		}
	}
	{
		// _3.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_33 = __this->____3_9;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_34 = __this->___textInput_6;
		String_t* L_35;
		L_35 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_34, NULL);
		String_t* L_36;
		L_36 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_35);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_33, L_36);
		goto IL_0a6f;
	}

IL_010d:
	{
		// else if (_4.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_37 = __this->____4_10;
		String_t* L_38;
		L_38 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_37);
		bool L_39;
		L_39 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_38, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_5 = L_39;
		bool L_40 = V_5;
		if (!L_40)
		{
			goto IL_0187;
		}
	}
	{
		// _4.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_41 = __this->____4_10;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_42 = __this->___textInput_6;
		String_t* L_43;
		L_43 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_42, NULL);
		String_t* L_44;
		L_44 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_43);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_41, L_44);
		// R2.text = Math.Round(float.Parse(_3.text) / float.Parse(_4.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_45 = __this->___R2_32;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_46 = __this->____3_9;
		String_t* L_47;
		L_47 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_46);
		float L_48;
		L_48 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_47, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_49 = __this->____4_10;
		String_t* L_50;
		L_50 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_49);
		float L_51;
		L_51 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_50, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_52;
		L_52 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_48/L_51))), 2, NULL);
		V_3 = L_52;
		String_t* L_53;
		L_53 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_45, L_53);
		goto IL_0a6f;
	}

IL_0187:
	{
		// else if (_5.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_54 = __this->____5_11;
		String_t* L_55;
		L_55 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_54);
		bool L_56;
		L_56 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_55, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_6 = L_56;
		bool L_57 = V_6;
		if (!L_57)
		{
			goto IL_01c5;
		}
	}
	{
		// _5.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_58 = __this->____5_11;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_59 = __this->___textInput_6;
		String_t* L_60;
		L_60 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_59, NULL);
		String_t* L_61;
		L_61 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_60);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_58, L_61);
		goto IL_0a6f;
	}

IL_01c5:
	{
		// else if (_6.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_62 = __this->____6_12;
		String_t* L_63;
		L_63 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_62);
		bool L_64;
		L_64 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_63, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_7 = L_64;
		bool L_65 = V_7;
		if (!L_65)
		{
			goto IL_0294;
		}
	}
	{
		// _6.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_66 = __this->____6_12;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_67 = __this->___textInput_6;
		String_t* L_68;
		L_68 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_67, NULL);
		String_t* L_69;
		L_69 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_68);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_66, L_69);
		// R3.text = Math.Round(float.Parse(_5.text) / float.Parse(_6.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_70 = __this->___R3_33;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_71 = __this->____5_11;
		String_t* L_72;
		L_72 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_71);
		float L_73;
		L_73 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_72, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_74 = __this->____6_12;
		String_t* L_75;
		L_75 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_74);
		float L_76;
		L_76 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_75, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_77;
		L_77 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_73/L_76))), 2, NULL);
		V_3 = L_77;
		String_t* L_78;
		L_78 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_70, L_78);
		// R1Result.text = Math.Round((float.Parse(R1.text) + float.Parse(R2.text) + float.Parse(R3.text))/3).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_79 = __this->___R1Result_34;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_80 = __this->___R1_31;
		String_t* L_81;
		L_81 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_80);
		float L_82;
		L_82 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_81, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_83 = __this->___R2_32;
		String_t* L_84;
		L_84 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_83);
		float L_85;
		L_85 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_84, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_86 = __this->___R3_33;
		String_t* L_87;
		L_87 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_86);
		float L_88;
		L_88 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_87, NULL);
		double L_89;
		L_89 = bankers_round(((double)((float)(((float)il2cpp_codegen_add(((float)il2cpp_codegen_add(L_82, L_85)), L_88))/(3.0f)))));
		V_3 = L_89;
		String_t* L_90;
		L_90 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_79, L_90);
		goto IL_0a6f;
	}

IL_0294:
	{
		// else if (_7.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_91 = __this->____7_13;
		String_t* L_92;
		L_92 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_91);
		bool L_93;
		L_93 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_92, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_8 = L_93;
		bool L_94 = V_8;
		if (!L_94)
		{
			goto IL_02d2;
		}
	}
	{
		// _7.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_95 = __this->____7_13;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_96 = __this->___textInput_6;
		String_t* L_97;
		L_97 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_96, NULL);
		String_t* L_98;
		L_98 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_97);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_95, L_98);
		goto IL_0a6f;
	}

IL_02d2:
	{
		// else if (_8.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_99 = __this->____8_14;
		String_t* L_100;
		L_100 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_99);
		bool L_101;
		L_101 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_100, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_9 = L_101;
		bool L_102 = V_9;
		if (!L_102)
		{
			goto IL_034c;
		}
	}
	{
		// _8.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_103 = __this->____8_14;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_104 = __this->___textInput_6;
		String_t* L_105;
		L_105 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_104, NULL);
		String_t* L_106;
		L_106 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_105);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_103, L_106);
		// R4.text = Math.Round(float.Parse(_7.text) / float.Parse(_8.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_107 = __this->___R4_35;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_108 = __this->____7_13;
		String_t* L_109;
		L_109 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_108);
		float L_110;
		L_110 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_109, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_111 = __this->____8_14;
		String_t* L_112;
		L_112 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_111);
		float L_113;
		L_113 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_112, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_114;
		L_114 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_110/L_113))), 2, NULL);
		V_3 = L_114;
		String_t* L_115;
		L_115 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_107, L_115);
		goto IL_0a6f;
	}

IL_034c:
	{
		// else if (_9.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_116 = __this->____9_15;
		String_t* L_117;
		L_117 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_116);
		bool L_118;
		L_118 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_117, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_10 = L_118;
		bool L_119 = V_10;
		if (!L_119)
		{
			goto IL_038a;
		}
	}
	{
		// _9.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_120 = __this->____9_15;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_121 = __this->___textInput_6;
		String_t* L_122;
		L_122 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_121, NULL);
		String_t* L_123;
		L_123 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_122);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_120, L_123);
		goto IL_0a6f;
	}

IL_038a:
	{
		// else if (_10.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_124 = __this->____10_16;
		String_t* L_125;
		L_125 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_124);
		bool L_126;
		L_126 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_125, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_11 = L_126;
		bool L_127 = V_11;
		if (!L_127)
		{
			goto IL_0404;
		}
	}
	{
		// _10.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_128 = __this->____10_16;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_129 = __this->___textInput_6;
		String_t* L_130;
		L_130 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_129, NULL);
		String_t* L_131;
		L_131 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_130);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_128, L_131);
		// R5.text = Math.Round(float.Parse(_9.text) / float.Parse(_10.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_132 = __this->___R5_36;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_133 = __this->____9_15;
		String_t* L_134;
		L_134 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_133);
		float L_135;
		L_135 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_134, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_136 = __this->____10_16;
		String_t* L_137;
		L_137 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_136);
		float L_138;
		L_138 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_137, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_139;
		L_139 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_135/L_138))), 2, NULL);
		V_3 = L_139;
		String_t* L_140;
		L_140 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_132, L_140);
		goto IL_0a6f;
	}

IL_0404:
	{
		// else if (_11.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_141 = __this->____11_17;
		String_t* L_142;
		L_142 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_141);
		bool L_143;
		L_143 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_142, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_12 = L_143;
		bool L_144 = V_12;
		if (!L_144)
		{
			goto IL_0442;
		}
	}
	{
		// _11.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_145 = __this->____11_17;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_146 = __this->___textInput_6;
		String_t* L_147;
		L_147 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_146, NULL);
		String_t* L_148;
		L_148 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_147);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_145, L_148);
		goto IL_0a6f;
	}

IL_0442:
	{
		// else if (_12.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_149 = __this->____12_18;
		String_t* L_150;
		L_150 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_149);
		bool L_151;
		L_151 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_150, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_13 = L_151;
		bool L_152 = V_13;
		if (!L_152)
		{
			goto IL_0511;
		}
	}
	{
		// _12.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_153 = __this->____12_18;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_154 = __this->___textInput_6;
		String_t* L_155;
		L_155 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_154, NULL);
		String_t* L_156;
		L_156 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_155);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_153, L_156);
		// R6.text = Math.Round(float.Parse(_11.text) / float.Parse(_12.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_157 = __this->___R6_37;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_158 = __this->____11_17;
		String_t* L_159;
		L_159 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_158);
		float L_160;
		L_160 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_159, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_161 = __this->____12_18;
		String_t* L_162;
		L_162 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_161);
		float L_163;
		L_163 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_162, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_164;
		L_164 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_160/L_163))), 2, NULL);
		V_3 = L_164;
		String_t* L_165;
		L_165 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_157, L_165);
		// R2Result.text = Math.Round((float.Parse(R4.text) + float.Parse(R5.text) + float.Parse(R6.text)) / 3).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_166 = __this->___R2Result_38;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_167 = __this->___R4_35;
		String_t* L_168;
		L_168 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_167);
		float L_169;
		L_169 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_168, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_170 = __this->___R5_36;
		String_t* L_171;
		L_171 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_170);
		float L_172;
		L_172 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_171, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_173 = __this->___R6_37;
		String_t* L_174;
		L_174 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_173);
		float L_175;
		L_175 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_174, NULL);
		double L_176;
		L_176 = bankers_round(((double)((float)(((float)il2cpp_codegen_add(((float)il2cpp_codegen_add(L_169, L_172)), L_175))/(3.0f)))));
		V_3 = L_176;
		String_t* L_177;
		L_177 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_166, L_177);
		goto IL_0a6f;
	}

IL_0511:
	{
		// else if (_13.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_178 = __this->____13_19;
		String_t* L_179;
		L_179 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_178);
		bool L_180;
		L_180 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_179, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_14 = L_180;
		bool L_181 = V_14;
		if (!L_181)
		{
			goto IL_054f;
		}
	}
	{
		// _13.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_182 = __this->____13_19;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_183 = __this->___textInput_6;
		String_t* L_184;
		L_184 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_183, NULL);
		String_t* L_185;
		L_185 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_184);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_182, L_185);
		goto IL_0a6f;
	}

IL_054f:
	{
		// else if (_14.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_186 = __this->____14_20;
		String_t* L_187;
		L_187 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_186);
		bool L_188;
		L_188 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_187, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_15 = L_188;
		bool L_189 = V_15;
		if (!L_189)
		{
			goto IL_05c9;
		}
	}
	{
		// _14.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_190 = __this->____14_20;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_191 = __this->___textInput_6;
		String_t* L_192;
		L_192 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_191, NULL);
		String_t* L_193;
		L_193 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_192);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_190, L_193);
		// Z1.text = Math.Round(float.Parse(_13.text) / float.Parse(_14.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_194 = __this->___Z1_39;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_195 = __this->____13_19;
		String_t* L_196;
		L_196 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_195);
		float L_197;
		L_197 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_196, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_198 = __this->____14_20;
		String_t* L_199;
		L_199 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_198);
		float L_200;
		L_200 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_199, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_201;
		L_201 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_197/L_200))), 2, NULL);
		V_3 = L_201;
		String_t* L_202;
		L_202 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_194, L_202);
		goto IL_0a6f;
	}

IL_05c9:
	{
		// else if (_15.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_203 = __this->____15_21;
		String_t* L_204;
		L_204 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_203);
		bool L_205;
		L_205 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_204, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_16 = L_205;
		bool L_206 = V_16;
		if (!L_206)
		{
			goto IL_0607;
		}
	}
	{
		// _15.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_207 = __this->____15_21;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_208 = __this->___textInput_6;
		String_t* L_209;
		L_209 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_208, NULL);
		String_t* L_210;
		L_210 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_209);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_207, L_210);
		goto IL_0a6f;
	}

IL_0607:
	{
		// else if (_16.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_211 = __this->____16_22;
		String_t* L_212;
		L_212 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_211);
		bool L_213;
		L_213 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_212, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_17 = L_213;
		bool L_214 = V_17;
		if (!L_214)
		{
			goto IL_0681;
		}
	}
	{
		// _16.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_215 = __this->____16_22;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_216 = __this->___textInput_6;
		String_t* L_217;
		L_217 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_216, NULL);
		String_t* L_218;
		L_218 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_217);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_215, L_218);
		// Z2.text = Math.Round(float.Parse(_15.text) / float.Parse(_16.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_219 = __this->___Z2_40;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_220 = __this->____15_21;
		String_t* L_221;
		L_221 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_220);
		float L_222;
		L_222 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_221, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_223 = __this->____16_22;
		String_t* L_224;
		L_224 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_223);
		float L_225;
		L_225 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_224, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_226;
		L_226 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_222/L_225))), 2, NULL);
		V_3 = L_226;
		String_t* L_227;
		L_227 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_219, L_227);
		goto IL_0a6f;
	}

IL_0681:
	{
		// else if (_17.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_228 = __this->____17_23;
		String_t* L_229;
		L_229 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_228);
		bool L_230;
		L_230 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_229, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_18 = L_230;
		bool L_231 = V_18;
		if (!L_231)
		{
			goto IL_06bf;
		}
	}
	{
		// _17.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_232 = __this->____17_23;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_233 = __this->___textInput_6;
		String_t* L_234;
		L_234 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_233, NULL);
		String_t* L_235;
		L_235 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_234);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_232, L_235);
		goto IL_0a6f;
	}

IL_06bf:
	{
		// else if (_18.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_236 = __this->____18_24;
		String_t* L_237;
		L_237 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_236);
		bool L_238;
		L_238 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_237, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_19 = L_238;
		bool L_239 = V_19;
		if (!L_239)
		{
			goto IL_07c2;
		}
	}
	{
		// _18.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_240 = __this->____18_24;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_241 = __this->___textInput_6;
		String_t* L_242;
		L_242 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_241, NULL);
		String_t* L_243;
		L_243 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_242);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_240, L_243);
		// Z3.text = Math.Round(float.Parse(_17.text) / float.Parse(_18.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_244 = __this->___Z3_41;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_245 = __this->____17_23;
		String_t* L_246;
		L_246 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_245);
		float L_247;
		L_247 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_246, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_248 = __this->____18_24;
		String_t* L_249;
		L_249 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_248);
		float L_250;
		L_250 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_249, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_251;
		L_251 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_247/L_250))), 2, NULL);
		V_3 = L_251;
		String_t* L_252;
		L_252 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_244, L_252);
		// Z1Result.text = Math.Round((float.Parse(Z1.text) + float.Parse(Z2.text) + float.Parse(Z3.text)) / 3).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_253 = __this->___Z1Result_42;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_254 = __this->___Z1_39;
		String_t* L_255;
		L_255 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_254);
		float L_256;
		L_256 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_255, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_257 = __this->___Z2_40;
		String_t* L_258;
		L_258 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_257);
		float L_259;
		L_259 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_258, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_260 = __this->___Z3_41;
		String_t* L_261;
		L_261 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_260);
		float L_262;
		L_262 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_261, NULL);
		double L_263;
		L_263 = bankers_round(((double)((float)(((float)il2cpp_codegen_add(((float)il2cpp_codegen_add(L_256, L_259)), L_262))/(3.0f)))));
		V_3 = L_263;
		String_t* L_264;
		L_264 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_253, L_264);
		// L1Result.text = Math.Round((float.Parse(Z1Result.text) / (2 * 3.14))).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_265 = __this->___L1Result_47;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_266 = __this->___Z1Result_42;
		String_t* L_267;
		L_267 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_266);
		float L_268;
		L_268 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_267, NULL);
		double L_269;
		L_269 = bankers_round(((double)(((double)L_268)/(6.2800000000000002))));
		V_3 = L_269;
		String_t* L_270;
		L_270 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_265, L_270);
		goto IL_0a6f;
	}

IL_07c2:
	{
		// else if (_19.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_271 = __this->____19_25;
		String_t* L_272;
		L_272 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_271);
		bool L_273;
		L_273 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_272, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_20 = L_273;
		bool L_274 = V_20;
		if (!L_274)
		{
			goto IL_0800;
		}
	}
	{
		// _19.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_275 = __this->____19_25;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_276 = __this->___textInput_6;
		String_t* L_277;
		L_277 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_276, NULL);
		String_t* L_278;
		L_278 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_277);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_275, L_278);
		goto IL_0a6f;
	}

IL_0800:
	{
		// else if (_20.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_279 = __this->____20_26;
		String_t* L_280;
		L_280 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_279);
		bool L_281;
		L_281 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_280, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_21 = L_281;
		bool L_282 = V_21;
		if (!L_282)
		{
			goto IL_087a;
		}
	}
	{
		// _20.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_283 = __this->____20_26;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_284 = __this->___textInput_6;
		String_t* L_285;
		L_285 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_284, NULL);
		String_t* L_286;
		L_286 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_285);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_283, L_286);
		// Z4.text = Math.Round(float.Parse(_19.text) / float.Parse(_20.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_287 = __this->___Z4_43;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_288 = __this->____19_25;
		String_t* L_289;
		L_289 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_288);
		float L_290;
		L_290 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_289, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_291 = __this->____20_26;
		String_t* L_292;
		L_292 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_291);
		float L_293;
		L_293 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_292, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_294;
		L_294 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_290/L_293))), 2, NULL);
		V_3 = L_294;
		String_t* L_295;
		L_295 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_287, L_295);
		goto IL_0a6f;
	}

IL_087a:
	{
		// else if (_21.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_296 = __this->____21_27;
		String_t* L_297;
		L_297 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_296);
		bool L_298;
		L_298 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_297, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_22 = L_298;
		bool L_299 = V_22;
		if (!L_299)
		{
			goto IL_08b8;
		}
	}
	{
		// _21.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_300 = __this->____21_27;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_301 = __this->___textInput_6;
		String_t* L_302;
		L_302 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_301, NULL);
		String_t* L_303;
		L_303 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_302);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_300, L_303);
		goto IL_0a6f;
	}

IL_08b8:
	{
		// else if (_22.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_304 = __this->____22_28;
		String_t* L_305;
		L_305 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_304);
		bool L_306;
		L_306 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_305, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_23 = L_306;
		bool L_307 = V_23;
		if (!L_307)
		{
			goto IL_0932;
		}
	}
	{
		// _22.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_308 = __this->____22_28;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_309 = __this->___textInput_6;
		String_t* L_310;
		L_310 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_309, NULL);
		String_t* L_311;
		L_311 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_310);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_308, L_311);
		// Z5.text = Math.Round(float.Parse(_21.text) / float.Parse(_22.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_312 = __this->___Z5_44;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_313 = __this->____21_27;
		String_t* L_314;
		L_314 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_313);
		float L_315;
		L_315 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_314, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_316 = __this->____22_28;
		String_t* L_317;
		L_317 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_316);
		float L_318;
		L_318 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_317, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_319;
		L_319 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_315/L_318))), 2, NULL);
		V_3 = L_319;
		String_t* L_320;
		L_320 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_312, L_320);
		goto IL_0a6f;
	}

IL_0932:
	{
		// else if (_23.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_321 = __this->____23_29;
		String_t* L_322;
		L_322 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_321);
		bool L_323;
		L_323 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_322, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_24 = L_323;
		bool L_324 = V_24;
		if (!L_324)
		{
			goto IL_0970;
		}
	}
	{
		// _23.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_325 = __this->____23_29;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_326 = __this->___textInput_6;
		String_t* L_327;
		L_327 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_326, NULL);
		String_t* L_328;
		L_328 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_327);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_325, L_328);
		goto IL_0a6f;
	}

IL_0970:
	{
		// else if (_24.text == "-")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_329 = __this->____24_30;
		String_t* L_330;
		L_330 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_329);
		bool L_331;
		L_331 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_330, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0, NULL);
		V_25 = L_331;
		bool L_332 = V_25;
		if (!L_332)
		{
			goto IL_0a6f;
		}
	}
	{
		// _24.text = textInput.text.ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_333 = __this->____24_30;
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_334 = __this->___textInput_6;
		String_t* L_335;
		L_335 = InputField_get_text_m6E0796350FF559505E4DF17311803962699D6704(L_334, NULL);
		String_t* L_336;
		L_336 = VirtualFuncInvoker0< String_t* >::Invoke(3 /* System.String System.Object::ToString() */, L_335);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_333, L_336);
		// Z6.text = Math.Round(float.Parse(_23.text) / float.Parse(_24.text), 2).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_337 = __this->___Z6_45;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_338 = __this->____23_29;
		String_t* L_339;
		L_339 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_338);
		float L_340;
		L_340 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_339, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_341 = __this->____24_30;
		String_t* L_342;
		L_342 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_341);
		float L_343;
		L_343 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_342, NULL);
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_344;
		L_344 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)((float)(L_340/L_343))), 2, NULL);
		V_3 = L_344;
		String_t* L_345;
		L_345 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_337, L_345);
		// Z2Result.text = Math.Round((float.Parse(Z4.text) + float.Parse(Z5.text) + float.Parse(Z6.text)) / 3).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_346 = __this->___Z2Result_46;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_347 = __this->___Z4_43;
		String_t* L_348;
		L_348 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_347);
		float L_349;
		L_349 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_348, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_350 = __this->___Z5_44;
		String_t* L_351;
		L_351 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_350);
		float L_352;
		L_352 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_351, NULL);
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_353 = __this->___Z6_45;
		String_t* L_354;
		L_354 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_353);
		float L_355;
		L_355 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_354, NULL);
		double L_356;
		L_356 = bankers_round(((double)((float)(((float)il2cpp_codegen_add(((float)il2cpp_codegen_add(L_349, L_352)), L_355))/(3.0f)))));
		V_3 = L_356;
		String_t* L_357;
		L_357 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_346, L_357);
		// L2Result.text = Math.Round((float.Parse(Z2Result.text) / (2 * 3.14 )),6).ToString();
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_358 = __this->___L2Result_48;
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_359 = __this->___Z2Result_46;
		String_t* L_360;
		L_360 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_359);
		float L_361;
		L_361 = Single_Parse_m621F610BB84997A2E3C4686913F482316CD3E6B8(L_360, NULL);
		double L_362;
		L_362 = Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline(((double)(((double)L_361)/(6.2800000000000002))), 6, NULL);
		V_3 = L_362;
		String_t* L_363;
		L_363 = Double_ToString_m7499A5D792419537DCB9470A3675CEF5117DE339((&V_3), NULL);
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_358, L_363);
	}

IL_0a6f:
	{
		// textInput.text = "";
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_364 = __this->___textInput_6;
		InputField_set_text_m28B1C806BBCAC44F3ACCDC3B550509CA0C7D257F(L_364, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, NULL);
	}

IL_0a80:
	{
		// }
		return;
	}
}
// System.Void OutputInfo::Clean()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OutputInfo_Clean_mB201BB083ACBC0F9D04A41EA5049A57932DDEC6F (OutputInfo_tAC08BE0EC12F767A093907FF0347268ABA8E6BBB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709);
		s_Il2CppMethodInitialized = true;
	}
	{
		// _1.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->____1_7;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _2.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_1 = __this->____2_8;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_1, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _3.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_2 = __this->____3_9;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_2, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _4.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_3 = __this->____4_10;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_3, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _5.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_4 = __this->____5_11;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_4, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _6.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_5 = __this->____6_12;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_5, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _7.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_6 = __this->____7_13;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_6, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _8.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_7 = __this->____8_14;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_7, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _9.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_8 = __this->____9_15;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_8, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _10.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_9 = __this->____10_16;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_9, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _11.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_10 = __this->____11_17;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_10, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _12.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_11 = __this->____12_18;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_11, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _13.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_12 = __this->____13_19;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_12, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _14.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_13 = __this->____14_20;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_13, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _15.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_14 = __this->____15_21;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_14, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _16.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_15 = __this->____16_22;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_15, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _17.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_16 = __this->____17_23;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_16, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _18.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_17 = __this->____18_24;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_17, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _19.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_18 = __this->____19_25;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_18, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _20.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_19 = __this->____20_26;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_19, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _21.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_20 = __this->____21_27;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_20, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _22.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_21 = __this->____22_28;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_21, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _23.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_22 = __this->____23_29;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_22, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// _24.text = "-";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_23 = __this->____24_30;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_23, _stringLiteral3B2C1C62D4D1C2A0C8A9AC42DB00D33C654F9AD0);
		// textInput.text = "";
		InputField_tABEA115F23FBD374EBE80D4FAC1D15BD6E37A140* L_24 = __this->___textInput_6;
		InputField_set_text_m28B1C806BBCAC44F3ACCDC3B550509CA0C7D257F(L_24, _stringLiteralDA39A3EE5E6B4B0D3255BFEF95601890AFD80709, NULL);
		// }
		return;
	}
}
// System.Void OutputInfo::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OutputInfo__ctor_mD7C89109806C9D140C0D64E4E18E257E20EDE084 (OutputInfo_tAC08BE0EC12F767A093907FF0347268ABA8E6BBB* __this, const RuntimeMethod* method) 
{
	{
		// public float l = 1.5f;
		__this->___l_4 = (1.5f);
		// public float s = 0.000000000155f;
		__this->___s_5 = (1.54999999E-10f);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void RotMouse::OnEnable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RotMouse_OnEnable_m9139D6C04E57068C6DD448E848D7950588D9384D (RotMouse_tB15C38E97A03A7782CB6BBC472FCA7E80721D844* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RotMouse_HandlePlayInstChanged_m08198C416FA37E07ACD3A36DD92FA32A32B8AE5F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// RunTest.OnPlayInstChanged += HandlePlayInstChanged;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_0 = (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*)il2cpp_codegen_object_new(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91_il2cpp_TypeInfo_var);
		PlayInstChanged__ctor_m9DBD9E676393AE119505B981B6015C0F8913612C(L_0, __this, (intptr_t)((void*)RotMouse_HandlePlayInstChanged_m08198C416FA37E07ACD3A36DD92FA32A32B8AE5F_RuntimeMethod_var), NULL);
		RunTest_add_OnPlayInstChanged_m357E7B4B9A256F93E8326F26F5F106EF02489719(L_0, NULL);
		// }
		return;
	}
}
// System.Void RotMouse::OnDisable()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RotMouse_OnDisable_m9FD5C4FE184E5A20F08C86276798500079E4C97D (RotMouse_tB15C38E97A03A7782CB6BBC472FCA7E80721D844* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RotMouse_HandlePlayInstChanged_m08198C416FA37E07ACD3A36DD92FA32A32B8AE5F_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// RunTest.OnPlayInstChanged -= HandlePlayInstChanged;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_0 = (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*)il2cpp_codegen_object_new(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91_il2cpp_TypeInfo_var);
		PlayInstChanged__ctor_m9DBD9E676393AE119505B981B6015C0F8913612C(L_0, __this, (intptr_t)((void*)RotMouse_HandlePlayInstChanged_m08198C416FA37E07ACD3A36DD92FA32A32B8AE5F_RuntimeMethod_var), NULL);
		RunTest_remove_OnPlayInstChanged_mE8E5B1AA4ED0FF64C9C6013FCFB987799824E2F3(L_0, NULL);
		// }
		return;
	}
}
// System.Void RotMouse::HandlePlayInstChanged(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RotMouse_HandlePlayInstChanged_m08198C416FA37E07ACD3A36DD92FA32A32B8AE5F (RotMouse_tB15C38E97A03A7782CB6BBC472FCA7E80721D844* __this, bool ___0_newValue, const RuntimeMethod* method) 
{
	{
		// Play = newValue;
		bool L_0 = ___0_newValue;
		__this->___Play_9 = L_0;
		// }
		return;
	}
}
// System.Void RotMouse::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RotMouse_Update_m61EF387541B227783A7B46D2076F891724148784 (RotMouse_tB15C38E97A03A7782CB6BBC472FCA7E80721D844* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 V_2;
	memset((&V_2), 0, sizeof(V_2));
	RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 V_3;
	memset((&V_3), 0, sizeof(V_3));
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_7;
	memset((&V_7), 0, sizeof(V_7));
	float V_8 = 0.0f;
	float V_9 = 0.0f;
	float V_10 = 0.0f;
	bool V_11 = false;
	int32_t G_B6_0 = 0;
	int32_t G_B14_0 = 0;
	{
		// if (!GlobalGonfig.isSocket) return;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0;
		L_0 = GlobalGonfig_get_isSocket_m57DAE1FBAE65E6AC8FADDED4F56EEEB136152844_inline(NULL);
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0012;
		}
	}
	{
		// if (!GlobalGonfig.isSocket) return;
		goto IL_01bb;
	}

IL_0012:
	{
		// if (Input.GetMouseButtonDown(0))
		bool L_2;
		L_2 = Input_GetMouseButtonDown_m8DFC792D15FFF15D311614D5CC6C5D055E5A1DE3(0, NULL);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0067;
		}
	}
	{
		// Ray ray = UnityEngine.Camera.main.ScreenPointToRay(Input.mousePosition);
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_4;
		L_4 = Camera_get_main_m52C992F18E05355ABB9EEB64A4BF2215E12762DF(NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_5;
		L_5 = Input_get_mousePosition_mFF21FBD2647DAE2A23BD4C45571CA95D05A0A42C(NULL);
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_6;
		L_6 = Camera_ScreenPointToRay_m2887B9A49880B7AB670C57D66B67D6A6689FE315(L_4, L_5, NULL);
		V_2 = L_6;
		// if (Physics.Raycast(ray, out hit) && hit.transform == transform)
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_7 = V_2;
		bool L_8;
		L_8 = Physics_Raycast_mCAC9F02A1AAB49E16B384EBC8318E2DF30F4B0E5(L_7, (&V_3), NULL);
		if (!L_8)
		{
			goto IL_004b;
		}
	}
	{
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_9;
		L_9 = RaycastHit_get_transform_m89DB7FCFC50E0213A37CBE089400064B8FA19155((&V_3), NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_10;
		L_10 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_11;
		L_11 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_9, L_10, NULL);
		G_B6_0 = ((int32_t)(L_11));
		goto IL_004c;
	}

IL_004b:
	{
		G_B6_0 = 0;
	}

IL_004c:
	{
		V_4 = (bool)G_B6_0;
		bool L_12 = V_4;
		if (!L_12)
		{
			goto IL_0066;
		}
	}
	{
		// isRotating = true;
		__this->___isRotating_4 = (bool)1;
		// previousMousePosition = Input.mousePosition;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_13;
		L_13 = Input_get_mousePosition_mFF21FBD2647DAE2A23BD4C45571CA95D05A0A42C(NULL);
		__this->___previousMousePosition_5 = L_13;
	}

IL_0066:
	{
	}

IL_0067:
	{
		// if (Input.GetMouseButtonUp(0))
		bool L_14;
		L_14 = Input_GetMouseButtonUp_mBE89CC9C69BBEA9A863819E77EA54411B0476ED6(0, NULL);
		V_5 = L_14;
		bool L_15 = V_5;
		if (!L_15)
		{
			goto IL_007c;
		}
	}
	{
		// isRotating = false;
		__this->___isRotating_4 = (bool)0;
	}

IL_007c:
	{
		// if (isRotating && Play)
		bool L_16 = __this->___isRotating_4;
		if (!L_16)
		{
			goto IL_008c;
		}
	}
	{
		bool L_17 = __this->___Play_9;
		G_B14_0 = ((int32_t)(L_17));
		goto IL_008d;
	}

IL_008c:
	{
		G_B14_0 = 0;
	}

IL_008d:
	{
		V_6 = (bool)G_B14_0;
		bool L_18 = V_6;
		if (!L_18)
		{
			goto IL_01bb;
		}
	}
	{
		// Vector3 currentMousePosition = Input.mousePosition;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_19;
		L_19 = Input_get_mousePosition_mFF21FBD2647DAE2A23BD4C45571CA95D05A0A42C(NULL);
		V_7 = L_19;
		// float deltaY = currentMousePosition.y - previousMousePosition.y;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_20 = V_7;
		float L_21 = L_20.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* L_22 = (&__this->___previousMousePosition_5);
		float L_23 = L_22->___y_3;
		V_8 = ((float)il2cpp_codegen_subtract(L_21, L_23));
		// transform.Translate(Vector3.up * deltaY * rotationSpeed * Time.deltaTime);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_24;
		L_24 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_25;
		L_25 = Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline(NULL);
		float L_26 = V_8;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_27;
		L_27 = Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline(L_25, L_26, NULL);
		float L_28 = __this->___rotationSpeed_6;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_29;
		L_29 = Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline(L_27, L_28, NULL);
		float L_30;
		L_30 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_31;
		L_31 = Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline(L_29, L_30, NULL);
		Transform_Translate_m018D015E89C8CB743C54A21B4A1C5202EBF6297A(L_24, L_31, NULL);
		// float newZ = Mathf.Clamp(transform.position.z, minZ, maxZ);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_32;
		L_32 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_33;
		L_33 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_32, NULL);
		float L_34 = L_33.___z_4;
		float L_35 = __this->___minZ_10;
		float L_36 = __this->___maxZ_11;
		float L_37;
		L_37 = Mathf_Clamp_mEB9AEA827D27D20FCC787F7375156AF46BB12BBF_inline(L_34, L_35, L_36, NULL);
		V_9 = L_37;
		// transform.position = new Vector3(transform.position.x, transform.position.y, newZ);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_38;
		L_38 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_39;
		L_39 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_40;
		L_40 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_39, NULL);
		float L_41 = L_40.___x_2;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_42;
		L_42 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_43;
		L_43 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_42, NULL);
		float L_44 = L_43.___y_3;
		float L_45 = V_9;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_46;
		memset((&L_46), 0, sizeof(L_46));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_46), L_41, L_44, L_45, /*hidden argument*/NULL);
		Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156(L_38, L_46, NULL);
		// previousMousePosition = currentMousePosition;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_47 = V_7;
		__this->___previousMousePosition_5 = L_47;
		// float res = deltaY * rotationSpeed;
		float L_48 = V_8;
		float L_49 = __this->___rotationSpeed_6;
		V_10 = ((float)il2cpp_codegen_multiply(L_48, L_49));
		// if (!GlobalGonfig.isHeart)
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_50;
		L_50 = GlobalGonfig_get_isHeart_m14A72AC416E63D6C1A5F8C371A85FE17667A0EF6_inline(NULL);
		V_11 = (bool)((((int32_t)L_50) == ((int32_t)0))? 1 : 0);
		bool L_51 = V_11;
		if (!L_51)
		{
			goto IL_0163;
		}
	}
	{
		// res *= 2f;
		float L_52 = V_10;
		V_10 = ((float)il2cpp_codegen_multiply(L_52, (2.0f)));
	}

IL_0163:
	{
		// Amp.transform.Rotate(-Vector3.right, res);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_53 = __this->___Amp_7;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_54;
		L_54 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_53, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_55;
		L_55 = Vector3_get_right_mFF573AFBBB2186E7AFA1BA7CA271A78DF67E4EA0_inline(NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_56;
		L_56 = Vector3_op_UnaryNegation_m5450829F333BD2A88AF9A592C4EE331661225915_inline(L_55, NULL);
		float L_57 = V_10;
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_54, L_56, L_57, NULL);
		// Volt.transform.Rotate(-Vector3.right, res);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_58 = __this->___Volt_8;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_59;
		L_59 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_58, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_60;
		L_60 = Vector3_get_right_mFF573AFBBB2186E7AFA1BA7CA271A78DF67E4EA0_inline(NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_61;
		L_61 = Vector3_op_UnaryNegation_m5450829F333BD2A88AF9A592C4EE331661225915_inline(L_60, NULL);
		float L_62 = V_10;
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_59, L_61, L_62, NULL);
		// digitValue += deltaY / 20;
		float L_63 = __this->___digitValue_13;
		float L_64 = V_8;
		__this->___digitValue_13 = ((float)il2cpp_codegen_add(L_63, ((float)(L_64/(20.0f)))));
		// previousMousePosition = currentMousePosition;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_65 = V_7;
		__this->___previousMousePosition_5 = L_65;
	}

IL_01bb:
	{
		// }
		return;
	}
}
// System.Void RotMouse::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RotMouse__ctor_m0566305F1CC3A768B192A30C424D55F7D164122A (RotMouse_tB15C38E97A03A7782CB6BBC472FCA7E80721D844* __this, const RuntimeMethod* method) 
{
	{
		// bool isRotating = false;
		__this->___isRotating_4 = (bool)0;
		// float rotationSpeed = 0.5f;
		__this->___rotationSpeed_6 = (0.5f);
		// float minZ = 902.458f;
		__this->___minZ_10 = (902.458008f);
		// float maxZ = 903.4f;
		__this->___maxZ_11 = (903.400024f);
		// float digitValue = 0;
		__this->___digitValue_13 = (0.0f);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void RotPir::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RotPir_Update_m90128FD37A9E84C69729A19AE5F5C7D9124DAC2E (RotPir_t568F2AB4F3F42493F526733A25173694B1D591AB* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0459945BB841C0193561201BBC1332C36EB10ADB);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 V_2;
	memset((&V_2), 0, sizeof(V_2));
	RaycastHit_t6F30BD0B38B56401CA833A1B87BD74F2ACD2F2B5 V_3;
	memset((&V_3), 0, sizeof(V_3));
	bool V_4 = false;
	bool V_5 = false;
	bool V_6 = false;
	bool V_7 = false;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_8;
	memset((&V_8), 0, sizeof(V_8));
	float V_9 = 0.0f;
	float V_10 = 0.0f;
	bool V_11 = false;
	int32_t G_B7_0 = 0;
	{
		// if (Input.GetMouseButtonDown(0))
		bool L_0;
		L_0 = Input_GetMouseButtonDown_m8DFC792D15FFF15D311614D5CC6C5D055E5A1DE3(0, NULL);
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0086;
		}
	}
	{
		// if (mainCamera != null)
		Camera_t9FA9D68A2946676AA0E9C404046C831F5535DB24* L_2 = __this->___mainCamera_7;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_3;
		L_3 = Object_op_Inequality_mD0BE578448EAA61948F25C32F8DD55AB1F778602(L_2, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		V_1 = L_3;
		bool L_4 = V_1;
		if (!L_4)
		{
			goto IL_0085;
		}
	}
	{
		// Ray ray = UnityEngine.Camera.main.ScreenPointToRay(Input.mousePosition);
		Camera_tA92CC927D7439999BC82DBEDC0AA45B470F9E184* L_5;
		L_5 = Camera_get_main_m52C992F18E05355ABB9EEB64A4BF2215E12762DF(NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6;
		L_6 = Input_get_mousePosition_mFF21FBD2647DAE2A23BD4C45571CA95D05A0A42C(NULL);
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_7;
		L_7 = Camera_ScreenPointToRay_m2887B9A49880B7AB670C57D66B67D6A6689FE315(L_5, L_6, NULL);
		V_2 = L_7;
		// if (Physics.Raycast(ray, 100))
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_8 = V_2;
		bool L_9;
		L_9 = Physics_Raycast_m7A0FEA813B93A82713C06D8466F0A21325743488(L_8, (100.0f), NULL);
		V_4 = L_9;
		bool L_10 = V_4;
		if (!L_10)
		{
			goto IL_004b;
		}
	}
	{
		// print("Hit something");
		MonoBehaviour_print_m9E6FF71C673B651F35DD418C293CFC50C46803B6(_stringLiteral0459945BB841C0193561201BBC1332C36EB10ADB, NULL);
	}

IL_004b:
	{
		// if (Physics.Raycast(ray, out hit) && hit.transform == transform)
		Ray_t2B1742D7958DC05BDC3EFC7461D3593E1430DC00 L_11 = V_2;
		bool L_12;
		L_12 = Physics_Raycast_mCAC9F02A1AAB49E16B384EBC8318E2DF30F4B0E5(L_11, (&V_3), NULL);
		if (!L_12)
		{
			goto IL_0069;
		}
	}
	{
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_13;
		L_13 = RaycastHit_get_transform_m89DB7FCFC50E0213A37CBE089400064B8FA19155((&V_3), NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_14;
		L_14 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_15;
		L_15 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_13, L_14, NULL);
		G_B7_0 = ((int32_t)(L_15));
		goto IL_006a;
	}

IL_0069:
	{
		G_B7_0 = 0;
	}

IL_006a:
	{
		V_5 = (bool)G_B7_0;
		bool L_16 = V_5;
		if (!L_16)
		{
			goto IL_0084;
		}
	}
	{
		// isRotating = true;
		__this->___isRotating_8 = (bool)1;
		// previousMousePosition = Input.mousePosition;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_17;
		L_17 = Input_get_mousePosition_mFF21FBD2647DAE2A23BD4C45571CA95D05A0A42C(NULL);
		__this->___previousMousePosition_9 = L_17;
	}

IL_0084:
	{
	}

IL_0085:
	{
	}

IL_0086:
	{
		// if (Input.GetMouseButtonUp(0))
		bool L_18;
		L_18 = Input_GetMouseButtonUp_mBE89CC9C69BBEA9A863819E77EA54411B0476ED6(0, NULL);
		V_6 = L_18;
		bool L_19 = V_6;
		if (!L_19)
		{
			goto IL_009b;
		}
	}
	{
		// isRotating = false;
		__this->___isRotating_8 = (bool)0;
	}

IL_009b:
	{
		// if (isRotating)
		bool L_20 = __this->___isRotating_8;
		V_7 = L_20;
		bool L_21 = V_7;
		if (!L_21)
		{
			goto IL_01b2;
		}
	}
	{
		// Vector3 currentMousePosition = Input.mousePosition;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_22;
		L_22 = Input_get_mousePosition_mFF21FBD2647DAE2A23BD4C45571CA95D05A0A42C(NULL);
		V_8 = L_22;
		// float deltaX = currentMousePosition.y - previousMousePosition.y;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_23 = V_8;
		float L_24 = L_23.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* L_25 = (&__this->___previousMousePosition_9);
		float L_26 = L_25->___y_3;
		V_9 = ((float)il2cpp_codegen_subtract(L_24, L_26));
		// float PirRotation = Pir.transform.eulerAngles.x;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_27 = __this->___Pir_6;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_28;
		L_28 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_27, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_29;
		L_29 = Transform_get_eulerAngles_mCAAF48EFCF628F1ED91C2FFE75A4FD19C039DD6A(L_28, NULL);
		float L_30 = L_29.___x_2;
		V_10 = L_30;
		// if (PirRotation > 333)
		float L_31 = V_10;
		V_11 = (bool)((((float)L_31) > ((float)(333.0f)))? 1 : 0);
		bool L_32 = V_11;
		if (!L_32)
		{
			goto IL_00f6;
		}
	}
	{
		// PirRotation = 333;
		V_10 = (333.0f);
	}

IL_00f6:
	{
		// transform.Rotate(-Vector3.forward, deltaX * rotationSpeed);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_33;
		L_33 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_34;
		L_34 = Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline(NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_35;
		L_35 = Vector3_op_UnaryNegation_m5450829F333BD2A88AF9A592C4EE331661225915_inline(L_34, NULL);
		float L_36 = V_9;
		float L_37 = __this->___rotationSpeed_4;
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_33, L_35, ((float)il2cpp_codegen_multiply(L_36, L_37)), NULL);
		// Pir.transform.eulerAngles = new Vector3(PirRotation, Pir.transform.eulerAngles.y, Pir.transform.eulerAngles.z);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_38 = __this->___Pir_6;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_39;
		L_39 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_38, NULL);
		float L_40 = V_10;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_41 = __this->___Pir_6;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_42;
		L_42 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_41, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_43;
		L_43 = Transform_get_eulerAngles_mCAAF48EFCF628F1ED91C2FFE75A4FD19C039DD6A(L_42, NULL);
		float L_44 = L_43.___y_3;
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_45 = __this->___Pir_6;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_46;
		L_46 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_45, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_47;
		L_47 = Transform_get_eulerAngles_mCAAF48EFCF628F1ED91C2FFE75A4FD19C039DD6A(L_46, NULL);
		float L_48 = L_47.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_49;
		memset((&L_49), 0, sizeof(L_49));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_49), L_40, L_44, L_48, /*hidden argument*/NULL);
		Transform_set_eulerAngles_m9F0BC484A7915A51FAB87230644229B75BACA004(L_39, L_49, NULL);
		// Pir.transform.Rotate(Vector3.right, deltaX * rotationSpeed);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_50 = __this->___Pir_6;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_51;
		L_51 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_50, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_52;
		L_52 = Vector3_get_right_mFF573AFBBB2186E7AFA1BA7CA271A78DF67E4EA0_inline(NULL);
		float L_53 = V_9;
		float L_54 = __this->___rotationSpeed_4;
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_51, L_52, ((float)il2cpp_codegen_multiply(L_53, L_54)), NULL);
		// Line.transform.position += new Vector3(0, 0, deltaX / 1500);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_55 = __this->___Line_5;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_56;
		L_56 = GameObject_get_transform_m0BC10ADFA1632166AE5544BDF9038A2650C2AE56(L_55, NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_57 = L_56;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_58;
		L_58 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_57, NULL);
		float L_59 = V_9;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_60;
		memset((&L_60), 0, sizeof(L_60));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_60), (0.0f), (0.0f), ((float)(L_59/(1500.0f))), /*hidden argument*/NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_61;
		L_61 = Vector3_op_Addition_m78C0EC70CB66E8DCAC225743D82B268DAEE92067_inline(L_58, L_60, NULL);
		Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156(L_57, L_61, NULL);
		// previousMousePosition = currentMousePosition;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_62 = V_8;
		__this->___previousMousePosition_9 = L_62;
	}

IL_01b2:
	{
		// }
		return;
	}
}
// System.Void RotPir::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RotPir__ctor_mF1E97200CDDA440ED85F7BEF7E0080933202AA1D (RotPir_t568F2AB4F3F42493F526733A25173694B1D591AB* __this, const RuntimeMethod* method) 
{
	{
		// private float rotationSpeed = 0.5f;
		__this->___rotationSpeed_4 = (0.5f);
		// bool isRotating = false;
		__this->___isRotating_8 = (bool)0;
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void RunTest::add_OnPlayInstChanged(RunTest/PlayInstChanged)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RunTest_add_OnPlayInstChanged_m357E7B4B9A256F93E8326F26F5F106EF02489719 (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* V_0 = NULL;
	PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* V_1 = NULL;
	PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* V_2 = NULL;
	{
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_0 = ((RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_StaticFields*)il2cpp_codegen_static_fields_for(RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_il2cpp_TypeInfo_var))->___OnPlayInstChanged_5;
		V_0 = L_0;
	}

IL_0006:
	{
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_1 = V_0;
		V_1 = L_1;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_2 = V_1;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m1F725AEF318BE6F0426863490691A6F4606E7D00(L_2, L_3, NULL);
		V_2 = ((PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*)CastclassSealed((RuntimeObject*)L_4, PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91_il2cpp_TypeInfo_var));
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_5 = V_2;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_6 = V_1;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_7;
		L_7 = InterlockedCompareExchangeImpl<PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*>((&((RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_StaticFields*)il2cpp_codegen_static_fields_for(RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_il2cpp_TypeInfo_var))->___OnPlayInstChanged_5), L_5, L_6);
		V_0 = L_7;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_8 = V_0;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_9 = V_1;
		if ((!(((RuntimeObject*)(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*)L_8) == ((RuntimeObject*)(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*)L_9))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}
}
// System.Void RunTest::remove_OnPlayInstChanged(RunTest/PlayInstChanged)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RunTest_remove_OnPlayInstChanged_mE8E5B1AA4ED0FF64C9C6013FCFB987799824E2F3 (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* V_0 = NULL;
	PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* V_1 = NULL;
	PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* V_2 = NULL;
	{
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_0 = ((RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_StaticFields*)il2cpp_codegen_static_fields_for(RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_il2cpp_TypeInfo_var))->___OnPlayInstChanged_5;
		V_0 = L_0;
	}

IL_0006:
	{
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_1 = V_0;
		V_1 = L_1;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_2 = V_1;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_3 = ___0_value;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m8B7DD5661308FA972E23CA1CC3FC9CEB355504E3(L_2, L_3, NULL);
		V_2 = ((PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*)CastclassSealed((RuntimeObject*)L_4, PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91_il2cpp_TypeInfo_var));
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_5 = V_2;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_6 = V_1;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_7;
		L_7 = InterlockedCompareExchangeImpl<PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*>((&((RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_StaticFields*)il2cpp_codegen_static_fields_for(RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_il2cpp_TypeInfo_var))->___OnPlayInstChanged_5), L_5, L_6);
		V_0 = L_7;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_8 = V_0;
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_9 = V_1;
		if ((!(((RuntimeObject*)(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*)L_8) == ((RuntimeObject*)(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*)L_9))))
		{
			goto IL_0006;
		}
	}
	{
		return;
	}
}
// System.Void RunTest::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RunTest_Start_m1C573A8E7AED1B4A2E2EE836FCBDBEE977F61BE6 (RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// anim = GetComponent<Animator>();
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_0;
		L_0 = Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE(__this, Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		__this->___anim_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___anim_4), (void*)L_0);
		// }
		return;
	}
}
// System.Void RunTest::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RunTest_Update_mA7489CF116C560F2B4F9624CD59B4DD6CC5167BB (RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9F24FB9F6B79BD601755A6710686857F7B86347B);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	{
		// if (Input.GetKeyDown(KeyCode.C))
		bool L_0;
		L_0 = Input_GetKeyDown_mB237DEA6244132670D38990BAB77D813FBB028D2(((int32_t)99), NULL);
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_003a;
		}
	}
	{
		// GlobalGonfig.isSocket = true;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		GlobalGonfig_set_isSocket_m89642441CD2C0F5112EA12496F732EA889B224CC_inline((bool)1, NULL);
		// GlobalGonfig.Step = 1;
		GlobalGonfig_set_Step_m07F0DC514B18F632AA191958E08758F26EB1192A_inline(1, NULL);
		// anim.SetBool("run",true);
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_2 = __this->___anim_4;
		Animator_SetBool_m6F8D4FAF0770CD4EC1F54406249785DE7391E42B(L_2, _stringLiteral9F24FB9F6B79BD601755A6710686857F7B86347B, (bool)1, NULL);
		// OnPlayInstChanged(true);
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_3 = ((RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_StaticFields*)il2cpp_codegen_static_fields_for(RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_il2cpp_TypeInfo_var))->___OnPlayInstChanged_5;
		PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_inline(L_3, (bool)1, NULL);
	}

IL_003a:
	{
		// if (Input.GetKeyDown(KeyCode.O))
		bool L_4;
		L_4 = Input_GetKeyDown_mB237DEA6244132670D38990BAB77D813FBB028D2(((int32_t)111), NULL);
		V_1 = L_4;
		bool L_5 = V_1;
		if (!L_5)
		{
			goto IL_0073;
		}
	}
	{
		// GlobalGonfig.Step = 0;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		GlobalGonfig_set_Step_m07F0DC514B18F632AA191958E08758F26EB1192A_inline(0, NULL);
		// GlobalGonfig.isSocket = false ;
		GlobalGonfig_set_isSocket_m89642441CD2C0F5112EA12496F732EA889B224CC_inline((bool)0, NULL);
		// anim.SetBool("run", false);
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_6 = __this->___anim_4;
		Animator_SetBool_m6F8D4FAF0770CD4EC1F54406249785DE7391E42B(L_6, _stringLiteral9F24FB9F6B79BD601755A6710686857F7B86347B, (bool)0, NULL);
		// OnPlayInstChanged(false);
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* L_7 = ((RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_StaticFields*)il2cpp_codegen_static_fields_for(RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A_il2cpp_TypeInfo_var))->___OnPlayInstChanged_5;
		PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_inline(L_7, (bool)0, NULL);
	}

IL_0073:
	{
		// }
		return;
	}
}
// System.Void RunTest::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void RunTest__ctor_m6884C567B74BB8F009616C528A7E217EB44FDBC6 (RunTest_tFDA69A34D77749F05B6E9E1F25FA3DEE19A7753A* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_Multicast(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, bool ___0_newValue, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* currentDelegate = reinterpret_cast<PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, bool, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_newValue, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_OpenInst(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, bool ___0_newValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (bool, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_newValue, method);
}
void PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_OpenStatic(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, bool ___0_newValue, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (bool, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_newValue, method);
}
void PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_OpenStaticInvoker(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, bool ___0_newValue, const RuntimeMethod* method)
{
	InvokerActionInvoker1< bool >::Invoke(__this->___method_ptr_0, method, NULL, ___0_newValue);
}
void PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_ClosedStaticInvoker(PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, bool ___0_newValue, const RuntimeMethod* method)
{
	InvokerActionInvoker2< RuntimeObject*, bool >::Invoke(__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_newValue);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91 (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, bool ___0_newValue, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)(int32_t);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Native function invocation
	il2cppPInvokeFunc(static_cast<int32_t>(___0_newValue));

}
// System.Void RunTest/PlayInstChanged::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayInstChanged__ctor_m9DBD9E676393AE119505B981B6015C0F8913612C (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 1;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = (intptr_t)__this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = (intptr_t)__this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_Multicast;
}
// System.Void RunTest/PlayInstChanged::Invoke(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32 (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, bool ___0_newValue, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, bool, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_newValue, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult RunTest/PlayInstChanged::BeginInvoke(System.Boolean,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* PlayInstChanged_BeginInvoke_mDC4042C37936A21079FBDFCB1E722F4625CAC9D7 (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, bool ___0_newValue, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___1_callback, RuntimeObject* ___2_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[2] = {0};
	__d_args[0] = Box(Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var, &___0_newValue);
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___1_callback, (RuntimeObject*)___2_object);
}
// System.Void RunTest/PlayInstChanged::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayInstChanged_EndInvoke_mE6738F3C76239C51BAB49E3C92935EFC7EF3A72C (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Script::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Script_Start_m26181EB142F9E9D13BB497FAEA9E42CFDC132438 (Script_t16820696475B1CE5329D1A278120D55D1EAB0117* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void Script::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Script_Update_m3D73B366324BC0BF8F060D1E0CB6B52EAEED1518 (Script_t16820696475B1CE5329D1A278120D55D1EAB0117* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7F8C014BD4810CC276D0F9F81A1E759C7B098B1E);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral88BEE283254D7094E258B3A88730F4CC4F1E4AC7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFC6687DC37346CD2569888E29764F727FAF530E0);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	float V_1 = 0.0f;
	bool V_2 = false;
	float V_3 = 0.0f;
	bool V_4 = false;
	bool V_5 = false;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_6;
	memset((&V_6), 0, sizeof(V_6));
	bool V_7 = false;
	bool V_8 = false;
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_9;
	memset((&V_9), 0, sizeof(V_9));
	bool V_10 = false;
	{
		// if (Input.GetMouseButton(1))
		bool L_0;
		L_0 = Input_GetMouseButton_m4995DD4A2D4F916565C1B1B5AAF7DF17C126B3EA(1, NULL);
		V_2 = L_0;
		bool L_1 = V_2;
		if (!L_1)
		{
			goto IL_0050;
		}
	}
	{
		// float y = Input.GetAxis("Mouse X") * sensitivity;
		float L_2;
		L_2 = Input_GetAxis_m10372E6C5FF591668D2DC5F58C58D213CC598A62(_stringLiteral88BEE283254D7094E258B3A88730F4CC4F1E4AC7, NULL);
		int32_t L_3 = __this->___sensitivity_5;
		V_3 = ((float)il2cpp_codegen_multiply(L_2, ((float)L_3)));
		// if (y != 0)
		float L_4 = V_3;
		V_4 = (bool)((((int32_t)((((float)L_4) == ((float)(0.0f)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_5 = V_4;
		if (!L_5)
		{
			goto IL_004f;
		}
	}
	{
		// transform.RotateAround(targetPos.position, Vector3.up, y);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_6;
		L_6 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_7 = __this->___targetPos_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8;
		L_8 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_7, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9;
		L_9 = Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline(NULL);
		float L_10 = V_3;
		Transform_RotateAround_m489C5BE8B8B15D0A5F4863DE6D23FF2CC8FA76C6(L_6, L_8, L_9, L_10, NULL);
	}

IL_004f:
	{
	}

IL_0050:
	{
		// float x = Input.GetAxis("Horizontal") / sensitivity; // ??????? A, D
		float L_11;
		L_11 = Input_GetAxis_m10372E6C5FF591668D2DC5F58C58D213CC598A62(_stringLiteral7F8C014BD4810CC276D0F9F81A1E759C7B098B1E, NULL);
		int32_t L_12 = __this->___sensitivity_5;
		V_0 = ((float)(L_11/((float)L_12)));
		// if (x != 0)
		float L_13 = V_0;
		V_5 = (bool)((((int32_t)((((float)L_13) == ((float)(0.0f)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_14 = V_5;
		if (!L_14)
		{
			goto IL_00d1;
		}
	}
	{
		// Vector3 newpos = transform.position + transform.TransformDirection(new Vector3(x, 0, 0));
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_15;
		L_15 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_16;
		L_16 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_15, NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_17;
		L_17 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		float L_18 = V_0;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_19;
		memset((&L_19), 0, sizeof(L_19));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_19), L_18, (0.0f), (0.0f), /*hidden argument*/NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_20;
		L_20 = Transform_TransformDirection_m9BE1261DF2D48B7A4A27D31EE24D2D97F89E7757(L_17, L_19, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_21;
		L_21 = Vector3_op_Addition_m78C0EC70CB66E8DCAC225743D82B268DAEE92067_inline(L_16, L_20, NULL);
		V_6 = L_21;
		// if (ControlDistance(Vector3.Distance(newpos, targetPos.position)))
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_22 = V_6;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_23 = __this->___targetPos_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_24;
		L_24 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_23, NULL);
		float L_25;
		L_25 = Vector3_Distance_m2314DB9B8BD01157E013DF87BEA557375C7F9FF9_inline(L_22, L_24, NULL);
		bool L_26;
		L_26 = Script_ControlDistance_m2DA061CADBB51303DF37021DD0DC0BBD27BFE62B(__this, L_25, NULL);
		V_7 = L_26;
		bool L_27 = V_7;
		if (!L_27)
		{
			goto IL_00d0;
		}
	}
	{
		// transform.position = newpos;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_28;
		L_28 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_29 = V_6;
		Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156(L_28, L_29, NULL);
	}

IL_00d0:
	{
	}

IL_00d1:
	{
		// float z = Input.GetAxis("Mouse ScrollWheel") * scrollSpeed;
		float L_30;
		L_30 = Input_GetAxis_m10372E6C5FF591668D2DC5F58C58D213CC598A62(_stringLiteralFC6687DC37346CD2569888E29764F727FAF530E0, NULL);
		float L_31 = __this->___scrollSpeed_6;
		V_1 = ((float)il2cpp_codegen_multiply(L_30, L_31));
		// if (z != 0)
		float L_32 = V_1;
		V_8 = (bool)((((int32_t)((((float)L_32) == ((float)(0.0f)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		bool L_33 = V_8;
		if (!L_33)
		{
			goto IL_014c;
		}
	}
	{
		// Vector3 newpos = transform.position + transform.TransformDirection(Vector3.forward * z);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_34;
		L_34 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_35;
		L_35 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_34, NULL);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_36;
		L_36 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_37;
		L_37 = Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline(NULL);
		float L_38 = V_1;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_39;
		L_39 = Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline(L_37, L_38, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_40;
		L_40 = Transform_TransformDirection_m9BE1261DF2D48B7A4A27D31EE24D2D97F89E7757(L_36, L_39, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_41;
		L_41 = Vector3_op_Addition_m78C0EC70CB66E8DCAC225743D82B268DAEE92067_inline(L_35, L_40, NULL);
		V_9 = L_41;
		// if (ControlDistance(Vector3.Distance(newpos, targetPos.position)))
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_42 = V_9;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_43 = __this->___targetPos_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_44;
		L_44 = Transform_get_position_m69CD5FA214FDAE7BB701552943674846C220FDE1(L_43, NULL);
		float L_45;
		L_45 = Vector3_Distance_m2314DB9B8BD01157E013DF87BEA557375C7F9FF9_inline(L_42, L_44, NULL);
		bool L_46;
		L_46 = Script_ControlDistance_m2DA061CADBB51303DF37021DD0DC0BBD27BFE62B(__this, L_45, NULL);
		V_10 = L_46;
		bool L_47 = V_10;
		if (!L_47)
		{
			goto IL_014b;
		}
	}
	{
		// transform.position = newpos;
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_48;
		L_48 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_49 = V_9;
		Transform_set_position_mA1A817124BB41B685043DED2A9BA48CDF37C4156(L_48, L_49, NULL);
	}

IL_014b:
	{
	}

IL_014c:
	{
		// }
		return;
	}
}
// System.Boolean Script::ControlDistance(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Script_ControlDistance_m2DA061CADBB51303DF37021DD0DC0BBD27BFE62B (Script_t16820696475B1CE5329D1A278120D55D1EAB0117* __this, float ___0_distance, const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	int32_t G_B3_0 = 0;
	{
		// if (distance > minDistance && distance < maxDistance) return true;
		float L_0 = ___0_distance;
		int32_t L_1 = __this->___minDistance_8;
		if ((!(((float)L_0) > ((float)((float)L_1)))))
		{
			goto IL_0017;
		}
	}
	{
		float L_2 = ___0_distance;
		int32_t L_3 = __this->___maxDistance_7;
		G_B3_0 = ((((float)L_2) < ((float)((float)L_3)))? 1 : 0);
		goto IL_0018;
	}

IL_0017:
	{
		G_B3_0 = 0;
	}

IL_0018:
	{
		V_0 = (bool)G_B3_0;
		bool L_4 = V_0;
		if (!L_4)
		{
			goto IL_0020;
		}
	}
	{
		// if (distance > minDistance && distance < maxDistance) return true;
		V_1 = (bool)1;
		goto IL_0024;
	}

IL_0020:
	{
		// return false;
		V_1 = (bool)0;
		goto IL_0024;
	}

IL_0024:
	{
		// }
		bool L_5 = V_1;
		return L_5;
	}
}
// System.Void Script::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Script__ctor_mC411C5D59BEB7BF2105E339FD817C5B1F8EB8451 (Script_t16820696475B1CE5329D1A278120D55D1EAB0117* __this, const RuntimeMethod* method) 
{
	{
		// int sensitivity = 3;
		__this->___sensitivity_5 = 3;
		// float scrollSpeed = 10f;
		__this->___scrollSpeed_6 = (10.0f);
		// int maxDistance = 20;
		__this->___maxDistance_7 = ((int32_t)20);
		// int minDistance = 1;
		__this->___minDistance_8 = 1;
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Trigger_Anim::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Trigger_Anim_Start_mB8E1BE4CD72F8C0BB07FECF25528AC79F0C7BCC6 (Trigger_Anim_tF3C781751DD09B03E8AC9509860F8F3FC1242BF6* __this, const RuntimeMethod* method) 
{
	{
		// }
		return;
	}
}
// System.Void Trigger_Anim::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Trigger_Anim_Update_m711105B5CEEB1C57FF69CC64CEE7D2A70B27B33E (Trigger_Anim_tF3C781751DD09B03E8AC9509860F8F3FC1242BF6* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral64B966C17214F45051BA3BBE40EFFF89A6C36424);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9CEB4D81FE1382FF120AEE05E403D6F7BCE690D2);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC71913A9C8423A634306B793FD996AD5C940C9E1);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	{
		// if (GlobalGonfig.Step == 1)
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		int32_t L_0;
		L_0 = GlobalGonfig_get_Step_m486B62F18526F24C79F59C02E034D73902EACD16_inline(NULL);
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)1))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0058;
		}
	}
	{
		// if (Input.GetMouseButtonDown(0))
		bool L_2;
		L_2 = Input_GetMouseButtonDown_m8DFC792D15FFF15D311614D5CC6C5D055E5A1DE3(0, NULL);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0057;
		}
	}
	{
		// if (message.text == "??? 1: ???????? ? ??????? ????? ??????? C. ????? ???????? ??????? ?? ????????? ???????")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_4 = __this->___message_4;
		String_t* L_5;
		L_5 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_4);
		bool L_6;
		L_6 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_5, _stringLiteral64B966C17214F45051BA3BBE40EFFF89A6C36424, NULL);
		V_2 = L_6;
		bool L_7 = V_2;
		if (!L_7)
		{
			goto IL_0056;
		}
	}
	{
		// message.text = "??? 2: ?????? ???????? ?? ???????? ????? ?? 1 ??, 2 ??, 3 ?? ? ?????? ???????? ?? ????????.????? ????? ????? ? ??????????? ??????? ????. ??????? ?? ?????? X";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_8 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_8, _stringLiteralC71913A9C8423A634306B793FD996AD5C940C9E1);
		// anim.SetTrigger("hit");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_9 = __this->___anim_5;
		Animator_SetTrigger_mC9CD54D627C8843EF6E159E167449D216EF6EB30(L_9, _stringLiteral9CEB4D81FE1382FF120AEE05E403D6F7BCE690D2, NULL);
	}

IL_0056:
	{
	}

IL_0057:
	{
	}

IL_0058:
	{
		// }
		return;
	}
}
// System.Void Trigger_Anim::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Trigger_Anim__ctor_m15ABA62DB719E8C2DA83FA9035C75D0FE19EDA8F (Trigger_Anim_tF3C781751DD09B03E8AC9509860F8F3FC1242BF6* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Tumbler::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Tumbler_Start_mE337DAC64DE9F513D705552097B68B6E8BB4B4E1 (Tumbler_t625725C532E9AF9C93E4B2B40A7A812C2E4DD6AC* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// anim = GetComponent<Animator>();
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_0;
		L_0 = Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE(__this, Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		__this->___anim_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___anim_4), (void*)L_0);
		// }
		return;
	}
}
// System.Void Tumbler::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Tumbler_Update_m81E41AA67C4E282B0BCB7553937B807738AFCE7D (Tumbler_t625725C532E9AF9C93E4B2B40A7A812C2E4DD6AC* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral0B0FD00CCE723A953C3ADBBAD1430C433014C703);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB2DD8390EDD462B3183E90D041F1BA75121138B5);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralBA69D7E125E0D005D67F802926FF010F322A4A25);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralC71913A9C8423A634306B793FD996AD5C940C9E1);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralDBAEBBE394D4B81FC4A2E94EA1078E305D3DCDF4);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	bool V_4 = false;
	{
		// if (!GlobalGonfig.isSocket) return;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0;
		L_0 = GlobalGonfig_get_isSocket_m57DAE1FBAE65E6AC8FADDED4F56EEEB136152844_inline(NULL);
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0012;
		}
	}
	{
		// if (!GlobalGonfig.isSocket) return;
		goto IL_00b2;
	}

IL_0012:
	{
		// if (Input.GetKeyDown(KeyCode.X))
		bool L_2;
		L_2 = Input_GetKeyDown_mB237DEA6244132670D38990BAB77D813FBB028D2(((int32_t)120), NULL);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_00b2;
		}
	}
	{
		// var prev = anim.GetBool("tumbler");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_4 = __this->___anim_4;
		bool L_5;
		L_5 = Animator_GetBool_mBC4D952885FF7504963E5923C29481A891028FD8(L_4, _stringLiteralDBAEBBE394D4B81FC4A2E94EA1078E305D3DCDF4, NULL);
		V_2 = L_5;
		// anim.SetBool("tumbler", !prev);
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_6 = __this->___anim_4;
		bool L_7 = V_2;
		Animator_SetBool_m6F8D4FAF0770CD4EC1F54406249785DE7391E42B(L_6, _stringLiteralDBAEBBE394D4B81FC4A2E94EA1078E305D3DCDF4, (bool)((((int32_t)L_7) == ((int32_t)0))? 1 : 0), NULL);
		// if (anim.GetBool("tumbler"))
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_8 = __this->___anim_4;
		bool L_9;
		L_9 = Animator_GetBool_mBC4D952885FF7504963E5923C29481A891028FD8(L_8, _stringLiteralDBAEBBE394D4B81FC4A2E94EA1078E305D3DCDF4, NULL);
		V_3 = L_9;
		bool L_10 = V_3;
		if (!L_10)
		{
			goto IL_009e;
		}
	}
	{
		// anim.Play("Tumbler1");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_11 = __this->___anim_4;
		Animator_Play_m0F6A9F84B2E256E644D56C34A7A9BD622CB00FF9(L_11, _stringLiteralB2DD8390EDD462B3183E90D041F1BA75121138B5, NULL);
		// if (message.text == "??? 2: ?????? ???????? ?? ???????? ????? ?? 1 ??, 2 ??, 3 ?? ? ?????? ???????? ?? ????????.????? ????? ????? ? ??????????? ??????? ????. ??????? ?? ?????? X")
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_12 = __this->___message_5;
		String_t* L_13;
		L_13 = VirtualFuncInvoker0< String_t* >::Invoke(74 /* System.String UnityEngine.UI.Text::get_text() */, L_12);
		bool L_14;
		L_14 = String_op_Equality_m030E1B219352228970A076136E455C4E568C02C1(L_13, _stringLiteralC71913A9C8423A634306B793FD996AD5C940C9E1, NULL);
		V_4 = L_14;
		bool L_15 = V_4;
		if (!L_15)
		{
			goto IL_009b;
		}
	}
	{
		// message.text = "??? 3: ?????? ???????? ?? ???????? ????? ?? 1 ??, 2 ??, 3 ?? ? ?????? ???????? ?? ????????.????? ????? ????? ??? ??????? ?????? ? ?????????? ?????. ??? ????, ????? ???????? ?????????? ??? ????? ?????? ?? ?????? P";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_16 = __this->___message_5;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_16, _stringLiteral0B0FD00CCE723A953C3ADBBAD1430C433014C703);
	}

IL_009b:
	{
		goto IL_00b1;
	}

IL_009e:
	{
		// anim.Play("Tumbler1Back");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_17 = __this->___anim_4;
		Animator_Play_m0F6A9F84B2E256E644D56C34A7A9BD622CB00FF9(L_17, _stringLiteralBA69D7E125E0D005D67F802926FF010F322A4A25, NULL);
	}

IL_00b1:
	{
	}

IL_00b2:
	{
		// }
		return;
	}
}
// System.Void Tumbler::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Tumbler__ctor_m5F5A421646B67F2007ED2CE602C0C2D81F030D09 (Tumbler_t625725C532E9AF9C93E4B2B40A7A812C2E4DD6AC* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Tumbler1::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Tumbler1_Start_m68100332393F7FE9FC75E02E01383FE9AE8F4B0D (Tumbler1_t5F8D47869C2459B4D767E01867D9865281754ACC* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// anim = GetComponent<Animator>();
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_0;
		L_0 = Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE(__this, Component_GetComponent_TisAnimator_t8A52E42AE54F76681838FE9E632683EF3952E883_m1C9FCB4BBE56BEC6BDEF6E4BA1E5DFF91614D7CE_RuntimeMethod_var);
		__this->___anim_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___anim_4), (void*)L_0);
		// }
		return;
	}
}
// System.Void Tumbler1::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Tumbler1_Update_m331AC89957EE4F39BAAB09EC0788E9F1BF273E80 (Tumbler1_t5F8D47869C2459B4D767E01867D9865281754ACC* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral22BCB08134DF4129F83330A14F3760EEE62D8858);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4CCB470730A3A7B6552F44D8F3BD5316F1655B9B);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB889CCEBAD3C5A0EA57CBF1E1EC93237C8BAD9B6);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	bool V_2 = false;
	bool V_3 = false;
	{
		// if (!GlobalGonfig.isSocket) return;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0;
		L_0 = GlobalGonfig_get_isSocket_m57DAE1FBAE65E6AC8FADDED4F56EEEB136152844_inline(NULL);
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_000f;
		}
	}
	{
		// if (!GlobalGonfig.isSocket) return;
		goto IL_008c;
	}

IL_000f:
	{
		// if (Input.GetKeyDown(KeyCode.X))
		bool L_2;
		L_2 = Input_GetKeyDown_mB237DEA6244132670D38990BAB77D813FBB028D2(((int32_t)120), NULL);
		V_1 = L_2;
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_008c;
		}
	}
	{
		// var prev = anim.GetBool("tumbler2");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_4 = __this->___anim_4;
		bool L_5;
		L_5 = Animator_GetBool_mBC4D952885FF7504963E5923C29481A891028FD8(L_4, _stringLiteralB889CCEBAD3C5A0EA57CBF1E1EC93237C8BAD9B6, NULL);
		V_2 = L_5;
		// anim.SetBool("tumbler2", !prev);
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_6 = __this->___anim_4;
		bool L_7 = V_2;
		Animator_SetBool_m6F8D4FAF0770CD4EC1F54406249785DE7391E42B(L_6, _stringLiteralB889CCEBAD3C5A0EA57CBF1E1EC93237C8BAD9B6, (bool)((((int32_t)L_7) == ((int32_t)0))? 1 : 0), NULL);
		// if (anim.GetBool("tumbler2"))
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_8 = __this->___anim_4;
		bool L_9;
		L_9 = Animator_GetBool_mBC4D952885FF7504963E5923C29481A891028FD8(L_8, _stringLiteralB889CCEBAD3C5A0EA57CBF1E1EC93237C8BAD9B6, NULL);
		V_3 = L_9;
		bool L_10 = V_3;
		if (!L_10)
		{
			goto IL_0071;
		}
	}
	{
		// GlobalGonfig.isHeart = false;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		GlobalGonfig_set_isHeart_m989E0D619D6EA32F6836D4F97269A4AF84416BA2_inline((bool)0, NULL);
		// anim.Play("Tumbler2");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_11 = __this->___anim_4;
		Animator_Play_m0F6A9F84B2E256E644D56C34A7A9BD622CB00FF9(L_11, _stringLiteral22BCB08134DF4129F83330A14F3760EEE62D8858, NULL);
		goto IL_008b;
	}

IL_0071:
	{
		// GlobalGonfig.isHeart = true;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		GlobalGonfig_set_isHeart_m989E0D619D6EA32F6836D4F97269A4AF84416BA2_inline((bool)1, NULL);
		// anim.Play("Tumbler2Back");
		Animator_t8A52E42AE54F76681838FE9E632683EF3952E883* L_12 = __this->___anim_4;
		Animator_Play_m0F6A9F84B2E256E644D56C34A7A9BD622CB00FF9(L_12, _stringLiteral4CCB470730A3A7B6552F44D8F3BD5316F1655B9B, NULL);
	}

IL_008b:
	{
	}

IL_008c:
	{
		// }
		return;
	}
}
// System.Void Tumbler1::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Tumbler1__ctor_mB73EDB0914DCBD7253101CD6465BB262F612CD7D (Tumbler1_t5F8D47869C2459B4D767E01867D9865281754ACC* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void VoltMeterScript::Update()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VoltMeterScript_Update_mE6D1676243CFF0060579ABF6032C1D996246D77A (VoltMeterScript_t076A2E0A790F6C3C209A171F75B922CC27838586* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	float V_2 = 0.0f;
	{
		// if (!GlobalGonfig.isSocket) return;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0;
		L_0 = GlobalGonfig_get_isSocket_m57DAE1FBAE65E6AC8FADDED4F56EEEB136152844_inline(NULL);
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_000f;
		}
	}
	{
		// if (!GlobalGonfig.isSocket) return;
		goto IL_0073;
	}

IL_000f:
	{
		// if (!GlobalGonfig.isConstTok)
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = GlobalGonfig_get_isConstTok_mB62CCC94C131692862AB730ED6980A2E68C320C2_inline(NULL);
		V_1 = (bool)((((int32_t)L_2) == ((int32_t)0))? 1 : 0);
		bool L_3 = V_1;
		if (!L_3)
		{
			goto IL_0073;
		}
	}
	{
		// float deltaY = amplitude * Mathf.Sin(2 * Mathf.PI * frequency * timeCounter);
		float L_4 = __this->___amplitude_4;
		float L_5 = __this->___frequency_5;
		float L_6 = __this->___timeCounter_7;
		float L_7;
		L_7 = sinf(((float)il2cpp_codegen_multiply(((float)il2cpp_codegen_multiply((6.28318548f), L_5)), L_6)));
		V_2 = ((float)il2cpp_codegen_multiply(L_4, L_7));
		// transform.Rotate(-Vector3.right, deltaY * rotationSpeed * Time.deltaTime);
		Transform_tB27202C6F4E36D225EE28A13E4D662BF99785DB1* L_8;
		L_8 = Component_get_transform_m2919A1D81931E6932C7F06D4C2F0AB8DDA9A5371(__this, NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9;
		L_9 = Vector3_get_right_mFF573AFBBB2186E7AFA1BA7CA271A78DF67E4EA0_inline(NULL);
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10;
		L_10 = Vector3_op_UnaryNegation_m5450829F333BD2A88AF9A592C4EE331661225915_inline(L_9, NULL);
		float L_11 = V_2;
		float L_12 = __this->___rotationSpeed_6;
		float L_13;
		L_13 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		Transform_Rotate_m35B44707FE16FF8015D519D8C162C0B4A85D6D1F(L_8, L_10, ((float)il2cpp_codegen_multiply(((float)il2cpp_codegen_multiply(L_11, L_12)), L_13)), NULL);
		// timeCounter += Time.deltaTime;
		float L_14 = __this->___timeCounter_7;
		float L_15;
		L_15 = Time_get_deltaTime_mC3195000401F0FD167DD2F948FD2BC58330D0865(NULL);
		__this->___timeCounter_7 = ((float)il2cpp_codegen_add(L_14, L_15));
	}

IL_0073:
	{
		// }
		return;
	}
}
// System.Void VoltMeterScript::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void VoltMeterScript__ctor_m4C9DF7EF7681507FB2EE7083BF6F3C8FE7E0C7ED (VoltMeterScript_t076A2E0A790F6C3C209A171F75B922CC27838586* __this, const RuntimeMethod* method) 
{
	{
		// public float amplitude = 0.01f;
		__this->___amplitude_4 = (0.00999999978f);
		// public float frequency = 0.01f;
		__this->___frequency_5 = (0.00999999978f);
		// public float rotationSpeed = 150f;
		__this->___rotationSpeed_6 = (150.0f);
		// private float timeCounter = 0f;
		__this->___timeCounter_7 = (0.0f);
		// public float minYRotation = -180f;
		__this->___minYRotation_8 = (-180.0f);
		// public float maxYRotation = 180.25f;
		__this->___maxYRotation_9 = (180.25f);
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Windows_up::OnSettings()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Windows_up_OnSettings_m53F2F7484FFC7843AC17E4B901BBD9284D60E773 (Windows_up_t369E4FBE2D3DF45BFBEE7FE0EC42B546BEC651A4* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFF007DCBAADA2014554528E5BEAADE4DFC5E217E);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "??? ?????? ?????? ????? ?????????? ????????? ? ????????? ???????.";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteralFF007DCBAADA2014554528E5BEAADE4DFC5E217E);
		// }
		return;
	}
}
// System.Void Windows_up::OnExit()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Windows_up_OnExit_mDDEB623C4E7B869C35A6EC85C8FEC3CDB97C243A (Windows_up_t369E4FBE2D3DF45BFBEE7FE0EC42B546BEC651A4* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6069A933D1289F5E11D63BF4FBF355117226CFEC);
		s_Il2CppMethodInitialized = true;
	}
	{
		// message.text = "?? ???????? ????????? ??????? ????? ????????? ??????.";
		Text_tD60B2346DAA6666BF0D822FF607F0B220C2B9E62* L_0 = __this->___message_4;
		VirtualActionInvoker1< String_t* >::Invoke(75 /* System.Void UnityEngine.UI.Text::set_text(System.String) */, L_0, _stringLiteral6069A933D1289F5E11D63BF4FBF355117226CFEC);
		// }
		return;
	}
}
// System.Void Windows_up::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Windows_up__ctor_mC22309CE29AEF523745C93539D3A28D6533884E9 (Windows_up_t369E4FBE2D3DF45BFBEE7FE0EC42B546BEC651A4* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Window_up2::Start()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Window_up2_Start_m839D18A34E8871F60B67EF4A89F0DC97A33A950D (Window_up2_tA58A67A9C61588E05FE1156060249039DF64E1BE* __this, const RuntimeMethod* method) 
{
	{
		// Close(); //  ??????? ??????????? ???? ??? ??????? ?????????
		Window_up2_Close_m313A6EB20E46707A6073BBF6C5CF1573C6EBEBD0(__this, NULL);
		// }
		return;
	}
}
// System.Void Window_up2::Open()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Window_up2_Open_mBF6897E0844A497FD5CE7AEC7BDE610076FB6E59 (Window_up2_tA58A67A9C61588E05FE1156060249039DF64E1BE* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		// if (isClose)
		bool L_0 = __this->___isClose_4;
		V_0 = L_0;
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		// isClose = false;
		__this->___isClose_4 = (bool)0;
		goto IL_001f;
	}

IL_0016:
	{
		// isClose = true;
		__this->___isClose_4 = (bool)1;
	}

IL_001f:
	{
		// gameObject.SetActive(isClose);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
		L_2 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(__this, NULL);
		bool L_3 = __this->___isClose_4;
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_2, L_3, NULL);
		// }
		return;
	}
}
// System.Void Window_up2::Close()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Window_up2_Close_m313A6EB20E46707A6073BBF6C5CF1573C6EBEBD0 (Window_up2_tA58A67A9C61588E05FE1156060249039DF64E1BE* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		// if (!isClose)
		bool L_0 = __this->___isClose_4;
		V_0 = (bool)((((int32_t)L_0) == ((int32_t)0))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0019;
		}
	}
	{
		// isClose = true;
		__this->___isClose_4 = (bool)1;
		goto IL_0022;
	}

IL_0019:
	{
		// isClose = false;
		__this->___isClose_4 = (bool)0;
	}

IL_0022:
	{
		// gameObject.SetActive(isClose);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2;
		L_2 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(__this, NULL);
		bool L_3 = __this->___isClose_4;
		GameObject_SetActive_m638E92E1E75E519E5B24CF150B08CA8E0CDFAB92(L_2, L_3, NULL);
		// }
		return;
	}
}
// System.Void Window_up2::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Window_up2__ctor_m4F935A9B93093F496EB5852DFE55A3BA3F263C06 (Window_up2_tA58A67A9C61588E05FE1156060249039DF64E1BE* __this, const RuntimeMethod* method) 
{
	{
		// private bool isClose = true;
		__this->___isClose_4 = (bool)1;
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GlobalGonfig_get_isSocket_m57DAE1FBAE65E6AC8FADDED4F56EEEB136152844_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isSocket { get; set; } = false;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0 = ((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisSocketU3Ek__BackingField_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GlobalGonfig_get_isConstTok_mB62CCC94C131692862AB730ED6980A2E68C320C2_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isConstTok { get; set; } = true;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0 = ((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisConstTokU3Ek__BackingField_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_right_mFF573AFBBB2186E7AFA1BA7CA271A78DF67E4EA0_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ((Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields*)il2cpp_codegen_static_fields_for(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var))->___rightVector_10;
		V_0 = L_0;
		goto IL_0009;
	}

IL_0009:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_UnaryNegation_m5450829F333BD2A88AF9A592C4EE331661225915_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_a;
		float L_1 = L_0.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___0_a;
		float L_3 = L_2.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_a;
		float L_5 = L_4.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6;
		memset((&L_6), 0, sizeof(L_6));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_6), ((-L_1)), ((-L_3)), ((-L_5)), /*hidden argument*/NULL);
		V_0 = L_6;
		goto IL_001e;
	}

IL_001e:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_7 = V_0;
		return L_7;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GlobalGonfig_set_isConstTok_m829451F001136839108CCAF669A96DA63F266A7D_inline (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isConstTok { get; set; } = true;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisConstTokU3Ek__BackingField_0 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_up_m128AF3FDC820BF59D5DE86D973E7DE3F20C3AEBA_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ((Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields*)il2cpp_codegen_static_fields_for(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var))->___upVector_7;
		V_0 = L_0;
		goto IL_0009;
	}

IL_0009:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2* __this, float ___0_x, float ___1_y, float ___2_z, const RuntimeMethod* method) 
{
	{
		float L_0 = ___0_x;
		__this->___x_2 = L_0;
		float L_1 = ___1_y;
		__this->___y_3 = L_1;
		float L_2 = ___2_z;
		__this->___z_4 = L_2;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_Addition_m78C0EC70CB66E8DCAC225743D82B268DAEE92067_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_b, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_a;
		float L_1 = L_0.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___1_b;
		float L_3 = L_2.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_a;
		float L_5 = L_4.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___1_b;
		float L_7 = L_6.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8 = ___0_a;
		float L_9 = L_8.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = ___1_b;
		float L_11 = L_10.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_12;
		memset((&L_12), 0, sizeof(L_12));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_12), ((float)il2cpp_codegen_add(L_1, L_3)), ((float)il2cpp_codegen_add(L_5, L_7)), ((float)il2cpp_codegen_add(L_9, L_11)), /*hidden argument*/NULL);
		V_0 = L_12;
		goto IL_0030;
	}

IL_0030:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_13 = V_0;
		return L_13;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Vector3_Distance_m2314DB9B8BD01157E013DF87BEA557375C7F9FF9_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_b, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	float V_1 = 0.0f;
	float V_2 = 0.0f;
	float V_3 = 0.0f;
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_a;
		float L_1 = L_0.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___1_b;
		float L_3 = L_2.___x_2;
		V_0 = ((float)il2cpp_codegen_subtract(L_1, L_3));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___0_a;
		float L_5 = L_4.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___1_b;
		float L_7 = L_6.___y_3;
		V_1 = ((float)il2cpp_codegen_subtract(L_5, L_7));
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_8 = ___0_a;
		float L_9 = L_8.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = ___1_b;
		float L_11 = L_10.___z_4;
		V_2 = ((float)il2cpp_codegen_subtract(L_9, L_11));
		float L_12 = V_0;
		float L_13 = V_0;
		float L_14 = V_1;
		float L_15 = V_1;
		float L_16 = V_2;
		float L_17 = V_2;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_18;
		L_18 = sqrt(((double)((float)il2cpp_codegen_add(((float)il2cpp_codegen_add(((float)il2cpp_codegen_multiply(L_12, L_13)), ((float)il2cpp_codegen_multiply(L_14, L_15)))), ((float)il2cpp_codegen_multiply(L_16, L_17))))));
		V_3 = ((float)L_18);
		goto IL_0040;
	}

IL_0040:
	{
		float L_19 = V_3;
		return L_19;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_get_forward_mAA55A7034304DF8B2152EAD49AE779FC4CA2EB4A_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ((Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_StaticFields*)il2cpp_codegen_static_fields_for(Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2_il2cpp_TypeInfo_var))->___forwardVector_11;
		V_0 = L_0;
		goto IL_0009;
	}

IL_0009:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_1 = V_0;
		return L_1;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_op_Multiply_m87BA7C578F96C8E49BB07088DAAC4649F83B0353_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, float ___1_d, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_0 = ___0_a;
		float L_1 = L_0.___x_2;
		float L_2 = ___1_d;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_3 = ___0_a;
		float L_4 = L_3.___y_3;
		float L_5 = ___1_d;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___0_a;
		float L_7 = L_6.___z_4;
		float L_8 = ___1_d;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9;
		memset((&L_9), 0, sizeof(L_9));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_9), ((float)il2cpp_codegen_multiply(L_1, L_2)), ((float)il2cpp_codegen_multiply(L_4, L_5)), ((float)il2cpp_codegen_multiply(L_7, L_8)), /*hidden argument*/NULL);
		V_0 = L_9;
		goto IL_0021;
	}

IL_0021:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_10 = V_0;
		return L_10;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Color__ctor_mCD6889CDE39F18704CD6EA8E2EFBFA48BA3E13B0_inline (Color_tD001788D726C3A7F1379BEED0260B9591F440C1F* __this, float ___0_r, float ___1_g, float ___2_b, const RuntimeMethod* method) 
{
	{
		float L_0 = ___0_r;
		__this->___r_0 = L_0;
		float L_1 = ___1_g;
		__this->___g_1 = L_1;
		float L_2 = ___2_b;
		__this->___b_2 = L_2;
		__this->___a_3 = (1.0f);
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 Vector3_Lerp_m3A906D0530A94FAABB94F0F905E84D99BE85C3F8_inline (Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___0_a, Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 ___1_b, float ___2_t, const RuntimeMethod* method) 
{
	Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		float L_0 = ___2_t;
		float L_1;
		L_1 = Mathf_Clamp01_mA7E048DBDA832D399A581BE4D6DED9FA44CE0F14_inline(L_0, NULL);
		___2_t = L_1;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_2 = ___0_a;
		float L_3 = L_2.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_4 = ___1_b;
		float L_5 = L_4.___x_2;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_6 = ___0_a;
		float L_7 = L_6.___x_2;
		float L_8 = ___2_t;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_9 = ___0_a;
		float L_10 = L_9.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_11 = ___1_b;
		float L_12 = L_11.___y_3;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_13 = ___0_a;
		float L_14 = L_13.___y_3;
		float L_15 = ___2_t;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_16 = ___0_a;
		float L_17 = L_16.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_18 = ___1_b;
		float L_19 = L_18.___z_4;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_20 = ___0_a;
		float L_21 = L_20.___z_4;
		float L_22 = ___2_t;
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_23;
		memset((&L_23), 0, sizeof(L_23));
		Vector3__ctor_m376936E6B999EF1ECBE57D990A386303E2283DE0_inline((&L_23), ((float)il2cpp_codegen_add(L_3, ((float)il2cpp_codegen_multiply(((float)il2cpp_codegen_subtract(L_5, L_7)), L_8)))), ((float)il2cpp_codegen_add(L_10, ((float)il2cpp_codegen_multiply(((float)il2cpp_codegen_subtract(L_12, L_14)), L_15)))), ((float)il2cpp_codegen_add(L_17, ((float)il2cpp_codegen_multiply(((float)il2cpp_codegen_subtract(L_19, L_21)), L_22)))), /*hidden argument*/NULL);
		V_0 = L_23;
		goto IL_0053;
	}

IL_0053:
	{
		Vector3_t24C512C7B96BBABAD472002D0BA2BDA40A5A80B2 L_24 = V_0;
		return L_24;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t String_get_Length_m42625D67623FA5CC7A44D47425CE86FB946542D2_inline (String_t* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->____stringLength_4;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR double Math_Round_m0BD20E38C73A9283F2EC89E6DF9CCC80A7752C38_inline (double ___0_value, int32_t ___1_digits, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		double L_0 = ___0_value;
		int32_t L_1 = ___1_digits;
		il2cpp_codegen_runtime_class_init_inline(Math_tEB65DE7CA8B083C412C969C92981C030865486CE_il2cpp_TypeInfo_var);
		double L_2;
		L_2 = Math_Round_m8DB2F61CB73B9E71E54149290ABD5DC8A68890D1(L_0, L_1, 0, NULL);
		return L_2;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Clamp_mEB9AEA827D27D20FCC787F7375156AF46BB12BBF_inline (float ___0_value, float ___1_min, float ___2_max, const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	float V_2 = 0.0f;
	{
		float L_0 = ___0_value;
		float L_1 = ___1_min;
		V_0 = (bool)((((float)L_0) < ((float)L_1))? 1 : 0);
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_000e;
		}
	}
	{
		float L_3 = ___1_min;
		___0_value = L_3;
		goto IL_0019;
	}

IL_000e:
	{
		float L_4 = ___0_value;
		float L_5 = ___2_max;
		V_1 = (bool)((((float)L_4) > ((float)L_5))? 1 : 0);
		bool L_6 = V_1;
		if (!L_6)
		{
			goto IL_0019;
		}
	}
	{
		float L_7 = ___2_max;
		___0_value = L_7;
	}

IL_0019:
	{
		float L_8 = ___0_value;
		V_2 = L_8;
		goto IL_001d;
	}

IL_001d:
	{
		float L_9 = V_2;
		return L_9;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool GlobalGonfig_get_isHeart_m14A72AC416E63D6C1A5F8C371A85FE17667A0EF6_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isHeart { get; set; } = false;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		bool L_0 = ((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisHeartU3Ek__BackingField_1;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GlobalGonfig_set_isSocket_m89642441CD2C0F5112EA12496F732EA889B224CC_inline (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isSocket { get; set; } = false;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisSocketU3Ek__BackingField_2 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GlobalGonfig_set_Step_m07F0DC514B18F632AA191958E08758F26EB1192A_inline (int32_t ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static int Step { get; set; } = 0;
		int32_t L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CStepU3Ek__BackingField_3 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PlayInstChanged_Invoke_m443DE3F5F56F97FFA758262E8CBDD96C3531DB32_inline (PlayInstChanged_tBE46D52B91A34F95619C5D9CED10E58B77412E91* __this, bool ___0_newValue, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, bool, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_newValue, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t GlobalGonfig_get_Step_m486B62F18526F24C79F59C02E034D73902EACD16_inline (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static int Step { get; set; } = 0;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		int32_t L_0 = ((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CStepU3Ek__BackingField_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void GlobalGonfig_set_isHeart_m989E0D619D6EA32F6836D4F97269A4AF84416BA2_inline (bool ___0_value, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public static bool isHeart { get; set; } = false;
		bool L_0 = ___0_value;
		il2cpp_codegen_runtime_class_init_inline(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var);
		((GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_StaticFields*)il2cpp_codegen_static_fields_for(GlobalGonfig_tC9CEF7BF3E650437896FD24352603A5C3E79DA01_il2cpp_TypeInfo_var))->___U3CisHeartU3Ek__BackingField_1 = L_0;
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Clamp01_mA7E048DBDA832D399A581BE4D6DED9FA44CE0F14_inline (float ___0_value, const RuntimeMethod* method) 
{
	bool V_0 = false;
	float V_1 = 0.0f;
	bool V_2 = false;
	{
		float L_0 = ___0_value;
		V_0 = (bool)((((float)L_0) < ((float)(0.0f)))? 1 : 0);
		bool L_1 = V_0;
		if (!L_1)
		{
			goto IL_0015;
		}
	}
	{
		V_1 = (0.0f);
		goto IL_002d;
	}

IL_0015:
	{
		float L_2 = ___0_value;
		V_2 = (bool)((((float)L_2) > ((float)(1.0f)))? 1 : 0);
		bool L_3 = V_2;
		if (!L_3)
		{
			goto IL_0029;
		}
	}
	{
		V_1 = (1.0f);
		goto IL_002d;
	}

IL_0029:
	{
		float L_4 = ___0_value;
		V_1 = L_4;
		goto IL_002d;
	}

IL_002d:
	{
		float L_5 = V_1;
		return L_5;
	}
}
