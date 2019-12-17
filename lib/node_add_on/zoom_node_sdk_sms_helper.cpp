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
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsBoolean())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	bool zn_enable;
	zoom_v8toc(args[0].As<v8::Boolean>(), zn_enable);

	bool err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().EnableZoomAuthRealNameMeetingUIShown(zn_enable);
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
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZoomSTRING zn_countryCode;
	zoom_v8toc(args[0].As<v8::String>(), zn_countryCode);
	ZoomSTRING zn_phoneNum;
	zoom_v8toc(args[1].As<v8::String>(), zn_phoneNum);

	bool err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().Retrieve(zn_countryCode, zn_phoneNum);
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
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString() ||
		!args[2]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZoomSTRING zn_countryCode;
	zoom_v8toc(args[0].As<v8::String>(), zn_countryCode);
	ZoomSTRING zn_phoneNum;
	zoom_v8toc(args[1].As<v8::String>(), zn_phoneNum);
	ZoomSTRING zn_verificationCode;
	zoom_v8toc(args[2].As<v8::String>(), zn_verificationCode);

	bool err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().Verify(zn_countryCode, zn_phoneNum, zn_verificationCode);
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
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onNeedRealNameAuthMeetingNotification.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onNeedRealNameAuthMeetingNotification = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::SetRetrieveSMSVerificationCodeResultNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onRetrieveSMSVerificationCodeResultNotification.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onRetrieveSMSVerificationCodeResultNotification = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::SetVerifySMSVerificationCodeResultNotificationCB(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 1) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	if (args[0]->IsNull())	{		ZoomNodeSinkHelper::GetInst().onVerifySMSVerificationCodeResultNotification.Empty();		return;	}
	if (!args[0]->IsFunction())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	v8::Local<v8::Function> cbfunc = v8::Local<v8::Function>::Cast(args[0]);
	v8::Persistent<v8::Function, v8::CopyablePersistentTraits<v8::Function> > cb(isolate, cbfunc);
	ZoomNodeSinkHelper::GetInst().onVerifySMSVerificationCodeResultNotification = cb;

	ZNSDKError err = ZNSDKERR_SUCCESS;
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeSDKSMSHelperWrap::SetDefaultCellPhoneInfo(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString())
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZoomSTRING zn_countryCode;
	zoom_v8toc(args[0].As<v8::String>(), zn_countryCode);
	ZoomSTRING zn_phoneNum;
	zoom_v8toc(args[1].As<v8::String>(), zn_phoneNum);

	bool err = _g_native_wrap.GetMeetingServiceWrap().GetSDKSMSHelper().SetDefaultCellPhoneInfo(zn_countryCode, zn_phoneNum);
	v8::Local<v8::Boolean> bret = v8::Boolean::New(isolate, err);
	args.GetReturnValue().Set(bret);
}