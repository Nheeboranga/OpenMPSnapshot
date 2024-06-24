
#ifndef PROTOBUF_INCLUDED_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto
#define PROTOBUF_INCLUDED_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_protobuf_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto 

namespace protobuf_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto {
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
class RecvBufRespExtra;
class RecvBufRespExtraDefaultTypeInternal;
extern RecvBufRespExtraDefaultTypeInternal _RecvBufRespExtra_default_instance_;
}  
namespace google {
namespace protobuf {
template<> ::tensorflow::RecvBufRespExtra* Arena::CreateMaybeMessage<::tensorflow::RecvBufRespExtra>(Arena*);
}  
}  
namespace tensorflow {


class RecvBufRespExtra : public ::google::protobuf::Message  {
public:
RecvBufRespExtra();
virtual ~RecvBufRespExtra();

RecvBufRespExtra(const RecvBufRespExtra& from);

inline RecvBufRespExtra& operator=(const RecvBufRespExtra& from) {
CopyFrom(from);
return *this;
}
#if LANG_CXX11
RecvBufRespExtra(RecvBufRespExtra&& from) noexcept
: RecvBufRespExtra() {
*this = ::std::move(from);
}

inline RecvBufRespExtra& operator=(RecvBufRespExtra&& from) noexcept {
if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
if (this != &from) InternalSwap(&from);
} else {
CopyFrom(from);
}
return *this;
}
#endif
static const ::google::protobuf::Descriptor* descriptor();
static const RecvBufRespExtra& default_instance();

static void InitAsDefaultInstance();  
static inline const RecvBufRespExtra* internal_default_instance() {
return reinterpret_cast<const RecvBufRespExtra*>(
&_RecvBufRespExtra_default_instance_);
}
static constexpr int kIndexInFileMessages =
0;

void Swap(RecvBufRespExtra* other);
friend void swap(RecvBufRespExtra& a, RecvBufRespExtra& b) {
a.Swap(&b);
}


inline RecvBufRespExtra* New() const final {
return CreateMaybeMessage<RecvBufRespExtra>(NULL);
}

RecvBufRespExtra* New(::google::protobuf::Arena* arena) const final {
return CreateMaybeMessage<RecvBufRespExtra>(arena);
}
void CopyFrom(const ::google::protobuf::Message& from) final;
void MergeFrom(const ::google::protobuf::Message& from) final;
void CopyFrom(const RecvBufRespExtra& from);
void MergeFrom(const RecvBufRespExtra& from);
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
void InternalSwap(RecvBufRespExtra* other);
private:
inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
return NULL;
}
inline void* MaybeArenaPtr() const {
return NULL;
}
public:

::google::protobuf::Metadata GetMetadata() const final;



int tensor_content_size() const;
void clear_tensor_content();
static const int kTensorContentFieldNumber = 1;
const ::std::string& tensor_content(int index) const;
::std::string* mutable_tensor_content(int index);
void set_tensor_content(int index, const ::std::string& value);
#if LANG_CXX11
void set_tensor_content(int index, ::std::string&& value);
#endif
void set_tensor_content(int index, const char* value);
void set_tensor_content(int index, const void* value, size_t size);
::std::string* add_tensor_content();
void add_tensor_content(const ::std::string& value);
#if LANG_CXX11
void add_tensor_content(::std::string&& value);
#endif
void add_tensor_content(const char* value);
void add_tensor_content(const void* value, size_t size);
const ::google::protobuf::RepeatedPtrField< ::std::string>& tensor_content() const;
::google::protobuf::RepeatedPtrField< ::std::string>* mutable_tensor_content();

private:

::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
::google::protobuf::RepeatedPtrField< ::std::string> tensor_content_;
mutable ::google::protobuf::internal::CachedSize _cached_size_;
friend struct ::protobuf_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto::TableStruct;
};



#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  

inline int RecvBufRespExtra::tensor_content_size() const {
return tensor_content_.size();
}
inline void RecvBufRespExtra::clear_tensor_content() {
tensor_content_.Clear();
}
inline const ::std::string& RecvBufRespExtra::tensor_content(int index) const {
return tensor_content_.Get(index);
}
inline ::std::string* RecvBufRespExtra::mutable_tensor_content(int index) {
return tensor_content_.Mutable(index);
}
inline void RecvBufRespExtra::set_tensor_content(int index, const ::std::string& value) {
tensor_content_.Mutable(index)->assign(value);
}
#if LANG_CXX11
inline void RecvBufRespExtra::set_tensor_content(int index, ::std::string&& value) {
tensor_content_.Mutable(index)->assign(std::move(value));
}
#endif
inline void RecvBufRespExtra::set_tensor_content(int index, const char* value) {
GOOGLE_DCHECK(value != NULL);
tensor_content_.Mutable(index)->assign(value);
}
inline void RecvBufRespExtra::set_tensor_content(int index, const void* value, size_t size) {
tensor_content_.Mutable(index)->assign(
reinterpret_cast<const char*>(value), size);
}
inline ::std::string* RecvBufRespExtra::add_tensor_content() {
return tensor_content_.Add();
}
inline void RecvBufRespExtra::add_tensor_content(const ::std::string& value) {
tensor_content_.Add()->assign(value);
}
#if LANG_CXX11
inline void RecvBufRespExtra::add_tensor_content(::std::string&& value) {
tensor_content_.Add(std::move(value));
}
#endif
inline void RecvBufRespExtra::add_tensor_content(const char* value) {
GOOGLE_DCHECK(value != NULL);
tensor_content_.Add()->assign(value);
}
inline void RecvBufRespExtra::add_tensor_content(const void* value, size_t size) {
tensor_content_.Add()->assign(reinterpret_cast<const char*>(value), size);
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
RecvBufRespExtra::tensor_content() const {
return tensor_content_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
RecvBufRespExtra::mutable_tensor_content() {
return &tensor_content_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  


}  


#endif  
