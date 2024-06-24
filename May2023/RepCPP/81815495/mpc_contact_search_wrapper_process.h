
#pragma once



#include "processes/process.h"
#include "includes/kratos_parameters.h"
#include "includes/model_part.h"

namespace Kratos
{






class KRATOS_API(CONTACT_STRUCTURAL_MECHANICS_APPLICATION) MPCContactSearchWrapperProcess
: public Process
{
public:

KRATOS_CLASS_POINTER_DEFINITION( MPCContactSearchWrapperProcess );




MPCContactSearchWrapperProcess(
ModelPart& rMainModelPart,
Parameters ThisParameters =  Parameters(R"({})"),
Properties::Pointer pPairedProperties = nullptr
);

virtual ~MPCContactSearchWrapperProcess()= default;;



void operator()()
{
Execute();
}



void Execute() override
{
mpContactProcess->Execute();
}


void ExecuteInitialize() override
{
mpContactProcess->ExecuteInitialize();
}


void ExecuteInitializeSolutionStep() override
{
mpContactProcess->ExecuteInitializeSolutionStep();
}


void ExecuteFinalizeSolutionStep() override
{
mpContactProcess->ExecuteFinalizeSolutionStep();
}


const Parameters GetDefaultParameters() const override;







std::string Info() const override
{
return "MPCContactSearchWrapperProcess";
}




void PrintInfo(std::ostream& rOStream) const override
{
rOStream << Info();
}



protected:



Process::Pointer mpContactProcess = nullptr; 







private:








}; 








inline std::istream& operator >> (std::istream& rIStream,
MPCContactSearchWrapperProcess& rThis);




inline std::ostream& operator << (std::ostream& rOStream,
const MPCContactSearchWrapperProcess& rThis)
{
return rOStream;
}


}  