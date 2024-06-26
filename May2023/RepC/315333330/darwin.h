#ifndef CONFIG_DARWIN_H
#define CONFIG_DARWIN_H
#define DARWIN_X86 0
#define DARWIN_PPC 0
#define NO_IMPLICIT_EXTERN_C
#define MATH_LIBRARY ""
#define HAVE_ATEXIT
#define DO_GLOBAL_DTORS_BODY
#ifndef SIZE_TYPE
#define SIZE_TYPE "long unsigned int"
#endif
#undef  PTRDIFF_TYPE
#define PTRDIFF_TYPE "int"
#undef	WCHAR_TYPE
#define WCHAR_TYPE "int"
#undef	WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE 32
#define INT8_TYPE "signed char"
#define INT16_TYPE "short int"
#define INT32_TYPE "int"
#define INT64_TYPE "long long int"
#define UINT8_TYPE "unsigned char"
#define UINT16_TYPE "short unsigned int"
#define UINT32_TYPE "unsigned int"
#define UINT64_TYPE "long long unsigned int"
#define INT_LEAST8_TYPE "signed char"
#define INT_LEAST16_TYPE "short int"
#define INT_LEAST32_TYPE "int"
#define INT_LEAST64_TYPE "long long int"
#define UINT_LEAST8_TYPE "unsigned char"
#define UINT_LEAST16_TYPE "short unsigned int"
#define UINT_LEAST32_TYPE "unsigned int"
#define UINT_LEAST64_TYPE "long long unsigned int"
#define INT_FAST8_TYPE "signed char"
#define INT_FAST16_TYPE "short int"
#define INT_FAST32_TYPE "int"
#define INT_FAST64_TYPE "long long int"
#define UINT_FAST8_TYPE "unsigned char"
#define UINT_FAST16_TYPE "short unsigned int"
#define UINT_FAST32_TYPE "unsigned int"
#define UINT_FAST64_TYPE "long long unsigned int"
#define INTPTR_TYPE "long int"
#define UINTPTR_TYPE "long unsigned int"
#define SIG_ATOMIC_TYPE "int"
#define NEXT_OBJC_RUNTIME 1
#undef	DEFAULT_PCC_STRUCT_RETURN
#define DEFAULT_PCC_STRUCT_RETURN 0
extern GTY(()) int darwin_ms_struct;
#define DRIVER_SELF_SPECS					\
"%{gfull:-g -fno-eliminate-unused-debug-symbols} %<gfull",	\
"%{gused:-g -feliminate-unused-debug-symbols} %<gused",	\
"%{fapple-kext|mkernel:-static}",				\
"%{shared:-Zdynamiclib} %<shared",                            \
"%{gsplit-dwarf:%ngsplit-dwarf is not supported on this platform } \
%<gsplit-dwarf"
#define DARWIN_CC1_SPEC							\
"%{findirect-virtual-calls: -fapple-kext} %<findirect-virtual-calls " \
"%{fterminated-vtables: -fapple-kext} %<fterminated-vtables "		\
"%<filelist* %<framework*"
#define SUBSUBTARGET_OVERRIDE_OPTIONS					\
do {									\
darwin_override_options ();						\
} while (0)
#define SUBTARGET_C_COMMON_OVERRIDE_OPTIONS do {                        \
if (flag_mkernel || flag_apple_kext)				\
{									\
if (flag_use_cxa_atexit == 2)					\
flag_use_cxa_atexit = 0;					\
\
flag_weak = 0;							\
\
flag_rtti = 0;							\
}									\
} while (0)
#undef	CPP_SPEC
#define CPP_SPEC "%{static:%{!dynamic:-D__STATIC__}}%{!static:-D__DYNAMIC__}" \
" %{pthread:-D_REENTRANT}"
#if LD64_HAS_EXPORT_DYNAMIC
#define DARWIN_EXPORT_DYNAMIC " %{rdynamic:-export_dynamic}"
#else
#define DARWIN_EXPORT_DYNAMIC " %{rdynamic: %nrdynamic is not supported}"
#endif
#define LINK_COMMAND_SPEC_A \
"%{!fdump=*:%{!fsyntax-only:%{!c:%{!M:%{!MM:%{!E:%{!S:\
%(linker)" \
LINK_PLUGIN_SPEC \
"%{flto*:%<fcompare-debug*} \
%{flto*} \
%l " LINK_COMPRESS_DEBUG_SPEC \
"%X %{s} %{t} %{Z} %{u*} \
%{e*} %{r} \
%{o*}%{!o:-o a.out} \
%{!nostdlib:%{!nostartfiles:%S}} \
%{L*} %(link_libgcc) %o %{fprofile-arcs|fprofile-generate*|coverage:-lgcov} \
%{fopenacc|fopenmp|%:gt(%{ftree-parallelize-loops=*:%*} 1): \
%{static|static-libgcc|static-libstdc++|static-libgfortran: libgomp.a%s; : -lgomp } } \
%{fgnu-tm: \
%{static|static-libgcc|static-libstdc++|static-libgfortran: libitm.a%s; : -litm } } \
%{!nostdlib:%{!nodefaultlibs:\
%{%:sanitize(address): -lasan } \
%{%:sanitize(undefined): -lubsan } \
%(link_ssp) \
" DARWIN_EXPORT_DYNAMIC " %<rdynamic \
%(link_gcc_c_sequence) \
}}\
%{!nostdlib:%{!nostartfiles:%E}} %{T*} %{F*} }}}}}}}"
#define DSYMUTIL "\ndsymutil"
#define DSYMUTIL_SPEC \
"%{!fdump=*:%{!fsyntax-only:%{!c:%{!M:%{!MM:%{!E:%{!S:\
%{v} \
%{gdwarf-2:%{!gstabs*:%{%:debug-level-gt(0): -idsym}}}\
%{.c|.cc|.C|.cpp|.cp|.c++|.cxx|.CPP|.m|.mm: \
%{gdwarf-2:%{!gstabs*:%{%:debug-level-gt(0): -dsym}}}}}}}}}}}"
#define LINK_COMMAND_SPEC LINK_COMMAND_SPEC_A DSYMUTIL_SPEC
#define COLLECT_RUN_DSYMUTIL 1
#undef  LINK_GCC_C_SEQUENCE_SPEC
#define LINK_GCC_C_SEQUENCE_SPEC "%G %L"
#undef HAVE_LD_SYSROOT
#define HAVE_LD_SYSROOT 1
#define SYSROOT_SPEC "%{!isysroot*:-syslibroot %R/ }"
#define LINK_SYSROOT_SPEC "%{isysroot*:-syslibroot %*}"
#define STANDARD_STARTFILE_PREFIX_1 ""
#define STANDARD_STARTFILE_PREFIX_2 ""
#define DARWIN_PIE_SPEC "%{fpie|pie|fPIE:}"
#define LINK_SPEC  \
"%{static}%{!static:-dynamic} \
%:remove-outfile(-ldl) \
%:remove-outfile(-lm) \
%:remove-outfile(-lpthread) \
%{fgnu-runtime: %{static|static-libgcc: \
%:replace-outfile(-lobjc libobjc-gnu.a%s); \
:%:replace-outfile(-lobjc -lobjc-gnu ) } }\
%{static|static-libgcc|static-libgfortran:%:replace-outfile(-lgfortran libgfortran.a%s)}\
%{static|static-libgcc|static-libstdc++|static-libgfortran:%:replace-outfile(-lgomp libgomp.a%s)}\
%{static|static-libgcc|static-libstdc++:%:replace-outfile(-lstdc++ libstdc++.a%s)}\
%{!Zdynamiclib: \
%{Zforce_cpusubtype_ALL:-arch %(darwin_arch) -force_cpusubtype_ALL} \
%{!Zforce_cpusubtype_ALL:-arch %(darwin_subarch)} \
%{Zbundle:-bundle} \
%{Zbundle_loader*:-bundle_loader %*} \
%{client_name*} \
%{compatibility_version*:%e-compatibility_version only allowed with -dynamiclib\
} \
%{current_version*:%e-current_version only allowed with -dynamiclib} \
%{Zforce_flat_namespace:-force_flat_namespace} \
%{Zinstall_name*:%e-install_name only allowed with -dynamiclib} \
%{keep_private_externs} \
%{private_bundle} \
} \
%{Zdynamiclib: -dylib \
%{Zbundle:%e-bundle not allowed with -dynamiclib} \
%{Zbundle_loader*:%e-bundle_loader not allowed with -dynamiclib} \
%{client_name*:%e-client_name not allowed with -dynamiclib} \
%{compatibility_version*:-dylib_compatibility_version %*} \
%{current_version*:-dylib_current_version %*} \
%{Zforce_cpusubtype_ALL:-arch %(darwin_arch)} \
%{!Zforce_cpusubtype_ALL: -arch %(darwin_subarch)} \
%{Zforce_flat_namespace:%e-force_flat_namespace not allowed with -dynamiclib} \
%{Zinstall_name*:-dylib_install_name %*} \
%{keep_private_externs:%e-keep_private_externs not allowed with -dynamiclib} \
%{private_bundle:%e-private_bundle not allowed with -dynamiclib} \
} \
%{Zall_load:-all_load} \
%{Zallowable_client*:-allowable_client %*} \
%{Zbind_at_load:-bind_at_load} \
%{Zarch_errors_fatal:-arch_errors_fatal} \
%{Zdead_strip:-dead_strip} \
%{Zno_dead_strip_inits_and_terms:-no_dead_strip_inits_and_terms} \
%{Zdylib_file*:-dylib_file %*} \
%{Zdynamic:-dynamic}\
%{Zexported_symbols_list*:-exported_symbols_list %*} \
%{Zflat_namespace:-flat_namespace} \
%{headerpad_max_install_names} \
%{Zimage_base*:-image_base %*} \
%{Zinit*:-init %*} \
%{mmacosx-version-min=*:-macosx_version_min %*} \
%{nomultidefs} \
%{Zmulti_module:-multi_module} %{Zsingle_module:-single_module} \
%{Zmultiply_defined*:-multiply_defined %*} \
%{!Zmultiply_defined*:%{shared-libgcc: \
%:version-compare(< 10.5 mmacosx-version-min= -multiply_defined) \
%:version-compare(< 10.5 mmacosx-version-min= suppress)}} \
%{Zmultiplydefinedunused*:-multiply_defined_unused %*} \
" DARWIN_PIE_SPEC " \
%{prebind} %{noprebind} %{nofixprebinding} %{prebind_all_twolevel_modules} \
%{read_only_relocs} \
%{sectcreate*} %{sectorder*} %{seg1addr*} %{segprot*} \
%{Zsegaddr*:-segaddr %*} \
%{Zsegs_read_only_addr*:-segs_read_only_addr %*} \
%{Zsegs_read_write_addr*:-segs_read_write_addr %*} \
%{Zseg_addr_table*: -seg_addr_table %*} \
%{Zfn_seg_addr_table_filename*:-seg_addr_table_filename %*} \
%{sub_library*} %{sub_umbrella*} \
" LINK_SYSROOT_SPEC " \
%{twolevel_namespace} %{twolevel_namespace_hints} \
%{Zumbrella*: -umbrella %*} \
%{undefined*} \
%{Zunexported_symbols_list*:-unexported_symbols_list %*} \
%{Zweak_reference_mismatches*:-weak_reference_mismatches %*} \
%{!Zweak_reference_mismatches*:-weak_reference_mismatches non-weak} \
%{X} \
%{y*} \
%{w} \
%{pagezero_size*} %{segs_read_*} %{seglinkedit} %{noseglinkedit}  \
%{sectalign*} %{sectobjectsymbols*} %{segcreate*} %{whyload} \
%{whatsloaded} %{dylinker_install_name*} \
%{dylinker} %{Mach} "
#define LIB_SPEC "%{!static:-lSystem}"
#undef REAL_LIBGCC_SPEC
#define REAL_LIBGCC_SPEC						   \
"%{static-libgcc|static: -lgcc_eh -lgcc;				   \
shared-libgcc|fexceptions|fgnu-runtime:				   \
%:version-compare(!> 10.5 mmacosx-version-min= -lgcc_s.10.4)	   \
%:version-compare(>< 10.5 10.6 mmacosx-version-min= -lgcc_s.10.5)   \
%:version-compare(!> 10.5 mmacosx-version-min= -lgcc_ext.10.4)	   \
%:version-compare(>= 10.5 mmacosx-version-min= -lgcc_ext.10.5)	   \
-lgcc ;								   \
:%:version-compare(>< 10.3.9 10.5 mmacosx-version-min= -lgcc_s.10.4) \
%:version-compare(>< 10.5 10.6 mmacosx-version-min= -lgcc_s.10.5)   \
%:version-compare(!> 10.5 mmacosx-version-min= -lgcc_ext.10.4)	   \
%:version-compare(>= 10.5 mmacosx-version-min= -lgcc_ext.10.5)	   \
-lgcc }"
#undef  STARTFILE_SPEC
#define STARTFILE_SPEC							    \
"%{Zdynamiclib: %(darwin_dylib1) %{fgnu-tm: -lcrttms.o}}		    \
%{!Zdynamiclib:%{Zbundle:%{!static:					    \
%:version-compare(< 10.6 mmacosx-version-min= -lbundle1.o)	    \
%{fgnu-tm: -lcrttms.o}}}					    \
%{!Zbundle:%{pg:%{static:-lgcrt0.o}				    \
%{!static:%{object:-lgcrt0.o}			    \
%{!object:%{preload:-lgcrt0.o}		    \
%{!preload:-lgcrt1.o                       \
%:version-compare(>= 10.8 mmacosx-version-min= -no_new_main) \
%(darwin_crt2)}}}}    \
%{!pg:%{static:-lcrt0.o}				    \
%{!static:%{object:-lcrt0.o}			    \
%{!object:%{preload:-lcrt0.o}		    \
%{!preload: %(darwin_crt1)		    \
%(darwin_crt2)}}}}}}	    \
%{shared-libgcc:%:version-compare(< 10.5 mmacosx-version-min= crt3.o%s)}"
#define TM_DESTRUCTOR "%{fgnu-tm: -lcrttme.o}"
#define ENDFILE_SPEC TM_DESTRUCTOR
#define DARWIN_EXTRA_SPECS						\
{ "darwin_crt1", DARWIN_CRT1_SPEC },					\
{ "darwin_dylib1", DARWIN_DYLIB1_SPEC },
#define DARWIN_DYLIB1_SPEC						\
"%:version-compare(!> 10.5 mmacosx-version-min= -ldylib1.o)		\
%:version-compare(>< 10.5 10.6 mmacosx-version-min= -ldylib1.10.5.o)"
#define DARWIN_CRT1_SPEC						\
"%:version-compare(!> 10.5 mmacosx-version-min= -lcrt1.o)		\
%:version-compare(>< 10.5 10.6 mmacosx-version-min= -lcrt1.10.5.o)	\
%:version-compare(>< 10.6 10.8 mmacosx-version-min= -lcrt1.10.6.o)	\
%{fgnu-tm: -lcrttms.o}"
#ifdef HAVE_AS_MMACOSX_VERSION_MIN_OPTION
#define ASM_MMACOSX_VERSION_MIN_SPEC \
" %{asm_macosx_version_min=*: -mmacosx-version-min=%*} %<asm_macosx_version_min=*"
#else
#define ASM_MMACOSX_VERSION_MIN_SPEC " %<asm_macosx_version_min=*"
#endif
#if HAVE_GNU_AS
#define ASM_OPTIONS ""
#else
#define ASM_OPTIONS "%{v} %{w:-W} %{I*}"
#endif
#define ASM_SPEC "-arch %(darwin_arch) \
" ASM_OPTIONS " \
%{Zforce_cpusubtype_ALL:-force_cpusubtype_ALL} \
%{static}" ASM_MMACOSX_VERSION_MIN_SPEC
#define ASM_DEBUG_SPEC  "%{g*:%{%:debug-level-gt(0):%{!gdwarf*:--gstabs}}}"
#define ASM_FINAL_SPEC \
"%{gsplit-dwarf:%ngsplit-dwarf is not supported on this platform } %<gsplit-dwarf"
#ifdef HAVE_AS_STABS_DIRECTIVE
#define DBX_DEBUGGING_INFO 1
#define PREFERRED_DEBUGGING_TYPE DBX_DEBUG
#endif
#define DWARF2_DEBUGGING_INFO 1
#define DEBUG_FRAME_SECTION	  "__DWARF,__debug_frame,regular,debug"
#define DEBUG_INFO_SECTION	  "__DWARF,__debug_info,regular,debug"
#define DEBUG_ABBREV_SECTION	  "__DWARF,__debug_abbrev,regular,debug"
#define DEBUG_ARANGES_SECTION	  "__DWARF,__debug_aranges,regular,debug"
#define DEBUG_MACINFO_SECTION	  "__DWARF,__debug_macinfo,regular,debug"
#define DEBUG_LINE_SECTION	  "__DWARF,__debug_line,regular,debug"
#define DEBUG_LOC_SECTION	  "__DWARF,__debug_loc,regular,debug"
#define DEBUG_LOCLISTS_SECTION    "__DWARF,__debug_loclists,regular,debug"
#define DEBUG_STR_SECTION	  "__DWARF,__debug_str,regular,debug"
#define DEBUG_STR_OFFSETS_SECTION "__DWARF,__debug_str_offs,regular,debug"
#define DEBUG_RANGES_SECTION	  "__DWARF,__debug_ranges,regular,debug"
#define DEBUG_RNGLISTS_SECTION    "__DWARF,__debug_rnglists,regular,debug"
#define DEBUG_MACRO_SECTION       "__DWARF,__debug_macro,regular,debug"
#define DEBUG_LTO_INFO_SECTION	  "__GNU_DWARF_LTO,__debug_info,regular,debug"
#define DEBUG_LTO_ABBREV_SECTION  "__GNU_DWARF_LTO,__debug_abbrev,regular,debug"
#define DEBUG_LTO_MACINFO_SECTION "__GNU_DWARF_LTO,__debug_macinfo,regular,debug"
#define DEBUG_LTO_LINE_SECTION	  "__GNU_DWARF_LTO,__debug_line,regular,debug"
#define DEBUG_LTO_STR_SECTION	  "__GNU_DWARF_LTO,__debug_str,regular,debug"
#define DEBUG_LTO_MACRO_SECTION   "__GNU_DWARF_LTO,__debug_macro,regular,debug"
#define TARGET_WANT_DEBUG_PUB_SECTIONS true
#define DEBUG_PUBNAMES_SECTION   ((debug_generate_pub_sections == 2) \
? "__DWARF,__debug_gnu_pubn,regular,debug" \
: "__DWARF,__debug_pubnames,regular,debug")
#define DEBUG_PUBTYPES_SECTION   ((debug_generate_pub_sections == 2) \
? "__DWARF,__debug_gnu_pubt,regular,debug" \
: "__DWARF,__debug_pubtypes,regular,debug")
#define DBX_USE_BINCL
#define DBX_CONTIN_LENGTH 0
#define DBX_OUTPUT_NULL_N_SO_AT_MAIN_SOURCE_FILE_END
#define MAKE_DECL_ONE_ONLY(DECL) (DECL_WEAK (DECL) = 1)
#define ASM_WEAKEN_DECL(FILE, DECL, NAME, ALIAS)			\
do {									\
if (ALIAS)								\
{									\
warning (0, "alias definitions not supported in Mach-O; ignored");	\
break;								\
}									\
\
if (! DECL_EXTERNAL (DECL) && TREE_PUBLIC (DECL))			\
targetm.asm_out.globalize_label (FILE, NAME);			\
if (DECL_EXTERNAL (DECL))						\
fputs ("\t.weak_reference ", FILE);				\
else if (lookup_attribute ("weak_import", DECL_ATTRIBUTES (DECL)))	\
break;								\
else if (TREE_PUBLIC (DECL))					\
fputs ("\t.weak_definition ", FILE);				\
else								\
break;								\
assemble_name (FILE, NAME);						\
fputc ('\n', FILE);							\
} while (0)
#define GTHREAD_USE_WEAK 0
#define TARGET_CXX_CLASS_DATA_ALWAYS_COMDAT hook_bool_void_false
#define TARGET_CXX_LIBRARY_RTTI_COMDAT hook_bool_void_false
#undef TARGET_USES_WEAK_UNWIND_INFO
#define TARGET_USES_WEAK_UNWIND_INFO 1
#undef FRAME_BEGIN_LABEL
#define FRAME_BEGIN_LABEL (for_eh ? "EH_frame" : "Lframe")
#define TARGET_ASM_EMIT_UNWIND_LABEL darwin_emit_unwind_label
#define TARGET_ASM_EMIT_EXCEPT_TABLE_LABEL darwin_emit_except_table_label
#define NO_PROFILE_COUNTERS	1
#undef	INIT_SECTION_ASM_OP
#define INIT_SECTION_ASM_OP ""
#undef	INVOKE__main
#define TARGET_ASM_CONSTRUCTOR  machopic_asm_out_constructor
#define TARGET_ASM_DESTRUCTOR   machopic_asm_out_destructor
#define USER_LABEL_PREFIX "_"
#define MACHOPIC_FUNCTION_BASE_NAME "<pic base>"
#undef	TARGET_ASM_FILE_START_FILE_DIRECTIVE
#define TARGET_ASM_FILE_START_FILE_DIRECTIVE false
#undef  TARGET_ASM_FILE_END
#define TARGET_ASM_FILE_END darwin_file_end
#undef  TARGET_ASM_LTO_START
#define TARGET_ASM_LTO_START darwin_asm_lto_start
#undef  TARGET_ASM_LTO_END
#define TARGET_ASM_LTO_END darwin_asm_lto_end
#define ASM_OUTPUT_SKIP(FILE,SIZE)  \
fprintf (FILE, "\t.space " HOST_WIDE_INT_PRINT_UNSIGNED"\n", SIZE)
#undef	OBJC_GEN_METHOD_LABEL
#define OBJC_GEN_METHOD_LABEL(BUF,IS_INST,CLASS_NAME,CAT_NAME,SEL_NAME,NUM) \
do { if (CAT_NAME)							\
sprintf (BUF, "%c[%s(%s) %s]", (IS_INST) ? '-' : '+',		\
(CLASS_NAME), (CAT_NAME), (SEL_NAME));		\
else								\
sprintf (BUF, "%c[%s %s]", (IS_INST) ? '-' : '+',		\
(CLASS_NAME), (SEL_NAME));				\
} while (0)
#undef ASM_DECLARE_OBJECT_NAME
#define ASM_DECLARE_OBJECT_NAME(FILE, NAME, DECL) \
darwin_asm_declare_object_name ((FILE), (NAME), (DECL))
#define ASM_DECLARE_FUNCTION_NAME(FILE, NAME, DECL)			\
do {									\
const char *xname = NAME;						\
if (GET_CODE (XEXP (DECL_RTL (DECL), 0)) != SYMBOL_REF)		\
xname = IDENTIFIER_POINTER (DECL_NAME (DECL));			\
if (! DECL_WEAK (DECL)						\
&& ((TREE_STATIC (DECL)						\
&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\
|| DECL_INITIAL (DECL)))					\
machopic_define_symbol (DECL_RTL (DECL));			\
if ((TREE_STATIC (DECL)						\
&& (!DECL_COMMON (DECL) || !TREE_PUBLIC (DECL)))		\
|| DECL_INITIAL (DECL))						\
(* targetm.encode_section_info) (DECL, DECL_RTL (DECL), false);	\
ASM_OUTPUT_FUNCTION_LABEL (FILE, xname, DECL);			\
} while (0)
#undef TARGET_ASM_DECLARE_CONSTANT_NAME
#define TARGET_ASM_DECLARE_CONSTANT_NAME darwin_asm_declare_constant_name
int darwin_label_is_anonymous_local_objc_name (const char *name);
#undef	ASM_OUTPUT_LABELREF
#define ASM_OUTPUT_LABELREF(FILE,NAME)					     \
do {									     \
const char *xname = (NAME);					     \
if (! strcmp (xname, MACHOPIC_FUNCTION_BASE_NAME))		     \
machopic_output_function_base_name(FILE);                           \
else if (xname[0] == '&' || xname[0] == '*')			     \
{								     \
int len = strlen (xname);					     \
if (len > 6 && !strcmp ("$stub", xname + len - 5))		     \
machopic_validate_stub_or_non_lazy_ptr (xname);		     \
else if (len > 7 && !strcmp ("$stub\"", xname + len - 6))	     \
machopic_validate_stub_or_non_lazy_ptr (xname);		     \
else if (len > 14 && !strcmp ("$non_lazy_ptr", xname + len - 13)) \
machopic_validate_stub_or_non_lazy_ptr (xname);		     \
else if (len > 15 && !strcmp ("$non_lazy_ptr\"", xname + len - 14)) \
machopic_validate_stub_or_non_lazy_ptr (xname);		     \
if (xname[1] != '"' && name_needs_quotes (&xname[1]))	     \
fprintf (FILE, "\"%s\"", &xname[1]);			     \
else								     \
fputs (&xname[1], FILE); 					     \
}								     \
else if (xname[0] == '+' || xname[0] == '-')			     \
fprintf (FILE, "\"%s\"", xname);				     \
else if (darwin_label_is_anonymous_local_objc_name (xname))	     \
fprintf (FILE, "L%s", xname);					     \
else if (xname[0] != '"' && name_needs_quotes (xname))		     \
asm_fprintf (FILE, "\"%U%s\"", xname);				     \
else								     \
asm_fprintf (FILE, "%U%s", xname);				     \
} while (0)
#undef TEXT_SECTION_ASM_OP
#define TEXT_SECTION_ASM_OP "\t.text"
#undef DATA_SECTION_ASM_OP
#define DATA_SECTION_ASM_OP "\t.data"
#undef	ALIGN_ASM_OP
#define ALIGN_ASM_OP		".align"
#undef	ASM_OUTPUT_ALIGN
#define ASM_OUTPUT_ALIGN(FILE,LOG)	\
if ((LOG) != 0)			\
fprintf (FILE, "\t%s\t%d\n", ALIGN_ASM_OP, (LOG))
#undef	MAX_OFILE_ALIGNMENT
#define MAX_OFILE_ALIGNMENT (0x8000 * 8)
#define L2_MAX_OFILE_ALIGNMENT 15
#define ASM_OUTPUT_ALIGNED_BSS(FILE, DECL, NAME, SIZE, ALIGN)		\
darwin_output_aligned_bss ((FILE), (DECL), (NAME), (SIZE), (ALIGN))
#undef	ASM_OUTPUT_ALIGNED_DECL_LOCAL
#define ASM_OUTPUT_ALIGNED_DECL_LOCAL(FILE, DECL, NAME, SIZE, ALIGN)	\
darwin_asm_output_aligned_decl_local				\
((FILE), (DECL), (NAME), (SIZE), (ALIGN))
#undef  ASM_OUTPUT_ALIGNED_DECL_COMMON
#define ASM_OUTPUT_ALIGNED_DECL_COMMON(FILE, DECL, NAME, SIZE, ALIGN)	\
darwin_asm_output_aligned_decl_common				\
((FILE), (DECL), (NAME), (SIZE), (ALIGN))
#define MACHOPIC_NL_SYMBOL_PTR_SECTION ".non_lazy_symbol_pointer"
#ifndef USED_FOR_TARGET
enum darwin_section_enum {
#define DEF_SECTION(NAME, FLAGS, DIRECTIVE, OBJC) NAME,
#include "darwin-sections.def"
#undef DEF_SECTION
NUM_DARWIN_SECTIONS
};
extern GTY(()) section * darwin_sections[NUM_DARWIN_SECTIONS];
#endif
#undef	TARGET_ASM_SELECT_SECTION
#define TARGET_ASM_SELECT_SECTION machopic_select_section
#undef	TARGET_ASM_FUNCTION_SECTION
#define TARGET_ASM_FUNCTION_SECTION darwin_function_section
#undef	TARGET_ASM_SELECT_RTX_SECTION
#define TARGET_ASM_SELECT_RTX_SECTION machopic_select_rtx_section
#undef  TARGET_ASM_UNIQUE_SECTION
#define TARGET_ASM_UNIQUE_SECTION darwin_unique_section
#undef  TARGET_ASM_FUNCTION_RODATA_SECTION
#define TARGET_ASM_FUNCTION_RODATA_SECTION default_no_function_rodata_section
#undef  TARGET_ASM_TM_CLONE_TABLE_SECTION
#define TARGET_ASM_TM_CLONE_TABLE_SECTION darwin_tm_clone_table_section
#undef  TARGET_ASM_RELOC_RW_MASK
#define TARGET_ASM_RELOC_RW_MASK machopic_reloc_rw_mask
#define GLOBAL_ASM_OP "\t.globl "
#define TARGET_ASM_GLOBALIZE_LABEL darwin_globalize_label
#undef TARGET_ASM_ASSEMBLE_VISIBILITY
#define TARGET_ASM_ASSEMBLE_VISIBILITY darwin_assemble_visibility
#define SUBTARGET_ATTRIBUTE_TABLE					     \
\
{ "apple_kext_compatibility", 0, 0, false, true, false, false,	     \
darwin_handle_kext_attribute, NULL },				     \
{ "weak_import", 0, 0, true, false, false, false,			     \
darwin_handle_weak_import_attribute, NULL }
#undef ASM_GENERATE_INTERNAL_LABEL
#define ASM_GENERATE_INTERNAL_LABEL(LABEL,PREFIX,NUM)	\
do {							\
if (strcmp ("LC", PREFIX) == 0)			\
sprintf (LABEL, "*%s%ld", "lC", (long)(NUM));	\
else						\
sprintf (LABEL, "*%s%ld", PREFIX, (long)(NUM));	\
} while (0)
#undef TARGET_ASM_MARK_DECL_PRESERVED
#define TARGET_ASM_MARK_DECL_PRESERVED darwin_mark_decl_preserved
#define MACHO_SYMBOL_FLAG_VARIABLE (SYMBOL_FLAG_MACH_DEP)
#define MACHO_SYMBOL_FLAG_DEFINED ((SYMBOL_FLAG_MACH_DEP) << 1)
#define MACHO_SYMBOL_STATIC ((SYMBOL_FLAG_MACH_DEP) << 2)
enum machopic_addr_class {
MACHOPIC_UNDEFINED,
MACHOPIC_DEFINED_DATA,
MACHOPIC_UNDEFINED_DATA,
MACHOPIC_DEFINED_FUNCTION,
MACHOPIC_UNDEFINED_FUNCTION
};
#undef  MACHO_DYNAMIC_NO_PIC_P
#define MACHO_DYNAMIC_NO_PIC_P	(TARGET_MACHO_DYNAMIC_NO_PIC)
#undef  MACHOPIC_INDIRECT
#define MACHOPIC_INDIRECT	(flag_pic || MACHO_DYNAMIC_NO_PIC_P)
#define MACHOPIC_JUST_INDIRECT	(MACHO_DYNAMIC_NO_PIC_P)
#undef  MACHOPIC_PURE
#define MACHOPIC_PURE		(flag_pic && ! MACHO_DYNAMIC_NO_PIC_P)
#undef TARGET_ENCODE_SECTION_INFO
#define TARGET_ENCODE_SECTION_INFO  darwin_encode_section_info
#undef TARGET_STRIP_NAME_ENCODING
#define TARGET_STRIP_NAME_ENCODING  default_strip_name_encoding
#define GEN_BINDER_NAME_FOR_STUB(BUF,STUB,STUB_LENGTH)		\
do {								\
const char *const stub_ = (STUB);				\
char *buffer_ = (BUF);					\
strcpy (buffer_, stub_);					\
if (stub_[0] == '"')					\
{								\
strcpy (buffer_ + (STUB_LENGTH) - 1, "_binder\"");	\
}								\
else							\
{								\
strcpy (buffer_ + (STUB_LENGTH), "_binder");		\
}								\
} while (0)
#define GEN_SYMBOL_NAME_FOR_SYMBOL(BUF,SYMBOL,SYMBOL_LENGTH)	\
do {								\
const char *const symbol_ = (SYMBOL);			\
char *buffer_ = (BUF);					\
if (name_needs_quotes (symbol_) && symbol_[0] != '"')	\
{								\
sprintf (buffer_, "\"%s\"", symbol_);			\
}								\
else							\
{								\
strcpy (buffer_, symbol_);				\
}								\
} while (0)
#define GEN_LAZY_PTR_NAME_FOR_SYMBOL(BUF,SYMBOL,SYMBOL_LENGTH)	\
do {								\
const char *symbol_ = (SYMBOL);                             \
char *buffer_ = (BUF);					\
if (symbol_[0] == '"')					\
{								\
strcpy (buffer_, "\"L");				\
strcpy (buffer_ + 2, symbol_ + 1);			\
strcpy (buffer_ + (SYMBOL_LENGTH), "$lazy_ptr\"");	\
}								\
else if (name_needs_quotes (symbol_))			\
{								\
strcpy (buffer_, "\"L");				\
strcpy (buffer_ + 2, symbol_);				\
strcpy (buffer_ + (SYMBOL_LENGTH) + 2, "$lazy_ptr\"");	\
}								\
else							\
{								\
strcpy (buffer_, "L");					\
strcpy (buffer_ + 1, symbol_);				\
strcpy (buffer_ + (SYMBOL_LENGTH) + 1, "$lazy_ptr");	\
}								\
} while (0)
#define EH_FRAME_SECTION_NAME   "__TEXT"
#define EH_FRAME_SECTION_ATTR ",coalesced,no_toc+strip_static_syms+live_support"
#undef ASM_PREFERRED_EH_DATA_FORMAT
#define ASM_PREFERRED_EH_DATA_FORMAT(CODE,GLOBAL)  \
(((CODE) == 2 && (GLOBAL) == 1) \
? (DW_EH_PE_pcrel | DW_EH_PE_indirect | DW_EH_PE_sdata4) : \
((CODE) == 1 || (GLOBAL) == 0) ? DW_EH_PE_pcrel : DW_EH_PE_absptr)
#define ASM_OUTPUT_DWARF_DELTA(FILE,SIZE,LABEL1,LABEL2)  \
darwin_asm_output_dwarf_delta (FILE, SIZE, LABEL1, LABEL2, 0)
#define ASM_OUTPUT_DWARF_OFFSET(FILE,SIZE,LABEL,OFFSET,BASE)  \
darwin_asm_output_dwarf_offset (FILE, SIZE, LABEL, OFFSET, BASE)
#define ASM_MAYBE_OUTPUT_ENCODED_ADDR_RTX(ASM_OUT_FILE, ENCODING, SIZE, ADDR, DONE)	\
if (ENCODING == ASM_PREFERRED_EH_DATA_FORMAT (2, 1)) {				\
darwin_non_lazy_pcrel (ASM_OUT_FILE, ADDR);					\
goto DONE;									\
}
#ifndef JUMP_TABLES_IN_TEXT_SECTION
#define JUMP_TABLES_IN_TEXT_SECTION 1
#endif
#define TARGET_TERMINATE_DW2_EH_FRAME_INFO false
#define TARGET_ASM_INIT_SECTIONS darwin_init_sections
#undef TARGET_ASM_NAMED_SECTION
#define TARGET_ASM_NAMED_SECTION darwin_asm_named_section
#define DARWIN_REGISTER_TARGET_PRAGMAS()			\
do {								\
if (!flag_preprocess_only)					\
cpp_register_pragma (parse_in, NULL, "mark",		\
darwin_pragma_ignore, false);	\
c_register_pragma (0, "options", darwin_pragma_options);	\
c_register_pragma (0, "segment", darwin_pragma_ignore);	\
c_register_pragma (0, "unused", darwin_pragma_unused);	\
c_register_pragma (0, "ms_struct", darwin_pragma_ms_struct); \
} while (0)
#undef ASM_APP_ON
#define ASM_APP_ON ""
#undef ASM_APP_OFF
#define ASM_APP_OFF ""
void darwin_register_frameworks (const char *, const char *, int);
void darwin_register_objc_includes (const char *, const char *, int);
#define TARGET_EXTRA_PRE_INCLUDES darwin_register_objc_includes
#define TARGET_EXTRA_INCLUDES darwin_register_frameworks
void add_framework_path (char *);
#define TARGET_OPTF add_framework_path
#define TARGET_POSIX_IO
#define WINT_TYPE "int"
#undef GOMP_SELF_SPECS
#define GOMP_SELF_SPECS ""
#undef GTM_SELF_SPECS
#define GTM_SELF_SPECS ""
#define TARGET_ASM_OUTPUT_ANCHOR NULL
#define DARWIN_SECTION_ANCHORS 0
#define HAVE_ENABLE_EXECUTE_STACK
#define TARGET_CXX_CDTOR_RETURNS_THIS (darwin_kextabi_p)
#define TARGET_KEXTABI flag_apple_kext
#define SUBTARGET_FOLD_BUILTIN darwin_fold_builtin
#define TARGET_N_FORMAT_TYPES 1
#define TARGET_FORMAT_TYPES darwin_additional_format_types
#ifndef USED_FOR_TARGET
extern void darwin_driver_init (unsigned int *,struct cl_decoded_option **);
#define GCC_DRIVER_HOST_INITIALIZATION \
darwin_driver_init (&decoded_options_count, &decoded_options)
#endif
#undef SUPPORTS_INIT_PRIORITY
#define SUPPORTS_INIT_PRIORITY 0
#define DEF_MIN_OSX_VERSION "10.5"
#define MIN_LD64_NO_COAL_SECTS "236.4"
#ifndef LD64_VERSION
#define LD64_VERSION "85.2"
#else
#define DEF_LD64 LD64_VERSION
#endif
#endif 
