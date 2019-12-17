#ifndef _ZOOM_NODE_SETTING_AUDIO_CTRL_H_
#define _ZOOM_NODE_SETTING_AUDIO_CTRL_H_
#include "zoom_node_common_include.h"
#include "zoom_native_sdk_wrap_core.h"
#include "zoom_singleton_wrap_class.h"

extern ZNativeSDKWrap _g_native_wrap;
class ZOOM_NODE_HIDE ZoomNodeSettingAudioCtrlWrap :
	public ZoomWrapObject<ZoomNodeSettingAudioCtrlWrap >
{
	friend class ZoomWrapObject<ZoomNodeSettingAudioCtrlWrap >;
private:
	ZoomNodeSettingAudioCtrlWrap();
	~ZoomNodeSettingAudioCtrlWrap();
public:
	/// \brief Select mic device.
	/// \param 1. deviceId(string) Specify the device to be selected.
	/// \param 2. deviceName(string) Specify the device name assigned by deviceId.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SelectMic(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the mic device list.
	/// \return If the function succeeds, the return value is the camera device list.
	///Otherwise failed, returns empty list.
	static void GetMicList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Select speaker device.
	/// \param 1. deviceId(string) Specify the device to be selected.
	/// \param 2. deviceName(string) Specify the device the device name assigned by deviceId.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void SelectSpeaker(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the speaker device list.
	/// \return If the function succeeds, the return value is the camera device list.
	///Otherwise failed, returns empty list.
	static void GetSpeakerList(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the flag to enable/disable the audio automatically when join meeting.
	/// \return Enabled(TRUE) or disabled(FALSE).
	static void IsAutoJoinAudioEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Get the flag to enable/disable to auto-adjust the mic volume.
	/// \return Enabled(TRUE) or disabled(FALSE).
	static void IsAutoAdjustMicEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enable or disable the audio automatically when join meeting.
	/// \param 1. bEnable(bool) TRUE indicates to enable the audio automatically when join meeting.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EnableAutoJoinAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	/// \brief Enable or disable the auto-adjust mic volume.
	/// \param 1. bEnable(bool) TRUE indicates to enable to auto-adjust the mic volume.
	/// \return If the function succeeds, the return value is ZNSDKERR_SUCCESS.
	///Otherwise failed. To get extended error information, see \link ZNSDKError \endlink enum.
	static void EnableAutoAdjustMic(const v8::FunctionCallbackInfo<v8::Value>& args);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	static void SetComputerMicDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetComputerSpeakerDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetDefaultMicDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetDefaultSpeakerDeviceChangedCB(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableStereoAudio(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsStereoAudioEnable(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableMicOriginalInput(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsMicOriginalInputEnable(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableHoldSpaceKeyToSpeak(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsHoldSpaceKeyToSpeakEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableAlwaysMuteMicWhenJoinVoip(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsAlwaysMuteMicWhenJoinVoipEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableSuppressAudioNotify(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsSuppressAudioNotifyEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void EnableEchoCancellation(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void IsEchoCancellationEnabled(const v8::FunctionCallbackInfo<v8::Value>& args);

	static void SetMicVol(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetMicVol(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void SetSpeakerVol(const v8::FunctionCallbackInfo<v8::Value>& args);
	static void GetSpeakerVol(const v8::FunctionCallbackInfo<v8::Value>& args);
	
	static v8::Persistent<v8::Function> constructor;
};
template<>
static void InitClassAttribute<ZoomNodeSettingAudioCtrlWrap >(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{
	tpl->SetClassName(v8::String::NewFromUtf8(
		isolate, "ZoomNodeSettingAudioCtrlWrap", v8::NewStringType::kInternalized).ToLocalChecked());
	tpl->InstanceTemplate()->SetInternalFieldCount(1);

	// Prototype
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectMic", ZoomNodeSettingAudioCtrlWrap::SelectMic);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMicList", ZoomNodeSettingAudioCtrlWrap::GetMicList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SelectSpeaker", ZoomNodeSettingAudioCtrlWrap::SelectSpeaker);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSpeakerList", ZoomNodeSettingAudioCtrlWrap::GetSpeakerList);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoJoinAudioEnabled", ZoomNodeSettingAudioCtrlWrap::IsAutoJoinAudioEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAutoAdjustMicEnabled", ZoomNodeSettingAudioCtrlWrap::IsAutoAdjustMicEnabled);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoJoinAudio", ZoomNodeSettingAudioCtrlWrap::EnableAutoJoinAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAutoAdjustMic", ZoomNodeSettingAudioCtrlWrap::EnableAutoAdjustMic);
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetComputerMicDeviceChangedCB", ZoomNodeSettingAudioCtrlWrap::SetComputerMicDeviceChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetComputerSpeakerDeviceChangedCB", ZoomNodeSettingAudioCtrlWrap::SetComputerSpeakerDeviceChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDefaultMicDeviceChangedCB", ZoomNodeSettingAudioCtrlWrap::SetDefaultMicDeviceChangedCB);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetDefaultSpeakerDeviceChangedCB", ZoomNodeSettingAudioCtrlWrap::SetDefaultSpeakerDeviceChangedCB);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableStereoAudio", ZoomNodeSettingAudioCtrlWrap::EnableStereoAudio);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsStereoAudioEnable", ZoomNodeSettingAudioCtrlWrap::IsStereoAudioEnable);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableMicOriginalInput", ZoomNodeSettingAudioCtrlWrap::EnableMicOriginalInput);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsMicOriginalInputEnable", ZoomNodeSettingAudioCtrlWrap::IsMicOriginalInputEnable);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableHoldSpaceKeyToSpeak", ZoomNodeSettingAudioCtrlWrap::EnableHoldSpaceKeyToSpeak);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsHoldSpaceKeyToSpeakEnabled", ZoomNodeSettingAudioCtrlWrap::IsHoldSpaceKeyToSpeakEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableAlwaysMuteMicWhenJoinVoip", ZoomNodeSettingAudioCtrlWrap::EnableAlwaysMuteMicWhenJoinVoip);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsAlwaysMuteMicWhenJoinVoipEnabled", ZoomNodeSettingAudioCtrlWrap::IsAlwaysMuteMicWhenJoinVoipEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableSuppressAudioNotify", ZoomNodeSettingAudioCtrlWrap::EnableSuppressAudioNotify);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsSuppressAudioNotifyEnabled", ZoomNodeSettingAudioCtrlWrap::IsSuppressAudioNotifyEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "EnableEchoCancellation", ZoomNodeSettingAudioCtrlWrap::EnableEchoCancellation);
	NODE_SET_PROTOTYPE_METHOD(tpl, "IsEchoCancellationEnabled", ZoomNodeSettingAudioCtrlWrap::IsEchoCancellationEnabled);

	NODE_SET_PROTOTYPE_METHOD(tpl, "SetMicVol", ZoomNodeSettingAudioCtrlWrap::SetMicVol);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetMicVol", ZoomNodeSettingAudioCtrlWrap::GetMicVol);
	NODE_SET_PROTOTYPE_METHOD(tpl, "SetSpeakerVol", ZoomNodeSettingAudioCtrlWrap::SetSpeakerVol);
	NODE_SET_PROTOTYPE_METHOD(tpl, "GetSpeakerVol", ZoomNodeSettingAudioCtrlWrap::GetSpeakerVol);
}
template<>
static v8::Persistent<v8::Function>* GetConstructor<ZoomNodeSettingAudioCtrlWrap >() {
	return &ZoomNodeSettingAudioCtrlWrap::constructor;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




#endif
