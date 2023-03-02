// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_arena.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include <google/protobuf/unittest_arena.pb.h>

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace proto2_arena_unittest {

namespace {

const ::google::protobuf::Descriptor* NestedMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  NestedMessage_reflection_ = NULL;
const ::google::protobuf::Descriptor* ArenaMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ArenaMessage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_google_2fprotobuf_2funittest_5farena_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_google_2fprotobuf_2funittest_5farena_2eproto() {
  protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "google/protobuf/unittest_arena.proto");
  GOOGLE_CHECK(file != NULL);
  NestedMessage_descriptor_ = file->message_type(0);
  static const int NestedMessage_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NestedMessage, d_),
  };
  NestedMessage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      NestedMessage_descriptor_,
      NestedMessage::internal_default_instance(),
      NestedMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NestedMessage, _has_bits_),
      -1,
      -1,
      sizeof(NestedMessage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NestedMessage, _internal_metadata_));
  ArenaMessage_descriptor_ = file->message_type(1);
  static const int ArenaMessage_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaMessage, repeated_nested_message_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaMessage, repeated_import_no_arena_message_),
  };
  ArenaMessage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      ArenaMessage_descriptor_,
      ArenaMessage::internal_default_instance(),
      ArenaMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaMessage, _has_bits_),
      -1,
      -1,
      sizeof(ArenaMessage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaMessage, _internal_metadata_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_google_2fprotobuf_2funittest_5farena_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      NestedMessage_descriptor_, NestedMessage::internal_default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      ArenaMessage_descriptor_, ArenaMessage::internal_default_instance());
}

}  // namespace

void protobuf_ShutdownFile_google_2fprotobuf_2funittest_5farena_2eproto() {
  NestedMessage_default_instance_.Shutdown();
  delete NestedMessage_reflection_;
  ArenaMessage_default_instance_.Shutdown();
  delete ArenaMessage_reflection_;
}

void protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::proto2_arena_unittest::protobuf_InitDefaults_google_2fprotobuf_2funittest_5fno_5farena_5fimport_2eproto();
  NestedMessage_default_instance_.DefaultConstruct();
  ArenaMessage_default_instance_.DefaultConstruct();
  NestedMessage_default_instance_.get_mutable()->InitAsDefaultInstance();
  ArenaMessage_default_instance_.get_mutable()->InitAsDefaultInstance();
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto_once_);
void protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto_once_,
                 &protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto_impl);
}
void protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n$google/protobuf/unittest_arena.proto\022\025"
    "proto2_arena_unittest\032.google/protobuf/u"
    "nittest_no_arena_import.proto\"\032\n\rNestedM"
    "essage\022\t\n\001d\030\001 \001(\005\"\262\001\n\014ArenaMessage\022E\n\027re"
    "peated_nested_message\030\001 \003(\0132$.proto2_are"
    "na_unittest.NestedMessage\022[\n repeated_im"
    "port_no_arena_message\030\002 \003(\01321.proto2_are"
    "na_unittest.ImportNoArenaNestedMessageB\003"
    "\370\001\001", 323);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "google/protobuf/unittest_arena.proto", &protobuf_RegisterTypes);
  ::proto2_arena_unittest::protobuf_AddDesc_google_2fprotobuf_2funittest_5fno_5farena_5fimport_2eproto();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_google_2fprotobuf_2funittest_5farena_2eproto);
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto_once_);
void protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto_once_,
                 &protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto_impl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_google_2fprotobuf_2funittest_5farena_2eproto {
  StaticDescriptorInitializer_google_2fprotobuf_2funittest_5farena_2eproto() {
    protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto();
  }
} static_descriptor_initializer_google_2fprotobuf_2funittest_5farena_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD GOOGLE_ATTRIBUTE_NORETURN;
static void MergeFromFail(int line) {
  ::google::protobuf::internal::MergeFromFail(__FILE__, line);
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int NestedMessage::kDFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

NestedMessage::NestedMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto2_arena_unittest.NestedMessage)
}
NestedMessage::NestedMessage(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena) {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto();
#endif  // GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:proto2_arena_unittest.NestedMessage)
}

void NestedMessage::InitAsDefaultInstance() {
}

NestedMessage::NestedMessage(const NestedMessage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:proto2_arena_unittest.NestedMessage)
}

void NestedMessage::SharedCtor() {
  _cached_size_ = 0;
  d_ = 0;
}

