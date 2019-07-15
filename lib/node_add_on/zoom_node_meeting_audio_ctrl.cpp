#include "zoom_node_meeting_audio_ctrl.h"

ZoomNodeMeetingAudioCtrlWrap::ZoomNodeMeetingAudioCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().SetSink(&_g_node_meetingAudio_cb);
}

ZoomNodeMeetingAudioCtrlWrap::~ZoomNodeMeetingAudioCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().SetSink(NULL);
}
void ZoomNodeMeetingAudioCtrlWrap::MuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 3) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsBoolean() ||
		!args[2]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	ZoomSTRING zn_userid;
	zoom_v8toc(args[0].As<v8::String>(), zn_userid);
	bool zn_allowUnmuteBySelf;
	zoom_v8toc(args[1].As<v8::Boolean>(), zn_allowUnmuteBySelf);

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[2]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().MuteAudio(zn_userid, zn_allowUnmuteBySelf);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAudioCtrlWrap::UnMuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	ZoomSTRING zn_userid;
	zoom_v8toc(args[0].As<v8::String>(), zn_userid);

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[1]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().UnMuteAudio(zn_userid);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAudioCtrlWrap::JoinVoip(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().JoinVoip();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAudioCtrlWrap::LeaveVoip(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().LeaveVoip();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAudioCtrlWrap::SetMeetingAudioStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
