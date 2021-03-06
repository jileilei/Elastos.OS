//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

//This file is autogenerated for
//    MediaCodecBridge.java
//put this file at the end of the include list
//so the type definition used in this file will be found
#ifndef ELASTOS_MEDIACODECBRIDGE_CALLBACK_DEC_HH
#define ELASTOS_MEDIACODECBRIDGE_CALLBACK_DEC_HH

#ifdef __cplusplus
extern "C"
{
#endif
    extern void Elastos_MediaCodecBridge_InitCallback(Handle32 cb);
#ifdef __cplusplus
}
#endif


namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Media {

struct ElaMediaCodecBridgeCallback
{
    Int32 (*elastos_DequeueInputResult_status)(IInterface* obj);
    Int32 (*elastos_DequeueInputResult_index)(IInterface* obj);
    String (*elastos_CodecInfo_codecType)(IInterface* obj);
    String (*elastos_CodecInfo_codecName)(IInterface* obj);
    Int32 (*elastos_CodecInfo_direction)(IInterface* obj);
    Int32 (*elastos_DequeueOutputResult_status)(IInterface* obj);
    Int32 (*elastos_DequeueOutputResult_index)(IInterface* obj);
    Int32 (*elastos_DequeueOutputResult_flags)(IInterface* obj);
    Int32 (*elastos_DequeueOutputResult_offset)(IInterface* obj);
    Int64 (*elastos_DequeueOutputResult_presentationTimeMicroseconds)(IInterface* obj);
    Int32 (*elastos_DequeueOutputResult_numBytes)(IInterface* obj);
    AutoPtr<ArrayOf<IInterface*> > (*elastos_MediaCodecBridge_getCodecsInfo)();
    AutoPtr<IInterface> (*elastos_MediaCodecBridge_create)(const String& mime, Boolean isSecure, Int32 direction);
    void (*elastos_MediaCodecBridge_release)(IInterface* obj);
    Boolean (*elastos_MediaCodecBridge_start)(IInterface* obj);
    AutoPtr<IInterface> (*elastos_MediaCodecBridge_dequeueInputBuffer)(IInterface* obj, Int64 timeoutUs);
    Int32 (*elastos_MediaCodecBridge_flush)(IInterface* obj);
    void (*elastos_MediaCodecBridge_stop)(IInterface* obj);
    Int32 (*elastos_MediaCodecBridge_getOutputHeight)(IInterface* obj);
    Int32 (*elastos_MediaCodecBridge_getOutputWidth)(IInterface* obj);
    AutoPtr<IInterface> (*elastos_MediaCodecBridge_getInputBuffer)(IInterface* obj, Int32 index);
    AutoPtr<IInterface> (*elastos_MediaCodecBridge_getOutputBuffer)(IInterface* obj, Int32 index);
    Int32 (*elastos_MediaCodecBridge_getInputBuffersCount)(IInterface* obj);
    Int32 (*elastos_MediaCodecBridge_getOutputBuffersCount)(IInterface* obj);
    Int32 (*elastos_MediaCodecBridge_getOutputBuffersCapacity)(IInterface* obj);
    Boolean (*elastos_MediaCodecBridge_getOutputBuffers)(IInterface* obj);
    Int32 (*elastos_MediaCodecBridge_queueInputBuffer)(IInterface* obj, Int32 index, Int32 offset, Int32 size, Int64 presentationTimeUs, Int32 flags);
    void (*elastos_MediaCodecBridge_setVideoBitrate)(IInterface* obj, Int32 bps);
    void (*elastos_MediaCodecBridge_requestKeyFrameSoon)(IInterface* obj);
    Int32 (*elastos_MediaCodecBridge_queueSecureInputBuffer)(IInterface* obj, Int32 index, Int32 offset, ArrayOf<Byte>* iv, ArrayOf<Byte>* keyId, ArrayOf<Int32>* numBytesOfClearData, ArrayOf<Int32>* numBytesOfEncryptedData, Int32 numSubSamples, Int64 presentationTimeUs);
    void (*elastos_MediaCodecBridge_releaseOutputBuffer)(IInterface* obj, Int32 index, Boolean render);
    AutoPtr<IInterface> (*elastos_MediaCodecBridge_dequeueOutputBuffer)(IInterface* obj, Int64 timeoutUs);
    Boolean (*elastos_MediaCodecBridge_configureVideo)(IInterface* obj, IInterface* format, IInterface* surface, IInterface* crypto, Int32 flags);
    AutoPtr<IInterface> (*elastos_MediaCodecBridge_createAudioFormat)(const String& mime, Int32 sampleRate, Int32 channelCount);
    AutoPtr<IInterface> (*elastos_MediaCodecBridge_createVideoDecoderFormat)(const String& mime, Int32 width, Int32 height);
    AutoPtr<IInterface> (*elastos_MediaCodecBridge_createVideoEncoderFormat)(const String& mime, Int32 width, Int32 height, Int32 bitRate, Int32 frameRate, Int32 iFrameInterval, Int32 colorFormat);
    Boolean (*elastos_MediaCodecBridge_isAdaptivePlaybackSupported)(IInterface* obj, Int32 width, Int32 height);
    void (*elastos_MediaCodecBridge_setCodecSpecificData)(IInterface* format, Int32 index, ArrayOf<Byte>* bytes);
    void (*elastos_MediaCodecBridge_setFrameHasADTSHeader)(IInterface* format);
    Boolean (*elastos_MediaCodecBridge_configureAudio)(IInterface* obj, IInterface* format, IInterface* crypto, Int32 flags, Boolean playAudio);
    Int64 (*elastos_MediaCodecBridge_playOutputBuffer)(IInterface* obj, ArrayOf<Byte>* buf);
    void (*elastos_MediaCodecBridge_setVolume)(IInterface* obj, Double volume);
};

void* MediaCodecBridge::ElaMediaCodecBridgeCallback_Init()
{
    static ElaMediaCodecBridgeCallback sElaMediaCodecBridgeCallback;

    sElaMediaCodecBridgeCallback.elastos_DequeueInputResult_status = &MediaCodecBridge::DequeueInputResult::Status;
    sElaMediaCodecBridgeCallback.elastos_DequeueInputResult_index = &MediaCodecBridge::DequeueInputResult::Index;
    sElaMediaCodecBridgeCallback.elastos_CodecInfo_codecType = &MediaCodecBridge::CodecInfo::CodecType;
    sElaMediaCodecBridgeCallback.elastos_CodecInfo_codecName = &MediaCodecBridge::CodecInfo::CodecName;
    sElaMediaCodecBridgeCallback.elastos_CodecInfo_direction = &MediaCodecBridge::CodecInfo::Direction;
    sElaMediaCodecBridgeCallback.elastos_DequeueOutputResult_status = &MediaCodecBridge::DequeueOutputResult::Status;
    sElaMediaCodecBridgeCallback.elastos_DequeueOutputResult_index = &MediaCodecBridge::DequeueOutputResult::Index;
    sElaMediaCodecBridgeCallback.elastos_DequeueOutputResult_flags = &MediaCodecBridge::DequeueOutputResult::Flags;
    sElaMediaCodecBridgeCallback.elastos_DequeueOutputResult_offset = &MediaCodecBridge::DequeueOutputResult::Offset;
    sElaMediaCodecBridgeCallback.elastos_DequeueOutputResult_presentationTimeMicroseconds = &MediaCodecBridge::DequeueOutputResult::PresentationTimeMicroseconds;
    sElaMediaCodecBridgeCallback.elastos_DequeueOutputResult_numBytes = &MediaCodecBridge::DequeueOutputResult::NumBytes;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_getCodecsInfo = &MediaCodecBridge::GetCodecsInfo;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_create = &MediaCodecBridge::Create;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_release = &MediaCodecBridge::ReleaseResource;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_start = &MediaCodecBridge::Start;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_dequeueInputBuffer = &MediaCodecBridge::DequeueInputBuffer;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_flush = &MediaCodecBridge::Flush;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_stop = &MediaCodecBridge::Stop;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_getOutputHeight = &MediaCodecBridge::GetOutputHeight;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_getOutputWidth = &MediaCodecBridge::GetOutputWidth;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_getInputBuffer = &MediaCodecBridge::GetInputBuffer;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_getOutputBuffer = &MediaCodecBridge::GetOutputBuffer;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_getInputBuffersCount = &MediaCodecBridge::GetInputBuffersCount;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_getOutputBuffersCount = &MediaCodecBridge::GetOutputBuffersCount;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_getOutputBuffersCapacity = &MediaCodecBridge::GetOutputBuffersCapacity;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_getOutputBuffers = &MediaCodecBridge::GetOutputBuffers;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_queueInputBuffer = &MediaCodecBridge::QueueInputBuffer;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_setVideoBitrate = &MediaCodecBridge::SetVideoBitrate;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_requestKeyFrameSoon = &MediaCodecBridge::RequestKeyFrameSoon;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_queueSecureInputBuffer = &MediaCodecBridge::QueueSecureInputBuffer;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_releaseOutputBuffer = &MediaCodecBridge::ReleaseOutputBuffer;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_dequeueOutputBuffer = &MediaCodecBridge::DequeueOutputBuffer;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_configureVideo = &MediaCodecBridge::ConfigureVideo;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_createAudioFormat = &MediaCodecBridge::CreateAudioFormat;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_createVideoDecoderFormat = &MediaCodecBridge::CreateVideoDecoderFormat;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_createVideoEncoderFormat = &MediaCodecBridge::CreateVideoEncoderFormat;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_isAdaptivePlaybackSupported = &MediaCodecBridge::IsAdaptivePlaybackSupported;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_setCodecSpecificData = &MediaCodecBridge::SetCodecSpecificData;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_setFrameHasADTSHeader = &MediaCodecBridge::SetFrameHasADTSHeader;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_configureAudio = &MediaCodecBridge::ConfigureAudio;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_playOutputBuffer = &MediaCodecBridge::PlayOutputBuffer;
    sElaMediaCodecBridgeCallback.elastos_MediaCodecBridge_setVolume = &MediaCodecBridge::SetVolume;

    Elastos_MediaCodecBridge_InitCallback((Handle32)&sElaMediaCodecBridgeCallback);
    return &sElaMediaCodecBridgeCallback;
}

static void* sPElaMediaCodecBridgeCallback = MediaCodecBridge::ElaMediaCodecBridgeCallback_Init();

} // namespace Media
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos

#endif //ELASTOS_MEDIACODECBRIDGE_CALLBACK_DEC_HH
