#include "zoom_node_meeting_share_ctrl.h"


ZoomNodeMeetingShareCtrlWrap::ZoomNodeMeetingShareCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingShareWrapSink);
}

ZoomNodeMeetingShareCtrlWrap::~ZoomNodeMeetingShareCtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().SetSink(NULL);
}
void ZoomNodeMeetingShareCtrlWrap::StartAppShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::StartAppShareParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::StartAppShareParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_hshareapp())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_hShare_app;
		_zn_hShare_app = s2zs(proto_params.hshareapp());

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().StartAppShare(_zn_hShare_app);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingShareCtrlWrap::StartMonitorShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::StartMonitorShareParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::StartMonitorShareParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_monitorid())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_monitorID;
		_zn_monitorID = s2zs(proto_params.monitorid());
		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingShareCtrl().StartMonitorShare(_zn_monitorID);
	} while (false);
	
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
void ZoomNodeMeetingShareCtrlWrap::SetOnSharingStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())
		{
			ZoomNodeSinkHelper::GetInst().onSharingStatus.Empty();
			err = ZNSDKERR_INVALID_PARAMETER;
			break;;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onSharingStatus = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}