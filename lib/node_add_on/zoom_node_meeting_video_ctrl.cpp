#include "zoom_node_meeting_video_ctrl.h"

ZoomNodeMeetingVideoCtrlWrap::ZoomNodeMeetingVideoCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().SetSink(&_g_node_meetingVideo_cb);
}

ZoomNodeMeetingVideoCtrlWrap::~ZoomNodeMeetingVideoCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().SetSink(NULL);
}
void ZoomNodeMeetingVideoCtrlWrap::MuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
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
	ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().MuteVideo();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::UnMuteVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
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
	ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().UnMuteVideo();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::PinVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 4) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean() ||
		!args[1]->IsBoolean() ||
		!args[2]->IsString() ||
		!args[3]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	bool bPin;
	zoom_v8toc(args[0].As<v8::Boolean>(), bPin);
	bool bFirstView;
	zoom_v8toc(args[1].As<v8::Boolean>(), bFirstView);
	ZoomSTRING zn_userid;
	zoom_v8toc(args[2].As<v8::String>(), zn_userid);


	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[3]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().PinVideo(bPin, bFirstView, zn_userid);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::SpotlightVideo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 3) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean() ||
		!args[1]->IsString() ||
		!args[2]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	bool bSpotlight;
	zoom_v8toc(args[0].As<v8::Boolean>(), bSpotlight);
	ZoomSTRING zn_userid;
	zoom_v8toc(args[1].As<v8::String>(), zn_userid);


	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[2]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().SpotlightVideo(bSpotlight, zn_userid);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::HideOrShowNoVideoUserOnVideoWall(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsBoolean() ||
		!args[1]->IsFunction()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}
	bool bHide;
	zoom_v8toc(args[0].As<v8::Boolean>(), bHide);



	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[1]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange = cb;

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingVideoCtrl().HideOrShowNoVideoUserOnVideoWall(bHide);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingVideoCtrlWrap::SetMeetingVideoStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
	ZoomNodeSinkHelper::GetInst().onUserVideoStatusChange = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
