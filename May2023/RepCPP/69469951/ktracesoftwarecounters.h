


#pragma once


#include "ktraceoptions.h"
#include "tracesoftwarecounters.h"

class KTraceSoftwareCounters : public TraceSoftwareCounters
{
public:
KTraceSoftwareCounters( char *trace_in,
char *trace_out,
TraceOptions *options,
ProgressController *progress );
virtual ~KTraceSoftwareCounters();
void execute( char *trace_in, char *trace_out, ProgressController *progress );

private:

struct counter
{
unsigned long long type;
unsigned long long value;
unsigned long long num;
bool last_is_zero;
};

struct stack
{
unsigned long long type[5];
bool valid[5];
int top;
};

struct ParaverEvent
{
int thread_id;
int cpu;
unsigned long long timestamp;
unsigned long long type[16];
unsigned long long value[16];
struct ParaverEvent *next_event;
struct ParaverEvent *previous_event;
};

struct counter_event
{
int cpu;
unsigned long long time;
unsigned long long type;
unsigned long long value;
struct counter_event *next;
};

struct thread_info
{
int appl;
int task;
int thread;
struct counter counters[150];
int next_free_counter;
struct stack calls;
unsigned long long last_time_of_sc;
unsigned long long ini_burst_time;
unsigned long long end_burst_time;
unsigned long long total_burst_time; 
struct counter_event *first_event_counter;
struct counter_event *last_event_counter;
};

struct type_values
{
unsigned long long type;
bool all_values;
unsigned long long values[16];
};

struct sc_allowed_types
{
struct type_values type_values[16];
int next_free_slot;
};

struct sc_kept_types
{
unsigned long long type[16];
int next_free_slot;
};

struct state_queue_elem
{
unsigned long long last_state_end_time;
int thread_id;
struct state_queue_elem *next;
};

char line[MAX_LINE_SIZE];  


bool all_types;
bool global_counters;
bool acumm_values;
bool remove_states;
bool only_in_bursts;
bool summarize_bursts;
unsigned long long interval;
unsigned long long last_time;
unsigned long long trace_time;
unsigned long long type_marks[10];
unsigned long long min_state_time;
struct sc_allowed_types types;
int last_type_mark;
bool type_of_counters;
bool keep_events;
int frequency;


FILE *infile, *outfile;
KTraceOptions *exec_options;


int thread_pointer[MAX_APPL][MAX_TASK][MAX_THREAD];


struct ParaverEvent *first_Paraver_event;
struct ParaverEvent *last_Paraver_event;


struct thread_info threads[MAX_THREADS];
int next_thread_slot;


unsigned long long total_trace_size;
unsigned long long current_read_size;
unsigned long total_iters;


struct state_queue_elem *first_state_elem;


struct sc_kept_types types_to_keep;

void read_sc_args();
void proces_header( char *header, FILE *in, FILE *out );
void write_pcf( char *file_out );
bool allowed_type( unsigned long long type, unsigned long long value );
bool allowed_type_mark( unsigned long long type );
int inc_counter( int appl, int task, int thread,
unsigned long long type, unsigned long long value );
void put_zeros( void );
void flush_all_events( void );
void put_all_counters( void );
void put_counters_by_thread( int appl, int task, int thread, int cpu );
void ini_progress_bar( char *file_name, ProgressController *progress );
void show_progress_bar( ProgressController *progress );
void put_counters_on_state_by_thread( int appl, int task, int thread );
void sc_by_time( ProgressController *progress );
void flush_counter_buffers( void );
void sc_by_event( ProgressController *progress );
void insert_in_queue_state( int thread_id, unsigned long long time );
void put_counters_on_state( struct KTraceSoftwareCounters::state_queue_elem *p,
struct KTraceSoftwareCounters::state_queue_elem *q );
void sc_by_states( ProgressController *progress );
};
