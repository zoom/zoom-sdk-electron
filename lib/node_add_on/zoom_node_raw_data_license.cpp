#include "zoom_raw_data_wrap.h"
#include "zoom_node_raw_data_license.h"

ZoomNodeRawDataLicenseWrap::ZoomNodeRawDataLicenseWrap()
{

}

ZoomNodeRawDataLicenseWrap::~ZoomNodeRawDataLicenseWrap()
{

}

void ZoomNodeRawDataLicenseWrap::HasRawDataLicense(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	SDKRawDataError err = SDKRawDataError_UNINITIALIZED;
	err = Node_HasRawDataLicense();
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}



