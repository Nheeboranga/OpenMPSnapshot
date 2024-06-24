

#include "muParserError.h"
#include <exception>

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 26812) 
#endif

namespace mu
{
const ParserErrorMsg& ParserErrorMsg::Instance()
{
static const ParserErrorMsg instance;
return instance;
}

string_type ParserErrorMsg::operator[](unsigned a_iIdx) const
{
return (a_iIdx < m_vErrMsg.size()) ? m_vErrMsg[a_iIdx] : string_type();
}

ParserErrorMsg::ParserErrorMsg()
:m_vErrMsg(0)
{
m_vErrMsg.resize(ecCOUNT);

m_vErrMsg[ecUNASSIGNABLE_TOKEN] = _T("Unexpected token \"$TOK$\" found at position $POS$.");
m_vErrMsg[ecINTERNAL_ERROR] = _T("Internal error");
m_vErrMsg[ecINVALID_NAME] = _T("Invalid function-, variable- or constant name: \"$TOK$\".");
m_vErrMsg[ecINVALID_BINOP_IDENT] = _T("Invalid binary operator identifier: \"$TOK$\".");
m_vErrMsg[ecINVALID_INFIX_IDENT] = _T("Invalid infix operator identifier: \"$TOK$\".");
m_vErrMsg[ecINVALID_POSTFIX_IDENT] = _T("Invalid postfix operator identifier: \"$TOK$\".");
m_vErrMsg[ecINVALID_FUN_PTR] = _T("Invalid pointer to callback function.");
m_vErrMsg[ecEMPTY_EXPRESSION] = _T("Expression is empty.");
m_vErrMsg[ecINVALID_VAR_PTR] = _T("Invalid pointer to variable.");
m_vErrMsg[ecUNEXPECTED_OPERATOR] = _T("Unexpected operator \"$TOK$\" found at position $POS$");
m_vErrMsg[ecUNEXPECTED_EOF] = _T("Unexpected end of expression at position $POS$");
m_vErrMsg[ecUNEXPECTED_ARG_SEP] = _T("Unexpected argument separator at position $POS$");
m_vErrMsg[ecUNEXPECTED_PARENS] = _T("Unexpected parenthesis \"$TOK$\" at position $POS$");
m_vErrMsg[ecUNEXPECTED_FUN] = _T("Unexpected function \"$TOK$\" at position $POS$");
m_vErrMsg[ecUNEXPECTED_VAL] = _T("Unexpected value \"$TOK$\" found at position $POS$");
m_vErrMsg[ecUNEXPECTED_VAR] = _T("Unexpected variable \"$TOK$\" found at position $POS$");
m_vErrMsg[ecUNEXPECTED_ARG] = _T("Function arguments used without a function (position: $POS$)");
m_vErrMsg[ecMISSING_PARENS] = _T("Missing parenthesis");
m_vErrMsg[ecTOO_MANY_PARAMS] = _T("Too many parameters for function \"$TOK$\" at expression position $POS$");
m_vErrMsg[ecTOO_FEW_PARAMS] = _T("Too few parameters for function \"$TOK$\" at expression position $POS$");
m_vErrMsg[ecDIV_BY_ZERO] = _T("Divide by zero");
m_vErrMsg[ecDOMAIN_ERROR] = _T("Domain error");
m_vErrMsg[ecNAME_CONFLICT] = _T("Name conflict");
m_vErrMsg[ecOPT_PRI] = _T("Invalid value for operator priority (must be greater or equal to zero).");
m_vErrMsg[ecBUILTIN_OVERLOAD] = _T("user defined binary operator \"$TOK$\" conflicts with a built in operator.");
m_vErrMsg[ecUNEXPECTED_STR] = _T("Unexpected string token found at position $POS$.");
m_vErrMsg[ecUNTERMINATED_STRING] = _T("Unterminated string starting at position $POS$.");
m_vErrMsg[ecSTRING_EXPECTED] = _T("String function called with a non string type of argument.");
m_vErrMsg[ecVAL_EXPECTED] = _T("String value used where a numerical argument is expected.");
m_vErrMsg[ecOPRT_TYPE_CONFLICT] = _T("No suitable overload for operator \"$TOK$\" at position $POS$.");
m_vErrMsg[ecSTR_RESULT] = _T("Strings must only be used as function arguments!");
m_vErrMsg[ecGENERIC] = _T("Parser error.");
m_vErrMsg[ecLOCALE] = _T("Decimal separator is identic to function argument separator.");
m_vErrMsg[ecUNEXPECTED_CONDITIONAL] = _T("The \"$TOK$\" operator must be preceded by a closing bracket.");
m_vErrMsg[ecMISSING_ELSE_CLAUSE] = _T("If-then-else operator is missing an else clause");
m_vErrMsg[ecMISPLACED_COLON] = _T("Misplaced colon at position $POS$");
m_vErrMsg[ecUNREASONABLE_NUMBER_OF_COMPUTATIONS] = _T("Number of computations to small for bulk mode. (Vectorisation overhead too costly)");
m_vErrMsg[ecIDENTIFIER_TOO_LONG] = _T("Identifier too long.");
m_vErrMsg[ecEXPRESSION_TOO_LONG] = _T("Expression too long.");
m_vErrMsg[ecINVALID_CHARACTERS_FOUND] = _T("Invalid non printable characters found in expression/identifer!");

for (int i = 0; i < ecCOUNT; ++i)
{
if (!m_vErrMsg[i].length())
throw std::runtime_error("Error definitions are incomplete!");
}
}



ParserError::ParserError()
:m_strMsg()
, m_strFormula()
, m_strTok()
, m_iPos(-1)
, m_iErrc(ecUNDEFINED)
, m_ErrMsg(ParserErrorMsg::Instance())
{
}


ParserError::ParserError(EErrorCodes a_iErrc)
:m_strMsg()
, m_strFormula()
, m_strTok()
, m_iPos(-1)
, m_iErrc(a_iErrc)
, m_ErrMsg(ParserErrorMsg::Instance())
{
m_strMsg = m_ErrMsg[m_iErrc];
stringstream_type stream;
stream << (int)m_iPos;
ReplaceSubString(m_strMsg, _T("$POS$"), stream.str());
ReplaceSubString(m_strMsg, _T("$TOK$"), m_strTok);
}


ParserError::ParserError(const string_type& sMsg)
:m_ErrMsg(ParserErrorMsg::Instance())
{
Reset();
m_strMsg = sMsg;
}


ParserError::ParserError(EErrorCodes iErrc,
const string_type& sTok,
const string_type& sExpr,
int iPos)
:m_strMsg()
, m_strFormula(sExpr)
, m_strTok(sTok)
, m_iPos(iPos)
, m_iErrc(iErrc)
, m_ErrMsg(ParserErrorMsg::Instance())
{
m_strMsg = m_ErrMsg[m_iErrc];
stringstream_type stream;
stream << (int)m_iPos;
ReplaceSubString(m_strMsg, _T("$POS$"), stream.str());
ReplaceSubString(m_strMsg, _T("$TOK$"), m_strTok);
}


ParserError::ParserError(EErrorCodes iErrc, int iPos, const string_type& sTok)
:m_strMsg()
, m_strFormula()
, m_strTok(sTok)
, m_iPos(iPos)
, m_iErrc(iErrc)
, m_ErrMsg(ParserErrorMsg::Instance())
{
m_strMsg = m_ErrMsg[m_iErrc];
stringstream_type stream;
stream << (int)m_iPos;
ReplaceSubString(m_strMsg, _T("$POS$"), stream.str());
ReplaceSubString(m_strMsg, _T("$TOK$"), m_strTok);
}


ParserError::ParserError(const char_type* szMsg, int iPos, const string_type& sTok)
:m_strMsg(szMsg)
, m_strFormula()
, m_strTok(sTok)
, m_iPos(iPos)
, m_iErrc(ecGENERIC)
, m_ErrMsg(ParserErrorMsg::Instance())
{
stringstream_type stream;
stream << (int)m_iPos;
ReplaceSubString(m_strMsg, _T("$POS$"), stream.str());
ReplaceSubString(m_strMsg, _T("$TOK$"), m_strTok);
}


ParserError::ParserError(const ParserError& a_Obj)
:m_strMsg(a_Obj.m_strMsg)
, m_strFormula(a_Obj.m_strFormula)
, m_strTok(a_Obj.m_strTok)
, m_iPos(a_Obj.m_iPos)
, m_iErrc(a_Obj.m_iErrc)
, m_ErrMsg(ParserErrorMsg::Instance())
{
}


ParserError& ParserError::operator=(const ParserError& a_Obj)
{
if (this == &a_Obj)
return *this;

m_strMsg = a_Obj.m_strMsg;
m_strFormula = a_Obj.m_strFormula;
m_strTok = a_Obj.m_strTok;
m_iPos = a_Obj.m_iPos;
m_iErrc = a_Obj.m_iErrc;
return *this;
}

ParserError::~ParserError()
{}


void ParserError::ReplaceSubString(string_type& strSource,
const string_type& strFind,
const string_type& strReplaceWith)
{
string_type strResult;
string_type::size_type iPos(0), iNext(0);

for (;;)
{
iNext = strSource.find(strFind, iPos);
strResult.append(strSource, iPos, iNext - iPos);

if (iNext == string_type::npos)
break;

strResult.append(strReplaceWith);
iPos = iNext + strFind.length();
}

strSource.swap(strResult);
}


void ParserError::Reset()
{
m_strMsg = _T("");
m_strFormula = _T("");
m_strTok = _T("");
m_iPos = -1;
m_iErrc = ecUNDEFINED;
}


void ParserError::SetFormula(const string_type& a_strFormula)
{
m_strFormula = a_strFormula;
}


const string_type& ParserError::GetExpr() const
{
return m_strFormula;
}


const string_type& ParserError::GetMsg() const
{
return m_strMsg;
}


int ParserError::GetPos() const
{
return m_iPos;
}


const string_type& ParserError::GetToken() const
{
return m_strTok;
}


EErrorCodes ParserError::GetCode() const
{
return m_iErrc;
}
} 

#if defined(_MSC_VER)
#pragma warning(pop)
#endif