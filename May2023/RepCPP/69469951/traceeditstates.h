


#pragma once


#include <string>
#include "kernelconnection.h"
#include "textoutput.h"

class TraceEditSequence;
class TraceOptions;
class Timeline;

template< bool v > struct BoolToType;

template< class SeqT >
class BaseTraceEditState
{
public:
BaseTraceEditState();
BaseTraceEditState( SeqT whichSequence );
~BaseTraceEditState();
void init();

protected:
SeqT mySequence;
};


template< class SeqT, class DataT >
class DerivedTraceEditState : public BaseTraceEditState< SeqT >
{
public:
DerivedTraceEditState( SeqT whichSequence );
~DerivedTraceEditState();
void init();

DataT getData() const;
void setData( DataT whichData );

private:
DataT myData;

void firstInit();
void firstInit( BoolToType< true > );
void firstInit( BoolToType< false > );

void init( BoolToType< true > );
void init( BoolToType< false > );
};


template< class SeqT >
class DerivedTraceEditStateBool : public BaseTraceEditState< SeqT >
{
public:
DerivedTraceEditStateBool( SeqT whichSequence );
~DerivedTraceEditStateBool();
void init();

bool getData() const;
void setData( bool whichData );

private:
bool myData;
};


template< class SeqT >
class DerivedTraceEditStateInt : public BaseTraceEditState< SeqT >
{
public:
DerivedTraceEditStateInt( SeqT whichSequence );
~DerivedTraceEditStateInt();
void init();

int getData() const;
void setData( int whichData );

private:
int myData;
};


template< class SeqT >
class DerivedTraceEditStateString : public BaseTraceEditState< SeqT >
{
public:
DerivedTraceEditStateString( SeqT whichSequence );
~DerivedTraceEditStateString();
void init();

std::string getData() const;
void setData( std::string whichData );

private:
std::string myData;
};


template< class SeqT >
class DerivedTraceEditStateTTime : public BaseTraceEditState< SeqT >
{
public:
DerivedTraceEditStateTTime( SeqT whichSequence );
~DerivedTraceEditStateTTime();
void init();

TTime getData() const;
void setData( TTime whichData );

private:
TTime myData;
};


template< class SeqT >
class DerivedTraceEditStateTWindowLevel : public BaseTraceEditState< SeqT >
{
public:
DerivedTraceEditStateTWindowLevel( SeqT whichSequence );
~DerivedTraceEditStateTWindowLevel();
void init();

TWindowLevel getData() const;
void setData( TWindowLevel whichData );

private:
TWindowLevel myData;
};

template< class SeqT >
class DerivedTraceEditStateTEventType : public BaseTraceEditState< SeqT >
{
public:
DerivedTraceEditStateTEventType( SeqT whichSequence );
~DerivedTraceEditStateTEventType();
void init();

TEventType getData() const;
void setData( TEventType whichData );

private:
TEventType myData;
};

#include "traceeditstates_impl.h"

typedef BaseTraceEditState< TraceEditSequence * > TraceEditState;

typedef DerivedTraceEditState< TraceEditSequence *, TextOutput > CSVOutputState;
typedef DerivedTraceEditState< TraceEditSequence *, TraceOptions * > TraceOptionsState;
typedef DerivedTraceEditState< TraceEditSequence *, Timeline * > SourceTimelineState;
typedef DerivedTraceEditState< TraceEditSequence *, std::vector< TTime > * > ShiftTimesState;
typedef DerivedTraceEditState< TraceEditSequence *, std::map< TTypeValuePair, TTypeValuePair > > EventTranslationTableState;

typedef DerivedTraceEditStateBool< TraceEditSequence * > EOFParsedState;
typedef DerivedTraceEditStateBool< TraceEditSequence * > CopyAdditionalFilesState;
typedef DerivedTraceEditStateBool< TraceEditSequence * > OnlyFilterState;

typedef DerivedTraceEditStateInt< TraceEditSequence * > TestState;

typedef DerivedTraceEditStateString< TraceEditSequence * > CSVFileNameState;
typedef DerivedTraceEditStateString< TraceEditSequence * > OutputDirSuffixState;
typedef DerivedTraceEditStateString<TraceEditSequence * > OutputTraceFileNameState;
typedef DerivedTraceEditStateString<TraceEditSequence * > PCFMergerReferenceState;

typedef DerivedTraceEditStateTTime< TraceEditSequence * > MaxTraceTimeState;
typedef DerivedTraceEditStateTWindowLevel< TraceEditSequence * > ShiftLevelState;
typedef DerivedTraceEditStateTEventType< TraceEditSequence * > OnEventCutter;


