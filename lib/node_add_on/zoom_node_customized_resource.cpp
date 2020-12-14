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
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::AddCustomizedPictureResourceParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::AddCustomizedPictureResourceParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_strpngid() ||
			!proto_params.has_strpngpath()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZoomSTRING _zn_strPNGID;
		_zn_strPNGID = s2zs(proto_params.strpngid());
		ZoomSTRING _zn_strPNGPath;
		_zn_strPNGPath = s2zs(proto_params.strpngpath());

		err = _g_native_wrap.GetCustomizedResourceWrap().AddCustomizedPictureResource(_zn_strPNGID, _zn_strPNGPath);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeCustomizedResourceWrap::AddCustomizedStringResource(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::AddCustomizedStringResourceParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::AddCustomizedStringResourceParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_customizedstringtype() ||
			!proto_params.has_strcustomizedstring()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKCustomizedStringType _zn_type = (ZNSDKCustomizedStringType)proto_params.customizedstringtype();
		ZoomSTRING _zn_strCustomizedString;
		_zn_strCustomizedString = s2zs(proto_params.strcustomizedstring());

		err = _g_native_wrap.GetCustomizedResourceWrap().AddCustomizedStringResource(_zn_type, _zn_strCustomizedString);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}
void ZoomNodeCustomizedResourceWrap::AddCustomizedURLResource(const v8::FunctionCallbackInfo<v8::Value>& args)
{
	v8::Isolate* isolate = args.GetIsolate();
	ZNSDKError err = ZNSDKERR_SUCCESS;
	do
	{
		com::electron::sdk::proto::AddCustomizedURLResourceParams proto_params;
		if (!SetProtoParam<com::electron::sdk::proto::AddCustomizedURLResourceParams >(args, proto_params))
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		if (!proto_params.has_customizedurltype() ||
			!proto_params.has_strcustomizedurl()
			)
		{
			err = ZNSDKERR_INVALID_PARAMETER;
			break;
		}
		ZNSDKCustomizedURLType _zn_type = (ZNSDKCustomizedURLType)proto_params.customizedurltype();
		ZoomSTRING _zn_strCustomizeURL;
		_zn_strCustomizeURL = s2zs(proto_params.strcustomizedurl());

		err = _g_native_wrap.GetCustomizedResourceWrap().AddCustomizedURLResource(_zn_type, _zn_strCustomizeURL);
	} while (false);
	
	v8::Local<v8::Integer> bret = v8::Integer::New(isolate, (int32_t)err);
	args.GetReturnValue().Set(bret);
}