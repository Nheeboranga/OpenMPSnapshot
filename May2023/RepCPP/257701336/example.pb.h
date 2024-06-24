
#ifndef PROTOBUF_INCLUDED_tensorflow_2fcore_2fexample_2fexample_2eproto
#define PROTOBUF_INCLUDED_tensorflow_2fcore_2fexample_2fexample_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  
#include <google/protobuf/extension_set.h>  
#include <google/protobuf/unknown_field_set.h>
#include "tensorflow/core/example/feature.pb.h"
#define PROTOBUF_INTERNAL_EXPORT_protobuf_tensorflow_2fcore_2fexample_2fexample_2eproto 

namespace protobuf_tensorflow_2fcore_2fexample_2fexample_2eproto {
struct TableStruct {
static const ::google::protobuf::internal::ParseTableField entries[];
static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
static const ::google::protobuf::internal::ParseTable schema[2];
static const ::google::protobuf::internal::FieldMetadata field_metadata[];
static const ::google::protobuf::internal::SerializationTable serialization_table[];
static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  
namespace tensorflow {
class Example;
class ExampleDefaultTypeInternal;
extern ExampleDefaultTypeInternal _Example_default_instance_;
class SequenceExample;
class SequenceExampleDefaultTypeInternal;
extern SequenceExampleDefaultTypeInternal _SequenceExample_default_instance_;
}  
namespace google {
namespace protobuf {
template<> ::tensorflow::Example* Arena::CreateMaybeMessage<::tensorflow::Example>(Arena*);
template<> ::tensorflow::SequenceExample* Arena::CreateMaybeMessage<::tensorflow::SequenceExample>(Arena*);
}  
}  
namespace tensorflow {


class Example : public ::google::protobuf::Message  {
public:
Example();
virtual ~Example();

Example(const Example& from);

inline Example& operator=(const Example& from) {
CopyFrom(from);
return *this;
}
#if LANG_CXX11
Example(Example&& from) noexcept
: Example() {
*this = ::std::move(from);
}

inline Example& operator=(Example&& from) noexcept {
if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
if (this != &from) InternalSwap(&from);
} else {
CopyFrom(from);
}
return *this;
}
#endif
inline ::google::protobuf::Arena* GetArena() const final {
return GetArenaNoVirtual();
}
inline void* GetMaybeArenaPointer() const final {
return MaybeArenaPtr();
}
static const ::google::protobuf::Descriptor* descriptor();
static const Example& default_instance();

static void InitAsDefaultInstance();  
static inline const Example* internal_default_instance() {
return reinterpret_cast<const Example*>(
&_Example_default_instance_);
}
static constexpr int kIndexInFileMessages =
0;

void UnsafeArenaSwap(Example* other);
void Swap(Example* other);
friend void swap(Example& a, Example& b) {
a.Swap(&b);
}


inline Example* New() const final {
return CreateMaybeMessage<Example>(NULL);
}

Example* New(::google::protobuf::Arena* arena) const final {
return CreateMaybeMessage<Example>(arena);
}
void CopyFrom(const ::google::protobuf::Message& from) final;
void MergeFrom(const ::google::protobuf::Message& from) final;
void CopyFrom(const Example& from);
void MergeFrom(const Example& from);
void Clear() final;
bool IsInitialized() const final;

size_t ByteSizeLong() const final;
bool MergePartialFromCodedStream(
::google::protobuf::io::CodedInputStream* input) final;
void SerializeWithCachedSizes(
::google::protobuf::io::CodedOutputStream* output) const final;
::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
bool deterministic, ::google::protobuf::uint8* target) const final;
int GetCachedSize() const final { return _cached_size_.Get(); }

private:
void SharedCtor();
void SharedDtor();
void SetCachedSize(int size) const final;
void InternalSwap(Example* other);
protected:
explicit Example(::google::protobuf::Arena* arena);
private:
static void ArenaDtor(void* object);
inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
private:
inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
return _internal_metadata_.arena();
}
inline void* MaybeArenaPtr() const {
return _internal_metadata_.raw_arena_ptr();
}
public:

::google::protobuf::Metadata GetMetadata() const final;



bool has_features() const;
void clear_features();
static const int kFeaturesFieldNumber = 1;
private:
const ::tensorflow::Features& _internal_features() const;
public:
const ::tensorflow::Features& features() const;
::tensorflow::Features* release_features();
::tensorflow::Features* mutable_features();
void set_allocated_features(::tensorflow::Features* features);
void unsafe_arena_set_allocated_features(
::tensorflow::Features* features);
::tensorflow::Features* unsafe_arena_release_features();

private:

::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
typedef void InternalArenaConstructable_;
typedef void DestructorSkippable_;
::tensorflow::Features* features_;
mutable ::google::protobuf::internal::CachedSize _cached_size_;
friend struct ::protobuf_tensorflow_2fcore_2fexample_2fexample_2eproto::TableStruct;
};

