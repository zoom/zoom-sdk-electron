#include "zoom_node_customized_resource.h"


ZoomNodeCustomizedResourceWrap::ZoomNodeCustomizedResourceWrap()
{

}

ZoomNodeCustomizedResourceWrap::~ZoomNodeCustomizedResourceWrap()
{

}
void ZoomNodeCustomizedResourceWrap::AddCustomizedPictureResource(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsString() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}
	ZoomSTRING zn_strPNGID;
	zoom_v8toc(args[0].As<v8::String>(), zn_strPNGID);
	ZoomSTRING zn_strPNGPath;
	zoom_v8toc(args[1].As<v8::String>(), zn_strPNGPath);


	ZNSDKError err = _g_native_wrap.GetCustomizedResourceWrap().AddCustomizedPictureResource(zn_strPNGID, zn_strPNGPath);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeCustomizedResourceWrap::AddCustomizedStringResource(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNSDKCustomizedStringType zn_type = (ZNSDKCustomizedStringType)args[0].As<v8::Integer >()->Value();
	ZoomSTRING zn_strCustomizedString;
	zoom_v8toc(args[1].As<v8::String>(), zn_strCustomizedString);


	ZNSDKError err = _g_native_wrap.GetCustomizedResourceWrap().AddCustomizedStringResource(zn_type, zn_strCustomizedString);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeCustomizedResourceWrap::AddCustomizedURLResource(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	if (args.Length() < 2) {
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong number of arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	if (!args[0]->IsNumber() ||
		!args[1]->IsString()
		)
	{
		isolate->ThrowException(v8::Exception::TypeError(
			v8::String::NewFromUtf8(isolate, "Wrong arguments", v8::NewStringType::kInternalized).ToLocalChecked()));
		return;
	}

	ZNSDKCustomizedURLType zn_type = (ZNSDKCustomizedURLType)args[0].As<v8::Integer >()->Value();
	ZoomSTRING zn_strCustomizeURL;
	zoom_v8toc(args[1].As<v8::String>(), zn_strCustomizeURL);

	ZNSDKError err = _g_native_wrap.GetCustomizedResourceWrap().AddCustomizedURLResource(zn_type, zn_strCustomizeURL);
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}