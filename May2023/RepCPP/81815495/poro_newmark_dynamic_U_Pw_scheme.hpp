
#if !defined(KRATOS_PORO_NEWMARK_DYNAMIC_U_PW_SCHEME )
#define  KRATOS_PORO_NEWMARK_DYNAMIC_U_PW_SCHEME

#include "custom_strategies/schemes/poro_newmark_quasistatic_U_Pw_scheme.hpp"
#include "poromechanics_application_variables.h"

namespace Kratos
{

template<class TSparseSpace, class TDenseSpace>

class PoroNewmarkDynamicUPwScheme : public PoroNewmarkQuasistaticUPwScheme<TSparseSpace,TDenseSpace>
{

public:

KRATOS_CLASS_POINTER_DEFINITION( PoroNewmarkDynamicUPwScheme );

typedef Scheme<TSparseSpace,TDenseSpace>                      BaseType;
typedef typename BaseType::DofsArrayType                 DofsArrayType;
typedef typename BaseType::TSystemMatrixType         TSystemMatrixType;
typedef typename BaseType::TSystemVectorType         TSystemVectorType;
typedef typename BaseType::LocalSystemVectorType LocalSystemVectorType;
typedef typename BaseType::LocalSystemMatrixType LocalSystemMatrixType;
using PoroNewmarkQuasistaticUPwScheme<TSparseSpace,TDenseSpace>::mDeltaTime;
using PoroNewmarkQuasistaticUPwScheme<TSparseSpace,TDenseSpace>::mBeta;
using PoroNewmarkQuasistaticUPwScheme<TSparseSpace,TDenseSpace>::mGamma;
using PoroNewmarkQuasistaticUPwScheme<TSparseSpace,TDenseSpace>::mTheta;


PoroNewmarkDynamicUPwScheme(double beta, double gamma, double theta)
: PoroNewmarkQuasistaticUPwScheme<TSparseSpace,TDenseSpace>(beta, gamma, theta)
{
int NumThreads = ParallelUtilities::GetNumThreads();
mMassMatrix.resize(NumThreads);
mAccelerationVector.resize(NumThreads);
mDampingMatrix.resize(NumThreads);
mVelocityVector.resize(NumThreads);
}


~PoroNewmarkDynamicUPwScheme() override {}


void Predict(
ModelPart& r_model_part,
DofsArrayType& rDofSet,
TSystemMatrixType& A,
TSystemVectorType& Dx,
TSystemVectorType& b) override
{

array_1d<double,3> DeltaDisplacement;
double DeltaPressure;

const int NNodes = static_cast<int>(r_model_part.Nodes().size());
ModelPart::NodesContainerType::iterator node_begin = r_model_part.NodesBegin();

#pragma omp parallel for private(DeltaDisplacement,DeltaPressure)
for(int i = 0; i < NNodes; i++)
{
ModelPart::NodesContainerType::iterator itNode = node_begin + i;

array_1d<double,3>& CurrentDisplacement = itNode->FastGetSolutionStepValue(DISPLACEMENT);
array_1d<double,3>& CurrentAcceleration = itNode->FastGetSolutionStepValue(ACCELERATION);
array_1d<double,3>& CurrentVelocity = itNode->FastGetSolutionStepValue(VELOCITY);

const array_1d<double,3>& PreviousDisplacement = itNode->FastGetSolutionStepValue(DISPLACEMENT, 1);
const array_1d<double,3>& PreviousAcceleration = itNode->FastGetSolutionStepValue(ACCELERATION, 1);
const array_1d<double,3>& PreviousVelocity = itNode->FastGetSolutionStepValue(VELOCITY, 1);

if (itNode -> IsFixed(ACCELERATION_X))
{
CurrentDisplacement[0] = PreviousDisplacement[0] + mDeltaTime * PreviousVelocity[0] + std::pow(mDeltaTime, 2) * ( ( 0.5 - mBeta) * PreviousAcceleration[0] + mBeta * CurrentAcceleration[0] );
}
else if (itNode -> IsFixed(VELOCITY_X))
{
CurrentDisplacement[0] = PreviousDisplacement[0] + mDeltaTime*(mBeta/mGamma*(CurrentVelocity[0]-PreviousVelocity[0])+PreviousVelocity[0]);
}
else if (itNode -> IsFixed(DISPLACEMENT_X) == false)
{
CurrentDisplacement[0] = PreviousDisplacement[0] + mDeltaTime * PreviousVelocity[0] + 0.5 * std::pow(mDeltaTime, 2) * PreviousAcceleration[0];
}

if (itNode -> IsFixed(ACCELERATION_Y))
{
CurrentDisplacement[1] = PreviousDisplacement[1] + mDeltaTime * PreviousVelocity[1] + std::pow(mDeltaTime, 2) * ( ( 0.5 - mBeta) * PreviousAcceleration[1] + mBeta * CurrentAcceleration[1] );
}
else if (itNode -> IsFixed(VELOCITY_Y))
{
CurrentDisplacement[1] = PreviousDisplacement[1] + mDeltaTime*(mBeta/mGamma*(CurrentVelocity[1]-PreviousVelocity[1])+PreviousVelocity[1]);
}
else if (itNode -> IsFixed(DISPLACEMENT_Y) == false)
{
CurrentDisplacement[1] = PreviousDisplacement[1] + mDeltaTime * PreviousVelocity[1] + 0.5 * std::pow(mDeltaTime, 2) * PreviousAcceleration[1];
}

if (itNode -> HasDofFor(DISPLACEMENT_Z))
{
if (itNode -> IsFixed(ACCELERATION_Z))
{
CurrentDisplacement[2] = PreviousDisplacement[2] + mDeltaTime * PreviousVelocity[2] + std::pow(mDeltaTime, 2) * ( ( 0.5 - mBeta) * PreviousAcceleration[2] + mBeta * CurrentAcceleration[2] );
}
else if (itNode -> IsFixed(VELOCITY_Z))
{
CurrentDisplacement[2] = PreviousDisplacement[2] + mDeltaTime*(mBeta/mGamma*(CurrentVelocity[2]-PreviousVelocity[2])+PreviousVelocity[2]);
}
else if (itNode -> IsFixed(DISPLACEMENT_Z) == false)
{
CurrentDisplacement[2] = PreviousDisplacement[2] + mDeltaTime * PreviousVelocity[2] + 0.5 * std::pow(mDeltaTime, 2) * PreviousAcceleration[2];
}
}

noalias(DeltaDisplacement) = CurrentDisplacement - PreviousDisplacement;

noalias(CurrentAcceleration) = 1.0/(mBeta*mDeltaTime*mDeltaTime)*(DeltaDisplacement - mDeltaTime*PreviousVelocity - (0.5-mBeta)*mDeltaTime*mDeltaTime*PreviousAcceleration);
noalias(CurrentVelocity) = PreviousVelocity + (1.0-mGamma)*mDeltaTime*PreviousAcceleration + mGamma*mDeltaTime*CurrentAcceleration;

double& CurrentDtPressure = itNode->FastGetSolutionStepValue(DT_WATER_PRESSURE);
DeltaPressure = itNode->FastGetSolutionStepValue(WATER_PRESSURE) - itNode->FastGetSolutionStepValue(WATER_PRESSURE, 1);
const double& PreviousDtPressure = itNode->FastGetSolutionStepValue(DT_WATER_PRESSURE, 1);

CurrentDtPressure = 1.0/(mTheta*mDeltaTime)*(DeltaPressure - (1.0-mTheta)*mDeltaTime*PreviousDtPressure);
}
}



void CalculateSystemContributions(
Element& rCurrentElement,
LocalSystemMatrixType& LHS_Contribution,
LocalSystemVectorType& RHS_Contribution,
Element::EquationIdVectorType& EquationId,
const ProcessInfo& CurrentProcessInfo) override
{
KRATOS_TRY

int thread = OpenMPUtils::ThisThread();

rCurrentElement.CalculateLocalSystem(LHS_Contribution,RHS_Contribution,CurrentProcessInfo);

rCurrentElement.CalculateMassMatrix(mMassMatrix[thread],CurrentProcessInfo);

rCurrentElement.CalculateDampingMatrix(mDampingMatrix[thread],CurrentProcessInfo);

this->AddDynamicsToLHS (LHS_Contribution, mMassMatrix[thread], mDampingMatrix[thread], CurrentProcessInfo);

this->AddDynamicsToRHS (rCurrentElement, RHS_Contribution, mMassMatrix[thread], mDampingMatrix[thread], CurrentProcessInfo);

rCurrentElement.EquationIdVector(EquationId,CurrentProcessInfo);

KRATOS_CATCH( "" )
}



void CalculateRHSContribution(
Element& rCurrentElement,
LocalSystemVectorType& RHS_Contribution,
Element::EquationIdVectorType& EquationId,
const ProcessInfo& CurrentProcessInfo) override
{
KRATOS_TRY

int thread = OpenMPUtils::ThisThread();

rCurrentElement.CalculateRightHandSide(RHS_Contribution,CurrentProcessInfo);

rCurrentElement.CalculateMassMatrix(mMassMatrix[thread], CurrentProcessInfo);

rCurrentElement.CalculateDampingMatrix(mDampingMatrix[thread],CurrentProcessInfo);

this->AddDynamicsToRHS (rCurrentElement, RHS_Contribution, mMassMatrix[thread], mDampingMatrix[thread], CurrentProcessInfo);

rCurrentElement.EquationIdVector(EquationId,CurrentProcessInfo);

KRATOS_CATCH( "" )
}



void CalculateLHSContribution(
Element& rCurrentElement,
LocalSystemMatrixType& LHS_Contribution,
Element::EquationIdVectorType& EquationId,
const ProcessInfo& CurrentProcessInfo) override
{
KRATOS_TRY

int thread = OpenMPUtils::ThisThread();

rCurrentElement.CalculateLeftHandSide(LHS_Contribution,CurrentProcessInfo);

rCurrentElement.CalculateMassMatrix(mMassMatrix[thread],CurrentProcessInfo);

rCurrentElement.CalculateDampingMatrix(mDampingMatrix[thread],CurrentProcessInfo);

this->AddDynamicsToLHS (LHS_Contribution, mMassMatrix[thread], mDampingMatrix[thread], CurrentProcessInfo);

rCurrentElement.EquationIdVector(EquationId,CurrentProcessInfo);

KRATOS_CATCH( "" )
}


protected:


std::vector< Matrix > mMassMatrix;
std::vector< Vector > mAccelerationVector;
std::vector< Matrix > mDampingMatrix;
std::vector< Vector > mVelocityVector;


void AddDynamicsToLHS(LocalSystemMatrixType& LHS_Contribution,LocalSystemMatrixType& M,LocalSystemMatrixType& C,const ProcessInfo& CurrentProcessInfo)
{
if (M.size1() != 0)
noalias(LHS_Contribution) += 1.0/(mBeta*mDeltaTime*mDeltaTime)*M;

if (C.size1() != 0)
noalias(LHS_Contribution) += mGamma/(mBeta*mDeltaTime)*C;
}


void AddDynamicsToRHS(Element& rCurrentElement,LocalSystemVectorType& RHS_Contribution,
LocalSystemMatrixType& M,LocalSystemMatrixType& C,const ProcessInfo& CurrentProcessInfo)
{
int thread = OpenMPUtils::ThisThread();

if (M.size1() != 0)
{
rCurrentElement.GetSecondDerivativesVector(mAccelerationVector[thread], 0);

noalias(RHS_Contribution) -= prod(M, mAccelerationVector[thread]);
}

if (C.size1() != 0)
{
rCurrentElement.GetFirstDerivativesVector(mVelocityVector[thread], 0);

noalias(RHS_Contribution) -= prod(C, mVelocityVector[thread]);
}
}

}; 
}  

#endif 