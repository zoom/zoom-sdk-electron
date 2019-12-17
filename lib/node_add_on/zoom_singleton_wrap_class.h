#ifndef _zoom_singleton_wrap_class_h_
#define _zoom_singleton_wrap_class_h_
#include "zoom_node_common_include.h"
template<class T>
static void InitClassAttribute(const v8::Local<v8::FunctionTemplate>& tpl, v8::Isolate* isolate)
{}

template<class T>
static v8::Persistent<v8::Function>* GetConstructor(){
	return NULL;
}

template<class T>
class ZoomWrapObject : public node::ObjectWrap
{
public:
	static void Init(v8::Isolate* isolate)
	{
		// Prepare constructor template
		v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New);
		InitClassAttribute<T >(tpl, isolate);
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		(*GetConstructor<T >()).Reset(isolate, tpl->GetFunction(context).ToLocalChecked());
	}
	static void NewInstance(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();

		const unsigned argc = 1;
		v8::Local<v8::Value> argv[argc] = { args[0] };
		v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, (*GetConstructor<T >()));
		v8::Local<v8::Context> context = isolate->GetCurrentContext();
		v8::Local<v8::Object> instance =
			cons->NewInstance(context, argc, argv).ToLocalChecked();

		args.GetReturnValue().Set(instance);
	}

	static void New(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		v8::Isolate* isolate = args.GetIsolate();
		v8::Local<v8::Context> context = isolate->GetCurrentContext();

		if (args.IsConstructCall()) {
			T* obj = new T();
			obj->Wrap(args.This());
			args.GetReturnValue().Set(args.This());
		}
		else {
			const int argc = 1;
			v8::Local<v8::Value> argv[argc] = { args[0] };
			v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, (*GetConstructor<T >()));
			v8::Local<v8::Object> instance =
				cons->NewInstance(context, argc, argv).ToLocalChecked();
			args.GetReturnValue().Set(instance);
		}
	}

protected:
	ZoomWrapObject() {};
	~ZoomWrapObject() {};
};

class ZoomNodeSinkHelper
{
public:
	//auth_service_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onAuthenticationReturn;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onLoginRet;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onLogout;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onZoomIdentityExpired;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onZoomAuthIdentityExpired;
	//meeting_service_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onMeetingStatusChanged;
	
	//premeeting_service_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onScheduleOrEditMeeting;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onListMeeting;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onDeleteMeeting;
	//meetingUI_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onInviteBtnClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onStartShareBtnClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onEndMeetingBtnClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onParticipantListBtnClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onCustomLiveStreamMenuClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onZoomInviteDialogFailed;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onCCBTNClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onAudioBtnClicked;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onAudioMenuBtnClicked;

	//meeting_audio_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserAudioStatusChange;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserActiveAudioChange;

	//meeting_video_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserVideoStatusChange;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onActiveSpeakerVideoUserChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onActiveVideoUserChanged;
	

	//meeting_video_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onSharingStatus;

	//meeting_participants_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserJoin;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onUserLeft;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onHostChangeNotification;

	//meeting_h323_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onH323CalloutStatusNotify;

	//meeting_config_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingNeedToUpgrade;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingUpgradeToGiftFreeTrialStart;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingUpgradeToGiftFreeTrialStop;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingUpgradeToProMeeting;

	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onInputMeetingPasswordAndScreenNameNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onAirPlayInstructionWndNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onWebinarNeedRegisterNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onEndOtherMeetingToJoinMeetingNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingRemainTime;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onFreeMeetingRemainTimeStopCountDown;

	//direct_share_helper_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > OnDirectShareStatusUpdate;

	//sdk_sms_helper_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onNeedRealNameAuthMeetingNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onRetrieveSMSVerificationCodeResultNotification;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onVerifySMSVerificationCodeResultNotification;

	//audio_setting_context_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onComputerMicDeviceChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onComputerSpeakerDeviceChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onDefaultMicDeviceChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onDefaultSpeakerDeviceChanged;

	//video_setting_context_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onComputerCamDeviceChanged;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onDefaultCamDeviceChanged;

	//recording_setting_context_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onCloudRecordingStorageInfo;

	static ZoomNodeSinkHelper& GetInst()
	{
		static ZoomNodeSinkHelper inst;
		return inst;
	}
	~ZoomNodeSinkHelper() {}
private:
	ZoomNodeSinkHelper() {}
};
#endif // !_zoom_singleton_wrap_class_h_
