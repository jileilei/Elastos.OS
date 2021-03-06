// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8Entry.h"

#include "bindings/core/v8/V8VoidCallback.h"
#include "bindings/modules/v8/V8DOMFileSystem.h"
#include "bindings/modules/v8/V8DirectoryEntry.h"
#include "bindings/modules/v8/V8EntryCallback.h"
#include "bindings/modules/v8/V8ErrorCallback.h"
#include "bindings/modules/v8/V8MetadataCallback.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(Entry* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8Entry::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::Entry* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8Entry::wrapperTypeInfo = { gin::kEmbedderBlink, V8Entry::domTemplate, V8Entry::derefObject, 0, 0, 0, V8Entry::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype, GarbageCollectedObject };

namespace EntryV8Internal {

template <typename T> void V8_USE(T) { }

static void isFileAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Entry* impl = V8Entry::toNative(holder);
    v8SetReturnValueBool(info, impl->isFile());
}

static void isFileAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    EntryV8Internal::isFileAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void isDirectoryAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Entry* impl = V8Entry::toNative(holder);
    v8SetReturnValueBool(info, impl->isDirectory());
}

static void isDirectoryAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    EntryV8Internal::isDirectoryAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void nameAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Entry* impl = V8Entry::toNative(holder);
    v8SetReturnValueString(info, impl->name(), info.GetIsolate());
}

static void nameAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    EntryV8Internal::nameAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void fullPathAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Entry* impl = V8Entry::toNative(holder);
    v8SetReturnValueString(info, impl->fullPath(), info.GetIsolate());
}

static void fullPathAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    EntryV8Internal::fullPathAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void filesystemAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Object> holder = info.Holder();
    Entry* impl = V8Entry::toNative(holder);
    RawPtr<DOMFileSystem> result(impl->filesystem());
    if (result && DOMDataStore::setReturnValueFromWrapper<V8DOMFileSystem>(info.GetReturnValue(), result.get()))
        return;
    v8::Handle<v8::Value> wrapper = toV8(result.get(), holder, info.GetIsolate());
    if (!wrapper.IsEmpty()) {
        V8HiddenValue::setHiddenValue(info.GetIsolate(), holder, v8AtomicString(info.GetIsolate(), "filesystem"), wrapper);
        v8SetReturnValue(info, wrapper);
    }
}

static void filesystemAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    EntryV8Internal::filesystemAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void getMetadataMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("getMetadata", "Entry", 1, info.Length(), info.GetIsolate());
        return;
    }
    Entry* impl = V8Entry::toNative(info.Holder());
    OwnPtr<MetadataCallback> successCallback;
    OwnPtr<ErrorCallback> errorCallback;
    {
        if (info.Length() <= 0 || !info[0]->IsFunction()) {
            throwTypeError(ExceptionMessages::failedToExecute("getMetadata", "Entry", "The callback provided as parameter 1 is not a function."), info.GetIsolate());
            return;
        }
        successCallback = V8MetadataCallback::create(v8::Handle<v8::Function>::Cast(info[0]), ScriptState::current(info.GetIsolate()));
        if (info.Length() > 1 && !isUndefinedOrNull(info[1])) {
            if (!info[1]->IsFunction()) {
                throwTypeError(ExceptionMessages::failedToExecute("getMetadata", "Entry", "The callback provided as parameter 2 is not a function."), info.GetIsolate());
                return;
            }
            errorCallback = V8ErrorCallback::create(v8::Handle<v8::Function>::Cast(info[1]), ScriptState::current(info.GetIsolate()));
        }
    }
    impl->getMetadata(successCallback.release(), errorCallback.release());
}

