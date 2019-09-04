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
	//meeting_service_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onMeetingStatusChanged;
	
	//premeeting_service_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onScheduleOrEditMeeting;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onListMeeting;
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onDeleteMeeting;
	//meetingUI_Controller_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > onInviteBtnClicked;

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

	//direct_share_helper_cb
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > OnDirectShareStatusUpdate;

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
