// hello.cc
#include <node.h>
#include <iostream>
#include <Windows.h>

namespace demo {

using v8::Context;
using v8::Exception;
using v8::Function;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::NewStringType;
using v8::Null;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;

void GetWindowRect(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	if (args.Length() < 1) {
		// Throw an Error that is passed back to JavaScript
		isolate->ThrowException(Exception::TypeError(
			String::NewFromUtf8(isolate,
				"Wrong number of arguments",
				NewStringType::kNormal).ToLocalChecked()));
		return;
	}
	int hwnd = args[0].As<Number>()->Value();
	// std::cout << "arg : [" << hwnd << "] " << std::endl;
	RECT rect;
	GetWindowRect((HWND)hwnd, (LPRECT)&rect);
	// std::cout << "(" << hwnd << ")  left:" << rect.left << ", top:" << rect.top << ", right:" << rect.right << ", bottom:" << rect.bottom << std::endl;
		
	Local<Number> left = Number::New(isolate, rect.left);
	Local<Number> top = Number::New(isolate, rect.top);
	Local<Number> right = Number::New(isolate, rect.right);
	Local<Number> bottom = Number::New(isolate, rect.bottom);

	Local<Object> obj = Object::New(isolate);
	obj->Set(context, String::NewFromUtf8(isolate, "left", NewStringType::kNormal).ToLocalChecked(), left).FromJust();
	obj->Set(context, String::NewFromUtf8(isolate, "top", NewStringType::kNormal).ToLocalChecked(), top).FromJust();
	obj->Set(context, String::NewFromUtf8(isolate, "right", NewStringType::kNormal).ToLocalChecked(), right).FromJust();
	obj->Set(context, String::NewFromUtf8(isolate, "bottom", NewStringType::kNormal).ToLocalChecked(), bottom).FromJust();

	args.GetReturnValue().Set(obj);
}
void init(Local<Object> exports) {
	NODE_SET_METHOD(exports, "getWindowRect", GetWindowRect);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo