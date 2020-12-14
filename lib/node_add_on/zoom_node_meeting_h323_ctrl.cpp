#include "zoom_node_meeting_h323_ctrl.h"


ZoomNodeMeetingH323CtrlWrap::ZoomNodeMeetingH323CtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_meetingH323WrapSink);
}

ZoomNodeMeetingH323CtrlWrap::~ZoomNodeMeetingH323CtrlWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().SetSink(NULL);
}
void ZoomNodeMeetingH323CtrlWrap::CallOutH323(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::CallOutH323Params proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::CallOutH323Params >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_devicee164num() ||
			!proto_params.has_deviceip() ||
			!proto_params.has_devicename() ||
			!proto_params.has_h323devicetype()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_deviceName;
		_zn_deviceName = s2zs(proto_params.devicename());
		ZoomSTRING _zn_deviceIP;
		_zn_deviceIP = s2zs(proto_params.deviceip());
		ZoomSTRING _zn_deviceE164num;
		_zn_deviceE164num = s2zs(proto_params.devicee164num());
		ZNH323DeviceType _zn_type = (ZNH323DeviceType)proto_params.h323devicetype();

		err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().CallOutH323(_zn_deviceName, _zn_deviceIP, _zn_deviceE164num, _zn_type);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingH323CtrlWrap::CancelCallOutH323(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().CancelCallOutH323();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingH323CtrlWrap::GetH323Address(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<ZoomSTRING> h323AddressList = _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().GetH323Address();
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for(unsigned int i = 0; i < h323AddressList.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "H323Address", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(h323AddressList[i]).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		nodes->Set(context, i, node);
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingH323CtrlWrap::GetH323Password(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZoomSTRING zn_h323Password;
	zn_h323Password = _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().GetH323Password();
	v8::Local<v8::String> bret = v8::String::NewFromUtf8(isolate, zs2s(zn_h323Password).c_str(), v8::NewStringType::kInternalized).ToLocalChecked();
	args.GetReturnValue().Set(bret);
}
void ZoomNodeMeetingH323CtrlWrap::GetCalloutH323DviceList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<ZNH323DeviecInfo> h323DeviceList = _g_native_wrap.GetMeetingServiceWrap().GetMeetingH323Ctrl().GetCalloutH323DviceList();
	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < h323DeviceList.size(); ++i) {
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "H323DeviceName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(h323DeviceList[i].h323_deviceName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "H323DeviceIP", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(h323DeviceList[i].h323_deviceIP).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "H323DeviceE164Name", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(h323DeviceList[i].h323_deviceE164Name).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "H323DeviceType", v8::NewStringType::kInternalized).ToLocalChecked(), v8::Integer::New(isolate, (int32_t)h323DeviceList[i].h323_DeviceType));
		nodes->Set(context, i, node);
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeMeetingH323CtrlWrap::SetH323CallOutStatusCB(const v8::FunctionCallbackInfo<v8::Value>& args)
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
			ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify.Empty();
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
		ZoomNodeSinkHelper::GetInst().onH323CalloutStatusNotify = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