NestedMessage::~NestedMessage() {
  // @@protoc_insertion_point(destructor:proto2_arena_unittest.NestedMessage)
  SharedDtor();
}

void NestedMessage::SharedDtor() {
  ::google::protobuf::Arena* arena = GetArenaNoVirtual();
  if (arena != NULL) {
    return;
  }

}

void NestedMessage::ArenaDtor(void* object) {
  NestedMessage* _this = reinterpret_cast< NestedMessage* >(object);
  (void)_this;
}
void NestedMessage::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void NestedMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NestedMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return NestedMessage_descriptor_;
}

const NestedMessage& NestedMessage::default_instance() {
  protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<NestedMessage> NestedMessage_default_instance_;

NestedMessage* NestedMessage::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<NestedMessage>(arena);
}

void NestedMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:proto2_arena_unittest.NestedMessage)
  d_ = 0;
  _has_bits_.Clear();
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool NestedMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto2_arena_unittest.NestedMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 d = 1;
      case 1: {
        if (tag == 8) {
          set_has_d();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &d_)));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto2_arena_unittest.NestedMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto2_arena_unittest.NestedMessage)
  return false;
#undef DO_
}

void NestedMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto2_arena_unittest.NestedMessage)
  // optional int32 d = 1;
  if (has_d()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->d(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:proto2_arena_unittest.NestedMessage)
}

::google::protobuf::uint8* NestedMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:proto2_arena_unittest.NestedMessage)
  // optional int32 d = 1;
  if (has_d()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->d(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto2_arena_unittest.NestedMessage)
  return target;
}

size_t NestedMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto2_arena_unittest.NestedMessage)
  size_t total_size = 0;

  // optional int32 d = 1;
  if (has_d()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->d());
  }

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void NestedMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:proto2_arena_unittest.NestedMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const NestedMessage* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const NestedMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:proto2_arena_unittest.NestedMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:proto2_arena_unittest.NestedMessage)
    UnsafeMergeFrom(*source);
  }
}

void NestedMessage::MergeFrom(const NestedMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto2_arena_unittest.NestedMessage)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void NestedMessage::UnsafeMergeFrom(const NestedMessage& from) {
  GOOGLE_DCHECK(&from != this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_d()) {
      set_d(from.d());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::UnknownFieldSet::MergeToInternalMetdata(
      from.unknown_fields(), &_internal_metadata_);
  }
}

void NestedMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:proto2_arena_unittest.NestedMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NestedMessage::CopyFrom(const NestedMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto2_arena_unittest.NestedMessage)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool NestedMessage::IsInitialized() const {

  return true;
}

void NestedMessage::Swap(NestedMessage* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    NestedMessage temp;
    temp.UnsafeMergeFrom(*this);
    CopyFrom(*other);
    other->CopyFrom(temp);
  }
}
void NestedMessage::UnsafeArenaSwap(NestedMessage* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void NestedMessage::InternalSwap(NestedMessage* other) {
  std::swap(d_, other->d_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata NestedMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = NestedMessage_descriptor_;
  metadata.reflection = NestedMessage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// NestedMessage

// optional int32 d = 1;
bool NestedMessage::has_d() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void NestedMessage::set_has_d() {
  _has_bits_[0] |= 0x00000001u;
}
void NestedMessage::clear_has_d() {
  _has_bits_[0] &= ~0x00000001u;
}
void NestedMessage::clear_d() {
  d_ = 0;
  clear_has_d();
}
::google::protobuf::int32 NestedMessage::d() const {
  // @@protoc_insertion_point(field_get:proto2_arena_unittest.NestedMessage.d)
  return d_;
}
void NestedMessage::set_d(::google::protobuf::int32 value) {
  set_has_d();
  d_ = value;
  // @@protoc_insertion_point(field_set:proto2_arena_unittest.NestedMessage.d)
}

inline const NestedMessage* NestedMessage::internal_default_instance() {
  return &NestedMessage_default_instance_.get();
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ArenaMessage::kRepeatedNestedMessageFieldNumber;
const int ArenaMessage::kRepeatedImportNoArenaMessageFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ArenaMessage::ArenaMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto2_arena_unittest.ArenaMessage)
}
ArenaMessage::ArenaMessage(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena),
  repeated_nested_message_(arena),
  repeated_import_no_arena_message_(arena) {
#ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto();
#endif  // GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:proto2_arena_unittest.ArenaMessage)
}

void ArenaMessage::InitAsDefaultInstance() {
}

ArenaMessage::ArenaMessage(const ArenaMessage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:proto2_arena_unittest.ArenaMessage)
}

void ArenaMessage::SharedCtor() {
  _cached_size_ = 0;
}

ArenaMessage::~ArenaMessage() {
  // @@protoc_insertion_point(destructor:proto2_arena_unittest.ArenaMessage)
  SharedDtor();
}

void ArenaMessage::SharedDtor() {
  ::google::protobuf::Arena* arena = GetArenaNoVirtual();
  if (arena != NULL) {
    return;
  }

}

void ArenaMessage::ArenaDtor(void* object) {
  ArenaMessage* _this = reinterpret_cast< ArenaMessage* >(object);
  (void)_this;
}
void ArenaMessage::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void ArenaMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArenaMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ArenaMessage_descriptor_;
}

