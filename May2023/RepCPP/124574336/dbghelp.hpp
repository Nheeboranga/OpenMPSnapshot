

#ifndef BOOST_WINAPI_DBGHELP_HPP_INCLUDED_
#define BOOST_WINAPI_DBGHELP_HPP_INCLUDED_

#include <boost/winapi/basic_types.hpp>

#if defined( BOOST_USE_WINDOWS_H )
#if !defined( BOOST_WINAPI_IS_MINGW )
#include <dbghelp.h>
#else
#include <imagehlp.h>
#endif
#endif

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if BOOST_WINAPI_PARTITION_DESKTOP

#include <boost/winapi/detail/header.hpp>

#if defined(API_VERSION_NUMBER)
#if API_VERSION_NUMBER >= 11
#define BOOST_WINAPI_DETAIL_HAS_UNDECORATESYMBOLNAMEW
#endif
#elif defined(_MSC_VER) && _MSC_VER >= 1500
#define BOOST_WINAPI_DETAIL_HAS_UNDECORATESYMBOLNAMEW
#elif !defined(BOOST_WINAPI_IS_MINGW)
#define BOOST_WINAPI_DETAIL_HAS_UNDECORATESYMBOLNAMEW
#endif

#if !defined( BOOST_USE_WINDOWS_H )
extern "C" {

struct API_VERSION;

BOOST_WINAPI_IMPORT boost::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
UnDecorateSymbolName(
boost::winapi::LPCSTR_ DecoratedName,
boost::winapi::LPSTR_ UnDecoratedName,
boost::winapi::DWORD_ UndecoratedLength,
boost::winapi::DWORD_ Flags);

#if defined( BOOST_WINAPI_DETAIL_HAS_UNDECORATESYMBOLNAMEW )
BOOST_WINAPI_IMPORT boost::winapi::DWORD_ BOOST_WINAPI_WINAPI_CC
UnDecorateSymbolNameW(
boost::winapi::LPCWSTR_ DecoratedName,
boost::winapi::LPWSTR_ UnDecoratedName,
boost::winapi::DWORD_ UndecoratedLength,
boost::winapi::DWORD_ Flags);
#endif

BOOST_WINAPI_IMPORT API_VERSION* BOOST_WINAPI_WINAPI_CC
ImagehlpApiVersion(BOOST_WINAPI_DETAIL_VOID);

} 
#endif

namespace boost {
namespace winapi {

#if defined( BOOST_USE_WINDOWS_H )

BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_COMPLETE_ = UNDNAME_COMPLETE;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_LEADING_UNDERSCORES_ = UNDNAME_NO_LEADING_UNDERSCORES;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_MS_KEYWORDS_ = UNDNAME_NO_MS_KEYWORDS;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_FUNCTION_RETURNS_ = UNDNAME_NO_FUNCTION_RETURNS;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_ALLOCATION_MODEL_ = UNDNAME_NO_ALLOCATION_MODEL;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_ALLOCATION_LANGUAGE_ = UNDNAME_NO_ALLOCATION_LANGUAGE;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_MS_THISTYPE_ = UNDNAME_NO_MS_THISTYPE;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_CV_THISTYPE_ = UNDNAME_NO_CV_THISTYPE;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_THISTYPE_ = UNDNAME_NO_THISTYPE;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_ACCESS_SPECIFIERS_ = UNDNAME_NO_ACCESS_SPECIFIERS;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_THROW_SIGNATURES_ = UNDNAME_NO_THROW_SIGNATURES;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_MEMBER_TYPE_ = UNDNAME_NO_MEMBER_TYPE;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_RETURN_UDT_MODEL_ = UNDNAME_NO_RETURN_UDT_MODEL;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_32_BIT_DECODE_ = UNDNAME_32_BIT_DECODE;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NAME_ONLY_ = UNDNAME_NAME_ONLY;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_ARGUMENTS_ = UNDNAME_NO_ARGUMENTS;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_SPECIAL_SYMS_ = UNDNAME_NO_SPECIAL_SYMS;

#else 

BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_COMPLETE_ = 0x00000000;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_LEADING_UNDERSCORES_ = 0x00000001;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_MS_KEYWORDS_ = 0x00000002;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_FUNCTION_RETURNS_ = 0x00000004;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_ALLOCATION_MODEL_ = 0x00000008;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_ALLOCATION_LANGUAGE_ = 0x00000010;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_MS_THISTYPE_ = 0x00000020;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_CV_THISTYPE_ = 0x00000040;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_THISTYPE_ = 0x00000060;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_ACCESS_SPECIFIERS_ = 0x00000080;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_THROW_SIGNATURES_ = 0x00000100;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_MEMBER_TYPE_ = 0x00000200;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_RETURN_UDT_MODEL_ = 0x00000400;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_32_BIT_DECODE_ = 0x00000800;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NAME_ONLY_ = 0x00001000;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_ARGUMENTS_ = 0x00002000;
BOOST_CONSTEXPR_OR_CONST DWORD_ UNDNAME_NO_SPECIAL_SYMS_ = 0x00004000;

#endif 

using ::UnDecorateSymbolName;
#if defined( BOOST_WINAPI_DETAIL_HAS_UNDECORATESYMBOLNAMEW )
using ::UnDecorateSymbolNameW;
#endif

typedef struct BOOST_MAY_ALIAS API_VERSION {
USHORT_  MajorVersion;
USHORT_  MinorVersion;
USHORT_  Revision;
USHORT_  Reserved;
} API_VERSION_, *LPAPI_VERSION_;

BOOST_FORCEINLINE LPAPI_VERSION_ ImagehlpApiVersion()
{
return reinterpret_cast<LPAPI_VERSION_>(::ImagehlpApiVersion());
}

BOOST_FORCEINLINE DWORD_ undecorate_symbol_name(
LPCSTR_ DecoratedName,
LPSTR_ UnDecoratedName,
DWORD_ UndecoratedLength,
DWORD_ Flags)
{
return ::UnDecorateSymbolName(
DecoratedName,
UnDecoratedName,
UndecoratedLength,
Flags);
}

#if defined( BOOST_WINAPI_DETAIL_HAS_UNDECORATESYMBOLNAMEW )

BOOST_FORCEINLINE DWORD_ undecorate_symbol_name(
LPCWSTR_ DecoratedName,
LPWSTR_ UnDecoratedName,
DWORD_ UndecoratedLength,
DWORD_ Flags)
{
return ::UnDecorateSymbolNameW(
DecoratedName,
UnDecoratedName,
UndecoratedLength,
Flags);
}

#endif

}
}

#include <boost/winapi/detail/footer.hpp>

#endif 
#endif 
