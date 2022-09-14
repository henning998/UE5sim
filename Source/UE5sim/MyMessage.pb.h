// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MyMessage.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_MyMessage_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_MyMessage_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_MyMessage_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_MyMessage_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_MyMessage_2eproto;
class MyMessage;
struct MyMessageDefaultTypeInternal;
extern MyMessageDefaultTypeInternal _MyMessage_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::MyMessage* Arena::CreateMaybeMessage<::MyMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class MyMessage final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:MyMessage) */ {
 public:
  inline MyMessage() : MyMessage(nullptr) {}
  ~MyMessage() override;
  explicit PROTOBUF_CONSTEXPR MyMessage(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  MyMessage(const MyMessage& from);
  MyMessage(MyMessage&& from) noexcept
    : MyMessage() {
    *this = ::std::move(from);
  }

  inline MyMessage& operator=(const MyMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline MyMessage& operator=(MyMessage&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MyMessage& default_instance() {
    return *internal_default_instance();
  }
  static inline const MyMessage* internal_default_instance() {
    return reinterpret_cast<const MyMessage*>(
               &_MyMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(MyMessage& a, MyMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(MyMessage* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MyMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MyMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<MyMessage>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const MyMessage& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const MyMessage& from) {
    MyMessage::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(MyMessage* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "MyMessage";
  }
  protected:
  explicit MyMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMystringFieldNumber = 2,
    kMynumberFieldNumber = 1,
  };
  // string mystring = 2;
  void clear_mystring();
  const std::string& mystring() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_mystring(ArgT0&& arg0, ArgT... args);
  std::string* mutable_mystring();
  PROTOBUF_NODISCARD std::string* release_mystring();
  void set_allocated_mystring(std::string* mystring);
  private:
  const std::string& _internal_mystring() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_mystring(const std::string& value);
  std::string* _internal_mutable_mystring();
  public:

  // int32 mynumber = 1;
  void clear_mynumber();
  int32_t mynumber() const;
  void set_mynumber(int32_t value);
  private:
  int32_t _internal_mynumber() const;
  void _internal_set_mynumber(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:MyMessage)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr mystring_;
    int32_t mynumber_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_MyMessage_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// MyMessage

// int32 mynumber = 1;
inline void MyMessage::clear_mynumber() {
  _impl_.mynumber_ = 0;
}
inline int32_t MyMessage::_internal_mynumber() const {
  return _impl_.mynumber_;
}
inline int32_t MyMessage::mynumber() const {
  // @@protoc_insertion_point(field_get:MyMessage.mynumber)
  return _internal_mynumber();
}
inline void MyMessage::_internal_set_mynumber(int32_t value) {
  
  _impl_.mynumber_ = value;
}
inline void MyMessage::set_mynumber(int32_t value) {
  _internal_set_mynumber(value);
  // @@protoc_insertion_point(field_set:MyMessage.mynumber)
}

// string mystring = 2;
inline void MyMessage::clear_mystring() {
  _impl_.mystring_.ClearToEmpty();
}
inline const std::string& MyMessage::mystring() const {
  // @@protoc_insertion_point(field_get:MyMessage.mystring)
  return _internal_mystring();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void MyMessage::set_mystring(ArgT0&& arg0, ArgT... args) {
 
 _impl_.mystring_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:MyMessage.mystring)
}
inline std::string* MyMessage::mutable_mystring() {
  std::string* _s = _internal_mutable_mystring();
  // @@protoc_insertion_point(field_mutable:MyMessage.mystring)
  return _s;
}
inline const std::string& MyMessage::_internal_mystring() const {
  return _impl_.mystring_.Get();
}
inline void MyMessage::_internal_set_mystring(const std::string& value) {
  
  _impl_.mystring_.Set(value, GetArenaForAllocation());
}
inline std::string* MyMessage::_internal_mutable_mystring() {
  
  return _impl_.mystring_.Mutable(GetArenaForAllocation());
}
inline std::string* MyMessage::release_mystring() {
  // @@protoc_insertion_point(field_release:MyMessage.mystring)
  return _impl_.mystring_.Release();
}
inline void MyMessage::set_allocated_mystring(std::string* mystring) {
  if (mystring != nullptr) {
    
  } else {
    
  }
  _impl_.mystring_.SetAllocated(mystring, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.mystring_.IsDefault()) {
    _impl_.mystring_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:MyMessage.mystring)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_MyMessage_2eproto