const ArenaMessage& ArenaMessage::default_instance() {
  protobuf_InitDefaults_google_2fprotobuf_2funittest_5farena_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<ArenaMessage> ArenaMessage_default_instance_;

ArenaMessage* ArenaMessage::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<ArenaMessage>(arena);
}

void ArenaMessage::Clear() {
// @@protoc_insertion_point(message_clear_start:proto2_arena_unittest.ArenaMessage)
  repeated_nested_message_.Clear();
  repeated_import_no_arena_message_.Clear();
  _has_bits_.Clear();
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool ArenaMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto2_arena_unittest.ArenaMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
      case 1: {
        if (tag == 10) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_repeated_nested_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_repeated_nested_message()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_loop_repeated_nested_message;
        if (input->ExpectTag(18)) goto parse_loop_repeated_import_no_arena_message;
        input->UnsafeDecrementRecursionDepth();
        break;
      }

      // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
      case 2: {
        if (tag == 18) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_repeated_import_no_arena_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_repeated_import_no_arena_message()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_loop_repeated_import_no_arena_message;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto2_arena_unittest.ArenaMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto2_arena_unittest.ArenaMessage)
  return false;
#undef DO_
}

void ArenaMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto2_arena_unittest.ArenaMessage)
  // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
  for (unsigned int i = 0, n = this->repeated_nested_message_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->repeated_nested_message(i), output);
  }

  // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
  for (unsigned int i = 0, n = this->repeated_import_no_arena_message_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->repeated_import_no_arena_message(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:proto2_arena_unittest.ArenaMessage)
}

::google::protobuf::uint8* ArenaMessage::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:proto2_arena_unittest.ArenaMessage)
  // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
  for (unsigned int i = 0, n = this->repeated_nested_message_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, this->repeated_nested_message(i), false, target);
  }

  // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
  for (unsigned int i = 0, n = this->repeated_import_no_arena_message_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        2, this->repeated_import_no_arena_message(i), false, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto2_arena_unittest.ArenaMessage)
  return target;
}

size_t ArenaMessage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:proto2_arena_unittest.ArenaMessage)
  size_t total_size = 0;

  // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
  {
    unsigned int count = this->repeated_nested_message_size();
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->repeated_nested_message(i));
    }
  }

  // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
  {
    unsigned int count = this->repeated_import_no_arena_message_size();
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->repeated_import_no_arena_message(i));
    }
  }

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ArenaMessage::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:proto2_arena_unittest.ArenaMessage)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const ArenaMessage* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ArenaMessage>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:proto2_arena_unittest.ArenaMessage)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:proto2_arena_unittest.ArenaMessage)
    UnsafeMergeFrom(*source);
  }
}

void ArenaMessage::MergeFrom(const ArenaMessage& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:proto2_arena_unittest.ArenaMessage)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void ArenaMessage::UnsafeMergeFrom(const ArenaMessage& from) {
  GOOGLE_DCHECK(&from != this);
  repeated_nested_message_.MergeFrom(from.repeated_nested_message_);
  repeated_import_no_arena_message_.MergeFrom(from.repeated_import_no_arena_message_);
  if (from._internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::UnknownFieldSet::MergeToInternalMetdata(
      from.unknown_fields(), &_internal_metadata_);
  }
}

void ArenaMessage::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:proto2_arena_unittest.ArenaMessage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArenaMessage::CopyFrom(const ArenaMessage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:proto2_arena_unittest.ArenaMessage)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool ArenaMessage::IsInitialized() const {

  return true;
}

