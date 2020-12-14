#include "zoom_node_meeting_audio_ctrl.h"

ZoomNodeMeetingAudioCtrlWrap::ZoomNodeMeetingAudioCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingAudioCtrlWrapSink);
}

ZoomNodeMeetingAudioCtrlWrap::~ZoomNodeMeetingAudioCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().SetSink(NULL);
}
void ZoomNodeMeetingAudioCtrlWrap::MuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::MuteAudioParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::MuteAudioParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_allowunmutebyself() ||
			!proto_params.has_userid()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _userid = proto_params.userid();
		bool _b_allowunmutebyself = false;
		convertBool(proto_params.allowunmutebyself(), _b_allowunmutebyself);

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().MuteAudio(_userid, _b_allowunmutebyself);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAudioCtrlWrap::UnMuteAudio(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::UnmuteAudioParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::UnmuteAudioParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_userid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		int _userid = proto_params.userid();
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().UnMuteAudio(_userid);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAudioCtrlWrap::JoinVoip(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().JoinVoip();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAudioCtrlWrap::LeaveVoip(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().LeaveVoip();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAudioCtrlWrap::SetMeetingAudioStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onUserAudioStatusChange = cb;

	} while (false);

	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAudioCtrlWrap::SetUserActiveAudioChangeCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onUserActiveAudioChange.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onUserActiveAudioChange = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingAudioCtrlWrap::EnablePlayChimeWhenEnterOrExit(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::EnablePlayChimeWhenEnterOrExitParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnablePlayChimeWhenEnterOrExitParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingAudioCtrl().EnablePlayChimeWhenEnterOrExit(_bEnable);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