static void getMetadataMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    EntryV8Internal::getMetadataMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void moveToMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("moveTo", "Entry", 1, info.Length(), info.GetIsolate());
        return;
    }
    Entry* impl = V8Entry::toNative(info.Holder());
    DirectoryEntry* parent;
    V8StringResource<WithUndefinedOrNullCheck> name;
    OwnPtr<EntryCallback> successCallback;
    OwnPtr<ErrorCallback> errorCallback;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(parent, V8DirectoryEntry::toNativeWithTypeCheck(info.GetIsolate(), info[0]));
        if (UNLIKELY(info.Length() <= 1)) {
            impl->moveTo(parent);
            return;
        }
        TOSTRING_VOID_INTERNAL(name, info[1]);
        if (info.Length() > 2 && !isUndefinedOrNull(info[2])) {
            if (!info[2]->IsFunction()) {
                throwTypeError(ExceptionMessages::failedToExecute("moveTo", "Entry", "The callback provided as parameter 3 is not a function."), info.GetIsolate());
                return;
            }
            successCallback = V8EntryCallback::create(v8::Handle<v8::Function>::Cast(info[2]), ScriptState::current(info.GetIsolate()));
        }
        if (info.Length() > 3 && !isUndefinedOrNull(info[3])) {
            if (!info[3]->IsFunction()) {
                throwTypeError(ExceptionMessages::failedToExecute("moveTo", "Entry", "The callback provided as parameter 4 is not a function."), info.GetIsolate());
                return;
            }
            errorCallback = V8ErrorCallback::create(v8::Handle<v8::Function>::Cast(info[3]), ScriptState::current(info.GetIsolate()));
        }
    }
    impl->moveTo(parent, name, successCallback.release(), errorCallback.release());
}

static void moveToMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    EntryV8Internal::moveToMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void copyToMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("copyTo", "Entry", 1, info.Length(), info.GetIsolate());
        return;
    }
    Entry* impl = V8Entry::toNative(info.Holder());
    DirectoryEntry* parent;
    V8StringResource<WithUndefinedOrNullCheck> name;
    OwnPtr<EntryCallback> successCallback;
    OwnPtr<ErrorCallback> errorCallback;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TONATIVE_VOID_INTERNAL(parent, V8DirectoryEntry::toNativeWithTypeCheck(info.GetIsolate(), info[0]));
        if (UNLIKELY(info.Length() <= 1)) {
            impl->copyTo(parent);
            return;
        }
        TOSTRING_VOID_INTERNAL(name, info[1]);
        if (info.Length() > 2 && !isUndefinedOrNull(info[2])) {
            if (!info[2]->IsFunction()) {
                throwTypeError(ExceptionMessages::failedToExecute("copyTo", "Entry", "The callback provided as parameter 3 is not a function."), info.GetIsolate());
                return;
            }
            successCallback = V8EntryCallback::create(v8::Handle<v8::Function>::Cast(info[2]), ScriptState::current(info.GetIsolate()));
        }
        if (info.Length() > 3 && !isUndefinedOrNull(info[3])) {
            if (!info[3]->IsFunction()) {
                throwTypeError(ExceptionMessages::failedToExecute("copyTo", "Entry", "The callback provided as parameter 4 is not a function."), info.GetIsolate());
                return;
            }
            errorCallback = V8ErrorCallback::create(v8::Handle<v8::Function>::Cast(info[3]), ScriptState::current(info.GetIsolate()));
        }
    }
    impl->copyTo(parent, name, successCallback.release(), errorCallback.release());
}

static void copyToMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    EntryV8Internal::copyToMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void toURLMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    Entry* impl = V8Entry::toNative(info.Holder());
    v8SetReturnValueString(info, impl->toURL(), info.GetIsolate());
}

