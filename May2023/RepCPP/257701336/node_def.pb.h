
#ifndef PROTOBUF_INCLUDED_tensorflow_2fcore_2fframework_2fnode_5fdef_2eproto
#define PROTOBUF_INCLUDED_tensorflow_2fcore_2fframework_2fnode_5fdef_2eproto

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
#include <google/protobuf/map.h>  
#include <google/protobuf/map_entry.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/unknown_field_set.h>
#include "tensorflow/core/framework/attr_value.pb.h"
#define PROTOBUF_INTERNAL_EXPORT_protobuf_tensorflow_2fcore_2fframework_2fnode_5fdef_2eproto 

namespace protobuf_tensorflow_2fcore_2fframework_2fnode_5fdef_2eproto {
struct TableStruct {
static const ::google::protobuf::internal::ParseTableField entries[];
static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
static const ::google::protobuf::internal::ParseTable schema[3];
static const ::google::protobuf::internal::FieldMetadata field_metadata[];
static const ::google::protobuf::internal::SerializationTable serialization_table[];
static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  
namespace tensorflow {
class NodeDef;
class NodeDefDefaultTypeInternal;
extern NodeDefDefaultTypeInternal _NodeDef_default_instance_;
class NodeDef_AttrEntry_DoNotUse;
class NodeDef_AttrEntry_DoNotUseDefaultTypeInternal;
extern NodeDef_AttrEntry_DoNotUseDefaultTypeInternal _NodeDef_AttrEntry_DoNotUse_default_instance_;
class NodeDef_ExperimentalDebugInfo;
class NodeDef_ExperimentalDebugInfoDefaultTypeInternal;
extern NodeDef_ExperimentalDebugInfoDefaultTypeInternal _NodeDef_ExperimentalDebugInfo_default_instance_;
}  
namespace google {
namespace protobuf {
template<> ::tensorflow::NodeDef* Arena::CreateMaybeMessage<::tensorflow::NodeDef>(Arena*);
template<> ::tensorflow::NodeDef_AttrEntry_DoNotUse* Arena::CreateMaybeMessage<::tensorflow::NodeDef_AttrEntry_DoNotUse>(Arena*);
template<> ::tensorflow::NodeDef_ExperimentalDebugInfo* Arena::CreateMaybeMessage<::tensorflow::NodeDef_ExperimentalDebugInfo>(Arena*);
}  
}  
namespace tensorflow {


class NodeDef_AttrEntry_DoNotUse : public ::google::protobuf::internal::MapEntry<NodeDef_AttrEntry_DoNotUse, 
::std::string, ::tensorflow::AttrValue,
::google::protobuf::internal::WireFormatLite::TYPE_STRING,
::google::protobuf::internal::WireFormatLite::TYPE_MESSAGE,
0 > {
public:
typedef ::google::protobuf::internal::MapEntry<NodeDef_AttrEntry_DoNotUse, 
::std::string, ::tensorflow::AttrValue,
::google::protobuf::internal::WireFormatLite::TYPE_STRING,
::google::protobuf::internal::WireFormatLite::TYPE_MESSAGE,
0 > SuperType;
NodeDef_AttrEntry_DoNotUse();
NodeDef_AttrEntry_DoNotUse(::google::protobuf::Arena* arena);
void MergeFrom(const NodeDef_AttrEntry_DoNotUse& other);
static const NodeDef_AttrEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const NodeDef_AttrEntry_DoNotUse*>(&_NodeDef_AttrEntry_DoNotUse_default_instance_); }
void MergeFrom(const ::google::protobuf::Message& other) final;
::google::protobuf::Metadata GetMetadata() const;
};


class NodeDef_ExperimentalDebugInfo : public ::google::protobuf::Message  {
public:
NodeDef_ExperimentalDebugInfo();
virtual ~NodeDef_ExperimentalDebugInfo();

NodeDef_ExperimentalDebugInfo(const NodeDef_ExperimentalDebugInfo& from);

inline NodeDef_ExperimentalDebugInfo& operator=(const NodeDef_ExperimentalDebugInfo& from) {
CopyFrom(from);
return *this;
}
#if LANG_CXX11
NodeDef_ExperimentalDebugInfo(NodeDef_ExperimentalDebugInfo&& from) noexcept
: NodeDef_ExperimentalDebugInfo() {
*this = ::std::move(from);
}

inline NodeDef_ExperimentalDebugInfo& operator=(NodeDef_ExperimentalDebugInfo&& from) noexcept {
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
static const NodeDef_ExperimentalDebugInfo& default_instance();

static void InitAsDefaultInstance();  
static inline const NodeDef_ExperimentalDebugInfo* internal_default_instance() {
return reinterpret_cast<const NodeDef_ExperimentalDebugInfo*>(
&_NodeDef_ExperimentalDebugInfo_default_instance_);
}
static constexpr int kIndexInFileMessages =
1;

void UnsafeArenaSwap(NodeDef_ExperimentalDebugInfo* other);
void Swap(NodeDef_ExperimentalDebugInfo* other);
friend void swap(NodeDef_ExperimentalDebugInfo& a, NodeDef_ExperimentalDebugInfo& b) {
a.Swap(&b);
}


inline NodeDef_ExperimentalDebugInfo* New() const final {
return CreateMaybeMessage<NodeDef_ExperimentalDebugInfo>(NULL);
}

NodeDef_ExperimentalDebugInfo* New(::google::protobuf::Arena* arena) const final {
return CreateMaybeMessage<NodeDef_ExperimentalDebugInfo>(arena);
}
void CopyFrom(const ::google::protobuf::Message& from) final;
void MergeFrom(const ::google::protobuf::Message& from) final;
void CopyFrom(const NodeDef_ExperimentalDebugInfo& from);
void MergeFrom(const NodeDef_ExperimentalDebugInfo& from);
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
void InternalSwap(NodeDef_ExperimentalDebugInfo* other);
protected:
explicit NodeDef_ExperimentalDebugInfo(::google::protobuf::Arena* arena);
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



int original_node_names_size() const;
void clear_original_node_names();
static const int kOriginalNodeNamesFieldNumber = 1;
const ::std::string& original_node_names(int index) const;
::std::string* mutable_original_node_names(int index);
void set_original_node_names(int index, const ::std::string& value);
#if LANG_CXX11
void set_original_node_names(int index, ::std::string&& value);
#endif
void set_original_node_names(int index, const char* value);
void set_original_node_names(int index, const char* value, size_t size);
::std::string* add_original_node_names();
void add_original_node_names(const ::std::string& value);
#if LANG_CXX11
void add_original_node_names(::std::string&& value);
#endif
void add_original_node_names(const char* value);
void add_original_node_names(const char* value, size_t size);
const ::google::protobuf::RepeatedPtrField< ::std::string>& original_node_names() const;
::google::protobuf::RepeatedPtrField< ::std::string>* mutable_original_node_names();

private:

::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
typedef void InternalArenaConstructable_;
typedef void DestructorSkippable_;
::google::protobuf::RepeatedPtrField< ::std::string> original_node_names_;
mutable ::google::protobuf::internal::CachedSize _cached_size_;
friend struct ::protobuf_tensorflow_2fcore_2fframework_2fnode_5fdef_2eproto::TableStruct;
};

class NodeDef : public ::google::protobuf::Message  {
public:
NodeDef();
virtual ~NodeDef();

NodeDef(const NodeDef& from);

inline NodeDef& operator=(const NodeDef& from) {
CopyFrom(from);
return *this;
}
#if LANG_CXX11
NodeDef(NodeDef&& from) noexcept
: NodeDef() {
*this = ::std::move(from);
}

inline NodeDef& operator=(NodeDef&& from) noexcept {
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
static const NodeDef& default_instance();

static void InitAsDefaultInstance();  
static inline const NodeDef* internal_default_instance() {
return reinterpret_cast<const NodeDef*>(
&_NodeDef_default_instance_);
}
static constexpr int kIndexInFileMessages =
2;

void UnsafeArenaSwap(NodeDef* other);
void Swap(NodeDef* other);
friend void swap(NodeDef& a, NodeDef& b) {
a.Swap(&b);
}


inline NodeDef* New() const final {
return CreateMaybeMessage<NodeDef>(NULL);
}

NodeDef* New(::google::protobuf::Arena* arena) const final {
return CreateMaybeMessage<NodeDef>(arena);
}
void CopyFrom(const ::google::protobuf::Message& from) final;
void MergeFrom(const ::google::protobuf::Message& from) final;
void CopyFrom(const NodeDef& from);
void MergeFrom(const NodeDef& from);
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
void InternalSwap(NodeDef* other);
protected:
explicit NodeDef(::google::protobuf::Arena* arena);
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


typedef NodeDef_ExperimentalDebugInfo ExperimentalDebugInfo;


int input_size() const;
void clear_input();
static const int kInputFieldNumber = 3;
const ::std::string& input(int index) const;
::std::string* mutable_input(int index);
void set_input(int index, const ::std::string& value);
#if LANG_CXX11
void set_input(int index, ::std::string&& value);
#endif
void set_input(int index, const char* value);
void set_input(int index, const char* value, size_t size);
::std::string* add_input();
void add_input(const ::std::string& value);
#if LANG_CXX11
void add_input(::std::string&& value);
#endif
void add_input(const char* value);
void add_input(const char* value, size_t size);
const ::google::protobuf::RepeatedPtrField< ::std::string>& input() const;
::google::protobuf::RepeatedPtrField< ::std::string>* mutable_input();

int attr_size() const;
void clear_attr();
static const int kAttrFieldNumber = 5;
const ::google::protobuf::Map< ::std::string, ::tensorflow::AttrValue >&
attr() const;
::google::protobuf::Map< ::std::string, ::tensorflow::AttrValue >*
mutable_attr();

void clear_name();
static const int kNameFieldNumber = 1;
const ::std::string& name() const;
void set_name(const ::std::string& value);
#if LANG_CXX11
void set_name(::std::string&& value);
#endif
void set_name(const char* value);
void set_name(const char* value, size_t size);
::std::string* mutable_name();
::std::string* release_name();
void set_allocated_name(::std::string* name);
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
::std::string* unsafe_arena_release_name();
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
void unsafe_arena_set_allocated_name(
::std::string* name);

void clear_op();
static const int kOpFieldNumber = 2;
const ::std::string& op() const;
void set_op(const ::std::string& value);
#if LANG_CXX11
void set_op(::std::string&& value);
#endif
void set_op(const char* value);
void set_op(const char* value, size_t size);
::std::string* mutable_op();
::std::string* release_op();
void set_allocated_op(::std::string* op);
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
::std::string* unsafe_arena_release_op();
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
void unsafe_arena_set_allocated_op(
::std::string* op);

void clear_device();
static const int kDeviceFieldNumber = 4;
const ::std::string& device() const;
void set_device(const ::std::string& value);
#if LANG_CXX11
void set_device(::std::string&& value);
#endif
void set_device(const char* value);
void set_device(const char* value, size_t size);
::std::string* mutable_device();
::std::string* release_device();
void set_allocated_device(::std::string* device);
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
::std::string* unsafe_arena_release_device();
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
void unsafe_arena_set_allocated_device(
::std::string* device);

bool has_experimental_debug_info() const;
void clear_experimental_debug_info();
static const int kExperimentalDebugInfoFieldNumber = 6;
private:
const ::tensorflow::NodeDef_ExperimentalDebugInfo& _internal_experimental_debug_info() const;
public:
const ::tensorflow::NodeDef_ExperimentalDebugInfo& experimental_debug_info() const;
::tensorflow::NodeDef_ExperimentalDebugInfo* release_experimental_debug_info();
::tensorflow::NodeDef_ExperimentalDebugInfo* mutable_experimental_debug_info();
void set_allocated_experimental_debug_info(::tensorflow::NodeDef_ExperimentalDebugInfo* experimental_debug_info);
void unsafe_arena_set_allocated_experimental_debug_info(
::tensorflow::NodeDef_ExperimentalDebugInfo* experimental_debug_info);
::tensorflow::NodeDef_ExperimentalDebugInfo* unsafe_arena_release_experimental_debug_info();

private:

::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
typedef void InternalArenaConstructable_;
typedef void DestructorSkippable_;
::google::protobuf::RepeatedPtrField< ::std::string> input_;
::google::protobuf::internal::MapField<
NodeDef_AttrEntry_DoNotUse,
::std::string, ::tensorflow::AttrValue,
::google::protobuf::internal::WireFormatLite::TYPE_STRING,
::google::protobuf::internal::WireFormatLite::TYPE_MESSAGE,
0 > attr_;
::google::protobuf::internal::ArenaStringPtr name_;
::google::protobuf::internal::ArenaStringPtr op_;
::google::protobuf::internal::ArenaStringPtr device_;
::tensorflow::NodeDef_ExperimentalDebugInfo* experimental_debug_info_;
mutable ::google::protobuf::internal::CachedSize _cached_size_;
friend struct ::protobuf_tensorflow_2fcore_2fframework_2fnode_5fdef_2eproto::TableStruct;
};



#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  


inline int NodeDef_ExperimentalDebugInfo::original_node_names_size() const {
return original_node_names_.size();
}
inline void NodeDef_ExperimentalDebugInfo::clear_original_node_names() {
original_node_names_.Clear();
}
inline const ::std::string& NodeDef_ExperimentalDebugInfo::original_node_names(int index) const {
return original_node_names_.Get(index);
}
inline ::std::string* NodeDef_ExperimentalDebugInfo::mutable_original_node_names(int index) {
return original_node_names_.Mutable(index);
}
inline void NodeDef_ExperimentalDebugInfo::set_original_node_names(int index, const ::std::string& value) {
original_node_names_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void NodeDef_ExperimentalDebugInfo::set_original_node_names(int index, ::std::string&& value) {
original_node_names_.Mutable(index)->assign(std::move(value));
}
#endif
inline void NodeDef_ExperimentalDebugInfo::set_original_node_names(int index, const char* value) {
GOOGLE_DCHECK(value != NULL);
original_node_names_.Mutable(index)->assign(value);
}
inline void NodeDef_ExperimentalDebugInfo::set_original_node_names(int index, const char* value, size_t size) {
original_node_names_.Mutable(index)->assign(
reinterpret_cast<const char*>(value), size);
}
inline ::std::string* NodeDef_ExperimentalDebugInfo::add_original_node_names() {
return original_node_names_.Add();
}
inline void NodeDef_ExperimentalDebugInfo::add_original_node_names(const ::std::string& value) {
original_node_names_.Add()->assign(value);
}
#if LANG_CXX11
inline void NodeDef_ExperimentalDebugInfo::add_original_node_names(::std::string&& value) {
original_node_names_.Add(std::move(value));
}
#endif
inline void NodeDef_ExperimentalDebugInfo::add_original_node_names(const char* value) {
GOOGLE_DCHECK(value != NULL);
original_node_names_.Add()->assign(value);
}
inline void NodeDef_ExperimentalDebugInfo::add_original_node_names(const char* value, size_t size) {
original_node_names_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
NodeDef_ExperimentalDebugInfo::original_node_names() const {
return original_node_names_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
NodeDef_ExperimentalDebugInfo::mutable_original_node_names() {
return &original_node_names_;
}



inline void NodeDef::clear_name() {
name_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& NodeDef::name() const {
return name_.Get();
}
inline void NodeDef::set_name(const ::std::string& value) {

name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
}
#if LANG_CXX11
inline void NodeDef::set_name(::std::string&& value) {

name_.Set(
&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
}
#endif
inline void NodeDef::set_name(const char* value) {
GOOGLE_DCHECK(value != NULL);

name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
GetArenaNoVirtual());
}
inline void NodeDef::set_name(const char* value,
size_t size) {

name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
}
inline ::std::string* NodeDef::mutable_name() {

return name_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* NodeDef::release_name() {

return name_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline void NodeDef::set_allocated_name(::std::string* name) {
if (name != NULL) {

} else {

}
name_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name,
GetArenaNoVirtual());
}
inline ::std::string* NodeDef::unsafe_arena_release_name() {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);

return name_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
GetArenaNoVirtual());
}
inline void NodeDef::unsafe_arena_set_allocated_name(
::std::string* name) {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
if (name != NULL) {

} else {

}
name_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
name, GetArenaNoVirtual());
}

inline void NodeDef::clear_op() {
op_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& NodeDef::op() const {
return op_.Get();
}
inline void NodeDef::set_op(const ::std::string& value) {

op_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
}
#if LANG_CXX11
inline void NodeDef::set_op(::std::string&& value) {

op_.Set(
&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
}
#endif
inline void NodeDef::set_op(const char* value) {
GOOGLE_DCHECK(value != NULL);

op_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
GetArenaNoVirtual());
}
inline void NodeDef::set_op(const char* value,
size_t size) {

op_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
}
inline ::std::string* NodeDef::mutable_op() {

return op_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* NodeDef::release_op() {

return op_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline void NodeDef::set_allocated_op(::std::string* op) {
if (op != NULL) {

} else {

}
op_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), op,
GetArenaNoVirtual());
}
inline ::std::string* NodeDef::unsafe_arena_release_op() {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);

return op_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
GetArenaNoVirtual());
}
inline void NodeDef::unsafe_arena_set_allocated_op(
::std::string* op) {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
if (op != NULL) {

} else {

}
op_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
op, GetArenaNoVirtual());
}

inline int NodeDef::input_size() const {
return input_.size();
}
inline void NodeDef::clear_input() {
input_.Clear();
}
inline const ::std::string& NodeDef::input(int index) const {
return input_.Get(index);
}
inline ::std::string* NodeDef::mutable_input(int index) {
return input_.Mutable(index);
}
inline void NodeDef::set_input(int index, const ::std::string& value) {
input_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void NodeDef::set_input(int index, ::std::string&& value) {
input_.Mutable(index)->assign(std::move(value));
}
#endif
inline void NodeDef::set_input(int index, const char* value) {
GOOGLE_DCHECK(value != NULL);
input_.Mutable(index)->assign(value);
}
inline void NodeDef::set_input(int index, const char* value, size_t size) {
input_.Mutable(index)->assign(
reinterpret_cast<const char*>(value), size);
}
inline ::std::string* NodeDef::add_input() {
return input_.Add();
}
inline void NodeDef::add_input(const ::std::string& value) {
input_.Add()->assign(value);
}
#if LANG_CXX11
inline void NodeDef::add_input(::std::string&& value) {
input_.Add(std::move(value));
}
#endif
inline void NodeDef::add_input(const char* value) {
GOOGLE_DCHECK(value != NULL);
input_.Add()->assign(value);
}
inline void NodeDef::add_input(const char* value, size_t size) {
input_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
NodeDef::input() const {
return input_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
NodeDef::mutable_input() {
return &input_;
}

inline void NodeDef::clear_device() {
device_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& NodeDef::device() const {
return device_.Get();
}
inline void NodeDef::set_device(const ::std::string& value) {

device_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
}
#if LANG_CXX11
inline void NodeDef::set_device(::std::string&& value) {

device_.Set(
&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
}
#endif
inline void NodeDef::set_device(const char* value) {
GOOGLE_DCHECK(value != NULL);

device_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
GetArenaNoVirtual());
}
inline void NodeDef::set_device(const char* value,
size_t size) {

device_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
}
inline ::std::string* NodeDef::mutable_device() {

return device_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* NodeDef::release_device() {

return device_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline void NodeDef::set_allocated_device(::std::string* device) {
if (device != NULL) {

} else {

}
device_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), device,
GetArenaNoVirtual());
}
inline ::std::string* NodeDef::unsafe_arena_release_device() {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);

return device_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
GetArenaNoVirtual());
}
inline void NodeDef::unsafe_arena_set_allocated_device(
::std::string* device) {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
if (device != NULL) {

} else {

}
device_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
device, GetArenaNoVirtual());
}

inline int NodeDef::attr_size() const {
return attr_.size();
}
inline const ::google::protobuf::Map< ::std::string, ::tensorflow::AttrValue >&
NodeDef::attr() const {
return attr_.GetMap();
}
inline ::google::protobuf::Map< ::std::string, ::tensorflow::AttrValue >*
NodeDef::mutable_attr() {
return attr_.MutableMap();
}

inline bool NodeDef::has_experimental_debug_info() const {
return this != internal_default_instance() && experimental_debug_info_ != NULL;
}
inline void NodeDef::clear_experimental_debug_info() {
if (GetArenaNoVirtual() == NULL && experimental_debug_info_ != NULL) {
delete experimental_debug_info_;
}
experimental_debug_info_ = NULL;
}
inline const ::tensorflow::NodeDef_ExperimentalDebugInfo& NodeDef::_internal_experimental_debug_info() const {
return *experimental_debug_info_;
}
inline const ::tensorflow::NodeDef_ExperimentalDebugInfo& NodeDef::experimental_debug_info() const {
const ::tensorflow::NodeDef_ExperimentalDebugInfo* p = experimental_debug_info_;
return p != NULL ? *p : *reinterpret_cast<const ::tensorflow::NodeDef_ExperimentalDebugInfo*>(
&::tensorflow::_NodeDef_ExperimentalDebugInfo_default_instance_);
}
inline ::tensorflow::NodeDef_ExperimentalDebugInfo* NodeDef::release_experimental_debug_info() {

::tensorflow::NodeDef_ExperimentalDebugInfo* temp = experimental_debug_info_;
if (GetArenaNoVirtual() != NULL) {
temp = ::google::protobuf::internal::DuplicateIfNonNull(temp);
}
experimental_debug_info_ = NULL;
return temp;
}
inline ::tensorflow::NodeDef_ExperimentalDebugInfo* NodeDef::unsafe_arena_release_experimental_debug_info() {

::tensorflow::NodeDef_ExperimentalDebugInfo* temp = experimental_debug_info_;
experimental_debug_info_ = NULL;
return temp;
}
inline ::tensorflow::NodeDef_ExperimentalDebugInfo* NodeDef::mutable_experimental_debug_info() {

if (experimental_debug_info_ == NULL) {
auto* p = CreateMaybeMessage<::tensorflow::NodeDef_ExperimentalDebugInfo>(GetArenaNoVirtual());
experimental_debug_info_ = p;
}
return experimental_debug_info_;
}
inline void NodeDef::set_allocated_experimental_debug_info(::tensorflow::NodeDef_ExperimentalDebugInfo* experimental_debug_info) {
::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
if (message_arena == NULL) {
delete experimental_debug_info_;
}
if (experimental_debug_info) {
::google::protobuf::Arena* submessage_arena =
::google::protobuf::Arena::GetArena(experimental_debug_info);
if (message_arena != submessage_arena) {
experimental_debug_info = ::google::protobuf::internal::GetOwnedMessage(
message_arena, experimental_debug_info, submessage_arena);
}

} else {

}
experimental_debug_info_ = experimental_debug_info;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  




}  


#endif  