class SequenceExample : public ::google::protobuf::Message  {
public:
SequenceExample();
virtual ~SequenceExample();

SequenceExample(const SequenceExample& from);

inline SequenceExample& operator=(const SequenceExample& from) {
CopyFrom(from);
return *this;
}
#if LANG_CXX11
SequenceExample(SequenceExample&& from) noexcept
: SequenceExample() {
*this = ::std::move(from);
}

inline SequenceExample& operator=(SequenceExample&& from) noexcept {
if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
if (this != &from) InternalSwap(&from);
} else {
CopyFrom(from);
}
return *this;
}
#endif
inline ::google::protobuf::Arena* GetArena() const final {
return GetArenaNoVirtual();
}
inline void* GetMaybeArenaPointer() const final {
return MaybeArenaPtr();
}
static const ::google::protobuf::Descriptor* descriptor();
static const SequenceExample& default_instance();

static void InitAsDefaultInstance();  
static inline const SequenceExample* internal_default_instance() {
return reinterpret_cast<const SequenceExample*>(
&_SequenceExample_default_instance_);
}
static constexpr int kIndexInFileMessages =
1;

void UnsafeArenaSwap(SequenceExample* other);
void Swap(SequenceExample* other);
friend void swap(SequenceExample& a, SequenceExample& b) {
a.Swap(&b);
}


inline SequenceExample* New() const final {
return CreateMaybeMessage<SequenceExample>(NULL);
}

SequenceExample* New(::google::protobuf::Arena* arena) const final {
return CreateMaybeMessage<SequenceExample>(arena);
}
void CopyFrom(const ::google::protobuf::Message& from) final;
void MergeFrom(const ::google::protobuf::Message& from) final;
void CopyFrom(const SequenceExample& from);
void MergeFrom(const SequenceExample& from);
void Clear() final;
bool IsInitialized() const final;

size_t ByteSizeLong() const final;
bool MergePartialFromCodedStream(
::google::protobuf::io::CodedInputStream* input) final;
void SerializeWithCachedSizes(
::google::protobuf::io::CodedOutputStream* output) const final;
::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
bool deterministic, ::google::protobuf::uint8* target) const final;
int GetCachedSize() const final { return _cached_size_.Get(); }

private:
void SharedCtor();
void SharedDtor();
void SetCachedSize(int size) const final;
void InternalSwap(SequenceExample* other);
protected:
explicit SequenceExample(::google::protobuf::Arena* arena);
private:
static void ArenaDtor(void* object);
inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
private:
inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
return _internal_metadata_.arena();
}
inline void* MaybeArenaPtr() const {
return _internal_metadata_.raw_arena_ptr();
}
public:

::google::protobuf::Metadata GetMetadata() const final;



bool has_context() const;
void clear_context();
static const int kContextFieldNumber = 1;
private:
const ::tensorflow::Features& _internal_context() const;
public:
const ::tensorflow::Features& context() const;
::tensorflow::Features* release_context();
::tensorflow::Features* mutable_context();
void set_allocated_context(::tensorflow::Features* context);
void unsafe_arena_set_allocated_context(
::tensorflow::Features* context);
::tensorflow::Features* unsafe_arena_release_context();

bool has_feature_lists() const;
void clear_feature_lists();
static const int kFeatureListsFieldNumber = 2;
private:
const ::tensorflow::FeatureLists& _internal_feature_lists() const;
public:
const ::tensorflow::FeatureLists& feature_lists() const;
::tensorflow::FeatureLists* release_feature_lists();
::tensorflow::FeatureLists* mutable_feature_lists();
void set_allocated_feature_lists(::tensorflow::FeatureLists* feature_lists);
void unsafe_arena_set_allocated_feature_lists(
::tensorflow::FeatureLists* feature_lists);
::tensorflow::FeatureLists* unsafe_arena_release_feature_lists();

private:

::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
typedef void InternalArenaConstructable_;
typedef void DestructorSkippable_;
::tensorflow::Features* context_;
::tensorflow::FeatureLists* feature_lists_;
mutable ::google::protobuf::internal::CachedSize _cached_size_;
friend struct ::protobuf_tensorflow_2fcore_2fexample_2fexample_2eproto::TableStruct;
};



#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  

inline bool Example::has_features() const {
return this != internal_default_instance() && features_ != NULL;
}
inline const ::tensorflow::Features& Example::_internal_features() const {
return *features_;
}
inline const ::tensorflow::Features& Example::features() const {
const ::tensorflow::Features* p = features_;
return p != NULL ? *p : *reinterpret_cast<const ::tensorflow::Features*>(
&::tensorflow::_Features_default_instance_);
}
inline ::tensorflow::Features* Example::release_features() {

::tensorflow::Features* temp = features_;
if (GetArenaNoVirtual() != NULL) {
temp = ::google::protobuf::internal::DuplicateIfNonNull(temp);
}
features_ = NULL;
return temp;
}
inline ::tensorflow::Features* Example::unsafe_arena_release_features() {

::tensorflow::Features* temp = features_;
features_ = NULL;
return temp;
}
inline ::tensorflow::Features* Example::mutable_features() {

if (features_ == NULL) {
auto* p = CreateMaybeMessage<::tensorflow::Features>(GetArenaNoVirtual());
features_ = p;
}
return features_;
}
inline void Example::set_allocated_features(::tensorflow::Features* features) {
::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
if (message_arena == NULL) {
delete reinterpret_cast< ::google::protobuf::MessageLite*>(features_);
}
if (features) {
::google::protobuf::Arena* submessage_arena =
reinterpret_cast<::google::protobuf::MessageLite*>(features)->GetArena();
if (message_arena != submessage_arena) {
features = ::google::protobuf::internal::GetOwnedMessage(
message_arena, features, submessage_arena);
}

} else {

}
features_ = features;
}



inline bool SequenceExample::has_context() const {
return this != internal_default_instance() && context_ != NULL;
}
inline const ::tensorflow::Features& SequenceExample::_internal_context() const {
return *context_;
}
inline const ::tensorflow::Features& SequenceExample::context() const {
const ::tensorflow::Features* p = context_;
return p != NULL ? *p : *reinterpret_cast<const ::tensorflow::Features*>(
&::tensorflow::_Features_default_instance_);
}
inline ::tensorflow::Features* SequenceExample::release_context() {

::tensorflow::Features* temp = context_;
if (GetArenaNoVirtual() != NULL) {
temp = ::google::protobuf::internal::DuplicateIfNonNull(temp);
}
context_ = NULL;
return temp;
}
inline ::tensorflow::Features* SequenceExample::unsafe_arena_release_context() {

::tensorflow::Features* temp = context_;
context_ = NULL;
return temp;
}
inline ::tensorflow::Features* SequenceExample::mutable_context() {

if (context_ == NULL) {
auto* p = CreateMaybeMessage<::tensorflow::Features>(GetArenaNoVirtual());
context_ = p;
}
return context_;
}
inline void SequenceExample::set_allocated_context(::tensorflow::Features* context) {
::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
if (message_arena == NULL) {
delete reinterpret_cast< ::google::protobuf::MessageLite*>(context_);
}
if (context) {
::google::protobuf::Arena* submessage_arena =
reinterpret_cast<::google::protobuf::MessageLite*>(context)->GetArena();
if (message_arena != submessage_arena) {
context = ::google::protobuf::internal::GetOwnedMessage(
message_arena, context, submessage_arena);
}

} else {

}
context_ = context;
}

inline bool SequenceExample::has_feature_lists() const {
return this != internal_default_instance() && feature_lists_ != NULL;
}
inline const ::tensorflow::FeatureLists& SequenceExample::_internal_feature_lists() const {
return *feature_lists_;
}
inline const ::tensorflow::FeatureLists& SequenceExample::feature_lists() const {
const ::tensorflow::FeatureLists* p = feature_lists_;
return p != NULL ? *p : *reinterpret_cast<const ::tensorflow::FeatureLists*>(
&::tensorflow::_FeatureLists_default_instance_);
}
inline ::tensorflow::FeatureLists* SequenceExample::release_feature_lists() {

::tensorflow::FeatureLists* temp = feature_lists_;
if (GetArenaNoVirtual() != NULL) {
temp = ::google::protobuf::internal::DuplicateIfNonNull(temp);
}
feature_lists_ = NULL;
return temp;
}
inline ::tensorflow::FeatureLists* SequenceExample::unsafe_arena_release_feature_lists() {

::tensorflow::FeatureLists* temp = feature_lists_;
feature_lists_ = NULL;
return temp;
}
inline ::tensorflow::FeatureLists* SequenceExample::mutable_feature_lists() {

if (feature_lists_ == NULL) {
auto* p = CreateMaybeMessage<::tensorflow::FeatureLists>(GetArenaNoVirtual());
feature_lists_ = p;
}
return feature_lists_;
}
inline void SequenceExample::set_allocated_feature_lists(::tensorflow::FeatureLists* feature_lists) {
::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
if (message_arena == NULL) {
delete reinterpret_cast< ::google::protobuf::MessageLite*>(feature_lists_);
}
if (feature_lists) {
::google::protobuf::Arena* submessage_arena =
reinterpret_cast<::google::protobuf::MessageLite*>(feature_lists)->GetArena();
if (message_arena != submessage_arena) {
feature_lists = ::google::protobuf::internal::GetOwnedMessage(
message_arena, feature_lists, submessage_arena);
}

} else {

}
feature_lists_ = feature_lists;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  



}  


#endif  
