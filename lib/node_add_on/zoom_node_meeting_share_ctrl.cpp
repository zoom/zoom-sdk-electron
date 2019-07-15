#include "zoom_node_meeting_share_ctrl.h"


ZoomNodeMeetingShareCtrlWrap::ZoomNodeMeetingShareCtrlWrap()
{

}

ZoomNodeMeetingShareCtrlWrap::~ZoomNodeMeetingShareCtrlWrap()
{

}
void ZoomNodeMeetingShareCtrlWrap::StartAppShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	ZoomSTRING zn_hShare_app;
	zoom_v8toc(args[0].As<v8::String>(), zn_hShare_app);


	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().StartAppShare(zn_hShare_app);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingShareCtrlWrap::StartMonitorShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments")));
		return;
	}

	if (!args[0]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments")));
		return;
	}

	ZoomSTRING zn_monitorID;
	zoom_v8toc(args[0].As<v8::String>(), zn_monitorID);

	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().StartMonitorShare(zn_monitorID);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingShareCtrlWrap::StopShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().StopShare();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}