


#pragma once


#include "paraverkerneltypes.h"

class KernelConnection;

class ProgressController
{
public:
typedef void(*ProgressHandler)( ProgressController*, void* );

static ProgressController *create( KernelConnection *whichKernel );

ProgressController() {};
virtual ~ProgressController() {};

virtual void setHandler( ProgressHandler whichHandler, void *callerWindow ) = 0;
virtual void callHandler( ProgressController *not_used ) = 0;
virtual double getEndLimit() const = 0;
virtual void setEndLimit( double limit ) = 0;
virtual double getCurrentProgress() const = 0;
virtual void setCurrentProgress( double progress ) = 0;
virtual void setPartner( ProgressController* partner ) = 0;
virtual void setStop( bool value ) = 0;
virtual bool getStop() const = 0;
virtual void setMessage( std::string whichMessage ) = 0;
virtual std::string getMessage() const = 0;
virtual bool getMessageChanged() const = 0;
virtual void clearMessageChanged() = 0;

virtual ProgressController *getConcrete() const
{
return nullptr;
}
};


class ProgressControllerProxy:public ProgressController
{
public:
~ProgressControllerProxy();

void setHandler( ProgressHandler whichHandler, void *callerWindow ) override;
void callHandler( ProgressController *not_used ) override;
double getEndLimit() const override;
void setEndLimit( double limit ) override;
double getCurrentProgress() const override;
void setCurrentProgress( double progress ) override;
void setPartner( ProgressController* partner ) override;
void setStop( bool value ) override;
bool getStop() const override;
void setMessage( std::string whichMessage ) override;
std::string getMessage() const override;
void clearMessageChanged() override;
bool getMessageChanged() const override;

ProgressController *getConcrete() const override;

private:
ProgressControllerProxy( KernelConnection *whichKernel );

KernelConnection *myKernel;
ProgressController *myPartner;

ProgressHandler handler;
void *window;
double endLimit;
double currentProgress;
std::string message;
bool messageChanged;

friend ProgressController *ProgressController::create( KernelConnection * );
};

