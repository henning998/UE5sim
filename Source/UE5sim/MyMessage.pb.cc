#include "CoreMinimal.h"
THIRD_PARTY_INCLUDES_START
// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MyMessage.proto

#include "MyMessage.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR MyMessage::MyMessage(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.mystring_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.mynumber_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct MyMessageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR MyMessageDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~MyMessageDefaultTypeInternal() {}
  union {
    MyMessage _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 MyMessageDefaultTypeInternal _MyMessage_default_instance_;
static ::_pb::Metadata file_level_metadata_MyMessage_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_MyMessage_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_MyMessage_2eproto = nullptr;

const uint32_t TableStruct_MyMessage_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::MyMessage, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::MyMessage, _impl_.mynumber_),
  PROTOBUF_FIELD_OFFSET(::MyMessage, _impl_.mystring_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::MyMessage)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_MyMessage_default_instance_._instance,
};

const char descriptor_table_protodef_MyMessage_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017MyMessage.proto\"/\n\tMyMessage\022\020\n\010mynumb"
  "er\030\001 \001(\005\022\020\n\010mystring\030\002 \001(\tb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_MyMessage_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_MyMessage_2eproto = {
    false, false, 74, descriptor_table_protodef_MyMessage_2eproto,
    "MyMessage.proto",
    &descriptor_table_MyMessage_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_MyMessage_2eproto::offsets,
    file_level_metadata_MyMessage_2eproto, file_level_enum_descriptors_MyMessage_2eproto,
    file_level_service_descriptors_MyMessage_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_MyMessage_2eproto_getter() {
  return &descriptor_table_MyMessage_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_MyMessage_2eproto(&descriptor_table_MyMessage_2eproto);

// ===================================================================

class MyMessage::_Internal {
 public:
};

MyMessage::MyMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:MyMessage)
}
MyMessage::MyMessage(const MyMessage& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  MyMessage* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.mystring_){}
    , decltype(_impl_.mynumber_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.mystring_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.mystring_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_mystring().empty()) {
    _this->_impl_.mystring_.Set(from._internal_mystring(), 
      _this->GetArenaForAllocation());
  }
  _this->_impl_.mynumber_ = from._impl_.mynumber_;
  // @@protoc_insertion_point(copy_constructor:MyMessage)
}

inline void MyMessage::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.mystring_){}
    , decltype(_impl_.mynumber_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.mystring_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.mystring_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

MyMessage::~MyMessage() {
  // @@protoc_insertion_point(destructor:MyMessage)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void MyMessage::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.mystring_.Destroy();
}

void MyMessage::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void MyMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:MyMessage)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.mystring_.ClearToEmpty();
  _impl_.mynumber_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* MyMessage::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 mynumber = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.mynumber_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string mystring = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_mystring();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "MyMessage.mystring"));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* MyMessage::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:MyMessage)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 mynumber = 1;
  if (this->_internal_mynumber() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_mynumber(), target);
  }

  // string mystring = 2;
  if (!this->_internal_mystring().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_mystring().data(), static_cast<int>(this->_internal_mystring().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "MyMessage.mystring");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_mystring(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:MyMessage)
  return target;
}

size_t MyMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:MyMessage)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string mystring = 2;
  if (!this->_internal_mystring().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_mystring());
  }

  // int32 mynumber = 1;
  if (this->_internal_mynumber() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_mynumber());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData MyMessage::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    MyMessage::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*MyMessage::GetClassData() const { return &_class_data_; }


void MyMessage::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<MyMessage*>(&to_msg);
  auto& from = static_cast<const MyMessage&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:MyMessage)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_mystring().empty()) {
    _this->_internal_set_mystring(from._internal_mystring());
  }
  if (from._internal_mynumber() != 0) {
    _this->_internal_set_mynumber(from._internal_mynumber());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void MyMessage::CopyFrom(const MyMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:MyMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MyMessage::IsInitialized() const {
  return true;
}

void MyMessage::InternalSwap(MyMessage* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.mystring_, lhs_arena,
      &other->_impl_.mystring_, rhs_arena
  );
  swap(_impl_.mynumber_, other->_impl_.mynumber_);
}

::PROTOBUF_NAMESPACE_ID::Metadata MyMessage::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_MyMessage_2eproto_getter, &descriptor_table_MyMessage_2eproto_once,
      file_level_metadata_MyMessage_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::MyMessage*
Arena::CreateMaybeMessage< ::MyMessage >(Arena* arena) {
  return Arena::CreateMessageInternal< ::MyMessage >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