void ArenaMessage::Swap(ArenaMessage* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    ArenaMessage temp;
    temp.UnsafeMergeFrom(*this);
    CopyFrom(*other);
    other->CopyFrom(temp);
  }
}
void ArenaMessage::UnsafeArenaSwap(ArenaMessage* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void ArenaMessage::InternalSwap(ArenaMessage* other) {
  repeated_nested_message_.UnsafeArenaSwap(&other->repeated_nested_message_);
  repeated_import_no_arena_message_.UnsafeArenaSwap(&other->repeated_import_no_arena_message_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ArenaMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ArenaMessage_descriptor_;
  metadata.reflection = ArenaMessage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ArenaMessage

// repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
int ArenaMessage::repeated_nested_message_size() const {
  return repeated_nested_message_.size();
}
void ArenaMessage::clear_repeated_nested_message() {
  repeated_nested_message_.Clear();
}
const ::proto2_arena_unittest::NestedMessage& ArenaMessage::repeated_nested_message(int index) const {
  // @@protoc_insertion_point(field_get:proto2_arena_unittest.ArenaMessage.repeated_nested_message)
  return repeated_nested_message_.Get(index);
}
::proto2_arena_unittest::NestedMessage* ArenaMessage::mutable_repeated_nested_message(int index) {
  // @@protoc_insertion_point(field_mutable:proto2_arena_unittest.ArenaMessage.repeated_nested_message)
  return repeated_nested_message_.Mutable(index);
}
::proto2_arena_unittest::NestedMessage* ArenaMessage::add_repeated_nested_message() {
  // @@protoc_insertion_point(field_add:proto2_arena_unittest.ArenaMessage.repeated_nested_message)
  return repeated_nested_message_.Add();
}
::google::protobuf::RepeatedPtrField< ::proto2_arena_unittest::NestedMessage >*
ArenaMessage::mutable_repeated_nested_message() {
  // @@protoc_insertion_point(field_mutable_list:proto2_arena_unittest.ArenaMessage.repeated_nested_message)
  return &repeated_nested_message_;
}
const ::google::protobuf::RepeatedPtrField< ::proto2_arena_unittest::NestedMessage >&
ArenaMessage::repeated_nested_message() const {
  // @@protoc_insertion_point(field_list:proto2_arena_unittest.ArenaMessage.repeated_nested_message)
  return repeated_nested_message_;
}

// repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
int ArenaMessage::repeated_import_no_arena_message_size() const {
  return repeated_import_no_arena_message_.size();
}
void ArenaMessage::clear_repeated_import_no_arena_message() {
  repeated_import_no_arena_message_.Clear();
}
const ::proto2_arena_unittest::ImportNoArenaNestedMessage& ArenaMessage::repeated_import_no_arena_message(int index) const {
  // @@protoc_insertion_point(field_get:proto2_arena_unittest.ArenaMessage.repeated_import_no_arena_message)
  return repeated_import_no_arena_message_.Get(index);
}
::proto2_arena_unittest::ImportNoArenaNestedMessage* ArenaMessage::mutable_repeated_import_no_arena_message(int index) {
  // @@protoc_insertion_point(field_mutable:proto2_arena_unittest.ArenaMessage.repeated_import_no_arena_message)
  return repeated_import_no_arena_message_.Mutable(index);
}
::proto2_arena_unittest::ImportNoArenaNestedMessage* ArenaMessage::add_repeated_import_no_arena_message() {
  // @@protoc_insertion_point(field_add:proto2_arena_unittest.ArenaMessage.repeated_import_no_arena_message)
  return repeated_import_no_arena_message_.Add();
}
::google::protobuf::RepeatedPtrField< ::proto2_arena_unittest::ImportNoArenaNestedMessage >*
ArenaMessage::mutable_repeated_import_no_arena_message() {
  // @@protoc_insertion_point(field_mutable_list:proto2_arena_unittest.ArenaMessage.repeated_import_no_arena_message)
  return &repeated_import_no_arena_message_;
}
const ::google::protobuf::RepeatedPtrField< ::proto2_arena_unittest::ImportNoArenaNestedMessage >&
ArenaMessage::repeated_import_no_arena_message() const {
  // @@protoc_insertion_point(field_list:proto2_arena_unittest.ArenaMessage.repeated_import_no_arena_message)
  return repeated_import_no_arena_message_;
}

inline const ArenaMessage* ArenaMessage::internal_default_instance() {
  return &ArenaMessage_default_instance_.get();
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto2_arena_unittest

// @@protoc_insertion_point(global_scope)
