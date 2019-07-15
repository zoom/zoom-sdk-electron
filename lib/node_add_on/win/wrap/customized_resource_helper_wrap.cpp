#pragma once
#include "customized_resource_helper_wrap.h"
BEGIN_ZOOM_SDK_NAMESPACE
SDKError ICustomizedResourceHelperWrap::AddCustomizedPictureResource(const wchar_t* key_, const wchar_t* absolute_resource_path)
{
	if (key_ && absolute_resource_path)
	{
		cache_customized_pic_map.insert(std::make_pair(key_, absolute_resource_path));
	}
	return SDKERR_SUCCESS;
}
SDKError ICustomizedResourceHelperWrap::AddCustomizedStringResource(SDKCustomizedStringType customizedType, const wchar_t* customizedString)
{
	if (customizedString)
	{
		cache_customized_str_map.insert(std::make_pair(customizedType, customizedString));
	}
	return SDKERR_SUCCESS;
}

SDKError ICustomizedResourceHelperWrap::AddCustomizedURLResource(SDKCustomizedURLType customizedType, const wchar_t* customizedUrl)
{
	if (customizedType)
	{
		cache_customized_url_map.insert(std::make_pair(customizedType, customizedUrl));
	}
	return SDKERR_SUCCESS;
}

void ICustomizedResourceHelperWrap::ApplyAll()
{
	ZOOM_SDK_NAMESPACE::ICustomizedResourceHelper* pObj(NULL);
	CSDKImpl::GetInst().RetrieveCustomizedResourceHelper(&pObj);
	if (pObj)
	{
		{
			std::map<std::wstring, std::wstring>::iterator iter_pic = cache_customized_pic_map.begin();
			while (cache_customized_pic_map.end() != iter_pic)
			{
				pObj->AddCustomizedPictureResource(iter_pic->first.c_str(), iter_pic->second.c_str());
				++iter_pic;
			}
		}
		

		{
			std::map<SDKCustomizedStringType, std::wstring>::iterator iter_str = cache_customized_str_map.begin();
			while (cache_customized_str_map.end() != iter_str)
			{
				pObj->AddCustomizedStringResource(iter_str->first, iter_str->second.c_str());
				++iter_str;
			}
		}
		
		{
			std::map<SDKCustomizedURLType, std::wstring>::iterator iter_url = cache_customized_url_map.begin();
			while (cache_customized_url_map.end() != iter_url)
			{
				pObj->AddCustomizedURLResource(iter_url->first, iter_url->second.c_str());
				++iter_url;
			}
		}

		cache_customized_pic_map.clear();
		cache_customized_str_map.clear();
		cache_customized_url_map.clear();
	}
}
END_ZOOM_SDK_NAMESPACE

