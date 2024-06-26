#ifndef GCC_V850_PROTOS_H
#define GCC_V850_PROTOS_H
extern void   expand_prologue               (void);
extern void   expand_epilogue               (void);
extern int    v850_handle_pragma            (int (*)(void), void (*)(int), char *);
extern int    compute_register_save_size    (long *);
extern int    compute_frame_size            (poly_int64, long *);
extern void   v850_init_expanders           (void);
#ifdef RTX_CODE
extern rtx    v850_return_addr              (int);
extern const char *output_move_single       (rtx *);
extern void   notice_update_cc              (rtx, rtx_insn *);
extern char * construct_save_jarl           (rtx);
extern char * construct_restore_jr          (rtx);
#ifdef HAVE_MACHINE_MODES
extern char * construct_dispose_instruction (rtx);
extern char * construct_prepare_instruction (rtx);
extern int    ep_memory_operand             (rtx, machine_mode, int);
extern int    v850_adjust_insn_length       (rtx_insn *, int);
extern const char * v850_gen_movdi          (rtx *);
extern rtx    v850_gen_compare              (enum rtx_code, machine_mode,
rtx, rtx);
extern machine_mode  v850_gen_float_compare (enum rtx_code,
machine_mode, rtx, rtx);
extern machine_mode  v850_select_cc_mode (RTX_CODE, rtx, rtx);
#endif
#endif 
#ifdef TREE_CODE
extern int    v850_interrupt_function_p     (tree);
extern void   v850_output_aligned_bss       (FILE *, tree, const char *, unsigned HOST_WIDE_INT, int);
extern void   v850_output_common            (FILE *, tree, const char *, int, int);
extern void   v850_output_local             (FILE *, tree, const char *, int, int);
extern v850_data_area v850_get_data_area    (tree);
#endif
extern void ghs_pragma_section		    (struct cpp_reader *);
extern void ghs_pragma_interrupt	    (struct cpp_reader *);
extern void ghs_pragma_starttda		    (struct cpp_reader *);
extern void ghs_pragma_startsda		    (struct cpp_reader *);
extern void ghs_pragma_startzda		    (struct cpp_reader *);
extern void ghs_pragma_endtda		    (struct cpp_reader *);
extern void ghs_pragma_endsda		    (struct cpp_reader *);
extern void ghs_pragma_endzda		    (struct cpp_reader *);
#endif 
