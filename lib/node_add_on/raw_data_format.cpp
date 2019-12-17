#include "raw_data_format.h"
UVIPCMessage* MakeUVIPCMsg(YUVRawDataI420* data_, IVector<unsigned long long >* recv_handle_list, unsigned int type)
{
	if (NULL == data_ || NULL == recv_handle_list)
		return NULL;

	IYUVRawDataI420Converter* yuv_data_converter = dynamic_cast<IYUVRawDataI420Converter*>(data_);
	if (NULL == yuv_data_converter)
		return NULL;
	unsigned int dataBufferLen = (data_->GetStreamWidth()*data_->GetStreamHeight()*3)/2;
	unsigned int recvHandleListCount = recv_handle_list->GetCount();
    unsigned int recvHandleBufLen = recvHandleListCount * sizeof(unsigned long long);
	int ipc_msg_buffer_len = sizeof(VideoRawDataHeader) + recvHandleBufLen + dataBufferLen;//head+recv_list+buffer
	UVIPCMessage* rawdata_msg = new UVIPCMessage(NULL, ipc_msg_buffer_len);
	if (NULL == rawdata_msg)
		return NULL;
	char* buf_ptr = rawdata_msg->GetBuf();
	YUVRawDataI420* filled_data = yuv_data_converter->ConvertToYUVViaExternalBuffer(buf_ptr + sizeof(VideoRawDataHeader) + recvHandleBufLen, dataBufferLen);
	if (filled_data)
	{
		//fill header
		VideoRawDataHeader* head_ptr = (VideoRawDataHeader*)buf_ptr;
		head_ptr->common_header.type = type;
		head_ptr->dataBufferLen = filled_data->GetBufferLen();
		head_ptr->recvHandleListCount = recv_handle_list->GetCount();
		head_ptr->isLimitedI420 = filled_data->IsLimitedI420() ? 1 : 0;
		head_ptr->width = filled_data->GetStreamWidth();
		head_ptr->height = filled_data->GetStreamHeight();
		head_ptr->rotation = filled_data->GetRotation();
		head_ptr->y_offset = (unsigned long long)filled_data->GetYBuffer() - (unsigned long long)filled_data->GetBuffer();
		head_ptr->u_offset = (unsigned long long)filled_data->GetUBuffer() - (unsigned long long)filled_data->GetBuffer();
		head_ptr->v_offset = (unsigned long long)filled_data->GetVBuffer() - (unsigned long long)filled_data->GetBuffer();
		head_ptr->source_id = filled_data->GetSourceID();
		//fill recv list
		unsigned long long* recv_list_buf_ptr = (unsigned long long*)(buf_ptr + sizeof(VideoRawDataHeader));
		for (int index = 0; index < recv_handle_list->GetCount(); ++index)
		{
			recv_list_buf_ptr[index] = recv_handle_list->GetItem(index);
		}
		filled_data->Release();
	}
	return rawdata_msg;
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

