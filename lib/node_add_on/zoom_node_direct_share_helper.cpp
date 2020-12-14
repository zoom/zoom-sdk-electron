#include "zoom_node_direct_share_helper.h"

ZoomNodeDirectShareHelperWrap::ZoomNodeDirectShareHelperWrap()
{
	_g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_directShareHelperWrapSink);
}

ZoomNodeDirectShareHelperWrap::~ZoomNodeDirectShareHelperWrap()
{
	_g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().SetSink(NULL);
}
void ZoomNodeDirectShareHelperWrap::CanStartDirectShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().CanStartDirectShare();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeDirectShareHelperWrap::IsDirectShareInProgress(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool zn_bIsInProgress = _g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().IsDirectShareInProgress();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, zn_bIsInProgress);
	args.GetReturnValue().Set(bret);

}
void ZoomNodeDirectShareHelperWrap::StartDirectShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().StartDirectShare();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeDirectShareHelperWrap::StopDirectShare(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().StopDirectShare();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeDirectShareHelperWrap::SetDirectShareStatusUpdateCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().OnDirectShareStatusUpdate.Empty();
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().OnDirectShareStatusUpdate = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeDirectShareHelperWrap::TryWithMeetingNumber(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::TryWithMeetingNumberParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::TryWithMeetingNumberParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_meetingnumber())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		unsigned long long _zn_meetingNumber = proto_params.meetingnumber();

		err = _g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().TryWithMeetingNumber(_zn_meetingNumber);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeDirectShareHelperWrap::TryWithPairingCode(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::TryWithPairingCodeParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::TryWithPairingCodeParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_paringcode())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _pairingCode;
		_pairingCode = s2zs(proto_params.paringcode());

		err = _g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().TryWithPairingCode(_pairingCode);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeDirectShareHelperWrap::Cancel(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetAuthServiceWrap().GetDirectShareHelper().Cancel();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}

