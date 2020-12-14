#include "zoom_node_sdk_sms_helper.h"

ZoomNodeSDKSMSHelperWrap::ZoomNodeSDKSMSHelperWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().SetSink(&ZoomNodeSinkWrapMgr::GetInst().m_smsHelperWrapSink);
}

ZoomNodeSDKSMSHelperWrap::~ZoomNodeSDKSMSHelperWrap()
{
	_g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().SetSink(NULL);
}
void ZoomNodeSDKSMSHelperWrap::EnableZoomAuthRealNameMeetingUIShown(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	do
	{
		com::electron::sdk::proto::EnableZoomAuthRealNameMeetingUIShownParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::EnableZoomAuthRealNameMeetingUIShownParams >(args, proto_params))
		{
			err = false;
			break;
		}
		if (!proto_params.has_benable())
		{
			err = false;
			break;
		}
		bool _bEnable = false;
		convertBool(proto_params.benable(), _bEnable);

		err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().EnableZoomAuthRealNameMeetingUIShown(_bEnable);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::GetResendSMSVerificationCodeHandler(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().GetResendSMSVerificationCodeHandler();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::Retrieve(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	do
	{
		com::electron::sdk::proto::RetrieveParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::RetrieveParams >(args, proto_params))
		{
			err = false;
			break;
		}
		if (!proto_params.has_countrycode() ||
			!proto_params.has_phonenum()
			)
		{
			err = false;
			break;
		}
		ZoomSTRING _zn_countryCode;
		_zn_countryCode = s2zs(proto_params.countrycode());
		ZoomSTRING _zn_phoneNum;
		_zn_phoneNum = s2zs(proto_params.phonenum());

		err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().Retrieve(_zn_countryCode, _zn_phoneNum);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::Retrieve_CancelAndLeaveMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().Retrieve_CancelAndLeaveMeeting();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::GetReVerifySMSVerificationCodeHandler(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().GetReVerifySMSVerificationCodeHandler();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::Verify(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	do
	{
		com::electron::sdk::proto::VerifyParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::VerifyParams >(args, proto_params))
		{
			err = false;
			break;
		}
		if (!proto_params.has_countrycode() ||
			!proto_params.has_phonenum() ||
			!proto_params.has_verificationcode()
			)
		{
			err = false;
			break;
		}
		ZoomSTRING _zn_countryCode;
		_zn_countryCode = s2zs(proto_params.countrycode());
		ZoomSTRING _zn_phoneNum;
		_zn_phoneNum = s2zs(proto_params.phonenum());
		ZoomSTRING _zn_verificationCode;
		_zn_verificationCode = s2zs(proto_params.verificationcode());

		err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().Verify(_zn_countryCode, _zn_phoneNum, _zn_verificationCode);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::Verify_CancelAndLeaveMeeting(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().Verify_CancelAndLeaveMeeting();
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::GetSupportPhoneNumberCountryList(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	auto context = isolate->GetCurrentContext();
	ZNList<ZNZoomRealNameAuthCountryInfo> zn_support_phone_number_country_lst;
	zn_support_phone_number_country_lst = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().GetSupportPhoneNumberCountryList();

	v8::Local<v8::Array> nodes = v8::Array::New(isolate);
	for (unsigned int i = 0; i < zn_support_phone_number_country_lst.size(); ++i) 
	{
		v8::HandleScope scope(isolate);
		v8::Local<v8::Object> node = v8::Object::New(isolate);
		node->Set(context, v8::String::NewFromUtf8(isolate, "countryCode", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_support_phone_number_country_lst[i].countryCode).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "countryID", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_support_phone_number_country_lst[i].countryID).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		node->Set(context, v8::String::NewFromUtf8(isolate, "countryName", v8::NewStringType::kInternalized).ToLocalChecked(), v8::String::NewFromUtf8(isolate, zs2s(zn_support_phone_number_country_lst[i].countryName).c_str(), v8::NewStringType::kInternalized).ToLocalChecked());
		nodes->Set(context, i, node);
	}
	args.GetReturnValue().Set(nodes);
}
void ZoomNodeSDKSMSHelperWrap::SetNeedRealNameAuthMeetingNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onNeedRealNameAuthMeetingNotification.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onNeedRealNameAuthMeetingNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::SetRetrieveSMSVerificationCodeResultNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onRetrieveSMSVerificationCodeResultNotification.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			isolate->ThrowException(v8::Exception::TypeError(
				v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
			return;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onRetrieveSMSVerificationCodeResultNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::SetVerifySMSVerificationCodeResultNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		if (args.Length() < 1) {
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (args[0]->IsNull())		{			ZoomNodeSinkHelper::GetInst().onVerifySMSVerificationCodeResultNotification.Empty();			err = ZNSDKERR_INVALID_PARAMETER;
			break;		}
		if (!args[0]->IsFunction())
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}

		v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
		v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
		ZoomNodeSinkHelper::GetInst().onVerifySMSVerificationCodeResultNotification = cb;

	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::SetDefaultCellPhoneInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	bool err = false;
	do
	{
		com::electron::sdk::proto::SetDefaultCellPhoneInfoParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::SetDefaultCellPhoneInfoParams >(args, proto_params))
		{
			err = false;
			break;
		}
		if (!proto_params.has_countrycode() ||
			!proto_params.has_phonenum()
			)
		{
			err = false;
			break;
		}
		ZoomSTRING _zn_countryCode;
		_zn_countryCode = s2zs(proto_params.countrycode());
		ZoomSTRING _zn_phoneNum;
		_zn_phoneNum = s2zs(proto_params.phonenum());

		err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().SetDefaultCellPhoneInfo(_zn_countryCode, _zn_phoneNum);
	} while (false);
	
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}