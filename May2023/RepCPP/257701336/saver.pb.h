
#ifndef PROTOBUF_INCLUDED_tensorflow_2fcore_2fprotobuf_2fsaver_2eproto
#define PROTOBUF_INCLUDED_tensorflow_2fcore_2fprotobuf_2fsaver_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#define PROTOBUF_INTERNAL_EXPORT_protobuf_tensorflow_2fcore_2fprotobuf_2fsaver_2eproto 

namespace protobuf_tensorflow_2fcore_2fprotobuf_2fsaver_2eproto {
struct TableStruct {
static const ::google::protobuf::internal::ParseTableField entries[];
static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
static const ::google::protobuf::internal::ParseTable schema[1];
static const ::google::protobuf::internal::FieldMetadata field_metadata[];
static const ::google::protobuf::internal::SerializationTable serialization_table[];
static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  
namespace tensorflow {
class SaverDef;
class SaverDefDefaultTypeInternal;
extern SaverDefDefaultTypeInternal _SaverDef_default_instance_;
}  
namespace google {
namespace protobuf {
template<> ::tensorflow::SaverDef* Arena::CreateMaybeMessage<::tensorflow::SaverDef>(Arena*);
}  
}  
namespace tensorflow {

enum SaverDef_CheckpointFormatVersion {
SaverDef_CheckpointFormatVersion_LEGACY = 0,
SaverDef_CheckpointFormatVersion_V1 = 1,
SaverDef_CheckpointFormatVersion_V2 = 2,
SaverDef_CheckpointFormatVersion_SaverDef_CheckpointFormatVersion_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
SaverDef_CheckpointFormatVersion_SaverDef_CheckpointFormatVersion_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SaverDef_CheckpointFormatVersion_IsValid(int value);
const SaverDef_CheckpointFormatVersion SaverDef_CheckpointFormatVersion_CheckpointFormatVersion_MIN = SaverDef_CheckpointFormatVersion_LEGACY;
const SaverDef_CheckpointFormatVersion SaverDef_CheckpointFormatVersion_CheckpointFormatVersion_MAX = SaverDef_CheckpointFormatVersion_V2;
const int SaverDef_CheckpointFormatVersion_CheckpointFormatVersion_ARRAYSIZE = SaverDef_CheckpointFormatVersion_CheckpointFormatVersion_MAX + 1;

const ::google::protobuf::EnumDescriptor* SaverDef_CheckpointFormatVersion_descriptor();
inline const ::std::string& SaverDef_CheckpointFormatVersion_Name(SaverDef_CheckpointFormatVersion value) {
return ::google::protobuf::internal::NameOfEnum(
SaverDef_CheckpointFormatVersion_descriptor(), value);
}
inline bool SaverDef_CheckpointFormatVersion_Parse(
const ::std::string& name, SaverDef_CheckpointFormatVersion* value) {
return ::google::protobuf::internal::ParseNamedEnum<SaverDef_CheckpointFormatVersion>(
SaverDef_CheckpointFormatVersion_descriptor(), name, value);
}

class SaverDef : public ::google::protobuf::Message  {
public:
SaverDef();
virtual ~SaverDef();

SaverDef(const SaverDef& from);

inline SaverDef& operator=(const SaverDef& from) {
CopyFrom(from);
return *this;
}
#if LANG_CXX11
SaverDef(SaverDef&& from) noexcept
: SaverDef() {
*this = ::std::move(from);
}

inline SaverDef& operator=(SaverDef&& from) noexcept {
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
static const SaverDef& default_instance();

static void InitAsDefaultInstance();  
static inline const SaverDef* internal_default_instance() {
return reinterpret_cast<const SaverDef*>(
&_SaverDef_default_instance_);
}
static constexpr int kIndexInFileMessages =
0;

void UnsafeArenaSwap(SaverDef* other);
void Swap(SaverDef* other);
friend void swap(SaverDef& a, SaverDef& b) {
a.Swap(&b);
}


inline SaverDef* New() const final {
return CreateMaybeMessage<SaverDef>(NULL);
}

SaverDef* New(::google::protobuf::Arena* arena) const final {
return CreateMaybeMessage<SaverDef>(arena);
}
void CopyFrom(const ::google::protobuf::Message& from) final;
void MergeFrom(const ::google::protobuf::Message& from) final;
void CopyFrom(const SaverDef& from);
void MergeFrom(const SaverDef& from);
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
void InternalSwap(SaverDef* other);
protected:
explicit SaverDef(::google::protobuf::Arena* arena);
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


typedef SaverDef_CheckpointFormatVersion CheckpointFormatVersion;
static const CheckpointFormatVersion LEGACY =
SaverDef_CheckpointFormatVersion_LEGACY;
static const CheckpointFormatVersion V1 =
SaverDef_CheckpointFormatVersion_V1;
static const CheckpointFormatVersion V2 =
SaverDef_CheckpointFormatVersion_V2;
static inline bool CheckpointFormatVersion_IsValid(int value) {
return SaverDef_CheckpointFormatVersion_IsValid(value);
}
static const CheckpointFormatVersion CheckpointFormatVersion_MIN =
SaverDef_CheckpointFormatVersion_CheckpointFormatVersion_MIN;
static const CheckpointFormatVersion CheckpointFormatVersion_MAX =
SaverDef_CheckpointFormatVersion_CheckpointFormatVersion_MAX;
static const int CheckpointFormatVersion_ARRAYSIZE =
SaverDef_CheckpointFormatVersion_CheckpointFormatVersion_ARRAYSIZE;
static inline const ::google::protobuf::EnumDescriptor*
CheckpointFormatVersion_descriptor() {
return SaverDef_CheckpointFormatVersion_descriptor();
}
static inline const ::std::string& CheckpointFormatVersion_Name(CheckpointFormatVersion value) {
return SaverDef_CheckpointFormatVersion_Name(value);
}
static inline bool CheckpointFormatVersion_Parse(const ::std::string& name,
CheckpointFormatVersion* value) {
return SaverDef_CheckpointFormatVersion_Parse(name, value);
}


void clear_filename_tensor_name();
static const int kFilenameTensorNameFieldNumber = 1;
const ::std::string& filename_tensor_name() const;
void set_filename_tensor_name(const ::std::string& value);
#if LANG_CXX11
void set_filename_tensor_name(::std::string&& value);
#endif
void set_filename_tensor_name(const char* value);
void set_filename_tensor_name(const char* value, size_t size);
::std::string* mutable_filename_tensor_name();
::std::string* release_filename_tensor_name();
void set_allocated_filename_tensor_name(::std::string* filename_tensor_name);
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
::std::string* unsafe_arena_release_filename_tensor_name();
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
void unsafe_arena_set_allocated_filename_tensor_name(
::std::string* filename_tensor_name);

void clear_save_tensor_name();
static const int kSaveTensorNameFieldNumber = 2;
const ::std::string& save_tensor_name() const;
void set_save_tensor_name(const ::std::string& value);
#if LANG_CXX11
void set_save_tensor_name(::std::string&& value);
#endif
void set_save_tensor_name(const char* value);
void set_save_tensor_name(const char* value, size_t size);
::std::string* mutable_save_tensor_name();
::std::string* release_save_tensor_name();
void set_allocated_save_tensor_name(::std::string* save_tensor_name);
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
::std::string* unsafe_arena_release_save_tensor_name();
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
void unsafe_arena_set_allocated_save_tensor_name(
::std::string* save_tensor_name);

void clear_restore_op_name();
static const int kRestoreOpNameFieldNumber = 3;
const ::std::string& restore_op_name() const;
void set_restore_op_name(const ::std::string& value);
#if LANG_CXX11
void set_restore_op_name(::std::string&& value);
#endif
void set_restore_op_name(const char* value);
void set_restore_op_name(const char* value, size_t size);
::std::string* mutable_restore_op_name();
::std::string* release_restore_op_name();
void set_allocated_restore_op_name(::std::string* restore_op_name);
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
::std::string* unsafe_arena_release_restore_op_name();
PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
"    string fields are deprecated and will be removed in a"
"    future release.")
void unsafe_arena_set_allocated_restore_op_name(
::std::string* restore_op_name);

void clear_max_to_keep();
static const int kMaxToKeepFieldNumber = 4;
::google::protobuf::int32 max_to_keep() const;
void set_max_to_keep(::google::protobuf::int32 value);

void clear_sharded();
static const int kShardedFieldNumber = 5;
bool sharded() const;
void set_sharded(bool value);

void clear_keep_checkpoint_every_n_hours();
static const int kKeepCheckpointEveryNHoursFieldNumber = 6;
float keep_checkpoint_every_n_hours() const;
void set_keep_checkpoint_every_n_hours(float value);

void clear_version();
static const int kVersionFieldNumber = 7;
::tensorflow::SaverDef_CheckpointFormatVersion version() const;
void set_version(::tensorflow::SaverDef_CheckpointFormatVersion value);

private:

::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
template <typename T> friend class ::google::protobuf::Arena::InternalHelper;
typedef void InternalArenaConstructable_;
typedef void DestructorSkippable_;
::google::protobuf::internal::ArenaStringPtr filename_tensor_name_;
::google::protobuf::internal::ArenaStringPtr save_tensor_name_;
::google::protobuf::internal::ArenaStringPtr restore_op_name_;
::google::protobuf::int32 max_to_keep_;
bool sharded_;
float keep_checkpoint_every_n_hours_;
int version_;
mutable ::google::protobuf::internal::CachedSize _cached_size_;
friend struct ::protobuf_tensorflow_2fcore_2fprotobuf_2fsaver_2eproto::TableStruct;
};



#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  

inline void SaverDef::clear_filename_tensor_name() {
filename_tensor_name_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& SaverDef::filename_tensor_name() const {
return filename_tensor_name_.Get();
}
inline void SaverDef::set_filename_tensor_name(const ::std::string& value) {

filename_tensor_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
}
#if LANG_CXX11
inline void SaverDef::set_filename_tensor_name(::std::string&& value) {

filename_tensor_name_.Set(
&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
}
#endif
inline void SaverDef::set_filename_tensor_name(const char* value) {
GOOGLE_DCHECK(value != NULL);

filename_tensor_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
GetArenaNoVirtual());
}
inline void SaverDef::set_filename_tensor_name(const char* value,
size_t size) {

filename_tensor_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
}
inline ::std::string* SaverDef::mutable_filename_tensor_name() {

return filename_tensor_name_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* SaverDef::release_filename_tensor_name() {

return filename_tensor_name_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline void SaverDef::set_allocated_filename_tensor_name(::std::string* filename_tensor_name) {
if (filename_tensor_name != NULL) {

} else {

}
filename_tensor_name_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), filename_tensor_name,
GetArenaNoVirtual());
}
inline ::std::string* SaverDef::unsafe_arena_release_filename_tensor_name() {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);

return filename_tensor_name_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
GetArenaNoVirtual());
}
inline void SaverDef::unsafe_arena_set_allocated_filename_tensor_name(
::std::string* filename_tensor_name) {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
if (filename_tensor_name != NULL) {

} else {

}
filename_tensor_name_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
filename_tensor_name, GetArenaNoVirtual());
}

inline void SaverDef::clear_save_tensor_name() {
save_tensor_name_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& SaverDef::save_tensor_name() const {
return save_tensor_name_.Get();
}
inline void SaverDef::set_save_tensor_name(const ::std::string& value) {

save_tensor_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
}
#if LANG_CXX11
inline void SaverDef::set_save_tensor_name(::std::string&& value) {

save_tensor_name_.Set(
&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
}
#endif
inline void SaverDef::set_save_tensor_name(const char* value) {
GOOGLE_DCHECK(value != NULL);

save_tensor_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
GetArenaNoVirtual());
}
inline void SaverDef::set_save_tensor_name(const char* value,
size_t size) {

save_tensor_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
}
inline ::std::string* SaverDef::mutable_save_tensor_name() {

return save_tensor_name_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* SaverDef::release_save_tensor_name() {

return save_tensor_name_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline void SaverDef::set_allocated_save_tensor_name(::std::string* save_tensor_name) {
if (save_tensor_name != NULL) {

} else {

}
save_tensor_name_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), save_tensor_name,
GetArenaNoVirtual());
}
inline ::std::string* SaverDef::unsafe_arena_release_save_tensor_name() {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);

return save_tensor_name_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
GetArenaNoVirtual());
}
inline void SaverDef::unsafe_arena_set_allocated_save_tensor_name(
::std::string* save_tensor_name) {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
if (save_tensor_name != NULL) {

} else {

}
save_tensor_name_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
save_tensor_name, GetArenaNoVirtual());
}