static void toURLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    EntryV8Internal::toURLMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void removeMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeErrorForMethod("remove", "Entry", 1, info.Length(), info.GetIsolate());
        return;
    }
    Entry* impl = V8Entry::toNative(info.Holder());
    OwnPtr<VoidCallback> successCallback;
    OwnPtr<ErrorCallback> errorCallback;
    {
        if (info.Length() <= 0 || !info[0]->IsFunction()) {
            throwTypeError(ExceptionMessages::failedToExecute("remove", "Entry", "The callback provided as parameter 1 is not a function."), info.GetIsolate());
            return;
        }
        successCallback = V8VoidCallback::create(v8::Handle<v8::Function>::Cast(info[0]), ScriptState::current(info.GetIsolate()));
        if (info.Length() > 1 && !isUndefinedOrNull(info[1])) {
            if (!info[1]->IsFunction()) {
                throwTypeError(ExceptionMessages::failedToExecute("remove", "Entry", "The callback provided as parameter 2 is not a function."), info.GetIsolate());
                return;
            }
            errorCallback = V8ErrorCallback::create(v8::Handle<v8::Function>::Cast(info[1]), ScriptState::current(info.GetIsolate()));
        }
    }
    impl->remove(successCallback.release(), errorCallback.release());
}

static void removeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    EntryV8Internal::removeMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void getParentMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    Entry* impl = V8Entry::toNative(info.Holder());
    OwnPtr<EntryCallback> successCallback;
    OwnPtr<ErrorCallback> errorCallback;
    {
        if (info.Length() > 0 && !isUndefinedOrNull(info[0])) {
            if (!info[0]->IsFunction()) {
                throwTypeError(ExceptionMessages::failedToExecute("getParent", "Entry", "The callback provided as parameter 1 is not a function."), info.GetIsolate());
                return;
            }
            successCallback = V8EntryCallback::create(v8::Handle<v8::Function>::Cast(info[0]), ScriptState::current(info.GetIsolate()));
        }
        if (info.Length() > 1 && !isUndefinedOrNull(info[1])) {
            if (!info[1]->IsFunction()) {
                throwTypeError(ExceptionMessages::failedToExecute("getParent", "Entry", "The callback provided as parameter 2 is not a function."), info.GetIsolate());
                return;
            }
            errorCallback = V8ErrorCallback::create(v8::Handle<v8::Function>::Cast(info[1]), ScriptState::current(info.GetIsolate()));
        }
    }
    impl->getParent(successCallback.release(), errorCallback.release());
}

static void getParentMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    EntryV8Internal::getParentMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace EntryV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8EntryAttributes[] = {
    {"isFile", EntryV8Internal::isFileAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"isDirectory", EntryV8Internal::isDirectoryAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"name", EntryV8Internal::nameAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"fullPath", EntryV8Internal::fullPathAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"filesystem", EntryV8Internal::filesystemAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static const V8DOMConfiguration::MethodConfiguration V8EntryMethods[] = {
    {"getMetadata", EntryV8Internal::getMetadataMethodCallback, 0, 1},
    {"moveTo", EntryV8Internal::moveToMethodCallback, 0, 1},
    {"copyTo", EntryV8Internal::copyToMethodCallback, 0, 1},
    {"toURL", EntryV8Internal::toURLMethodCallback, 0, 0},
    {"remove", EntryV8Internal::removeMethodCallback, 0, 1},
    {"getParent", EntryV8Internal::getParentMethodCallback, 0, 0},
};

static void configureV8EntryTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "Entry", v8::Local<v8::FunctionTemplate>(), V8Entry::internalFieldCount,
        V8EntryAttributes, WTF_ARRAY_LENGTH(V8EntryAttributes),
        0, 0,
        V8EntryMethods, WTF_ARRAY_LENGTH(V8EntryMethods),
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8Entry::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8EntryTemplate);
}

bool V8Entry::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8Entry::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

Entry* V8Entry::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

v8::Handle<v8::Object> V8Entry::createWrapper(RawPtr<Entry> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8Entry>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::fromObject(impl.get())->typeInfo();
        // Might be a XXXConstructor::wrapperTypeInfo instead of an XXX::wrapperTypeInfo. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == wrapperTypeInfo.derefObjectFunction);
    }

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextEnabledProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8Entry>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8Entry::derefObject(void* object)
{
}

template<>
v8::Handle<v8::Value> toV8NoInline(Entry* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore
