//Header
//This could go into separate header file defining interface:
#ifndef NATIVE_EXTENSION_GRAB_H
#define NATIVE_EXTENSION_GRAB_H

#include <nan.h>
#include <string>
#include <iostream>
#include <node.h>
#include <stdio.h>

/*
// Public interfaces of functions could be defined here
NAN_METHOD(int_in_int_out);
//...
*/

#endif

/* extern interface for Rust functions */
extern "C" {
  int32_t rs_mytest(int32_t input);
}


//Header end


using namespace std;
using namespace v8;

NAN_METHOD(mytest) {
  int value = info[0]->IsUndefined() ? 0 : Nan::To<int>(info[0]).FromJust();
  int out = rs_mytest(value);
  info.GetReturnValue().Set(out);
}

/* create V8 functions available in NodeJS */
using v8::FunctionTemplate;

NAN_MODULE_INIT(InitAll) {;
  Nan::Set(target, Nan::New("mytest").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(mytest)).ToLocalChecked());
}


NODE_MODULE(addon, InitAll)