inline void SaverDef::clear_restore_op_name() {
restore_op_name_.ClearToEmpty(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const ::std::string& SaverDef::restore_op_name() const {
return restore_op_name_.Get();
}
inline void SaverDef::set_restore_op_name(const ::std::string& value) {

restore_op_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
}
#if LANG_CXX11
inline void SaverDef::set_restore_op_name(::std::string&& value) {

restore_op_name_.Set(
&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
}
#endif
inline void SaverDef::set_restore_op_name(const char* value) {
GOOGLE_DCHECK(value != NULL);

restore_op_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
GetArenaNoVirtual());
}
inline void SaverDef::set_restore_op_name(const char* value,
size_t size) {

restore_op_name_.Set(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(
reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
}
inline ::std::string* SaverDef::mutable_restore_op_name() {

return restore_op_name_.Mutable(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline ::std::string* SaverDef::release_restore_op_name() {

return restore_op_name_.Release(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline void SaverDef::set_allocated_restore_op_name(::std::string* restore_op_name) {
if (restore_op_name != NULL) {

} else {

}
restore_op_name_.SetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), restore_op_name,
GetArenaNoVirtual());
}
inline ::std::string* SaverDef::unsafe_arena_release_restore_op_name() {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);

return restore_op_name_.UnsafeArenaRelease(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
GetArenaNoVirtual());
}
inline void SaverDef::unsafe_arena_set_allocated_restore_op_name(
::std::string* restore_op_name) {
GOOGLE_DCHECK(GetArenaNoVirtual() != NULL);
if (restore_op_name != NULL) {

} else {

}
restore_op_name_.UnsafeArenaSetAllocated(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
restore_op_name, GetArenaNoVirtual());
}

inline void SaverDef::clear_max_to_keep() {
max_to_keep_ = 0;
}
inline ::google::protobuf::int32 SaverDef::max_to_keep() const {
return max_to_keep_;
}
inline void SaverDef::set_max_to_keep(::google::protobuf::int32 value) {

max_to_keep_ = value;
}

inline void SaverDef::clear_sharded() {
sharded_ = false;
}
inline bool SaverDef::sharded() const {
return sharded_;
}
inline void SaverDef::set_sharded(bool value) {

sharded_ = value;
}

inline void SaverDef::clear_keep_checkpoint_every_n_hours() {
keep_checkpoint_every_n_hours_ = 0;
}
inline float SaverDef::keep_checkpoint_every_n_hours() const {
return keep_checkpoint_every_n_hours_;
}
inline void SaverDef::set_keep_checkpoint_every_n_hours(float value) {

keep_checkpoint_every_n_hours_ = value;
}

inline void SaverDef::clear_version() {
version_ = 0;
}
inline ::tensorflow::SaverDef_CheckpointFormatVersion SaverDef::version() const {
return static_cast< ::tensorflow::SaverDef_CheckpointFormatVersion >(version_);
}
inline void SaverDef::set_version(::tensorflow::SaverDef_CheckpointFormatVersion value) {

version_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  


}  

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::tensorflow::SaverDef_CheckpointFormatVersion> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::tensorflow::SaverDef_CheckpointFormatVersion>() {
return ::tensorflow::SaverDef_CheckpointFormatVersion_descriptor();
}

}  
}  


#endif  
