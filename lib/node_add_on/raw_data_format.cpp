#include "raw_data_format.h"
#include "zoom_node_rawdata_helper_mgr_class.h"
#ifdef _WIN32
UVIPCMessage* MakeUVIPCMsg(YUVRawDataI420* data_, unsigned long long recv_handle, unsigned int type)
{
	bool b_RawdataIntermediateMode = ZoomNodeRawDataHelperMgr::GetInst().GetRawdataIntermediateMode();
	if (b_RawdataIntermediateMode)
	{
		if (NULL == data_)
			return NULL;

		IYUVRawDataI420Converter* yuv_data_converter = dynamic_cast<IYUVRawDataI420Converter*>(data_);
		if (NULL == yuv_data_converter)
			return NULL;
		unsigned int dataBufferLen = (data_->GetStreamWidth() * data_->GetStreamHeight() * 3) / 2;

		int ipc_msg_buffer_len = sizeof(VideoRawDataHeader) + dataBufferLen;//head+buffer
		UVIPCMessage* rawdata_msg = new UVIPCMessage(NULL, ipc_msg_buffer_len);
		if (NULL == rawdata_msg)
			return NULL;
		char* buf_ptr = rawdata_msg->GetBuf();
		YUVRawDataI420* filled_data = yuv_data_converter->ConvertToYUVViaExternalBuffer(buf_ptr + sizeof(VideoRawDataHeader), dataBufferLen);
		if (filled_data)
		{
			//fill header
			VideoRawDataHeader* head_ptr = (VideoRawDataHeader*)buf_ptr;
			head_ptr->common_header.type = type;
			head_ptr->recvHandle = recv_handle;
			head_ptr->dataBufferLen = filled_data->GetBufferLen();
			head_ptr->isLimitedI420 = filled_data->IsLimitedI420() ? 1 : 0;
			head_ptr->width = filled_data->GetStreamWidth();
			head_ptr->height = filled_data->GetStreamHeight();
			head_ptr->rotation = filled_data->GetRotation();
			head_ptr->y_offset = (unsigned long long)filled_data->GetYBuffer() - (unsigned long long)filled_data->GetBuffer();
			head_ptr->u_offset = (unsigned long long)filled_data->GetUBuffer() - (unsigned long long)filled_data->GetBuffer();
			head_ptr->v_offset = (unsigned long long)filled_data->GetVBuffer() - (unsigned long long)filled_data->GetBuffer();
			head_ptr->source_id = filled_data->GetSourceID();

			filled_data->Release();
		}
		return rawdata_msg;
	}
	else
	{
		if (NULL == data_)
			return NULL;

		unsigned int dataBufferLen = (data_->GetStreamWidth() * data_->GetStreamHeight() * 3) / 2;

		int ipc_msg_buffer_len = sizeof(VideoRawDataHeader) + dataBufferLen;//head+buffer
		UVIPCMessage* rawdata_msg = new UVIPCMessage(NULL, ipc_msg_buffer_len);
		if (NULL == rawdata_msg)
			return NULL;
		char* buf_ptr = rawdata_msg->GetBuf();

		char* data_buf = buf_ptr + sizeof(VideoRawDataHeader);


		VideoRawDataHeader* head_ptr = (VideoRawDataHeader*)buf_ptr;
		//copy Y data
		head_ptr->y_offset = 0;
		memcpy(data_buf, data_->GetYBuffer(), (data_->GetStreamWidth() * data_->GetStreamHeight()));
		//copy U data
		head_ptr->u_offset = (data_->GetStreamWidth() * data_->GetStreamHeight());
		memcpy(data_buf + head_ptr->u_offset, data_->GetUBuffer(), (data_->GetStreamWidth() * data_->GetStreamHeight()) / 4);
		//copy V data
		head_ptr->v_offset = head_ptr->u_offset + (data_->GetStreamWidth() * data_->GetStreamHeight()) / 4;
		memcpy(data_buf + head_ptr->v_offset, data_->GetVBuffer(), (data_->GetStreamWidth() * data_->GetStreamHeight()) / 4);

		head_ptr->common_header.type = type;
		head_ptr->recvHandle = recv_handle;
		head_ptr->dataBufferLen = data_->GetBufferLen();
		head_ptr->isLimitedI420 = data_->IsLimitedI420() ? 1 : 0;
		head_ptr->width = data_->GetStreamWidth();
		head_ptr->height = data_->GetStreamHeight();
		head_ptr->rotation = data_->GetRotation();
		head_ptr->source_id = data_->GetSourceID();

		return rawdata_msg;
	}
}

UVIPCMessage* MakeUVIPCMsg(AudioRawData* data_, unsigned int node_id_, unsigned int type)
{
	if (NULL == data_)
		return NULL;

	unsigned int dataBufferLen = data_->GetBufferLen();
	unsigned int sampleRate = data_->GetSampleRate();
	unsigned int channelNum = data_->GetChannelNum();

	int ipc_msg_buffer_len = sizeof(AudioRawDataHeader) + dataBufferLen;
	UVIPCMessage* rawdata_msg = new UVIPCMessage(NULL, ipc_msg_buffer_len);
	if (NULL == rawdata_msg)
		return NULL;

	char* buf_ptr = rawdata_msg->GetBuf();
	//fill header
	AudioRawDataHeader* head_ptr = (AudioRawDataHeader*)buf_ptr;
	head_ptr->common_header.type = type;
	head_ptr->node_id = node_id_;
	head_ptr->dataBufferLen = dataBufferLen;
	head_ptr->sampleRate = sampleRate;
	head_ptr->channelNum = channelNum;
	//fill buffer
	char* data_buf = buf_ptr + sizeof(AudioRawDataHeader);
	memcpy(data_buf, data_->GetBuffer(), dataBufferLen);
	return rawdata_msg;
}
#else
UVIPCMessage* MakeUVIPCMsg(ZoomNodeYUVRawdataI420* data_, unsigned long long recv_handle, unsigned int type)
{
	if (NULL == data_)
		return NULL;

	unsigned int dataBufferLen = (data_->streamWidth * data_->streamHeight * 3) / 2;

	int ipc_msg_buffer_len = sizeof(VideoRawDataHeader) + dataBufferLen;//head+buffer
	UVIPCMessage* rawdata_msg = new UVIPCMessage(NULL, ipc_msg_buffer_len);
	if (NULL == rawdata_msg)
		return NULL;
	char* buf_ptr = rawdata_msg->GetBuf();

	char* data_buf = buf_ptr + sizeof(VideoRawDataHeader);


	VideoRawDataHeader* head_ptr = (VideoRawDataHeader*)buf_ptr;
	//copy Y data
	head_ptr->y_offset = 0;
	memcpy(data_buf, data_->ybuff, (data_->streamWidth * data_->streamHeight));
	//copy U data
	head_ptr->u_offset = (data_->streamWidth * data_->streamHeight);
	memcpy(data_buf + head_ptr->u_offset, data_->ubuff, (data_->streamWidth * data_->streamHeight)/4);
	//copy V data
	head_ptr->v_offset = head_ptr->u_offset + (data_->streamWidth * data_->streamHeight)/4;
	memcpy(data_buf + head_ptr->v_offset, data_->vbuff, (data_->streamWidth * data_->streamHeight)/4);

	head_ptr->common_header.type = type;
	head_ptr->recvHandle = recv_handle;
	head_ptr->dataBufferLen = data_->dataBufferLen;
	head_ptr->isLimitedI420 = data_->isLimitedI420 ? 1 : 0;
	head_ptr->width = data_->streamWidth;
	head_ptr->height = data_->streamHeight;
	head_ptr->rotation = data_->rotation;
	head_ptr->source_id = data_->source_id;
	
	return rawdata_msg;
}
UVIPCMessage* MakeUVIPCMsg(ZoomNodeAudioRawdata* data_, unsigned int node_id_, unsigned int type)
{
	if (NULL == data_)
		return NULL;

	unsigned int dataBufferLen = data_->dataBufferLen;
	unsigned int sampleRate = data_->sampleRate;
	unsigned int channelNum = data_->channelNum;

	int ipc_msg_buffer_len = sizeof(AudioRawDataHeader) + dataBufferLen;
	UVIPCMessage* rawdata_msg = new UVIPCMessage(NULL, ipc_msg_buffer_len);
	if (NULL == rawdata_msg)
		return NULL;

	char* buf_ptr = rawdata_msg->GetBuf();
	//fill header
	AudioRawDataHeader* head_ptr = (AudioRawDataHeader*)buf_ptr;
	head_ptr->common_header.type = type;
	head_ptr->node_id = node_id_;
	head_ptr->dataBufferLen = dataBufferLen;
	head_ptr->sampleRate = sampleRate;
	head_ptr->channelNum = channelNum;
	//fill buffer
	char* data_buf = buf_ptr + sizeof(AudioRawDataHeader);
	memcpy(data_buf, data_->buff, dataBufferLen);

	return rawdata_msg;
}
#endif


